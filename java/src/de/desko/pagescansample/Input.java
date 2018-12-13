package de.desko.pagescansample;

import java.util.Scanner;

public class Input {
	
	public Scanner scanner = new Scanner(System.in);
	public <T> T selectFromList(String prompt, T[] col, T deflt)
	{
		do {
			
			Tools.println(String.format("%s:",prompt));
	
			for (int i = 0; i < col.length; i++)
			{
				
	
				if (col[i] == deflt)
				{
					Tools.println(String.format("> %6d - %s", i, col[i].toString()));
				}
				else
				{
					Tools.println(String.format("  %6d - %s", i, col[i].toString()));
					
				}
			}
	
			String line = scanner.nextLine().trim();
			
			try {
				if (line.equals(""))
					return deflt;
				
				int sel = Integer.parseInt(line);
				
				if (sel < 0 || sel >= col.length) {
					throw new NumberFormatException("Number out of range.");
				}
				
				return col[sel];
			} catch (NumberFormatException ex) {
				Tools.println(ex.getMessage());
			}
		
		} while (true);
		
	}
	
	public boolean readYesNo(String prompt, boolean deflt)
	{
		do
		{
			Tools.println(String.format("%s  (Y/N) [%s]:", prompt, deflt ? "Y" : "N" ));
			String line = scanner.nextLine();
			line = line.toLowerCase().trim();
			if (line.equals("y") || line.equals("yes") || line.equals("1") || line.equals("true"))
				return true;
			else if (line.equals("n") || line.equals("no") || line.equals("0") || line.equals("false"))
				return false;
			else if (line.equals(""))
				return deflt;
			else
				Tools.println("Bad input. Repeat...");
		} while (true);
	}
	
}
