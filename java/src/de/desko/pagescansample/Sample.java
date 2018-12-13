package de.desko.pagescansample;




import de.desko.fullpage.*;
public class Sample {

	DeviceControl ctrl = null;	
	String command = null;
	Input input = null;
	boolean autoscan = false;
	
	public Sample()
	{
		command = null;
		ctrl = new DeviceControl();
		input = new Input();	
	}

	public void menuMain()
	{
		try {
			Tools.println("Starting up...");

			ctrl.startup();
		
			do
			{
				Tools.println("== Main Menu ==");
				Tools.println(" g - Get scan settings");
				Tools.println(" s - Set scan settings");
				Tools.println(" c - Trigger scan & data capturing");
				Tools.println(String.format(" a - Toggle autoscan (Now:%s)", autoscan ? "ON" : "OFF"));
				Tools.println();
				Tools.println(" q - quit");
				command = input.scanner.nextLine();
				
				if (command.length() == 0)
					continue;
				
				if (command.startsWith("q"))
				{
					break;
				}
				else if (command.startsWith("g"))
				{
					ScanSettings ss = ctrl.getScanSettings();
					
					if (ss == null)
					{
						System.out.println("Operation failed.");
					}
					else
					{
						System.out.println(String.format("IR=%b/%b VIS=%b/%b UV=%b/%b UVIS=%b/%b RES=%s",
								ss.infrared.use,
								ss.infrared.ambientLightElimination,
								ss.visible.use,
								ss.visible.ambientLightElimination,
								ss.ultraviolet.use,
								ss.ultraviolet.ambientLightElimination,
								ss.ultravioletVisible.use,
								ss.ultravioletVisible.ambientLightElimination,
								ss.resolution.name()
								));						
					}
				}
				else if (command.startsWith("s"))
				{
					menuSetScanSettings();
				}
				else if (command.startsWith("c"))
				{
					ctrl.manualTriggerScan();
				}
				else if (command.startsWith("a"))
				{
					autoscan = ! autoscan;
					System.out.println(String.format("Turning handler %s.",autoscan ? "ON" :"OFF"));
					ctrl.setAutomaticTrigger(autoscan);
					ctrl.setDocRemoveIndicator(autoscan);

				}
				
				
			} while (true);
			
			Tools.println("Shutting down...");
			
			ctrl.shutdown();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		
	}
	
	
	
	public void menuSetScanSettings()
	{
		Tools.println("== Set Scan Settings ==");
		
		ScanSettings ss = new ScanSettings();
		ss.infrared.use = input.readYesNo("Infrared - use", true);
		ss.infrared.use = input.readYesNo("Infrared - ambient light elimination", true);
		ss.visible.use = input.readYesNo("Visible - use", true);
		ss.visible.use = input.readYesNo("Visible - ambient light elimination", true);
		ss.ultraviolet.use = input.readYesNo("Ultraviolet - use", true);
		ss.ultraviolet.use = input.readYesNo("Ultraviolet - ambient light elimination", true);
		ss.resolution = input.selectFromList("Resolution", new ScanResolution[] { ScanResolution.Low, ScanResolution.Default, ScanResolution.High } , ScanResolution.Default);
		
		ctrl.setScanSettings(ss);
		
	}
	
	public static void main(String[] args) {
		

		Sample sc = new Sample();
		sc.menuMain();

		
		
	}

}
