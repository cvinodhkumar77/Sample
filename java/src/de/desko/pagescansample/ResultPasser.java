package de.desko.pagescansample;

public class ResultPasser<T> {

	T value = null;

	boolean available = false;
	
	synchronized void setResult(T val)
	{
		value = val;
		available = true;
		notifyAll();
	}
	
	public synchronized T getResult(int timeout)
	{
		T res = null;
		if (!available)
		{
			try {
				wait(timeout);
			} catch (InterruptedException e) {
				return null;
			}
		}
		
		res = value;
		available = false;
		value = null;
		
		return res;
	}
	
}
