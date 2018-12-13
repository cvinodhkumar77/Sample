package de.desko.pagescansample;

import java.awt.Image;
import java.io.FileNotFoundException;
import java.io.IOException;


import de.desko.fullpage.*;

/**
 * This class provides code fragments for controlling the device and reacting to events.
 * 
 * The device control does not call the device API directly. It starts up a 
 * device thread to execute the code fragments concurrently and in a defined order.
 * 
 * There are at least three threads involved in any communication:
 * <ul>
 * <li>The main thread (MT) talking to the device control to setup event handlers and initiate actions</li> 
 * <li>The device thread (DT) accepting commands and performing them by talking to the device API (DESKO PageScan API).</li>
 * <li>API threads (AT) maintained by the DESKO PageScan API to notify device events.</li>  
 * </ul>
 *
 * For commands initiated by the application the following communication pattern is used:
 * <ul>
 * <li>The individual calls to the PageScanAPI are defined as a series of commands, i.e., a custom implementation of the DeviceCommand interface.</li>
 * <li>MT puts an instance of this command series into the command queue.</li>
 * <li>DT takes the instance from the command queue and executes it in it's context.</li>
 * </ul>
 * 
 * For device events the approach is similar.
 * 
 * <ul>
 * <li>The individual calls to be executed on the event are defined as an implementation <em>e</em> of DeviceCommand.</li>
 * <li>When the event occurs, AT places <em>e</em> into the command queue.</li>
 * <li>DT takes the instance from the command queue and executes it in it's context.</li> 
 * </ul>
 * 
 * MT --- command queue ---> DT
 */
public class DeviceControl {

	/**
	 * Keeps current settings used by the device to capture images.
	 */
	ScanSettings settings = null;
	

	/**
	 * Constructor.
	 */
	public DeviceControl()
	{
		settings = new ScanSettings();
		settings.infrared.use = true;
		settings.infrared.ambientLightElimination = true;
		settings.visible.use = true;
		settings.visible.ambientLightElimination = true;
		settings.ultraviolet.use = true;
		settings.ultraviolet.ambientLightElimination = true;
		settings.resolution = ScanResolution.Default;
		
		
		deviceThread = new DeviceThread();
		deviceThread.setName("DeviceThread");
		
		// set a command to be called by the device thread
		deviceThread.setReconnectAction(cmdOnConnect);
		
	}
	
	/**
	 * The device thread instance.
	 */
	DeviceThread deviceThread = null;
	
	/**
	 * Start up device thread.
	 * @throws Exception
	 */
	public void startup() throws Exception {
		if (deviceThread == null)
		{
			deviceThread = new DeviceThread();
			deviceThread.setName("DeviceThread");
			deviceThread.setReconnectAction(cmdSetScanSettings);
		}
		deviceThread.start();
	}
	
