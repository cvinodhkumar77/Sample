package de.desko.pagescansample;

import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.TimeUnit;

import de.desko.fullpage.Api;
import de.desko.fullpage.OnDevicePlug;
import de.desko.fullpage.OnDocumentInsert;
import de.desko.fullpage.OnDocumentRemove;
import de.desko.fullpage.PsaException;
import de.desko.fullpage.Result;
import de.desko.fullpage.ScanSettings;

/**
 * Thread for communicating with the DESKO PageScan API. 
 *
 */
public class DeviceThread extends Thread implements OnDevicePlug {


	/**
	 * Enqueue new command to be executed by the device thread.
	 * @param cmd the command to be executed.
	 */
	public void enqueueCommand(DeviceCommand cmd)
	{
		Tools.println(String.format("enqueing command %08x", cmd != null ? cmd.hashCode() : 0));
		commandQueue.add(cmd);
	}

	/**
	 * Queue of commands.
	 * 
	 * Both the main thread and the callback threads of the PageScan API use this queue to pass commands to the device thread. 
	 * 
	 */
	LinkedBlockingQueue<DeviceCommand> commandQueue = new LinkedBlockingQueue<DeviceCommand>();

	/**
	 * Command to be run by the device thread after a successful connect.
	 */
	DeviceCommand runOnReConnect = null; 

	/**
	 * Set command to be executed after a successful connect.
	 * @param cmd
	 */
	public synchronized void setReconnectAction(DeviceCommand cmd)
	{
		runOnReConnect = cmd;
	}

	private synchronized DeviceCommand getReconnectAction()
	{
		return runOnReConnect;
	}

	/**
	 * Command to be executed when a document is inserted.
	 */
	DeviceCommand runOnDocumentInsert = null; 

	public synchronized void setDocumentInsertAction(DeviceCommand cmd)
	{
		runOnDocumentInsert = cmd;
		if (runOnDocumentInsert != null)
		{
			enqueueCommand(new DeviceCommand() {
				// this is executed by the device thread
				// to set up the handler

				@Override
				public void runByDeviceThread() throws PsaException {
					Api.setupOnDocumentCallback(new OnDocumentInsert() {

						@Override
						public void onDocumentInsertEvent() {
							// This is executed by an internal API thread
							// for an inserted document.

							DeviceCommand c = runOnDocumentInsert;
							if (c != null)
								enqueueCommand(c);

						}
					});

				}
			});
		}
		else
		{
			enqueueCommand(new DeviceCommand() {
				// This is executed by the device thread

				@Override
				public void runByDeviceThread() throws PsaException {
					// This disables document handling.
					Api.setupOnDocumentCallback(null);					
				}
			});			
		}
	}


	DeviceCommand runOnDocumentRemove = null; 

	public void setDocumentRemoveAction(DeviceCommand cmdOnDocRemove) {
		runOnDocumentRemove = cmdOnDocRemove;
		if (runOnDocumentRemove != null)
		{
			enqueueCommand(new DeviceCommand() {
				// this is executed by the device thread
				// to set up the handler

				@Override
				public void runByDeviceThread() throws PsaException {
					Api.setupOnDocumentRemove(new OnDocumentRemove() {

						@Override
						public void onDocumentRemoveEvent() {
							// This is executed by an internal API thread
							// for an removed document.

							DeviceCommand c = runOnDocumentRemove;
							if (c != null)
								enqueueCommand(c);
						}
					});

				}
			});
		}
		else
		{
			enqueueCommand(new DeviceCommand() {
				// This is executed by the device thread

				@Override
				public void runByDeviceThread() throws PsaException {
					// This disables document handling.
					Api.setupOnDocumentRemove(null);					
				}
			});			
		}
	}

	boolean shutdown = false;
	boolean currentlyPlugged = false;

	CommunicationState comState = CommunicationState.Closed;

	public synchronized CommunicationState getCommunicationState()
	{
		return comState;
	}

	private synchronized void setCommunicationState(CommunicationState s)
	{
		comState = s;
	}

	public void doShutdown()
	{
		shutdown = true;
		synchronized (this) {
			notifyAll();
		}
	}


	/**
	 * The actual device thread.
	 */
	@Override
	public void run() {
		Tools.println("STARTED");

		try {



			Api.setupOnDevicePlugCallback(this);

			while (! shutdown)
			{	
				// Stage 1 - establish connection

				while (!shutdown) {

					/// wait for plug
					setCommunicationState(CommunicationState.Disconnected);
					synchronized (this) {
						while (!currentlyPlugged && !shutdown)
						{

							Tools.println("Not plugged. Going to sleep.");
							wait();
							Tools.println("Woke up.");
						}
					}


					if (shutdown)
						break;

					Thread.sleep(500);

					setCommunicationState(CommunicationState.Pending);

					/// try connect
					try {
						Api.connectToDevice();
						Tools.println("Connected. Running reconnect action...");

						DeviceCommand cmd = getReconnectAction();
						if (cmd != null)
						{
							cmd.runByDeviceThread();
						}
						Tools.println("Device ready for use.");

						break;
					} catch (PsaException e) {
						Tools.println(e.getMessage());
						Tools.println("Waiting 5 sec for retry.");
						Thread.sleep(5000);
					}

				}

				if (shutdown)
					break;


				// Stage 2 - Process command queue.
				
				setCommunicationState(CommunicationState.Good);

				DeviceCommand cmd;
				do
				{
					cmd = commandQueue.poll(500,TimeUnit.MILLISECONDS);

					if (shutdown)
						break;

					if (cmd == null)
					{
						if (!Api.isDeviceConnected())
						{
							Tools.println("Connection lost. Failover.");
							setCommunicationState(CommunicationState.Disconnected);

							break;
						}
						else
							continue;
					}
					else
					{
						Tools.println(String.format("Running dequeued command %08x", cmd.hashCode()));

						try {
							cmd.runByDeviceThread();
						} catch (PsaException e) {
							System.err.println(e.toString());

							if (e.result == Result.Device_NotConnected || e.result == Result.Device_NotFound)
							{
								Tools.println("Connection lost. Failover.");
								setCommunicationState(CommunicationState.Disconnected);

								break;
							}
						}
					}

				} while (!shutdown);

			}
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		shutdown = false;

		Tools.println("STOPPED");
	}

	/**
	 *  plug event handler passing plug state to device thread.
	 */
	@Override
	public void onPlugEvent(boolean plugged) {
		Tools.println(String.format("Plug=%b", plugged));
		synchronized(this)
		{
			currentlyPlugged = plugged;
			notifyAll();
		}		
	}


}
