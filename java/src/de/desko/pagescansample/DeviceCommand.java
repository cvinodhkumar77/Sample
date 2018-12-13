package de.desko.pagescansample;

import de.desko.fullpage.PsaException;

public interface DeviceCommand {
	void runByDeviceThread() throws PsaException;
}
