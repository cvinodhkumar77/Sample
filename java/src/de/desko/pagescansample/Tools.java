package de.desko.pagescansample;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class Tools {
	
	
	/**
	 * base directory for collecting data.
	 */
	static String tempDir = null;

	static {
		String property = "java.io.tmpdir";

	    tempDir = System.getProperty(property) + File.separator + "pagescanjavasample" + File.separator;
		(new File(tempDir)).mkdirs();
	}

	public static void println()
	{
		System.out.println(String.format("[%s]", Thread.currentThread().getName()));
	}

	public static void println(String text)
	{
		System.out.println(String.format("[%s] %s", Thread.currentThread().getName(), text));
	}
	
	public static void errln()
	{
		System.err.println(String.format("[%s]", Thread.currentThread().getName()));
	}

	public static void errln(String text)
	{
		System.err.println(String.format("[%s] %s", Thread.currentThread().getName(), text));
	}

	public static void writeByteArrayToFile(String filename, byte[] data) throws IOException
	{
		FileOutputStream fos;
		fos = new FileOutputStream(tempDir + filename);
		fos.write(data);
		fos.close();
		Tools.println("wrote file to "+ tempDir + filename);
	}
}
