// THIS FILE IS GENERATED. DO NOT EDIT! 
/**

*/

/*
Product Name: DESKO PageScanAPI
OS: Win32
Manufacturer: DESKO GmbH, 95448 Bayreuth, Germany
*/

//---------------------------------------------------------------------------
#ifndef PAGESCANAPI_APPLICATION_INTERFACE_H
#define PAGESCANAPI_APPLICATION_INTERFACE_H
//---------------------------------------------------------------------------

#ifndef PAGESCANAPI_USAGE
#ifdef PAGESCANAPI_EXPORTS
#define PAGESCANAPI_USAGE extern "C" __declspec(dllexport)
#else
#define PAGESCANAPI_USAGE extern "C" __declspec(dllimport)
#endif
#endif

#ifndef PAGESCANAPI_STDCALL
#define PAGESCANAPI_STDCALL __stdcall
#endif

//---------------------------------------------------------------------------


/**
@file PageScanApi.h
PageScan C++ API 
Public Interface
*/

#ifndef PAGESCANAPI_NO_NAMESPACE
#ifdef PAGESCANAPI_NEW_NAMESPACE
#define PAGESCANAPI_NAMESPACE Desko::FullPage
namespace Desko
{
	namespace FullPage
#else
#define PAGESCANAPI_NAMESPACE PageScanAPI
namespace PageScanAPI
#endif
{
#endif
	//--------------------------------------------------------------------------------------------------

	/** \defgroup groupCommon Common Definitions
		
	Basic structures and data types, error handling and logging.
		
	@{
	*/

	/**
	@name API Version Constants
	
	@{
	*/

	/// Version of the API 
	const int API_VERSION = 4;
	/// Primary number of the API 
	const int API_NUMBER = 5;
	/// Release number of the API 
	const int API_RELEASE = 1;
	/** @} */

	/**
	@name Scan Light Source Constants
	
	@{
	*/
	/// Type of available light sources.
	typedef int TPSALightSource;
	/// Infrared light source.
	const TPSALightSource lsIr = 0;
	/// Visible white light source.
	const TPSALightSource lsVisible = 1;
	/// UV light source.
	const TPSALightSource lsUvOnly = 2;
	/// UV light source with additional white light.
	const TPSALightSource lsUv3LED = 3; 
	/// number of light sources
	const TPSALightSource lsCount = 4; 

	/** @} */

	/**
	@name Scan Resolution Constants
	
	@{
	*/

	/**
	Type of available scan resolutions.

	\see resUndefined, resLow, resDefault, resHigh
	*/
	typedef unsigned int TPSAResolution;
	/// Undefined resolution \deprecated Please, use resUndefined instead.
	const TPSAResolution PSA_UNDEF_PIXELS_PER_MM = 0;
	/// Resolution of 150 dpi \deprecated Resolution of 150 dpi is not guaranteed.
	const TPSAResolution PSA_150_DPI = 1; 
	/// Resolution of 240 dpi \deprecated Resolution of 240 dpi is not guaranteed.
	const TPSAResolution PSA_240_DPI = 2;
	/// Resolution of 300 dpi. On single camera device: Same as PSA_240_DPI. \deprecated Resolution of 300 dpi is not guaranteed.
	const TPSAResolution PSA_300_DPI = 3; 
	/// Resolution of 450 dpi. On single camera device: Same as PSA_240_DPI. \deprecated Resolution of 450 dpi is not guaranteed.
	const TPSAResolution PSA_450_DPI = 4; 
	/// Resolution of 600 dpi. \deprecated Resolution of 600 dpi is not guaranteed.
	const TPSAResolution PSA_600_DPI = 5; 

	/// Undefined resolution
	const TPSAResolution resUndefined = 0x00; 
	/// Low resolution
	const TPSAResolution resLow = 0x01;
	/// Default resolution. Recommended resolution for OCR on PC.
	const TPSAResolution resDefault = 0x02;
	/// High resolution
	const TPSAResolution resHigh = 0x05;
	/** @} */

	/**
	@name Recognition Result Codes
	
	@{
	*/

	/**
	Data type for available results of a text recognition call.
	\see rrFailedRecognition, rrGoodRecognition 
	*/
	typedef int TPSARecognitionResult;
	/// Recognition returned without error. \deprecated This value is not used as result anymore.
	const TPSARecognitionResult rrNoErr = 0;
	/// No document found on the scanner.
	const TPSARecognitionResult rrFailedRecognition = 1;
	/// Document without MRZ found on the scanner. \deprecated This value is not used as result anymore.
	const TPSARecognitionResult rrDocWithoutMrz = 2;
	/// Document found on the scanner but too much rotated. \deprecated This value is not used as result anymore.
	const TPSARecognitionResult rrDocRotation = 3;
	/// Good result, MRZ successfully recognized.
	const TPSARecognitionResult rrGoodRecognition = 4;
	/// Document with MRZ found but to many unreadable characters. \deprecated This value is not used as result anymore.
	const TPSARecognitionResult rrToManyRejections = 5;
	/// Document with MRZ found but invalid layout of the MRZ. \deprecated This value is not used as result anymore.
	const TPSARecognitionResult rrDocLayoutNotOK = 6;
	/// An unexpected error occurred during recognition. \deprecated This value is not used as result anymore.
	const TPSARecognitionResult rrUnknownError = 99;
	/// No document found on the scanner. \deprecated This value is not used as result anymore.
	const TPSARecognitionResult rrNoDoc = 1;
	/**
	@}
	*/


	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupError Error Handling

	Error handling functions.
	@{
	*/

	/**
	@name Status Codes
	
	@{
	*/


	/// Data type for all API call result codes
	typedef int TPSAResult;
	/// Call finished successfully.
	const TPSAResult psaSuccess = 0;
	/// Call ended with unknown error.
	const TPSAResult psaFail = 1;
	/// Call ended with error - not found.
	const TPSAResult psaDevice_NotFound = 51;
	/// Call ended with error - not connected.
	const TPSAResult psaDevice_NotConnected = 52;
	/// Call ended with error - already connected.
	const TPSAResult psaDevice_AlreadyConnected = 53;
	/// Call ended with error - unexpected answer.
	const TPSAResult psaDevice_UnexpectedAnswer = 54;
	/// Call ended with error - unknown error.
	const TPSAResult psaUnkownError = 99;
	/// Call ended with error - invalid buffer size.
	const TPSAResult psaIntf_InvalidBufferSize = 71;
	/// Call ended with error - device not calibrated.
	const TPSAResult psaIntf_NotCalibrated = 72;
	/// Call ended with error - function not supported.
	const TPSAResult psaUnsupportedFunction = 98;

	/** @} */

	/**
	Get the last error message.

	The function returns the result code and verbose message of the last error occurred in the API.
	It should be called right after the failing call to get a more detailed error description.

	\param[out] OutError  Result code of the error message.
	\param[out] OutMessage  Filled with the message text of the error message.
	\param[in]  MaxMessageLength  Maximum length of the error message.
	*/
	PAGESCANAPI_USAGE void PAGESCANAPI_STDCALL GetLastPSAError(TPSAResult& OutError, char* OutMessage, int MaxMessageLength); 

	/**
	Set the last error message (do not call in your application).

	This function is called internally by the the PageScan API to provide 
	verbose error information.
	\param[in] Error     Result code of the error message.
	\param[in] Message   Message text of the error message.
	\param[in] Function  Function where the error occurred.
	\see GetLastPSAError
	\deprecated Do not call. This function is for internal use only.
	*/
	PAGESCANAPI_USAGE void PAGESCANAPI_STDCALL SetLastPSAError(TPSAResult Error, const char* Message, const char* Function);
	/** @} */

	//--------------------------------------------------------------------------------------------------
	/**
	\defgroup groupLog Logging

	This section describes the API functions which can be used for logging.
	Alternatively, the DLL provides Log4J-compatible logging which does not require using this API.
	Log4J logging can be configured in the log4j.properties configuration file.
	@{
	*/

	/**
	 @name Log Levels

	 @{
	*/

	/**
	
	Type of available debug levels.

	\deprecated This type is deprecated because the level of verbosity does not correlate with the level value.
	\see TPSALogLevel
	*/
	typedef int TPSADebugLevel;
	/// Deprecated debug level: no debug output   \deprecated Please use log levels defined in TPSALogLevel.
	const TPSADebugLevel debugNone = 0; 
	/// Deprecated debug level: only errors, system messages and notices are shown.   \deprecated Please use log levels defined in TPSALogLevel.
	const TPSADebugLevel debugNotice = 1; 
	/// Deprecated debug level: only errors and system messages are shown.   \deprecated Please use log levels defined in TPSALogLevel.
	const TPSADebugLevel debugSystem = 2;
	/// Deprecated debug level: only errors are shown.   \deprecated Please use log levels defined in TPSALogLevel.
	const TPSADebugLevel debugError = 3;

	/// Data type for available log levels.
	typedef int TPSALogLevel;
	/// Log level for turning API logging off
	const TPSALogLevel logOff = 0x10; 
	/// Log level for fatal errors (program can not continue execution)
	const TPSALogLevel logFatal = 0x11; 
	/// Log level for normal errors (program can continue execution)
	const TPSALogLevel logError = 0x12;
	/// Log level for warnings
	const TPSALogLevel logWarn = 0x13;
	/// Log level for informative messages
	const TPSALogLevel logInfo = 0x14;
	/// Log level for debugging info
	const TPSALogLevel logDebug = 0x15;
	/// Log level for trace messages
	const TPSALogLevel logTrace = 0x16;
	/** @} */

	/**
	Event type for debug message output.

	The API caller can provide a callback function with this signature to 
	function SetupDebug() in order to implement custom debugging.

	\param[in] Timestamp   Timestamp of the trace output in ms since start of the application.
	\param[in] Domain      Domain where the trace output was written (null-terminated string).
	\param[in] Thread      Thread identifier.
	\param[in] Level       Debug level for this output. 
	\param[in] Function    Function where the trace output was written (null-terminated string).
	\param[in] Message     Message of the trace output (null-terminated string).

	\see SetupDebug
	*/
	typedef void (PAGESCANAPI_STDCALL *TOnDebug)(int Timestamp, const char* Thread, const char* Domain, TPSALogLevel Level, char* Function, char* Message);

	/**
	Setup callback for the debug event.

	Note that, in order to avoid deadlocks or race conditions, the custom callback OnDebug must never
	call any function of the API directly.

	\param[in] OnDebug         Reference to the debug callback. May be NULL to disable API logging.
	\param[in] NewDebugLevel   Maximum log level of a message to be send to output. 
	*/
	PAGESCANAPI_USAGE void PAGESCANAPI_STDCALL SetupDebug(TOnDebug OnDebug, TPSALogLevel NewDebugLevel);

	/** @} */
	/** @} */

	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupDeviceControl Device Control
	
	Basic device state and maintenance operations.
	
	@{
	*/

	/**
	Connect to the device.

	An established connection is required to be able to communicate with the device.
	The device cannot be shared by two applications: If another application is connected, this function will fail with return code psaDevice_AlreadyConnected.

	Note that this function must also be called after a temporary
	loss of the USB connection. The recommended way is to perform the connection in a custom TOnDevicePlug callback and register it to SetupOnDevicePlugCallback().

	\return  psaSuccess if successful. Otherwise psaDevice_NotConnected, psaDevice_AlreadyConnected or other suitable error code.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ConnectToDevice(void);

	/**
	Disconnect from the device.

	No communication is possible anymore after this call and other applications are be able to connect tho the device exclusively.
	
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL DisconnectFromDevice(void);

	/**
	Reset the device.

	A reset will force a full reboot of the firmware making the device unavailable for
	several seconds.
	During this process, the TOnDevicePlug will be called twice:
	Once when the device disconnects for rebooting and once when it is back up running.

	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ResetDevice(void);

	/**
	Get connection state of the device.

	\return  _true_ if the device is connected, _false_ if not.
	*/
	PAGESCANAPI_USAGE bool PAGESCANAPI_STDCALL IsDeviceConnected(void);

	/**
	Get USB driver plug state of the device.

	\return  _true_ if the device is plugged and the system drivers are operational, _false_ otherwise.
	*/
	PAGESCANAPI_USAGE bool PAGESCANAPI_STDCALL IsDevicePlugged(void);

	/**
	Set auto-reset mode for firmware and config updates.
	
	In auto-reset mode the device resets itself as soon as a firmware or configuration has been updated.
	During reset the connection gets lost and the device will not be available for the time it performs its reinitialization.

	Auto-reset can be disabled to speed up the process of a combined firmware and configuration update. This is done 
	by delaying the reset until the end of the operation and by concluding with an explicit call to ResetDevice().

	Note that for older firmware versions auto-reset cannot be disabled. In this situation the returned error value is psaFail.

	\param[in] enabled   If true, device will reset itself after firmware or config updates. 
	\return psaSuccess on success. Respective error result code otherwise.
	
	\see ResetDevice, UpdateFirmware, SetConfig
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetAutoReset(bool enabled);

	/**
	Get auto-reset mode for firmware and config updates.
	
	In auto-reset mode the device resets itself as soon as a firmware or configuration has been updated.
	During reset the connection gets lost and the device will not be available for the time it performs its reinitialization.

	Auto-reset can be disabled to speed up the process of a combined firmware and configuration update. This is done 
	by delaying the reset until the end of the operation and by concluding with an explicit call to ResetDevice().

	Note that for older firmware versions auto-reset cannot be disabled. In this situation the returned error value is psaFail.

	\param[out] enabled   true if the device will reset itself after firmware or config updates.
	\return psaSuccess on success. Respective error result code otherwise.
	
	\see ResetDevice, UpdateFirmware, SetConfig
	*/

	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetAutoReset(bool & enabled);

	/**
	Execute a firmware update. 

	For a simplified firmware update see also function UpdateDevice().

	Use the following code to calculate argument LineCount:
	
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.c}
	int LineCount = 0;
	for (unsigned char * c = FirmwareData; c != FirmwareData + DataSize; c++)
	{
		if (*c == ':') LineCount++;
	}
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	This call will take several minutes.
	
	If auto-reset is active, the device will automatically disconnect and reinitialize as soon as the update operation has finished.
	For reasons of backward compatibility, auto-reset is the default operation mode. Older firmware releases only support auto-reset and cannot switch
	to the manual reset mode. Nonetheless, we recommend using manual reset in order to get a more reliable and faster update process.



	\param[in] FirmwareData      Buffer containing firmware data. 
	\param[in] DataSize          Size of buffer FirmwareData.
	\param[in] LineCount         Line count of the firmware update file.
	\param[in] UpdateBootCode    Always set this to false unless you know what you are doing! Sending normal firmware data as boot code will break the device!
	\return psaSuccess on success. Respective error result code otherwise.

	\see UpdateDevice
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL UpdateFirmware(unsigned char* FirmwareData, size_t DataSize, int LineCount, bool UpdateBootCode); 

	/**
    Request the persistent device configuration.

	This function returns the size of the buffer to be allocated. 
	The actual configuration data can be fetched with GetPentaConfig().

	\param[out] nBytes 	Number of bytes required to store the PENTA Scanner configuration currently stored in device.

	\return psaSuccess on success. Respective error result code otherwise.
	\see GetPentaConfig
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL RequestPentaConfig(int &nBytes);

	/**
	Get the PentaScanner configuration file.

	\param[out] ConfigBuffer     Buffer used to store the configuration file.
								The buffer must have a size of at least the value returned by RequestPentaConfig()
	\return psaSuccess on success. Respective error result code otherwise.

	\see RequestPentaConfig()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetPentaConfig(unsigned char * ConfigBuffer);

	/**
	Set the PentaScanner configuration file.

	If auto-reset is active, the device will automatically disconnect and reinitialize as soon as the update operation has finished.
	For reasons of backward compatibility, auto-reset is the default operation mode. For details see the remarks for function UpdateFirmware().

	\param[in] ConfigBuffer   Buffer to read for storing the configuration file.
							  The buffer must have a size of at least the value returned by ExUtilsGetPentaConfigSize()
	\param[in] nBytes   	  size of the buffer
	\return psaSuccess on success. Respective error result code otherwise.

	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetPentaConfig(const unsigned char * ConfigBuffer, int nBytes);

	/**
	Enumeration type for device update types.
	*/
	typedef unsigned int TPSADeviceUpdateType;

	/**
	Firmware file (.ldr) update
	*/
	const TPSADeviceUpdateType updFirmware      = 0x00000000;
	/**
	Configuration file (.xml) update
	*/
	const TPSADeviceUpdateType updConfiguration = 0x00000001;
	/**
	Bootloader file (.ldr) update
	*/
	const TPSADeviceUpdateType updBootloader    = 0xF0000000;

	/**
	Update device.
	
	This function provides the functionality of both functions UpdateFirmware() and SetConfig() in a simplified call.
	Note that, in order to skip automatic reboot, SetAutoReset() must be called in advance with argument false.

	\param[in] updType  Type of update data
	\param[in] buffer  Device data for update

	\return psaSuccess on success. Respective error result code otherwise.
	\see UpdateFirmware, SetConfig, ResetDevice, SetAutoReset
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL UpdateDevice(TPSADeviceUpdateType updType, const unsigned char * data, int nBytes);

	/** @} */
	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupSystemInfo System Information
	
	DLL and device status information.
	@{
	*/


	/**
	Request DLL version string.

	This function can be called any time. It does not require an established connection to the device.

	\return Null-terminated string of ASCII characters containing the file version. Format: nnn.nnn.nnn.nnn
	*/
	PAGESCANAPI_USAGE const char * PAGESCANAPI_STDCALL GetDllVersion();
	/**
	 @name API Version Info
	 @{
	*/


#pragma pack(push, 1)

	/// Structure to read information from this API.
	typedef struct _PSAAPIInfo
	{
		/// Date when the API was compiled.
		char CompileDate[12];
		/// Time when the API was compiled.
		char CompileTime[9];
		/// Version of the API.
		int  Version;
		/// Number of the API.
		int  Number;
	} TPSAAPIInfo, *PPSAAPIInfo;

#pragma pack(pop)

	/**
	Request information about the API.

	This function can be executed even without a valid connection to the device.

	\param[out]  APIInfo	Structure element to be filled with API information.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetAPIInfo(TPSAAPIInfo& APIInfo);
	/** @} */
	/**
	 @name System Info Structure
	 @{
	*/

#pragma pack(push, 1)

	/// Structure to read information from the device and firmware.
	typedef struct _PSADeviceInfo 
	{ 
		/// Date when the firmware was compiled. 
		char CompileDate[12]; 
		/// Time when the firmware was compiled. 
		char CompileTime[9]; 
		/// Notifier if UV light is supported. 
		bool Support_UV; 
		/// Notifier if color sensors are supported. 
		bool Support_Color; 
		/// Notifier if barcode reading is supported 
		bool Support_Barcode; 
		/// Notifier if MSR reading is supported 
		bool Support_MSR; 
		/// Notifier if display is supported 
		bool Support_Display; 
		/// Notifier if external status LED is supported 
		bool Support_ExtStatusLed; 
		/// Notifier if external buzzer is supported 
		bool Support_ExtBuzzer; 
		/// Version of the firmware. 
		int  Version; 
		/// Number of the firmware. 
		int  Number; 
	} TPSADeviceInfo, *PPSADeviceInfo; 
#pragma pack(pop)

	/**
	Request information about the device.

	\param[out] DeviceInfo  Structure element to be filled with device information.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetSystemInfo(TPSADeviceInfo& DeviceInfo);
	/** @} */

		/**
	 @name System Info Flags
	 @{
	*/
	/**
	Bitmap type for system flags

	\see GetSystemInfoFlags()

	*/
	typedef unsigned int TPSASystemInfoFlags;
	/// System flag: Device supports UV light. \see GetSystemInfoFlags()
	const TPSASystemInfoFlags supportUvLight            = 0x00000001;
	/// System flag: Device supports color scanning. \see GetSystemInfoFlags()
	const TPSASystemInfoFlags supportColor              = 0x00000002;
	/// System flag: Device supports barcode. \see GetSystemInfoFlags()
	const TPSASystemInfoFlags supportBarcode            = 0x00000004;
	/// System flag: Device supports magnetic stripe reading. \see GetSystemInfoFlags()
	const TPSASystemInfoFlags supportMsr                = 0x00000008;
	/// System flag: Device supports text display. \see GetSystemInfoFlags()
	const TPSASystemInfoFlags supportTextDisplay        = 0x00000010;
	/// System flag: Device supports external status LED. \see GetSystemInfoFlags()
	const TPSASystemInfoFlags supportExternalStatusLed  = 0x00000020;
	/// System flag: Device supports external buzzer. \see GetSystemInfoFlags()
	const TPSASystemInfoFlags supportExternalBuzzer     = 0x00000040;
	/// System flag: Device supports graphical display. \see GetSystemInfoFlags()
	const TPSASystemInfoFlags supportGraphicalDisplay   = 0x00000080;
	/// System flag: Device supports graphical display. \see GetSystemInfoFlags()
	const TPSASystemInfoFlags supportGlareReduction     = 0x00000200;
  /// System flag: Device supports graphical display. \see GetSystemInfoFlags()
  const TPSASystemInfoFlags supportBatteryChargeLevel = 0x00000400;
  /// System flag: Device supports real-time clock. \see GetSystemInfoFlags()
  const TPSASystemInfoFlags supportRealTimeClock = 0x00000800;

	/**
	Get the system flags.
	Usage example:
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.c}

	TPSASystemInfoFlags flags;
	res = GetSystemInfoFlags(flags);
	if (res == psaSuccess)
	{
		if ( 0 != (flags & supportBarcode) )
		{
			cout << "Device supports barcode!" << endl;
		}
		if ( 0 != (flags & supportMsr) )
		{
			cout << "Device supports magnetic stripe reading!" << endl;
		}
	}
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	
	\param[out]   DeviceInfoFlags    Bitmap of system flags.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetSystemInfoFlags(TPSASystemInfoFlags &DeviceInfoFlags);
	/** @} */

	/**
	Get the USB vendor (VID) and product (PID) identifiers of the connected device.

	\param[out] Vid     USB vendor identifier
	\param[out] Pid     USB product identifier
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetSystemVidPid(int &Vid, int &Pid);


	/**
	 @name Device Generation
	 @{
	*/
	/// Data type for device type identification.
	typedef int TPSADeviceType;
	/// Device is unknown.
	const TPSADeviceType deviceTypeUnknown = 0;
	/// Device is four-camera generation 3 device. \deprecated Generation 3 device support has expired.
	const TPSADeviceType deviceTypeGen3 = 1;
	/// Device is single-camera generation 4 device.
	const TPSADeviceType deviceTypeGen4 = 2;

	/**
	Get the device type.

	Currently there are two generations of DESKO PENTA devices supported by this API:

	- Four-camera devices (generation 3).
	- Single-camera devices (generation 4).

	\returns Device generation.

	*/
	PAGESCANAPI_USAGE TPSADeviceType PAGESCANAPI_STDCALL GetDeviceType();
	/** @} */

	/**
	Get resolution information for current device.

	Examples for unit conversions:
	
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.c}
	double PixelsPerMilimeterX = 0.001 * PixelPerMeterX;
	double PixelsPerInchX = 0.0254 * PixelPerMeterX;
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	You can use these values to calculate the actual size of the window pane.
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.c}
	double PaneWidthInMillimeter = PixelsPerMilimeterX / ImageWidth;
	double PaneHeightInMillimeter = PixelsPerMilimeterY / ImageHeight;
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	\param[in] Resolution			Resolution handle. One of resLow, resDefault, resHigh.
	\param[out] ImageWidth			Expected image width in number of pixels.
	\param[out] ImageHeight			Expected image height in number of pixels.
	\param[out] PixelPerMeterX		Number of pixels per one meter in horizontal direction.
	\param[out] PixelPerMeterY		Number of pixels per one meter in vertical direction.
	\returns 						psaSuccess on success, psaFail if the
									resolution is not supported by the device,
									or any other available return value.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetResolutionInfo(TPSAResolution Resolution, int &ImageWidth, int &ImageHeight, int &PixelPerMeterX, int &PixelPerMeterY);
	
	/**
	 Get battery charge level.

	 \param[out] Level    Value between 0 and 100 representing the current battery charge level.
	 \returns             Returns psaSuccess on success, psaUnsupportedFunction if the device does not provide battery information, or any other suitable error value.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetBatteryChargeLevel(int & Level);

  /**
   Get current real-time clock (RTC) value.

   \param[out] Year   The full year of the Common Era.
   \param[out] Month  The number of the month (from 1=January to 12=December).
   \param[out] Day    The day of the month (from 1 to 31).
   \param[out] Hour   The hour (24 hrs format i.e. from 0 to 23).
   \param[out] Minute The minute (from 0 to 59).
   \param[out] Second The second (from 0 to 59).

   \returns Returns psaSuccess on success, psaUnsupportedFunction if the device does not provide RTC functionality, or any other suitable error value.
  */
  PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetRealTimeClock(int & Year, int & Month, int & Day, int & Hour, int & Minute, int & Second);

  /**
   Set current real-time clock (RTC) value.

   \param[in] Year   The full year of the Common Era.
   \param[in] Month  The number of the month (from 1=January to 12=December).
   \param[in] Day    The day of the month (from 1 to 31).
   \param[in] Hour   The hour (24 hrs format i.e. from 0 to 23).
   \param[in] Minute The minute (from 0 to 59).
   \param[in] Second The second (from 0 to 59).

   \returns Returns psaSuccess on success, psaUnsupportedFunction if the device does not provide RTC functionality, or any other suitable error value.
  */
  PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetRealTimeClock(int Year, int Month, int Day, int Hour, int Minute, int Second);


//--------------------------------------------------------------------------------------------------
	/** \defgroup groupProperties Properties
	
	DLL and device status information.
	@{
	*/
	/**
		Enumeration type for property keys.	 
	*/
	typedef unsigned int TPSAPropertyKey;

	///	 Property key (not used).
	const TPSAPropertyKey keyNone = 0;
	/// Property key: Compile date of runtime DLL (null-terminated C string).
	const TPSAPropertyKey keyDllCompileDate = 1;
	/// Property key: Compile time of runtime DLL (null-terminated C string).
	const TPSAPropertyKey keyDllCompileTime = 2;
	/// Property key: Get version string of runtime DLL (null-terminated C string).
	const TPSAPropertyKey keyDllVersionString = 3;
	/// Property key: Version string of DESKO PageScan API (null-terminated C string).
	const TPSAPropertyKey keyApiVersionString = 4;
	/// Property key: USB vendor identifier (VID) of opened device. (unsigned int).
	const TPSAPropertyKey keyDeviceVid = 20;
	/// Property key: USB product identifier (PID) of opened device (unsigned int).
	const TPSAPropertyKey keyDevicePid = 21;
	/// Property key: Firmware compile date of opened device (null-terminated C string).
	const TPSAPropertyKey keyDeviceFirmwareDate = 22;
	/// Property key: Firmware compile time of opened device (null-terminated C string).
	const TPSAPropertyKey keyDeviceFirmwareTime = 23;
	/// Property key: Firmware version string of opened device (null-terminated C string).
	const TPSAPropertyKey keyDeviceFirmwareVersionString = 24;
	/// Property key: Firmware major version number (unsigned int).
	const TPSAPropertyKey keyDeviceFirmwareVersionMajor = 25;
	/// Property key: Firmware minor version number (unsigned int).
	const TPSAPropertyKey keyDeviceFirmwareVersionMinor = 26;
	/// Property key: Barcode engine firmware revision information (null-terminated C string).
	const TPSAPropertyKey keyDeviceBarcodeFirmwareRevisionInfo = 30;
	/// Property key: Production identifier of opened device (null-terminated C string).
	const TPSAPropertyKey keyDeviceProductionId = 51;
	/// Property key: Serial number of opened device (null-terminated C string).
	const TPSAPropertyKey keyDeviceSerialNumber = 52;
	/// Property key: PCB revision of opened device (null-terminated C string).
	const TPSAPropertyKey keyDevicePcbRevision = 53;
	/// Property key: Illumination hardware revision (i.e., minor version number) of opened device (unsigned int).
	const TPSAPropertyKey keyDeviceIlluminationRevision = 54;
	/// Property key: Illumination hardware revision (i.e., minor version number) of opened device (string).
	const TPSAPropertyKey keyDeviceIlluminationRevisionVerbose = 55;
	/// Property key: Illumination hardware generation (i.e., major version number) of opened device (unsigned int).
	const TPSAPropertyKey keyDeviceIlluminationGeneration = 56;
	/// Property key: Illumination hardware generation (i.e., major version number) of opened device (string).
	const TPSAPropertyKey keyDeviceIlluminationGenerationVerbose = 57;
	/// Property key: Illumination hardware variant tag of opened device (unsigned int).
	const TPSAPropertyKey keyDeviceIlluminationVariant = 58;
	/// Property key: Illumination hardware variant tag of opened device (string).
	const TPSAPropertyKey keyDeviceIlluminationVariantVerbose = 59;
	/// Property key: Opened device supports UV illumination (int, 0-false, 1-true).
	const TPSAPropertyKey keyDeviceSupportUvLight = 100;
	/// Property key: Opened device supports color images (int, 0-false, 1-true).
	const TPSAPropertyKey keyDeviceSupportColor = 101;
	/// Property key: Opened device supports barcode reading (BCR) (int, 0-false, 1-true).
	const TPSAPropertyKey keyDeviceSupportBarcode = 102;
	/// Property key: Opened device supports magnetic stripe reading (MSR) (int, 0-false, 1-true).
	const TPSAPropertyKey keyDeviceSupportMsr = 103;
	/// Property key: Opened device supports text display (int, 0-false, 1-true).
	const TPSAPropertyKey keyDeviceSupportTextDisplay = 104;
	/// Property key: Opened device supports status LED (int, 0-false, 1-true).
	const TPSAPropertyKey keyDeviceSupportExternalStatusLed = 105;
	/// Property key: Opened device supports external buzzer (int, 0-false, 1-true).
	const TPSAPropertyKey keyDeviceSupportExternalBuzzer = 106;
	/// Property key: Opened device supports graphical display (int, 0-false, 1-true).
	const TPSAPropertyKey keyDeviceSupportGraphicalDisplay = 107;
	/// Property key: Opened device supports glare reduction (Device generation 4.3 or later, int, 0-false, 1-true).
	const TPSAPropertyKey keyDeviceSupportGlareReduction = 108;
	/// Property key: Opened device is connected to battery and supports battery charge status reports (int, 0-false, 1-true).
	const TPSAPropertyKey keyDeviceSupportBatteryChargeLevel = 109;
  /// Property key: Opened device features a real-time clock (int, 0-false, 1-true).
  const TPSAPropertyKey keyDeviceSupportRealTimeClock = 110;
  
	
		/**
	 Check if string property exists.

	 \param[in]  Key         The property key.

	 \return true if value for key exists.
	 \see GetPropertyString().
	*/
	PAGESCANAPI_USAGE bool PAGESCANAPI_STDCALL HasPropertyString(TPSAPropertyKey Key);


	/**
	 Get string size of property value.

	 The returned size value should be used to allocate a buffer for the value string.
	 \param[in]  Key         The property key.
	 \param[out] BufferSize  The size of the property value string including a terminating '\0'.

	 \return psaSuccess on success. Respective error result code otherwise.
	 \see GetPropertyString().
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetPropertyStringSize(TPSAPropertyKey Key, int &BufferSize);

	/**
	 Get property string value.

	 The returned size value should be used to allocate a buffer for the value string.
	 \param[in]  Key         The property key.
	 \param[out] ValueBuffer The property value as null-terminated C string.
	 \param[in]  BufferSize  The size of the property value string as returned by GetPropertyStringSize().

	 \return psaSuccess on success. Respective error result code otherwise.
	 \see GetPropertyString().
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetPropertyString(TPSAPropertyKey Key, unsigned char * ValueBuffer, int BufferSize);

	/**
	 Check if integer property exists.

	 \param[in]  Key         The property key.

	 \return true if value for key exists.
	 \see GetPropertyString().
	*/
	PAGESCANAPI_USAGE bool PAGESCANAPI_STDCALL HasPropertyInt(TPSAPropertyKey Key);

	/**
	 Get property integer value.

	 \param[in]  Key         The property key.
	 \param[out] Value      Property integer value.

	 \return psaSuccess on success. Respective error result code otherwise.
	 \see GetPropertyString().
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetPropertyInt(TPSAPropertyKey Key, int & Value);

		/**
	 Check if integer property exists.

	 \param[in]  Key         The property key.

	 \return true if value for key exists.
	 \see GetPropertyString().
	*/
	PAGESCANAPI_USAGE bool PAGESCANAPI_STDCALL HasPropertyUInt(TPSAPropertyKey Key);

	/**
	 Get property integer value.

	 \param[in]  Key         The property key.
	 \param[out] Value      Property integer value.

	 \return psaSuccess on success. Respective error result code otherwise.
	 \see GetPropertyString().
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetPropertyUInt(TPSAPropertyKey Key, unsigned int & Value);

	/**
	 Check if double property exists.

	 \param[in]  Key         The property key.

	 \return true if value for key exists.
	 \see GetPropertyString().
	*/
	PAGESCANAPI_USAGE bool PAGESCANAPI_STDCALL HasPropertyDouble(TPSAPropertyKey Key);

	/**
	 Get property double value.

	 \param[in]  Key         The property key.
	 \param[out] Value      Property double value.

	 \return psaSuccess on success. Respective error result code otherwise.
	 \see GetPropertyString().
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetPropertyDouble(TPSAPropertyKey Key, double & Value);

	/** @} */

	/** @} */


	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupLed LED Control
	
	User feedback operations for the internal and external status lights.
	
	@{
	*/

	/// Data type for available status LED usage. \see SetStatusLEDSettings
	typedef unsigned char TPSAStatusLEDUsage;
	/// Set status LED to permanent on
	const TPSAStatusLEDUsage sluPermanent = 2;
	/// Set status LED to flashing on
	const TPSAStatusLEDUsage sluFlashing = 3;

	/// Type of available status LED colors
	typedef unsigned char TPSAStatusLEDColor;
	/// Black status LED
	const TPSAStatusLEDColor slcBlack = 0;
	/// Red status LED
	const TPSAStatusLEDColor slcRed = 1;
	/// Green status LED
	const TPSAStatusLEDColor slcGreen = 2;
	/// Yellow status LED
	const TPSAStatusLEDColor slcYellow = 3;
	/// Blue status LED
	const TPSAStatusLEDColor slcBlue = 4;
	/// Purple status LED
	const TPSAStatusLEDColor slcPurple = 5;
	/// Turquoise status LED
	const TPSAStatusLEDColor slcTurquise = 6;
	/// White status LED
	const TPSAStatusLEDColor slcwhite = 7;

	/// Constant indicating infinite status LED
	const int INFINITE_DURATION_STATUSLED = 0;
#pragma pack(push, 1)

	/// Structure to read and set LED settings.
	typedef struct _PSAStatusLEDSettings
	{
		/// Switch if status LED is enabled or not.
		bool Enabled;
		/// Color for the status LED
		TPSAStatusLEDColor Color;
		/// Usage of the status LED
		TPSAStatusLEDUsage Usage;
		/// Duration of the LED command (milliseconds).
		unsigned int Duration;
		/// LED on period during one duration (milliseconds). 
		unsigned int HighTime;
		/// LED off period during one duration (milliseconds). 
		unsigned int LowTime;
	} TPSAStatusLEDSettings, *PPSAStatusLEDSettings;

#pragma pack(pop)

	/**
	Set new status LED configuration.

	The status LED provides two states which can be set up individually:
	- active:  The LED indicates some kind of activity feedback (e.g., success, warning, fail etc.) for a limited period of time
	- default: The LED does not give activity feedback.

	\param[in] ActiveState			Indicates whether the active (true) or default (false) state should be set.
	\param[in] StatusLEDSetting		Structure element with the status LED information to be set.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetStatusLEDSettings(bool ActiveState, TPSAStatusLEDSettings StatusLEDSetting);

	/**
	Request information about the status LED configuration.

  The status LED provides two states which can be set up individually:
  - active:  The LED indicates some kind of activity feedback (e.g., success, warning, fail etc.) for a limited period of time
  - default: The LED does not give activity feedback.

	\param[in] ActiveState			Indicates whether the active (true) or default (false) state should be requested.
	\param[out] StatusLEDSetting	Structure element with the status LED information to be filled.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetStatusLEDSettings(bool ActiveState, TPSAStatusLEDSettings& StatusLEDSetting);


	/**
	Use the status LED with the configured settings.

  The status LED provides two states which can be set up individually:
  - active:  The LED indicates some kind of activity feedback (e.g., success, warning, fail etc.) for a limited period of time
  - default: The LED does not give activity feedback.

	\param[in] Enabled	If the status LED configuration shall be activated 
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL UseStatusLED(bool Enabled);

	/**
	Set the external status LED.

	\param[in] color	Designated LED color. Use slcBlack to turn off the LED.
						Note that not all colors defined in TPSAStatusLEDColor
						may be available for your device.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetExtStatusLED(TPSAStatusLEDColor color);

	/**
	Control the external status led. 
	\param[in] Enabled		Indicates if the LED is switched on or off
	\param[in] UseGreen		Indicates color of the LED. Where true is green, false is red. (Deprecated)
	\param[in] Duration		Duration of active-time of the LED. Where 0=infinite. (Deprecated)
	\return psaSuccess on success. Respective error result code otherwise.
	\deprecated This function is deprecated. Use #SetExtStatusLED() instead.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL UseExtStatusLED(bool Enabled, bool UseGreen, int Duration);


	/** @} */

	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupBuzzer Buzzer Control
	
	User feedback operations for the buzzer.
	
	@{
	*/

#pragma pack(push, 1)

	/// Structure to read and set buzzer settings.
	typedef struct _PSABuzzerSettings
	{
		/// Switch if buzzer is enabled or not.
		bool Enabled;
		/// Duration for one buzzer command.
		int Duration;
		/// Buzzer on period during one duration. 
		int HighTime;
		/// Buzzer off period during one duration. 
		int LowTime;
	} TPSABuzzerSettings, *PPSABuzzerSettings;

	/// Structure to read and set buzzer settings.
	typedef struct _PSABuzzerSettingsEx
	{
		/// Buzzer Volume. Values from 0 (silent) to 255 (max. volume).
		unsigned char Volume;
		/// Duration for one buzzer command.
		int Duration;
		/// Buzzer on period during one duration. 
		int HighTime;
		/// Buzzer off period during one duration. 
		int LowTime;
	} TPSABuzzerSettings2, *PPSABuzzerSettings2;

#pragma pack(pop)


	/**
	Set new buzzer configuration.

	\param[in] BuzzerSettings	Structure element with the buzzer information to be set.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetBuzzerSettings(TPSABuzzerSettings BuzzerSettings);

	/**
	Get current buzzer configuration.

	\param[out] BuzzerSettings	Structure element to be filled with buzzer configuration.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetBuzzerSettings(TPSABuzzerSettings& BuzzerSettings);

	/**
	Set new configuration for external buzzer.

	\deprecated The device does not distinguish between internal or external buzzer anymore.

	\param[in] BuzzerSettings	Structure element with the buzzer information to be set.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetExtBuzzerSettings(TPSABuzzerSettings BuzzerSettings);

	/**
	Request information about the external buzzer configuration.

	\deprecated The device does not distinguish between internal or external buzzer anymore.

	\param[out] BuzzerSettings	Structure element to be filled with buzzer configuration.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetExtBuzzerSettings(TPSABuzzerSettings& BuzzerSettings);

	/**
	Set new buzzer configuration.

	\param[in] BuzzerSettings	Structure element with the buzzer information to be set.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetBuzzerSettings2(TPSABuzzerSettings2 BuzzerSettings);

	/**
	Request information about the buzzer configuration.

	\param[out] BuzzerSettings	Structure element to be filled with buzzer configuration.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetBuzzerSettings2(TPSABuzzerSettings2& BuzzerSettings);

	/**
	Set new external buzzer configuration.

	\deprecated The device does not distinguish between internal or external buzzer anymore.

	\param[in] BuzzerSettings	Structure element with the buzzer information to be set.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetExtBuzzerSettings2(TPSABuzzerSettings2 BuzzerSettings);

	/**
	Request information about the external buzzer configuration.

	\deprecated The device does not distinguish between internal or external buzzer anymore.

	\param[out] BuzzerSettings	Structure element to be filled with buzzer configuration.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetExtBuzzerSettings2(TPSABuzzerSettings2& BuzzerSettings);
	/**
	Use the buzzer with the configured settings.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL UseBuzzer(void);

	/**
	Use the external buzzer with the configured settings.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL UseExtBuzzer(void);

	/** @} */
	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupMode Operation Modes (deprecated)
	@{
	
	Deprecated. Do not use.
	*/

	/** 
	Type of available scan modes.

	This type is not used anymore by the API.
	Auto mode is always active.
	\deprecated There is no need for this type anymore since auto-mode is always active.
	*/
	typedef int TPSAWaitForDocMode;
	/// Application is notified when document is in place. \deprecated Not used anymore
	const TPSAWaitForDocMode wfdmAuto = 0;
	/// Application controls when scan is executed. \deprecated Not used anymore
	const TPSAWaitForDocMode wfdmManual = 1;

	/**
	Set the mode if the device is in auto mode or controlled by the application.

	\param[in] WaitForDocMode  Mode in which the device runs.
	\return psaSuccess on success. Respective error result code otherwise.
	\deprecated Since API version 3.0.3.5 auto mode is always active and cannot be deactivated.
				To stop the execution of a specific callback, 
				pass a NULL pointer to the respective setup function.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetMode(TPSAWaitForDocMode WaitForDocMode);

	/**
	Request the mode if the device is in auto mode or controlled by the application.

	\return psaSuccess on success. Respective error result code otherwise.
	\deprecated Since API version 3.0.3.5 auto mode is always active and can not be deactivated.
				To stop the execution of a specific callback, 
				pass a NULL pointer to the respective setup function.
	*/
	PAGESCANAPI_USAGE TPSAWaitForDocMode PAGESCANAPI_STDCALL GetMode(void);

	/** @} */

	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupEvents Event Control

	Handler registration and polling for unsolicited device events (OCR, barcode, magnetic stripe, touch display, etc.).
	
	@{
	*/

	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupEventsPlug Plug Event
	
	Device plug state event operations.
	
	@{
	*/
	/**
	Event type for notification when a device gets plugged or unplugged from the USB port.

	Typical implementation:
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.c}
	void PAGESCANAPI_STDCALL OnDevicePlug(bool PluggedIn)
	{
		if (PluggedIn)
		{
			while (...) 
			{
				if (ConnectToDevice() == psaSuccess) return;
			}
		}
		else
		DisconnectFromDevice();
	}
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	\param[in] PluggedIn   Notifier whether device is plugged or unplugged.

	\see SetupOnDevicePlugCallback
	*/
	typedef void (PAGESCANAPI_STDCALL *TOnDevicePlug)(bool PluggedIn);

	/**
	Setup the callback for device plug events.
	\param[in] OnPresent   Reference to the callback function. Passing a null pointer disables the event.

	*/
	PAGESCANAPI_USAGE void PAGESCANAPI_STDCALL SetupOnDevicePlugCallback(TOnDevicePlug OnPresent);


	/** @} */

	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupEventsDoc Document Event
	
	Device document presentation event operations.

	@{
	*/

	/**
	Event type for notification when a document was placed on the scanner.

	Sample implementation for OCR on PC (error handling omitted in code):
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.c}
	void PAGESCANAPI_STDCALL OnDocumentInsert(TPSAWaitForDocMode& deprecatedArgument)
	{
		TPSAScanSettings s = { true, false, false, true, PSA_240_DPI };
		SetScanSettings(s);
		Scan();

		// ... could use buzzer here to give feedback to user 

		TPSARecognitionResult RecognitionResult;
		int MrzLength=0;
		size_t MrzBufferSize=0;
		ReadOcr(RecognitionResult, MrzLength, MrzBufferSize);

		if (RecognitionResult != rrGoodRecognition)
			return "";

		char *buffer = new char[MrzBufferSize];
		GetOcrOutput(buffer, MrzBufferSize);

		// ... use OCR data in buffer

		delete [] buffer;
	}
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	

	\param[out] WaitForDocMode  Deprecated: this parameter has no effect.
	\see SetupOnDocumentCallback
	*/
	typedef void (PAGESCANAPI_STDCALL *TOnDocumentInsert)(TPSAWaitForDocMode& WaitForDocMode);  

	/**
	Setup the callback for document insertion events.

	\param[in] OnPresent   Reference to the callback function. Passing a NULL pointer disables the event.

	*/
	PAGESCANAPI_USAGE void PAGESCANAPI_STDCALL SetupOnDocumentCallback(TOnDocumentInsert OnPresent);

	/**
	Event type for notification when a document was removed from the scanner.

	\see SetupOnDocumentRemoveCallback
	*/
	typedef void (PAGESCANAPI_STDCALL *TOnDocumentRemove)();  

	/**
	Setup the callback for document remove events.

	This function is available for generation 4 devices only.

	\param[in] OnRemove   Reference to the callback function. Passing a NULL pointer disables the event.

	*/
	PAGESCANAPI_USAGE void PAGESCANAPI_STDCALL SetupOnDocumentRemoveCallback(TOnDocumentRemove OnRemove);
	/** @} */

	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupEventsOcr OCR Event
	
	Device OCR read operations.

	@{
	*/

	/**
	Event type for notification when a OCR document is read by the device.

	Typical implementation (error handling omitted in code):
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.c}
	void PAGESCANAPI_STDCALL OnOcrPresent()
	{
		TPSARecognitionResult result;
		int length;
		size_t size;

		ReadOcrPc(result, size);
		
		if (result != rrGoodRecognition) return;
		
		unsigned char *buffer = new unsigned char[size];
		GetOcrOutput(buffer, size);

		// ... use OCR data

		delete [] buffer;
	}
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	\see SetupOnOcrCallback
	*/
	typedef void (PAGESCANAPI_STDCALL *TOnOcrPresent)(void);

	/**
	Setup the callback for OCR events.
	\param[in] OnPresent   Reference to the callback function. Passing a NULL pointer disables the event.

	*/
	PAGESCANAPI_USAGE void PAGESCANAPI_STDCALL SetupOnOcrCallback(TOnOcrPresent OnPresent);


	/**
	Request information about the last OCR event from the device.

	This function should be used in a custom TOnOcrPresent callback. 
	Alternatively, you can use it for polling in a loop.

	This function requests the data of the last OCR on the device.
	The data can be requested only once, i.e., if the device has not performed
	a new OCR, the following call to this function will return <code>OcrResult == rrNoDoc</code>.

	Unlike ReadOcrPc(), no other API calls are required before calling this function.

	OCR is performed by the device each time a document is detected.
	OCR on the device has a lower recognition rate than OCR on the PC.
	Unlike function ReadOcrPc(), the execution time of this function is 
	not dependent on the CPU speed of the PC.

	\param[out] OcrResult      Result of the recognition call.
	\param[out] MrzBufferSize  Size of the result buffer.
	\return psaSuccess on success. Respective error result code otherwise.
	\see GetOcrOutput, ReadOcrPc
	*/

	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ReadOcrDevice(TPSARecognitionResult& OcrResult, size_t& MrzBufferSize);

	/**
	Get the data of the last device OCR event.

	This function requires ReadOcrDevice() to be called
	in advance.

	The returned buffer is a '\\0'-terminated string. Each line is terminated with '\\r';

	\param[out] MrzBuffer       Buffer where the MRZ is stored. 
	\param[in] MrzBufferSize   Size of buffer MrzBuffer.
	\return psaSuccess on success. Respective error result code otherwise.
	\see ReadOcrPc
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetOcrOutputDevice(unsigned char* MrzBuffer, size_t MrzBufferSize);

	/** @} */

	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupEventsBcr Barcode Event

	Device barcode read operations.

	@{
	*/
	/**
	Event type for notification when a barcode is read by the device.

	Typical implementation (error handling omitted in code):
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.c}
	void PAGESCANAPI_STDCALL OnBarcodePresent()
	{
		bool found;
		int length;
		size_t size;

		ReadBarcode(found, length, size);
		if (! found) return;
		unsigned char *buffer = new unsigned char[size];
		GetBarcodeOutput(buffer,size);

		// ... use barcode data

		delete [] buffer;
	}
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	\see SetupOnBarcodeCallback
	*/
	typedef void (PAGESCANAPI_STDCALL *TOnBarcodePresent)(void);

	/**
	Setup the callback for barcode events.
	\param[in] OnPresent   Reference to the callback function. Passing a NULL pointer disables the event.

	*/
	PAGESCANAPI_USAGE void PAGESCANAPI_STDCALL SetupOnBarcodeCallback(TOnBarcodePresent OnPresent);
	/** @} */

	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupEventsMsr Magnetic Stripe Event

	Device magnetic stripe read operations.

	@{
	*/
	/**
	Event type for notification when a MSR document is read by the device.

	Typical implementation (error handling omitted in code):
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.c}
	void PAGESCANAPI_STDCALL OnMsrPresent()
	{
	bool found;
	int length;
	size_t size;

	ReadMsr(found, length, size);
	if (! found) return;
	unsigned char *buffer = new unsigned char[size];
	GetMsrOutput(buffer,size);

	// ... use MSR data

	delete [] buffer;
	}
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	\see SetupOnMsrCallback
	*/
	typedef void (PAGESCANAPI_STDCALL *TOnMsrPresent)(void);
	/**
	Setup the callback for magnetic stripe (MSR) events.
	\param[in] OnPresent   Reference to the callback function. Passing a NULL pointer disables the event.

	*/
	PAGESCANAPI_USAGE void PAGESCANAPI_STDCALL SetupOnMsrCallback(TOnMsrPresent OnPresent);
	/** @} */
	/// Structure to set the available events / callbacks.
	typedef struct _PSANotification
	{
		/// Event to be is called when a document is inserted.
		TOnDocumentInsert OnDocumentInsert;
		/// Event to be is called when a device is plugged or unplugged.
		TOnDevicePlug OnDevicePlug;
		/// Event to be is called when a barcode is read.
		TOnBarcodePresent OnBarcodePresent;
		/// Event to be is called when a MSR document is swiped.
		TOnMsrPresent OnMsrPresent;
	} TPSANotification, *PPSANotification; 


	/**
	Setup the callbacks for device events.

	\param[in] PSANotification   Reference to the event structure.
	\deprecated For compatibility with previous versions of the API, TPSANotification does 
	not provide a callback for the OCR event.  Therefore, it is recommended 
	to use functions SetupOn...Callback() to register the callbacks instead.
	\see SetupOnDevicePlugCallback, SetupOnOcrCallback, SetupOnBarcodeCallback, SetupOnMsrCallback, SetupOnDocumentCallback
	*/
	PAGESCANAPI_USAGE void PAGESCANAPI_STDCALL SetupCallback(TPSANotification PSANotification);
	/** @} */

	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupEventsTouch Touch Events
	
	Device touch display event operations.

	@{
	*/

	/// Data type for touch event type.
	typedef int TouchType;
	/// Value indicating touch released from display.
	const TouchType TouchUp = 0;
	/// Value indicating touch down on display.
	const TouchType TouchDown = 1;

	/**
	Type of callback function for handling display touch events.

	\param[in] TouchDown   Type of touch event (up or down).
	\param[in] RelativeX   Relative coordinate in X direction. Left edge is 0.0, right edge is 1.0.
	\param[in] RelativeY   Relative coordinate in Y direction. Top edge is 0.0, bottom edge is 1.0.
	*/
	typedef void (PAGESCANAPI_STDCALL *TOnTouchDisplay)(TouchType TouchDown, float RelativeX, float RelativeY);

	/**
	Set up callback for handling touch events.

	\param[in] OnTouchDisplay    Pointer to event handler callback.
	*/
	PAGESCANAPI_USAGE void PAGESCANAPI_STDCALL SetupOnTouchDisplayCallback(TOnTouchDisplay OnTouchDisplay);

	/** @} */


	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupScan Scanning and Image Operations
	
	Setting and performing full-page image scans.
	
	@{
	*/


	/**
	Execute a scan with the configured light sources and resolution.
	\return psaSuccess on success. Respective error result code otherwise.
	\see SetScanSettings(), SetScanSettingsEx()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL Scan(void);


	/**
	Check if a document is present.

	This function asks the device if a document is present. The client does not need to perform any scan.

	Note: This function is not available for generation 3 devices!

	\param[out] DocInPlace  Notifier if a document is present or not.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL IsDocumentPresent(bool & DocInPlace);

	/**
	Check if a document is present.
	\deprecated This function is equivalent to IsDocumentPresent() and available only for backward compatibility.

	The original functionality was a scan with IR light, image transfer and check for a document on the PC.
	The current implementation performs the check on the device without any extra scan.
	
	\param[out] DocInPlace  Notifier if a document is present or not.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ScanAndCheck(bool & DocInPlace);

	
	 /**
       Estimate extent of document motion during last scan.
       
       Document motion detection only works if _all_ of the following preconditions hold:
       
       - The device is a PENTA Generation 4.3 or later
       - The light source used is either lsIr or lsVisible
	   - The device is connected and the last scan has been performed with the respective light source ( see SetScanSettingsEx() ).

	   If one or more of the preconditions do not apply, the result value will be psaFail and the delta will be undefined.
	   
	   A successful run returns the estimated euclidian distance (in pixels) of the maximum motion seen in the result image.
	   The algorithm returns a delta value less than 0.0 if it is not able to detect the motion
	   (e.g., document with insufficient patterns and/or contrast).

       
       \param[in]  LightSource         Light source by which the requested image was scanned.
       \param[out] Delta               Motion distance in pixels.
       \return psaSuccess on success.  Respective error result code otherwise.

       \see SetScanSettingsEx(), Scan()
    */
    PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL EstimateDocumentMotion(TPSALightSource LightSource, double & Delta);


    /**
     Check if the scanned document has a UV-dull paper.

	 The operation returns *false* if the paper of the document appears all bright in the UV scan.
	 The operation returns *true* if the paper is completely dark or has a low brightness and some fluorescent security elements.

     In order to use this function, UV illumination must be activated with SetScanSettings() or SetScanSettingsEx() in advance.
     The function call refers to the UV image of the most recent call to Scan(). 

     \param[out] IsDull   True if the material of the scanned document is dull under UV illumination.

     \return psaSuccess on success.  Respective error result code otherwise.
    */
    PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL CheckUvDullness(bool & IsDull);

   /**
     Check if B900 ink is used for OCR text.

     In order to use this function, infrared illumination must be activated with SetScanSettings() or SetScanSettingsEx() in advance.
     The function call refers to the infrared image of the most recent call to Scan(). 
     
     This function checks the correct use of B500 ink as specified by ICAO 9303.
     The test succeeds if and only if under infrared illumination both the ink of the OCR text is visible and any structured element in the background disappears.

     \param[out] InkDetected   True if the OCR ink has been identified as B900 ink.

     \return psaSuccess on success.  Respective error result code otherwise.
    */

    PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL CheckB900Ink(bool & InkDetected);

	//--------------------------------------------------------------------------------------------------
	/** \defgroup groupScanSettings Scan Settings
	
	Setting options for subsequent scans.
	
	@{
	*/

	/// Bitmap type for scan light flags. 
	typedef unsigned int TPSAScanLightFlags;
	/// All scan light flags disabled. \see _PSAScanSettingsEx
	const TPSAScanLightFlags sfNone                  = 0x0000;
	/// Use the scan light in following operations. \see _PSAScanSettingsEx
	const TPSAScanLightFlags sfUse                   = 0x0001;
	/// Use ambient light elimination in following operations. \see _PSAScanSettingsEx
	const TPSAScanLightFlags sfAmbientLightElimination = 0x0002;

	/// Bitmap type for scan flags. 
	typedef unsigned int TPSAScanFlags;
	/// All scan flags disabled. \see _PSAScanSettingsEx
	const TPSAScanFlags scfNone                  = 0x0000;
	/**
	If set, EstimateDocumentMotion() returns negative value if document motion detection fails.
	If not set, EstimateDocumentMotion() returns high value if document motion detection fails. (Default)
	\see EstimateDocumentMotion()
	*/
	const TPSAScanFlags scfMotionDetectionNegativeOnFail = 0x0100;

#pragma pack(push, 1)

	/// Structure to define which options shall be used for a scan
	typedef struct _PSAScanSettings
	{
		/// Scan with infrared light. To activate this light for scanning, pass at least flag sfUse.
		bool ScanIRLight;
		/// Scan with UV light. To activate this light for scanning, pass at least flag sfUse.
		bool ScanUvOnlyLight;
		/// Scan with combined UV and visible light. To activate this light for scanning, pass at least flag sfUse.
		bool ScanUV3Light;
		/// Scan with visible light. To activate this light for scanning, pass at least flag sfUse.
		bool ScanVisibleLight;

		/// Resolution to be used for scan
		TPSAResolution Resolution;
	} TPSAScanSettings, *PPSAScanSettings;

	/// Structure to define the options to be used for all scans which are following.
	typedef struct _PSAScanSettingsEx
	{
		/// Scan with infrared light
		TPSAScanLightFlags ScanIRLight;
		/// Scan with UV light only
		TPSAScanLightFlags ScanUvOnlyLight;
		/// Scan with UV light and additional visible light
		TPSAScanLightFlags ScanUV3Light;
		/// Scan with visible light
		TPSAScanLightFlags ScanVisibleLight;

		/// Resolution to be used for scan
		TPSAResolution Resolution;

		/// For future use.
		TPSAScanFlags ScanFlags;
	} TPSAScanSettingsEx, *PPSAScanSettingsEx;

#pragma pack(pop)

	/**
	Set resolution and light sources to be used for subsequent scans.
	Note: 
	- For scanning, you can use a single resolution but multiple light sources at once.
	- Infrared light must be used for OCR on the PC (i.e., function ReadOcrPc()).
	- Visble light must be used if functions PrepareRawImage() and PrepareJpegImage() are to be called
	with quality ioBest

	\param[in] ScanSettings  Configuration for scan call.
	\return psaSuccess on success. Respective error result code otherwise.

	\deprecated For advanced light settings see also function SetScanSettingsEx() and structure TPSAScanSettingsEx .
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetScanSettings(TPSAScanSettings ScanSettings);

	/**
	Set resolution and light sources to be used for subsequent scans.
	Note: 
	- For scanning, you can use a single resolution but multiple light sources at once.
	- Infrared light must be used for OCR on the PC (i.e., function ReadOcrPc()).
	- Visble light must be used if functions PrepareRawImage() and PrepareJpegImage() are to be called
	with quality ioBest
	\param[in] ScanSettings  Configuration for scan call.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetScanSettingsEx(TPSAScanSettingsEx ScanSettings);

	/**
	Get current configuration for scans (i.e. light sources and resolution).
	\param[out] ScanSettings  Configuration for scan call.
	\return psaSuccess on success. Respective error result code otherwise.

	\deprecated For advanced light settings see also function GetScanSettingsEx() and structure TPSAScanSettingsEx .
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetScanSettings(TPSAScanSettings & ScanSettings);

	/**
	Get current configuration for scans (i.e. light sources and resolution).
	\param[out] ScanSettings  Configuration for scan call.
	\return psaSuccess on success. Respective error result code otherwise.

	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetScanSettingsEx(TPSAScanSettingsEx & ScanSettings);


	/**
	Set linear factor for changing the exposure time (shutter speed).

	A factor of *f* will increase (*f* > 1.0) or decrease (*f* < 1.0) the shutter time by multiplying it with the default exposure time.
	The given factor will be used for all subsequent scans.

	Note that this value may be reset to 1.0 automatically on a reconnect or change of scan settings (see SetScanSettings() or SetScanSettingsEx()).

	\param[in] LightSource     Scan light source.
	\param[in] Factor          Factor multiplied to the default exposure time.
	\return psaSuccess on success. Respective error result code otherwise.

	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetExposureFactor(TPSALightSource LightSource, double Factor);

	/** @} */

	// ---------------------------------------------------------------------------------------------------------
	/** \defgroup groupRetrieval Image Retrieval
	
	Retrieve images of scans.
	
	@{
	*/

	/** 
	Data type for defining post-processing optimizations for image retrieval.

	\see PrepareRawImage, PrepareBmpImage, PrepareJpegImage
	*/
	typedef int TPSAImageOptimize;

	/**
	Low quality colors.
	*/
	const TPSAImageOptimize ioNone = 0;
	/**
	\deprecated Use value ioBest instead.
	*/
	const TPSAImageOptimize ioStitching = 1;

	/**
	Applies image color normalization and optimization.

	\see PrepareRawImage, PrepareBmpImage, PrepareJpegImage
	*/
	const TPSAImageOptimize ioBest = 1;

  /**
	Get pixel density for the current scan.

	Examples for unit conversions:
	
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.c}
	double PixelsPerMilimeterX = 0.001 * PixelPerMeterX;
	double PixelsPerInchX = 0.0254 * PixelPerMeterX;
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	You can use these values to calculate the actual size of the window pane.
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.c}
	double PaneWidthInMillimeter = PixelsPerMilimeterX / ImageWidth;
	double PaneHeightInMillimeter = PixelsPerMilimeterY / ImageHeight;
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	\param[out] PixelPerMeterX		Number of pixels per one meter in horizontal direction.
	\param[out] PixelPerMeterY		Number of pixels per one meter in vertical direction.
	\returns 						psaSuccess on success, psaFail if the
									resolution is not supported by the device,
									or any other available return value.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetCurrentPixelDensity(int &PixelPerMeterX, int &PixelPerMeterY);
	

	/**
	Request a raw image of the full scan pane.

	This function transfers the image data of the most recent scan operation
	to the host PC and post processes it. Note that the light source passed
	as first argument must refer to one of the selected light sources used
	for the scan (see SetScanSettingsEx()).

	The returned dimension information should be used to prepare a buffer
	for retrieving the image information. For details see GetRawImage().

	The raw image format is 24 bit interleaved RGB, i.e., a single pixel is
	represented by a consecutive triple of bytes with the color intensities
	for the red, green and blue. These triples are laid out
	consecutively in left-to-right line order. No padding is added between
	individual lines. The data has no header information.

	\param[in]  LightSource         Light source of with which the requested image was scanned.
	\param[in]  ImageOptimize       Image optimization. Use ioBest for optimal colors.
	\param[out] ImageWidth          Width of the captured image.
	\param[out] ImageHeight         Height of the captured image.
	\param[out] BitsPerPixel        Bits per pixel of the image (always 24 bit RGB).
	\param[out] ImageBufferSize     Length of the image buffer - used for 'GetRawImage' call.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetRawImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL PrepareRawImage(TPSALightSource LightSource, TPSAImageOptimize ImageOptimize, int& ImageWidth, int &ImageHeight, int& BitsPerPixel, size_t &ImageBufferSize);

	/**
	Request a raw image of the owner's face on the document.

	Note that currently face cropping is only available under the following conditions:
	- The document has an ICAO compliant machine readable zone (MRZ).
	- The face is printed on the same side as the MRZ.

	This function transfers the image data of the most recent scan operation
	to the host PC and post processes it. Note that the light source passed
	as first argument must refer to one of the selected light sources used
	for the scan (see SetScanSettingsEx()).

	The returned dimension information should be used to prepare a buffer
	for retrieving the image information. For details see GetRawImage().

	The raw image format is 24 bit interleaved RGB, i.e., a single pixel is
	represented by a consecutive triple of bytes with the color intensities
	for the red, green and blue. These triples are laid out
	consecutively in left-to-right line order. No padding is added between
	individual lines. The data has no header information.

	\param[in]  LightSource         Light source with which the requested image was scanned.
	\param[in]  ImageOptimize       Image optimization. Use ioBest for optimal colors.
	\param[out] ImageWidth          Width of the captured image.
	\param[out] ImageHeight         Height of the captured image.
	\param[out] BitsPerPixel        Bits per pixel of the image (always 24 bit RGB).
	\param[out] ImageBufferSize     Length of the image buffer &mdash; used for 'GetRawImage' call.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetRawImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL PrepareRawFacialImage(TPSALightSource LightSource, TPSAImageOptimize ImageOptimize, int& ImageWidth, int &ImageHeight, int& BitsPerPixel, size_t &ImageBufferSize);

	/**
	Request a raw image of the document auto-rotated and cropped at the edges.

	This function transfers the image data of the most recent scan operation
	to the host PC and post processes it. Note that the light source passed
	as first argument must refer to one of the selected light sources used
	for the scan (see SetScanSettingsEx()).

	The returned dimension information should be used to prepare a buffer
	for retrieving the image information. For details see GetRawImage().

	The raw image format is 24 bit interleaved RGB, i.e., a single pixel is
	represented by a consecutive triple of bytes with the color intensities
	for the red, green and blue. These triples are laid out
	consecutively in left-to-right line order. No padding is added between
	individual lines. The data has no header information.

	\param[in]  LightSource         Light source with which the requested image was scanned.
	\param[in]  ImageOptimize       Image optimization. 
	\param[out] ImageWidth          Width of the captured image.
	\param[out] ImageHeight         Height of the captured image.
	\param[out] BitsPerPixel        Bits per pixel of the image (always 24 bit RGB).
	\param[out] ImageBufferSize     Length of the image buffer &mdash; used for 'GetRawImage' call.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetRawImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL PrepareRawClippedDocumentImage(TPSALightSource LightSource, TPSAImageOptimize ImageOptimize, int& ImageWidth, int &ImageHeight, int& BitsPerPixel, size_t &ImageBufferSize);

	/**
	Get the data of the last call to PrepareRawImage, PrepareRawFacialImage or PrepareRawClippedDocumentImage.

	The raw image format is 24 bit interleaved RGB, i.e., a single pixel is
	represented by a consecutive triple of bytes with the color intensities
	for the red, green and blue. These triples are laid out
	consecutively in left-to-right line order. No padding is added between
	individual lines. The data has no header information.

	There is no extra metadata saved so the application must take care of the image dimensions received byPrepareRawImage() .

	\param ImageBuffer       Target buffer into which to store the image. 
	\param ImageBufferSize   Length of the prepared target buffer.
	\return psaSuccess on success. Respective error result code otherwise.

	\see PrepareRawImage(), PrepareRawFacialImage(), PrepareRawClippedDocumentImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetRawImage(unsigned char* ImageBuffer, size_t ImageBufferSize);

	/**
	Request a BMP image of the full scan pane.

	This function transfers the image data of the most recent scan operation
	to the host PC and post processes it. Note that the light source passed
	as first argument must refer to one of the selected light sources used
	for the scan (see SetScanSettingsEx()).

	The returned size information should be used to prepare a buffer
	for retrieving the image information. For details see GetRawImage().

	The format of the image is a 24 bit Windows Bitmap.
	The following information are part of the image metadata:

	- The image dimensions as width and height.
	- the image resolution in horizontal and vertical direction.

	\param[in]  LightSource         Light source with which the requested image was scanned.
	\param[in]  ImageOptimize       Image optimization. 
	\param[out] ImageBufferSize     Length of the image buffer &mdash; used for GetBmpImage() call.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetBmpImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL PrepareBmpImage(TPSALightSource LightSource, TPSAImageOptimize ImageOptimize, size_t &ImageBufferSize);
	/**
	Request a BMP image of the owner's face on the document.

	Note that currently face cropping is only available under the following conditions:
	- The document has an ICAO compliant machine readable zone (MRZ).
	- The face is printed on the same side as the MRZ.

	This function transfers the image data of the most recent scan operation
	to the host PC and post processes it. Note that the light source passed
	as first argument must refer to one of the selected light sources used
	for the scan (see SetScanSettingsEx()).

	The returned size information should be used to prepare a buffer
	for retrieving the image information. For details see GetBmpImage().

	The format of the image is a 24 bit Windows Bitmap.
	The following information are part of the image metadata:

	- The image dimensions as width and height.
	- the image resolution in horizontal and vertical direction.

	\param[in]  LightSource         Light source with which the requested image was scanned.
	\param[in]  ImageOptimize       Image optimization. Use ioBest for optimal colors.
	\param[out] ImageBufferSize     Length of the image buffer &mdash; used for GetBmpImage() call.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetBmpImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL PrepareBmpFacialImage(TPSALightSource LightSource, TPSAImageOptimize ImageOptimize, size_t &ImageBufferSize);
	/**
	Request a BMP image of the document auto-rotated and cropped at the edges.

	This function transfers the image data of the most recent scan operation
	to the host PC and post processes it. Note that the light source passed
	as first argument must refer to one of the selected light sources used
	for the scan (see SetScanSettingsEx()).

	The returned size information should be used to prepare a buffer
	for retrieving the image information. For details see GetBmpImage().

	The format of the image is a 24 bit Windows Bitmap.
	The following information are part of the image metadata:

	- The image dimensions as width and height.
	- the image resolution in horizontal and vertical direction.

	\param[in]  LightSource         Light source with which the requested image was scanned.
	\param[in]  ImageOptimize       Image optimization. Use ioBest for optimal colors.
	\param[out] ImageBufferSize     Length of the image buffer &mdash; used for GetBmpImage() call.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetBmpImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL PrepareBmpClippedDocumentImage(TPSALightSource LightSource, TPSAImageOptimize ImageOptimize, size_t &ImageBufferSize);

	/**
	Get the data of the last call to PrepareBmpImage, PrepareBmpFacialImage or PrepareBmpClippedDocumentImage.

	The format of the image is a 24 bit Windows Bitmap.
	The following information are part of the image metadata:

	- The image dimensions as width and height.
	- the image resolution in horizontal and vertical direction.

	\param ImageBuffer       Target buffer into which to store the image. 
	\param ImageBufferSize   Length of the prepared target buffer.
	\return psaSuccess on success. Respective error result code otherwise.

	\see PrepareBmpImage(), PrepareBmpFacialImage(), PrepareBmpClippedDocumentImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetBmpImage(unsigned char* ImageBuffer, size_t ImageBufferSize);

	/**
	Request a JPEG/JFIF image of the full scan pane.

	This function transfers the image data of the most recent scan operation
	to the host PC and post processes it. Note that the light source passed
	as first argument must refer to one of the selected light sources used
	for the scan (see SetScanSettingsEx()).

	The returned size information should be used to prepare a buffer
	for retrieving the image information. For details see GetJpegImage().

	The format of the image is a 24 bit JPEG/JFIF with the following
	information saved in the image metadata:

	- The image dimensions as width and height.
	- the image resolution in horizontal and vertical direction.

	\param[in] LightSource         Light source with which the requested image was scanned.
	\param[in] ImageOptimize       Image optimization. Use ioBest for optimal colors.
	\param[in] JpegQuality         Quality for Jpeg-File (100=max, 1=min)
	\param[out] ImageBufferSize     Length of the image buffer - used for GetJpegImage() call.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL PrepareJpegImage(TPSALightSource LightSource, TPSAImageOptimize ImageOptimize, short JpegQuality, size_t &ImageBufferSize);

	/**
	Request a JPEG/JFIF image of the owner's face on the document.

	Note that currently face cropping is only available under the following conditions:
	- The document has an ICAO compliant machine readable zone (MRZ).
	- The face is printed on the same side as the MRZ.

	This function transfers the image data of the most recent scan operation
	to the host PC and post processes it. Note that the light source passed
	as first argument must refer to one of the selected light sources used
	for the scan (see SetScanSettingsEx()).

	The returned size information should be used to prepare a buffer
	for retrieving the image information. For details see GetJpegImage().

	The format of the image is a 24 bit JPEG/JFIF with the following
	information saved in the image metadata:

	- The image dimensions as width and height.
	- the image resolution in horizontal and vertical direction.

	\param[in] LightSource         Light source with which the requested image was scanned.
	\param[in] ImageOptimize       Image optimization. Use ioBest for optimal colors.
	\param[in] JpegQuality         Quality for Jpeg-File (100=max, 1=min)
	\param[out] ImageBufferSize     Length of the image buffer - used for GetJpegImage() call.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetJpegImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL PrepareJpegFacialImage(TPSALightSource LightSource, TPSAImageOptimize ImageOptimize, short JpegQuality, size_t &ImageBufferSize);

	/**
	Request a JPEG/JFIF image of the owner's face on the document.

	Note that currently face cropping is only available under the following conditions:
	- The document has an ICAO compliant machine readable zone (MRZ).
	- The face is printed on the same side as the MRZ.

	This function transfers the image data of the most recent scan operation
	to the host PC and post processes it. Note that the light source passed
	as first argument must refer to one of the selected light sources used
	for the scan (see SetScanSettingsEx()).

	The returned size information should be used to prepare a buffer
	for retrieving the image information. For details see GetJpegImage().

	The format of the image is a 24 bit JPEG/JFIF with the following
	information saved in the image metadata:

	- The image dimensions as width and height.
	- the image resolution in horizontal and vertical direction.

	\param[in] LightSource         Light source with which the requested image was scanned.
	\param[in] ImageOptimize       Image optimization. Use ioBest for optimal colors.
	\param[in] JpegQuality         Quality for Jpeg-File (100=max, 1=min)
	\param[out] ImageBufferSize     Length of the image buffer - used for GetJpegImage() call.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetJpegImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL PrepareJpegClippedDocumentImage(TPSALightSource LightSource, TPSAImageOptimize ImageOptimize, short JpegQuality, size_t &ImageBufferSize);


	/**
	Get the data of the last call to PrepareJpegImage, PrepareJpegFacialImage or PrepareJpegClippedDocumentImage.

	The format of the image is a 24 bit JPEG/JFIF with the following
	information saved in the image metadata:

	- The image dimensions as width and height.
	- the image resolution in horizontal and vertical direction.

	\param ImageBuffer       Target buffer into which to store the image. 
	\param ImageBufferSize   Length of the prepared target buffer.
	\return psaSuccess on success. Respective error result code otherwise.

	\see PrepareJpegImage(), PrepareJpegFacialImage(), PrepareJpegClippedDocumentImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetJpegImage(unsigned char* ImageBuffer, size_t ImageBufferSize);

	/**
	Request a PNG image of the full scan pane.

	This function transfers the image data of the most recent scan operation
	to the host PC and post processes it. Note that the light source passed
	as first argument must refer to one of the selected light sources used
	for the scan (see SetScanSettingsEx()).

	The returned size information should be used to prepare a buffer
	for retrieving the image information. For details see GetPngImage().

	The format of the image is a 24 bit PNG with the following
	information saved in the image metadata:

	- The image dimensions as width and height.
	- the image resolution in horizontal and vertical direction.

	\param[in] LightSource         Light source with which the requested image was scanned.
	\param[in] ImageOptimize       Image optimization. Use ioBest for optimal colors.
	\param[in] CompressionLevel    PNG compression level (0&ndash;9);
	\param[out] ImageBufferSize     Length of the image buffer - used for GetJpegImage() call.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetPngImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL PreparePngImage(TPSALightSource LightSource, TPSAImageOptimize ImageOptimize, short CompressionLevel, size_t &ImageBufferSize);

	/**
	Request a PNG image of the owner's face on the document.

	Note that currently face cropping is only available under the following conditions:
	- The document has an ICAO compliant machine readable zone (MRZ).
	- The face is printed on the same side as the MRZ.

	This function transfers the image data of the most recent scan operation
	to the host PC and post processes it. Note that the light source passed
	as first argument must refer to one of the selected light sources used
	for the scan (see SetScanSettingsEx()).

	The returned size information should be used to prepare a buffer
	for retrieving the image information. For details see GetPngImage().

	The format of the image is a 24 bit PNG with the following
	information saved in the image metadata:

	- The image dimensions as width and height.
	- the image resolution in horizontal and vertical direction.

	\param[in] LightSource         Light source with which the requested image was scanned.
	\param[in] ImageOptimize       Image optimization. Use ioBest for optimal colors.
	\param[in] CompressionLevel    PNG compression level (0&ndash;9);
	\param[out] ImageBufferSize     Length of the image buffer - used for GetJpegImage() call.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetPngImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL PreparePngFacialImage(TPSALightSource LightSource, TPSAImageOptimize ImageOptimize, short CompressionLevel, size_t &ImageBufferSize);

	/**
	Request a PNG image of the owner's face on the document.

	Note that currently face cropping is only available under the following conditions:
	- The document has an ICAO compliant machine readable zone (MRZ).
	- The face is printed on the same side as the MRZ.

	This function transfers the image data of the most recent scan operation
	to the host PC and post processes it. Note that the light source passed
	as first argument must refer to one of the selected light sources used
	for the scan (see SetScanSettingsEx()).

	The returned size information should be used to prepare a buffer
	for retrieving the image information. For details see GetPngImage().

	The format of the image is a 24 bit PNG with the following
	information saved in the image metadata:

	- The image dimensions as width and height.
	- the image resolution in horizontal and vertical direction.

	\param[in] LightSource         Light source with which the requested image was scanned.
	\param[in] ImageOptimize       Image optimization. Use ioBest for optimal colors.
	\param[in] CompressionLevel    PNG compression level (0&ndash;9);
	\param[out] ImageBufferSize     Length of the image buffer - used for GetJpegImage() call.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetPngImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL PreparePngClippedDocumentImage(TPSALightSource LightSource, TPSAImageOptimize ImageOptimize, short CompressionLevel, size_t &ImageBufferSize);

	/**
	Get the data of the last call to PreparePngImage, PreparePngFacialImage or PreparePngClippedDocumentImage.

	The format of the image is a 24 bit PNG with the following
	information saved in the image metadata:

	- The image dimensions as width and height.
	- the image resolution in horizontal and vertical direction.

	\param[out] ImageBuffer       Target buffer into which to store the image. 
	\param[in] ImageBufferSize    Length of the prepared target buffer.
	\return psaSuccess on success. Respective error result code otherwise.

	\see PreparePngImage(), PreparePngFacialImage(), PreparePngClippedDocumentImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetPngImage(unsigned char* ImageBuffer, size_t ImageBufferSize);

  /**
   Enumeration type for known document shapes.
  */
  typedef int TPSADocumentShape;
  /**
   Unknown document shape.
  */
  const TPSADocumentShape shapeNoClippingFound = 0;
  /**
   ID1 / ICAO TD1 document shape (credit card size).
  */
  const TPSADocumentShape shapeId1 = 1;
  /**
   ID2 / ICAO TD2 document shape.
  */
  const TPSADocumentShape shapeId2 = 2;
  /**
   ID3 / ICAO Passport document shape.
  */
  const TPSADocumentShape shapeId3 = 3;

  /**
   No clipping has been found.
  */
  const TPSADocumentShape shapeUnknown = 9999;

  /**
  Get shape of clipped document.

  This function refers to the last call to Scan(). In order to get good results infrared light scanning should be activated.

  \param[out] Shape   Shape identifier. Value psaNoClippingFound indicates that the clipping has not been successful.
  \return psaSuccess on success. Respective error result code otherwise.

  \see SetScanSettings(), SetScanSettingsEx()
  */

  PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetClippedDocumentShape(TPSADocumentShape & Shape);

  /**
  Get width and height of clipped document in millimeters.

  This function refers to the last call to Scan(). In order to get good results infrared light scanning should be activated.

  \param[out] WidthMm  Width of the clipped image in millimeters.
  \param[out] HeightMm  Height of the clipped image in millimeters.
  \return psaSuccess on success. Respective error result code otherwise.

  \see SetScanSettings(), SetScanSettingsEx()
  */
  PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetClippedDocumentSizeMillimeters(double & WidthMm, double & HeightMm);

	/**
	 Analyze ambient light for a specific resolution and light source.

	 This function analyzes the ambient light in order to estimate its effect on regular scans.
	 The only prerequisite of this call is an established connection.
	 Unlike SetScanSettings() or SetScanSettingsEx() there is no speed penalty if called multiple times for different resolutions.
	 The result of the analysis can be requested by functions like AmbientLightEstimateArtifacts().

	 \param[in] Resolution      Scan resolution. One of resLow, resDefault or resresHigh.
	 \param[in] LightSource     Scan light source. One of lsIr, lsVisible or lsUvOnly.
	 \return psaSuccess on success. Respective error result code otherwise.

	 \see AmbientLightEstimateArtifacts()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL AmbientLightAnalyze(TPSAResolution Resolution, TPSALightSource LightSource);
	
	/**
	 Estimate proportion of artifact pixels caused by ambient light.

	 For a scan without internal illumination, a pixel counts as artifact if any of its red, green or blue color value reaches value 255.
	 The returned proportion is a rough estimation of the relative amount of these artifact pixels.

	 The returned value refers to the most recent call to AmbientLightAnalyze().

	 \param[out]   Proportion    Estimated proportion of artifact pixels. Value between 0.0 (no artifacts) and 1.0 (all artifacts)
	 \return psaSuccess on success. Respective error result code otherwise.

	 \see AmbientLightAnalyze()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL AmbientLightEstimateArtifacts(double & Proportion);	
	
	/** @} */
	// ---------------------------------------------------------------------------------------------------------
	/** \defgroup groupThumbnail Thumbnail Scans
	
	Retrieve images of scans.
	
	@{
	*/

	/**
	Set linear factor for changing the exposure time (shutter speed) of a thumbnail request.

	A factor of *f* will increase (*f* > 1.0) or decrease (*f* < 1.0) the shutter time by multiplying it with the default exposure time.
	The given factor will be used for all subsequent scans.

	Note that this value may be reset to 1.0 automatically on a reconnect.

	\param[in] Factor   Factor to be multiplied to the sensor shutter width.
	\return psaSuccess on success. Respective error result code otherwise.

	\see ThumbnailRequest(), ThumbnailGetImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ThumbnailSetExposureFactor(double Factor);

	/**
	 Request low resolution thumbnail scan.
	 
	 This function can be used to request a series of low resolution gray scale preview images.

	 \param[out] Width             Width of the result image
	 \param[out] Height            Height of the result image
	 \param[out] ImageBufferSize   Size of the complete image buffer, i.e., Width * Height.
	                               Can be used by the application to allocate a target buffer.
	 \return psaSuccess on success. Respective error result code otherwise.

	 \see ThumbnailGetImage(), ThumbnailSetExposureFactor(), ThumbnailGetResolutionInfo(), ThumbnailAmbientEstimateArtifacts()

	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ThumbnailRequest(int &Width, int &Height, size_t & ImageBufferSize);

	/**
	 Get low resolution thumbnail image.
	 
	 Get the image data obtained by the most recent call to ThumbnailRequest().
	 The resulting image will be a gray scale image encoded as 8-bit pixel values in row order layout.
	 All rows are encoded as contiguous data block without any line padding or special alignment.

	 \param[out] ImageBuffer       Target buffer to hold the image data
	 \param[out] ImageBufferSize   Size of the target buffer, i.e., Width * Height.
	                               Should be the same as returned by the respective argument of RequestThumbnail().
	 \return psaSuccess on success. Respective error result code otherwise.
	 \see ThumbnailRequest(), ThumbnailGetResolutionInfo()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ThumbnailGetImage(unsigned char * ImageBuffer, size_t ImageBufferSize);
	
	/**
	 Estimate proportion of artifact pixels caused by ambient light during a thumbnail scan.

	 For a scan without internal illumination, a pixel counts as artifact if any of its red, green or blue color value reaches value 255.
	 The returned proportion is a rough estimation of the relative amount of these artifact pixels.

	 There is no prerequisite to calling this function except for an established connection (see ConnectToDevice()).

	 \param[out]   Proportion    Estimated proportion of artifact pixels. Value between 0.0 (no artifacts) and 1.0 (all artifacts).
	 \return psaSuccess on success. Respective error result code otherwise.

	 \see AmbientLightAnalyze()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ThumbnailAmbientEstimateArtifacts(double & Proportion);

	
	/**
	 Get resolution information for thumbnail scans.

	 This function can be called without performing an actual scan. The only prerequisite is an established connection (See ConnectToDevice()).
	 Note that the thumbnail images are not corrected geometrically and still exhibit the radial distortion of the lens.
	 This is why the pixel density values returned by this function can only represent an average.
	 
	 \param[out] ImageWidth        Width of the thumbnail image.
	 \param[out] ImageHeight       Height of the thumbnail image.
	 \param[out] PixelPerMeterX    Estimated pixel density in horizontal direction.
	 \param[out] PixelPerMeterY    Estimated pixel density in vertical direction.
	 \return psaSuccess on success. Respective error result code otherwise.
	 \see ThumbnailRequest(), ThumbnailGetImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ThumbnailGetResolutionInfo(int &ImageWidth, int &ImageHeight, int &PixelPerMeterX, int &PixelPerMeterY);



	/** @} */

	// ---------------------------------------------------------------------------------------------------------
	/** \defgroup groupOcr OCR on the PC
	
	Perform MRZ reading on the PC.
	
	OCR on the PC uses the infrared image of the last scan to perform recognition.
	The functions must be called in the following sequence
	-# SetScanSettings() for setting light source to IR.
	-# Scan() for scanning the image.
	-# ReadOcrPc() perform OCR on the last scan.
	-# GetOcrOutputPc() to get the OCR data

	Use resolution resDefault for best results.

	We recommend this function to be used in a TOnDocumentInsert callback.
	See the documentation there for a short code example. 
	Alternatively, you can use function ScanAndCheck() in a loop to check for a new document
	and, on success, execute the sequence above. 

	Though OCR on the PC requires an extra scan, is has the following advantages 
	over OCR on the device.
	- It uses an extended recognition algorithm which leads to a better read rate.
	- The overall execution time is better on fast PCs.
	
	@{
	*/

	/**
	Perform optical character recognition (OCR) on the machine readable zone (MRZ).
	
	This function requires a previous scan with infrared light. Best 
	results can be expected for default or hight resolutions. For details see
	GetScanSettingsEx() and TPSAScanSettingsEx .

	\param[out] OcrResult  Result of the recognition call.
	\param[out] MrzLength  Length of the MRZ (if found any).
	\param[out] MrzBufferSize  Length of the Buffer - used for GetOcrOutput() call.
	\return psaSuccess on success. Respective error result code otherwise.
	\see ReadOcrPc, GetOcrOutputPc
	\deprecated This function is deprecated. Use ReadOcrPc().
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ReadOcr(TPSARecognitionResult& OcrResult, int& MrzLength, size_t& MrzBufferSize);

	/**
	Perform optical character recognition (OCR) on the machine readable zone (MRZ).

	This function requires a previous scan with infrared light. Best 
	results can be expected for default or hight resolutions. For details see
	GetScanSettingsEx() and TPSAScanSettingsEx .

	\param[out] OcrResult      Result of the recognition call.
	\param[out] MrzBufferSize  Size of the result buffer.
	\return psaSuccess on success. Respective error result code otherwise.
	\see GetOcrOutputPc()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ReadOcrPc(TPSARecognitionResult& OcrResult, size_t& MrzBufferSize);

	/**
	Get the OCR result.

	This function requires a previous call to ReadOcrPc().

	The returned buffer is a null-terminated string. Each MRZ line is terminated by carriage return (i.e, ASCII 0x0D or '\\r').

	\param[out] MrzBuffer       Buffer where the MRZ is stored. 
	\param[in] MrzBufferSize   Size of buffer MrzBuffer.
	\return psaSuccess on success. Respective error result code otherwise.
	\see ReadOcrPc
	*/	
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetOcrOutputPc(unsigned char* MrzBuffer, size_t MrzBufferSize);


	/**
	Get the OCR result.

	This function requires a previous call to ReadOcrPc().

	The returned buffer is a null-terminated string. Each MRZ line is terminated by carriage return (i.e, ASCII 0x0D or '\\r').

	\param[out] MrzBuffer       Buffer where the MRZ is stored. 
	\param[in] MrzBufferSize    Size of buffer MrzBuffer.
	\return psaSuccess on success. Respective error result code otherwise.
	\deprecated The function was split up into GetOcrOutputPc() and GetOcrOutputDevice()
	\see GetOcrOutputPc(), GetOcrOutputDevice()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetOcrOutput(unsigned char* MrzBuffer, size_t MrzBufferSize);

	/** @} */
	/** @} */

	// ---------------------------------------------------------------------------------------------------------
	/** \defgroup groupBcr Barcode Reading
	
	Read data of barcode event
	
	@{
	*/

	/**
	Request information about the last scanned barcode.

	This function should be used in a custom TOnBarcodePresent callback. 
	Alternatively, you can use it for polling in a loop.

	\param[out] BarcodeFound       Indicates whether a barcode was found or not.
	\param[out] BarcodeLength      Length of the barcode (if found any).
	\param[out] BarcodeBufferSize  Length of the Buffer - used for GetBarcodeOutput() call.
	\return psaSuccess on success. Respective error result code otherwise.
	\see GetBarcodeOutput
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ReadBarcode(bool& BarcodeFound, int& BarcodeLength, size_t& BarcodeBufferSize);

	/**
  Get the data of the most recently read barcode document.

  This function should be called directly after ReadBarcode().

	The barcode data has the following format:

	\verbatim
	STX type skip data ETX NUL

	where 

	NUL  = '\x00'
	STX  = '\x02'
	ETX  = '\x03'
	\endverbatim

	<tt>type</tt> is a two-byte code indicating the barcode type.
	\verbatim
	ATZTEC     = "]z";
	QR         = "]Q";
	PDF        = "]L";
	DM         = "]d";
	CODE128    = "]C";
	CODE39     = "]A";
	EAN13      = "]E";
	IN2OF5     = "]I";
	INDU2OF5_1 = "]R";
	INDU2OF5_2 = "]S";
	\endverbatim

	<tt>skip</tt> is a single byte which is not defined.

	Example: "\x02]C0This is the data of a CODE 128 barcode\x03\x00"

	Warning: The data may contain any binary, i.e, also '\0' may appear within the data block.

	\param[out] BarcodeBuffer       Buffer where the barcode data is stored. 
	\param[in] BarcodeBufferSize   Length of the buffer where the barcode data is stored.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetBarcodeOutput(unsigned char* BarcodeBuffer, size_t BarcodeBufferSize);

	/** @} */

	// ---------------------------------------------------------------------------------------------------------
	/** \defgroup groupMsr Magnetic Stripe Reading
	
	Read data of magnetic stripe event
	
	@{
	*/

	/**
	Request information about the most recently read magnetic stripe document.

	This function should be used in a custom TOnMsrPresent callback. 
	Alternatively, you can use it for polling in a loop.

	\param[out] MsrFound       Indicates whether a barcode was found or not.
	\param[out] MsrLength      Length of the mag. stripe data (if found).
	\param[out] MsrBufferSize  Length of the Buffer - used for 'GetMsrOutput' call.
	\return psaSuccess on success. Respective error result code otherwise.
	\see GetMsrOutput
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ReadMsr(bool& MsrFound, int& MsrLength, size_t& MsrBufferSize);

	/**
	Get the data of the most recently read magnetic stripe document.
  
  This function should be called directly after ReadMsr().

	The MSR data has the following format:

	\verbatim
	STX type { track } ETX NUL
	\endverbatim

	where 

	\verbatim
	type = 'A'    (* ATB ticket *)
	| 'C'    (* magnetic stripe card *)

	track = { block }

	block = blockNr blockData CR

	NUL  = '\x00'
	STX  = '\x02'
	ETX  = '\x03'
	CR   = '\x13' (* carriage return *)
	\endverbatim

	<tt>blockNr</tt> is a single byte which encodes the track and block number.
	The 4 high bits encode the track number, the 4 low bits encode the block
	number. Both tracks and blocks are 

	Example: '\\x21' - second track, first block

	ATB documents have redundant data saved in several blocks and tracks while
	ISO 7811 compliant magnetic stripe cards have one block per track.

	\param[out] MsrBuffer      Buffer to store the MSR data. 
	\param[in] MsrBufferSize   Length of the buffer MsrBuffer.
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetMsrOutput(unsigned char* MsrBuffer, size_t MsrBufferSize);

	/** @} */

	// ---------------------------------------------------------------------------------------------------------
	/** \defgroup groupDisplay Text and Graphical Display
	
	Set, store and show images on the display. Display text.
	
	@{
	*/

	/**
	Send a text message to the display of the device.
	Lines can be separated either by '\\n' (UNIX style), '\\r' (Mac style) or "\\r\\n" (Windows style). 
	
	On a graphical display the text format can be modified by special escape sequences.
	It supports a subset of the ANSI ESC commands traditionally used on terminal text displays. 
	(See also http://academic.evergreen.edu/projec...sc.htm#display)
	
	Default Settings
	----------------

	The device restores its default settings during its startup sequence. 
	Any format change will remain persistent for all following display 
	messages. To force a reset to the defaults there is the 
	following special command:
	
		"\x1b[0m"
	
	Default Settings:

	Feature                               | Setting
	--------------------------------------|---------------------------------
	Text box transparent mode             | Semi-transparent
	Text box transparent mode gamma value | RgbPixel(65, 65, 65)
	Text foreground mode                  | Color  
	Text background mode                  | Transparent
	Text color                            | RgbPixel(255,255,255) -> white
	Text background color                 | RgbPixel(0,0,0) -> black
	
	Test Box Modes
	--------------
	
	__Transparent__

	The text box is transparent. The text color remains as defined. Setting the background color has no effect.

	Mode:

		"\x1b[112;300m"

	Color:

		-

	__Color__

    The text box uses the the defined background color.
	
	Mode:

		"\x1b[112;301m"
	Color:

		"\x1b[113;r<0-255>;g<0-255>;b<0-255>m"

	__Semi-transparent__

	The text box is semi-transparent. The gamma  value used defines the amount of transparency.
	
	Mode: 

		"\x1b[112;302m"

	Gamma:

		"\x1b[113;r<0-255>;g<0-255>;b<0-255>m"

	__Image Transparent__

	The full image is semi-transparent rather than only a small text box. The respective gamma value is used.
	
	Mode:

		"\x1b[112;303m"

	Gamma:

		"\x1b[113;r<0-255>;g<0-255>;b<0-255>m"

	Text Foreground Mode
	-------------------

	__Transparent__

	The text is displayed transparently.

		"\x1b[110;300m"

	__Color__

	The text is displayed with the current text color.

		"\x1b[110;301m"

	Text Background Mode
	--------------------

	__Transparent__

	The background is transparent

		"\x1b[112;300m"

	__Color__

	The background uses the current text color.

		"\x1b[112;301m"

	Text Color
	----------

		"\x1b[30m" // black
		"\x1b[31m" // red
		"\x1b[32m" // green
		"\x1b[33m" // yellow
		"\x1b[34m" // blue
		"\x1b[35m" // magenta
		"\x1b[36m" // cyan
		"\x1b[37m" // white
		"\x1b[38;r<0-255>;g<0-255>;b<0-255>m" // RGB

	Text Background Color
	---------------------

		"\x1b[40m" // black
		"\x1b[41m" // red
		"\x1b[42m" // green
		"\x1b[43m" // yellow
		"\x1b[44m" // blue
		"\x1b[45m" // magenta
		"\x1b[46m" // cyan
		"\x1b[47m" // white
		"\x1b[48;r<0-255>;g<0-255>;b<0-255>m" // RGB

	\param[out] DisplayText  Null-terminated buffer containing the display text. 
							
	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL SetDisplayText(const char* DisplayText);

	/**
	Store a display image on the device.

	The image store on the device is structured in 4 pages with 32 positions 
	per page. Each position can store data for a single image.
	Image data is raw 24 bit RGB data organized in row-order. For maximum 
	performance, the image data should have the width and height as returned
	by function GetDisplayDimensions(DisplayWidth. DisplayHeight).

	\param[in] Page         Page of target position.
	\param[in] Position     Target position within the page.
	\param[in] ImageBuffer  Pointer to image buffer.
	\param[in] Width        Number of RGB pixels per row in ImageBuffer.
	\param[in] Height       Number or rows in image.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetDisplayDimensions(), ShowDisplayImage(), ShowDisplayImageNoStore()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL StoreDisplayImage(unsigned int Page, unsigned int Position, const unsigned char* ImageBuffer, unsigned int Width, unsigned int Height);

	/**
	Clear data of an individual image on the device.

	The image store on the device is structured in 4 pages with 32 positions 
	per page. Each position can store data for a single image.

	\param[in] Page         Page of target position.
	\param[in] Position     Image position within the page.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetDisplayDimensions(), ShowDisplayImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ClearDisplayImage(unsigned int Page, unsigned int Position);

	/**
	Show individual image stored on the device.

	The image store on the device is structured in 4 pages with 32 positions 
	per page. Each position can store data for a single image.

	\param[in] Page         Page of target position.
	\param[in] Position     Image position within the page.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetDisplayDimensions(), StoreDisplayImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ShowDisplayImage(unsigned int Page, unsigned int Position);

	/**
	Show an image without storing it on the device.

	Image data is raw 24 bit RGB data organized in row-order. For maximum 
	performance, the image data should have the width and height as returned
	by function GetDisplayDimensions(DisplayWidth. DisplayHeight).

	The image will be shown until the next time the device is rebooted
	or either ShowDisplayImage() or ShowDisplayImageNoStore() is called.

	\param[in] ImageBuffer  Pointer to image buffer.
	\param[in] Width        Number of RGB pixels per row in ImageBuffer.
	\param[in] Height       Number or rows in image.
	\return psaSuccess on success. Respective error result code otherwise.

	\see GetDisplayDimensions(), StoreDisplayImage()
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ShowDisplayImageNoStore(const unsigned char* ImageBuffer, unsigned int Width, unsigned int Height);

	/**
	Get pixel width and height of the graphical display.

	\param[out] DisplayWidth   Number of pixels of a single display row
	\param[out] DisplayHeight  Number of pixel rows on the display.

	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL GetDisplayDimensions(unsigned int &DisplayWidth, unsigned int &DisplayHeight);

	/**
	Select a specific display image and show it with text.

	This function combines the functionality of ShowDisplayImage() and SetDisplayText().
	It is executed faster than a call to both functions separately.

	\param[in] Page         Page of target position.
	\param[in] Position     Image position within the page.
	\param[in] Text         Null-terminated buffer containing the display
							text.
							See the documentation of SetDisplayText() for
							details on message formatting.

	\return psaSuccess on success. Respective error result code otherwise.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ShowDisplayImageAndText(unsigned int Page, unsigned int Position, const char * Text);
	/**
	Show a display image with text.

	This function combines the functionality of ShowDisplayImageNoStore()
	and SetDisplayText().
	It is executed faster than a call to both functions separately.
	
	\param[in] ImageBuffer  Pointer to image buffer.
	\param[in] Width        Number of RGB pixels per row in ImageBuffer.
	\param[in] Height       Number or rows in image.
	\param[in] Text         Null-terminated buffer containing the display
							text.
	                        See the documentation of SetDisplayText() for
							details on message formatting.
	\return psaSuccess on success. Respective error result code otherwise.

	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL ShowDisplayImageNoStoreAndText(const unsigned char* ImageBuffer, unsigned int Width, unsigned int Height, const char * Text);


	/** @} */

	//--------------------------------------------------------------------------------------------------------------------

	/**
	Do not use.
	*/
	PAGESCANAPI_USAGE TPSAResult PAGESCANAPI_STDCALL CheckDocumentPresentPc(TPSALightSource Light, bool & DocInPlace);

}

#ifndef PAGESCANAPI_NO_NAMESPACE
#ifdef PAGESCANAPI_NEW_NAMESPACE
}
#endif
#endif
//---------------------------------------------------------------------------
#endif