	/**
	 * Shut down device thread.
	 */
	public void shutdown() {
		if (deviceThread == null)
			return;
		
		deviceThread.doShutdown();
		try {
			deviceThread.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		deviceThread = null;
	}

	
	/**
	 * Cached device info. 
	 */
	DeviceInfo deviceInfo = new DeviceInfo();

	/**
	 * Commands to be executed after connect.
	 */
	DeviceCommand cmdOnConnect = new DeviceCommand() {			
		@Override
		public void runByDeviceThread() throws PsaException {
			Tools.println("SetScanSettings");
			Api.setScanSettings(settings);
			
			Tools.println(String.format("Serial Number: %s", Api.getProperty(PropertyKey.DeviceSerialNumber, "n/a")));
			Tools.println(String.format("Firmware: %s (%s %s)", Api.getProperty(PropertyKey.DeviceFirmwareVersionString, "n/a"),Api.getProperty(PropertyKey.DeviceFirmwareDate, "n/a"),Api.getProperty(PropertyKey.DeviceFirmwareTime, "n/a")));
			Tools.println(String.format("Illumination: %s.%s/%s", Api.getProperty(PropertyKey.DeviceIlluminationGenerationVerbose, "?"), Api.getProperty(PropertyKey.DeviceIlluminationRevisionVerbose, "?"), Api.getProperty(PropertyKey.DeviceIlluminationVariantVerbose, "?")));
			Tools.println(String.format("Support DeviceSupportBarcode: %d", Api.getProperty(PropertyKey.DeviceSupportBarcode, 0)));
			Tools.println(String.format("Support DeviceSupportBatteryChargeLevel: %d", Api.getProperty(PropertyKey.DeviceSupportBatteryChargeLevel, 0)));
			Tools.println(String.format("Support DeviceSupportColor: %d", Api.getProperty(PropertyKey.DeviceSupportColor, 0)));
			Tools.println(String.format("Support DeviceSupportExternalBuzzer: %d", Api.getProperty(PropertyKey.DeviceSupportExternalBuzzer, 0)));
			Tools.println(String.format("Support DeviceSupportExternalStatusLed: %d", Api.getProperty(PropertyKey.DeviceSupportExternalStatusLed, 0)));
			Tools.println(String.format("Support DeviceSupportGlareReduction: %d", Api.getProperty(PropertyKey.DeviceSupportGlareReduction, 0)));
			Tools.println(String.format("Support DeviceSupportGraphicalDisplay: %d", Api.getProperty(PropertyKey.DeviceSupportGraphicalDisplay, 0)));
			Tools.println(String.format("Support DeviceSupportMsr: %d", Api.getProperty(PropertyKey.DeviceSupportMsr, 0)));
			Tools.println(String.format("Support DeviceSupportRealTimeClock: %d", Api.getProperty(PropertyKey.DeviceSupportRealTimeClock, 0)));
			Tools.println(String.format("Support DeviceSupportTextDisplay: %d", Api.getProperty(PropertyKey.DeviceSupportTextDisplay, 0)));
			Tools.println(String.format("Support DeviceSupportUvLight: %d", Api.getProperty(PropertyKey.DeviceSupportUvLight, 0)));
			
			deviceInfo = Api.getDeviceInfo();
		}
	};

	
	/**
	 * Commands to set scan settings.
	 * 
	 */
	DeviceCommand cmdSetScanSettings = new DeviceCommand() {			
		@Override
		public void runByDeviceThread() throws PsaException {
			Tools.println("SetScanSettings");
			Api.setScanSettings(settings);
		}
	};
	


	/**
	 * Commands to be executed on a scan request.
	 * 
	 */
	DeviceCommand cmdPerformScan = new DeviceCommand() {
		
		/**
		 * Attention feedback.
		 * 
		 * Series of commands to be called in the device thread context.
		 */
		void feedbackAttention()
		{
			try {
				BuzzerSettings bs = new BuzzerSettings();
				bs.Duration=100;
				bs.HighTime=100;
				bs.LowTime=100;
				bs.Volume=255;
				Api.setBuzzer(bs);
				
				Api.useBuzzer();
				
				LedSettings ls = new LedSettings();
				ls.Color = LedColor.Yellow;
				ls.Duration = 1000;
				ls.Enabled = true;
				ls.HighTime = 1000;
				ls.LowTime = 0;
				ls.Usage = LedUsage.Flashing;
				Api.setStatusLed(false, ls);
				Api.useStatusLed(false);
				
				if (0 != (deviceInfo.features & DeviceInfoFlags.ExternalStatusLed))
				{
					Api.setExtStatusLed(LedColor.Yellow);
				}
			} catch (PsaException ex) {
				Tools.errln(ex.getMessage());
			}
		}

		/**
		 * Good feedback.
		 * 
		 * Series of commands to be called in the device thread context.
		 */
		void feedbackGood()
		{
			try {
				BuzzerSettings bs = new BuzzerSettings();
				bs.Duration=100;
				bs.HighTime=100;
				bs.LowTime=100;
				bs.Volume=255;
				Api.setBuzzer(bs);
				Api.useBuzzer();
				
				LedSettings ls = new LedSettings();
				ls.Color = LedColor.Green;
				ls.Duration = 1000;
				ls.Enabled = true;
				ls.HighTime = 1000;
				ls.LowTime = 0;
				ls.Usage = LedUsage.Permanent;
				Api.setStatusLed(true, ls);
				Api.useStatusLed(true);
				
				if (0 != (deviceInfo.features & DeviceInfoFlags.ExternalStatusLed))
				{
					Api.setExtStatusLed(LedColor.Green);
				}
			} catch (PsaException ex) {
				Tools.errln(ex.getMessage());
			}
		}
		
		/**
		 * Off feedback.
		 * 
		 * Series of commands to be called in the device thread context.
		 */
		void feedbackOff()
		{
			try {
				if (0 != (deviceInfo.features & DeviceInfoFlags.ExternalStatusLed))
				{
					Api.setExtStatusLed(LedColor.Green);
				}	
			} catch (PsaException ex) {
				Tools.errln(ex.getMessage());
			}
		}
		
		
		/**
		 * This is the actual series of operations to perform on a scan request.
		 */
		@Override
		public void runByDeviceThread() throws PsaException {
			
			// Important for optimal performance:
			// - Perform Api.setScanSettings() only once after (re-)connect - not each time you want to scan.
			// - Keep the optimal order of operations: First scan, then infrared operations, then visible and finally ultraviolet.
			// - Always call the operations from a single thread.
			try {			
				feedbackAttention();
				
				Api.scan();
				
				feedbackGood();
				
				
				if (settings.infrared.use)
				{
					
					try {
						Tools.println(String.format("Document moved while scanning infrared: %f px", Api.estimateDocumentMotion(LightSource.Infrared)));
						
						Tools.println(String.format("MRZ with B900 ink %s.", Api.checkB900Ink() ? "FOUND" : "MISSING"));
						
					} catch( PsaException ex) {
						Tools.errln(ex.getMessage());					
					}
					
					String ocr = null;
					try {
						ocr = Api.getOcrPc();
					} catch( PsaException ex) {
						Tools.errln(ex.getMessage());
					}
					
					if (ocr == null)
					{
						if (0!= (deviceInfo.features & DeviceInfoFlags.TextDisplay))
						{
							Api.showDisplay("No MRZ available.");
						}
						Tools.println("No ocr available.");
					}
					else
					{
						if (0!= (deviceInfo.features & DeviceInfoFlags.TextDisplay))
						{
							Api.showDisplay(ocr);
						}
	
						String[] lines = ocr.split("\r");
						for(String l : lines)
						{
							Tools.println(l);
						}
					}
					
					ImageData data = null;
					try {
						
					
						
						data = Api.getImageBytes(LightSource.Infrared, ImageOptimize.Best, ImageFileType.Png, ImageClipping.Document);
					} catch( PsaException ex) {
						Tools.errln(ex.getMessage());
					}
					
					if(data == null)
					{
						Tools.println("IR data is empty.");
					}
					else
					{
						Tools.println("IR received.");
					
						try {
							Tools.writeByteArrayToFile("infrared.png", data.data);
						} catch (FileNotFoundException e) {
							Tools.errln("Could not write data. File not found.");
						} catch (IOException e) {
							Tools.errln("Could not write data to file.");
						}
					}
				}
	
				if (settings.visible.use)
				{
					ImageData data = null;
					
					try {
						Tools.println(String.format("Document moved while scanning visible: %f px", Api.estimateDocumentMotion(LightSource.Visible)));
	
						data = Api.getImageBytes(LightSource.Visible, ImageOptimize.Best, ImageFileType.Jpeg, ImageClipping.Document);			
					} catch( PsaException ex) {
						
					}
					
					if(data == null)
					{
						Tools.println("Visible data is empty.");
					}
					else
					{
						Tools.println("Visible received.");
						
						try {
							Tools.writeByteArrayToFile("visible.jpg", data.data);
						} catch (FileNotFoundException e) {
							Tools.errln("Could not write data. File not found.");
						} catch (IOException e) {
							Tools.errln("Could not write data to file.");
						}
					}
					
					
					ImageData face = null;
					
					try {
						face = Api.getImageBytes(LightSource.Visible, ImageOptimize.Best, ImageFileType.Jpeg, ImageClipping.Face);
					} catch( PsaException ex) {
					}
					
					if(face == null)
					{
						Tools.println("Visible data for face not available.");
					}
					else
					{
						Tools.println("Visible data for face received.");
						
						try {
							Tools.writeByteArrayToFile("visible_face.jpg", face.data);
						} catch (FileNotFoundException e) {
							Tools.errln("Could not write data. File not found.");
						} catch (IOException e) {
							Tools.errln("Could not write data to file.");
						}
					}
					
					
				}
	
				if (settings.ultraviolet.use)
				{
					ImageData data = null;
					try {
						Tools.println(String.format("UV response is %s.", Api.checkUvDullness() ? "DULL" : "BRIGHT"));
	
						data = Api.getImageBytes(LightSource.Ultraviolet, ImageOptimize.Best, ImageFileType.Bmp, ImageClipping.Document);
					} catch( PsaException ex) {
						Tools.errln(ex.getMessage());
					}
					
					
					if(data == null)
					{
						Tools.println("Ultraviolet data is empty.");
					}
					else
					{
						Tools.println("Ultraviolet received.");
						
						try {
							Tools.writeByteArrayToFile("ultraviolet.bmp", data.data);
						} catch (FileNotFoundException e) {
							System.err.println("Could not write data. File not found.");
						} catch (IOException e) {
							System.err.println("Could not write data to file.");
						}
					}
				}
			
			}
			finally
			{
				System.gc();
			}
		}
	};

	private DeviceCommand cmdOnDocRemove = new DeviceCommand() {
		
		@Override
		public void runByDeviceThread() throws PsaException {
			Tools.println("Document removed.");
			
		}
	};



	/**
	 * Set scan settings to be used for subsequent scans.
	 * 
	 * @param active
	 */
	public void setScanSettings(ScanSettings s)
	{
		settings = s;
		
		deviceThread.enqueueCommand(cmdSetScanSettings);
	}

	
	
	
	ResultPasser<ScanSettings> scanSettingsPasser = null;

	/**
	 * Example of a blocking communication.
	 * @return
	 */
	public ScanSettings getScanSettings()
	{
		// Create a synchronization object for receiving the result. 
		scanSettingsPasser = new ResultPasser<ScanSettings>();
	
		// enqueue the command to get scan settings
		deviceThread.enqueueCommand(new DeviceCommand() {
			
			@Override
			public void runByDeviceThread() throws PsaException {
				scanSettingsPasser.setResult(Api.getScanSettings());
			}
		});
		
		// wait for the device thread to return the data.
		settings = scanSettingsPasser.getResult(5000);
		return settings;
	
	}

	
	
	
	ResultPasser<Image> imageIrPasser = null;

	public void manualTriggerScan()
	{
		imageIrPasser = new ResultPasser<Image>();
		deviceThread.enqueueCommand(cmdPerformScan);		
	}

	public void setAutomaticTrigger(boolean active) {
		if (active)
			deviceThread.setDocumentInsertAction(cmdPerformScan);
		else
			deviceThread.setDocumentInsertAction(null);
	}

	
	public void setDocRemoveIndicator(boolean active) {
		if (active)
			deviceThread.setDocumentRemoveAction(cmdOnDocRemove);
		else
			deviceThread.setDocumentRemoveAction(null);
	}

	
}
