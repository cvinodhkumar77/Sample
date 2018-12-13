/**
*  DESKO PageScan API Simple Demo
*
*  (c) 2017 DESKO GmbH Bayreuth, Germany
*
*  This is a sample program for the DESKO PENTA device. 
*
*/

#include "stdafx.h"
#include <PageScanApi.h>
#include <DeskoMrz.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using namespace Desko;
using namespace Desko;

const size_t TEXT_BUFFER_SIZE = 1024;
bool checkDocumentMotion = false;
bool useExternalLight = false;
bool scanUv = false;

// helpers

string getProp(FullPage::TPSAPropertyKey key, const string &def);
int getProp(FullPage::TPSAPropertyKey key, int def);
ostream & prettyPrintRaw(ostream &out, const vector<unsigned char> &buf);
ostream & prettyPrintOcr(ostream &out, const string &ocr);
string expandEnv(const string & Str);
void assertResult(FullPage::TPSAResult res);
void printApiInfo();
void printDeviceInfo();
void feedbackGood();
void feedbackBad();
void analyseMrz(const vector<char> &mrzAscii);

// Custom handler for establishing connection after plug event.
void PAGESCANAPI_STDCALL onDevicePlug(bool PluggedIn);
// Custom handler for capturing bar code events.
void PAGESCANAPI_STDCALL onBarcodePresent();
// Custom handler for capturing device OCR events.
void PAGESCANAPI_STDCALL onOcrPresent();
// Custom handler for capturing device magnetic stripe events.
void PAGESCANAPI_STDCALL onMsrPresent();
// Custom handler for reacting on document presentation.
void PAGESCANAPI_STDCALL onDocumentInsert(FullPage::TPSAWaitForDocMode& WaitForDocMode);
// Custom handler for reacting on document removal.
void PAGESCANAPI_STDCALL onDocumentRemoved();

// main function
int _tmain(int argc, _TCHAR* argv[])
{	
	try 
	{
		// print API info

    printApiInfo();

		cout << "Register custom plug handler." << endl;

		FullPage::SetupOnDevicePlugCallback(onDevicePlug); // This handler makes sure the connection is up and running.

    cout << "Setting event handlers..." << endl;
    FullPage::SetupOnDocumentCallback(onDocumentInsert); // This handler is where all the scanning is done.
    cout << "Document presented handler set." << endl;
    FullPage::SetupOnDocumentRemoveCallback(onDocumentRemoved);
    cout << "Document removed handler set." << endl;
		FullPage::SetupOnBarcodeCallback(onBarcodePresent);
		cout << "Barcode handler set." << endl;
		FullPage::SetupOnMsrCallback(onMsrPresent);
		cout << "Magnetic stripe handler set." << endl;
		FullPage::SetupOnOcrCallback(nullptr);

    // Uncomment the following lines if you want to listen to OCR events and disable automatic scanning.
    //SetupOnDocumentCallback(nullptr);
    //SetupOnOcrCallback(onOcrPresent);
	}
	catch (FullPage::TPSAResult res)
	{
    res;
	}

  cout << "press key to exit." << endl;
  cin.get();
	return 0;
}
//-------------------------------------------------------------------------


// Custom handler for establishing a connection after a plug event.
void PAGESCANAPI_STDCALL onDevicePlug(bool PluggedIn)
{
  try
  {
    if (PluggedIn)
    {
      cout << "Device plugged." << endl;

      assertResult(FullPage::ConnectToDevice());

      cout << "Device connected:" << endl;

      printDeviceInfo();
      
      // keep some info for later
      useExternalLight = (0 != getProp(FullPage::keyDeviceSupportExternalStatusLed, -1));
      checkDocumentMotion = (0 != getProp(FullPage::keyDeviceSupportGlareReduction, -1));
      scanUv = (0 != getProp(FullPage::keyDeviceSupportUvLight, -1));
      
      FullPage::TPSAScanSettingsEx s;

      // Setup light sources. Ambient light elimination is recommended for image cropping later on.
      s.ScanIRLight = (FullPage::sfUse | FullPage::sfAmbientLightElimination); // Configure infrared scan. Required for OCR.
      s.ScanVisibleLight = (FullPage::sfUse | FullPage::sfAmbientLightElimination); // Configure white light scan.
      s.ScanUvOnlyLight = (scanUv ? (FullPage::sfUse | FullPage::sfAmbientLightElimination) : FullPage::sfNone); // Configure UV scan if device supports it.
      s.ScanUV3Light = FullPage::sfNone; // Not using pseudo light source.
      s.Resolution = FullPage::resHigh;
      s.ScanFlags = 0; // Has no effect. For future use.

      assertResult(SetScanSettingsEx(s));

      // It is sufficient to call SetScanSettingsEx() once on connect, except if the settings need to be changed.
      
      cout << "Scan settings prepared. Ready to scan." << endl;

      feedbackGood();
    }
    else
    {
      FullPage::DisconnectFromDevice();

      cout << "Device unplugged" << endl;
    }
  } 
  catch (FullPage::TPSAResult res)
  {
    res;
  }
}
// --------------------------------------------------------------------------
void PAGESCANAPI_STDCALL onBarcodePresent()
{
  try {    
    bool found = false;
    int dummy = 0;
    size_t bcrSize;

    feedbackGood();

    assertResult(FullPage::ReadBarcode(found, dummy, bcrSize));

    if (!found)
    {
      cout << "No bar code data available." << endl;
      return;
    }
    std::vector<unsigned char> bcrData;
    bcrData.resize(bcrSize);

    assertResult(FullPage::GetBarcodeOutput(&bcrData[0], bcrData.size()));
	cout << "prettyPrintRaw(cout, bcrData)" << endl;

	cout << prettyPrintRaw(cout, bcrData).hex << "-------- " << endl;




  }
  catch (FullPage::TPSAResult res) {
    res;
  }

}
/// --------------------------------------------------------------------------


void PAGESCANAPI_STDCALL onOcrPresent()
{
  try {    
    FullPage::TPSARecognitionResult found = FullPage::rrFailedRecognition;
    int dummy = 0;
    size_t mrzSize;

    feedbackGood();

    assertResult(FullPage::ReadOcrDevice(found, mrzSize));

    if (found != FullPage::rrGoodRecognition)
    {
      cout << "No MRZ data available." << endl;
      return;
    }
    std::vector<unsigned char> mrzData;
    mrzData.resize(mrzSize);

    assertResult(FullPage::GetOcrOutputDevice(&mrzData[0], mrzData.size()));

    cout << prettyPrintRaw(cout, mrzData).hex << endl;
	cout << "prettyPrintRaw(cout, mrzData)" << endl;

  }
  catch (FullPage::TPSAResult res) {
    res;
  }

}
// --------------------------------------------------------------------------


void PAGESCANAPI_STDCALL onMsrPresent()
{
  try
  {
    bool found = false;
    int dummy = 0;
    size_t msrSize;

    feedbackGood();

    assertResult(FullPage::ReadMsr(found, dummy, msrSize));

    if (!found)
    {
      cout << "No magnetic stripe data available." << endl;
      return;
    }
    std::vector<unsigned char> msrData;
    msrData.resize(msrSize);

    assertResult(FullPage::GetMsrOutput(&msrData[0], msrData.size()));

    cout << prettyPrintRaw(cout, msrData).hex << endl;
	cout << "prettyPrintRaw(cout, msrData)" << endl;


  }
  catch (FullPage::TPSAResult res) {
    res;
  }
}
// --------------------------------------------------------------------------


void PAGESCANAPI_STDCALL onDocumentInsert(FullPage::TPSAWaitForDocMode& WaitForDocMode)
{
  try
  {

    feedbackGood();
    
    // Scan with light sources and resolution which was set up during connect (see onDevicePlug).
    assertResult(FullPage::Scan());

    // Give user feedback.
    // For RFID reading the feedback should be delayed until all data has been read .
    feedbackGood();
    
    if (checkDocumentMotion)
    {
      // On Illumination revision 4.3 and later the device supports glare reduction and motion detection.
      // We should use that and accept only good scans!

      double docMoveIr = 0.0;
      double docMoveVis = 0.0;
      FullPage::EstimateDocumentMotion(FullPage::lsIr, docMoveIr);
      FullPage::EstimateDocumentMotion(FullPage::lsVisible, docMoveVis);

      // doc motion value should be way below 1.0 and close to 0.0
      if (docMoveIr > 0.5 || docMoveVis > 0.5)
      {
        feedbackBad();
        cout << "Document moved during scan. Please remove and try again." << endl;
        return;
      }
    }


    // Now, perform OCR on PC
    FullPage::TPSARecognitionResult ocrResult;
    
    size_t ocrDataSize;
    std::vector<char> ocrData;
    assertResult(FullPage::ReadOcrPc(ocrResult, ocrDataSize));
    if (ocrResult == FullPage::rrGoodRecognition)
    {
      ocrData.resize(ocrDataSize);
      assertResult(FullPage::GetOcrOutputDevice((unsigned char*) &ocrData[0], ocrData.size()));
      cout << "MRZ found:" << endl;
      bool bad_chars = (find(ocrData.begin(), ocrData.end(), '*') != ocrData.end());
      cout << prettyPrintOcr(cout, std::string(ocrData.begin(), ocrData.end())).hex << endl;
	  cout << "prettyPrintOcr(cout, std::string(ocrData.begin(), ocrData.end()))" << endl;

      if (bad_chars)
      {
        cout << "MRZ has unclassified characters." << endl;
      }
      
    }
    else
    {
      cout << "No MRZ found." << endl;
    }

    // At this point the MRZ can be used to access an ePassport. For best performance, pass the MRZ to a separate thread for ePassport communication.
    // For sample code, see the DESKO ePass SDK.

    // Collect scans.

    if (!ocrData.empty())
    {
      analyseMrz(ocrData);

    }

    try {
      string filename = expandEnv("%TEMP%\\penta_sample_ir.bmp");
      size_t bufferSize = 0;
      std::vector<unsigned char> imageBuffer;

      // always use ioBest for optimal image quality.
      assertResult(FullPage::PrepareBmpClippedDocumentImage(FullPage::lsIr, FullPage::ioBest, bufferSize));
      
      imageBuffer.resize(bufferSize);
      
      assertResult(FullPage::GetBmpImage(&imageBuffer[0],imageBuffer.size()));
      
      ofstream os(filename, ios::binary);
      if (os.good())
      {
        os.write((const char*) imageBuffer.data(), imageBuffer.size());
        os.close();
        cout << "Scan written to " << filename << "." << endl;
        ShellExecute(0, 0, filename.c_str(), 0, 0 , SW_SHOW );
      }
      else
      {
        cout << "could not create output file." << endl;
      }

    } catch (FullPage::TPSAResult res)
    {
      res;
    }

    try {
      string filename = expandEnv("%TEMP%\\penta_sample_vis.bmp");
      size_t bufferSize = 0;
      std::vector<unsigned char> imageBuffer;
      
      assertResult(FullPage::PrepareBmpClippedDocumentImage(FullPage::lsVisible, FullPage::ioBest, bufferSize));
      
      imageBuffer.resize(bufferSize);
      
      assertResult(FullPage::GetBmpImage(&imageBuffer[0],imageBuffer.size()));
      
      ofstream os(filename, ios::binary);
      if (os.good())
      {
        os.write((const char*) imageBuffer.data(), imageBuffer.size());
        os.close();
        cout << "Scan written to " << filename << "." << endl;
        ShellExecute(0, 0, filename.c_str(), 0, 0 , SW_SHOW );
      }
      else
      {
        cout << "could not create output file." << endl;
      }

    } catch (FullPage::TPSAResult res)
    {
      res;
    }

    if (scanUv) try
    {
      string filename = expandEnv("%TEMP%\\penta_sample_uv.bmp");
      size_t bufferSize = 0;
      std::vector<unsigned char> imageBuffer;
      
      assertResult(FullPage::PrepareBmpClippedDocumentImage(FullPage::lsUvOnly, FullPage::ioBest, bufferSize));
      
      imageBuffer.resize(bufferSize);
      
      assertResult(FullPage::GetBmpImage(&imageBuffer[0],imageBuffer.size()));
      
      ofstream os(filename, ios::binary);
      if (os.good())
      {
        os.write((const char*) imageBuffer.data(), imageBuffer.size());
        os.close();
        cout << "Scan written to " << filename << "." << endl;
        ShellExecute(0, 0, filename.c_str(), 0, 0 , SW_SHOW );
      }
      else
      {
        cout << "could not create output file." << endl;
      }

    }
    catch (FullPage::TPSAResult res)
    {
      res;
    }


  }
  catch (FullPage::TPSAResult res)
  {
    cerr << "Error " << res << " in " << __FUNCTION__ << endl;
    char message[512];
    std::memset(message, 0, sizeof(message));
    FullPage::GetLastPSAError(res,message,sizeof(message));
    cerr << "Message: " << message << endl;
  }
}
/// --------------------------------------------------------------------------

void PAGESCANAPI_STDCALL onDocumentRemoved()
{
  cout << "Document removed" << endl;
}
//---------------------------------------------------------------------------


std::ostream & prettyPrintRaw(std::ostream &out, const std::vector<unsigned char> &buf)
{
  vector<unsigned char>::const_iterator ptr = buf.begin();
  vector<unsigned char>::const_iterator end = buf.end();

  while (ptr != end)
  {
    char c = (char) *ptr;

    if (c >= ' ' && c <= '~')
      out.put(c);
    else
      out << '{' << (int) c << '}';

    ptr++;
  }

  return out;
}
//-------------------------------------------------------------------------

std::ostream & prettyPrintOcr(std::ostream &out, const std::string &ocr)
{
  for (const char *c = ocr.c_str(); *c != '\0'; c++)
  {
    cout << "OCRR--------" << (*c == '\r' ? '\n' : *c);
  }
  cout << endl;
  return out;
}
//-------------------------------------------------------------------------

// Convenience function throwing any result value that is not successful.
void assertResult(FullPage::TPSAResult res)
{
  if (res != FullPage::psaSuccess)
  {
    FullPage::TPSAResult r;
    char message[TEXT_BUFFER_SIZE];
    memset(message, 0, TEXT_BUFFER_SIZE * sizeof(char));
    FullPage::GetLastPSAError(r, message, TEXT_BUFFER_SIZE);
    cerr << "Error " << res <<": " << message << endl;
    throw res;
  }
}
// --------------------------------------------------------------------------


string getProp(FullPage::TPSAPropertyKey key, const string &def)
{
  char value[TEXT_BUFFER_SIZE];

  FullPage::TPSAResult res = FullPage::GetPropertyString(key, (unsigned char*)value, TEXT_BUFFER_SIZE);

  if (res != FullPage::psaSuccess)
    return def;
  else
    return string(value);
}

int getProp(FullPage::TPSAPropertyKey key, int def)
{
  int value;

  FullPage::TPSAResult res = FullPage::GetPropertyInt(key, value);

  if (res != FullPage::psaSuccess)
    return def;
  else
    return value;
}

void printApiInfo()
{
  cout << "=== PagescanApi.dll loaded ===" << endl;

  int ival = 0;
  cout << "API:           " << getProp(FullPage::keyApiVersionString, "<n/a>") << endl;
  cout << "DLL:           " << getProp(FullPage::keyDllVersionString, "<n/a>") << " ";
  cout << getProp(FullPage::keyDllCompileDate, "<n/a>") << " ";
  cout << getProp(FullPage::keyDllCompileTime, "<n/a>") << endl;

}
// --------------------------------------------------------------------------

void printDeviceInfo()
{
  cout << "Serial Number: " << getProp(FullPage::keyDeviceSerialNumber, "<n/a>") << endl;

  cout << "Firmware:      " << getProp(FullPage::keyDeviceFirmwareVersionString, "<n/a>")  << " ";
  cout << getProp(FullPage::keyDeviceFirmwareDate, "<n/a>") << " ";
  cout << getProp(FullPage::keyDeviceFirmwareTime, "<n/a>") << endl;

  cout << "Illumination:  " << getProp(FullPage::keyDeviceIlluminationGeneration, -1) << "." ;
  cout << getProp(FullPage::keyDeviceIlluminationRevision, -1) << ".";
  cout << getProp(FullPage::keyDeviceIlluminationVariant, -1) << endl;

  cout << "Features:" << endl;
  cout << " Barcode              [" << (getProp(FullPage::keyDeviceSupportBarcode, -1) ? "X" : " ") << "]" << endl;
  cout << " Battery charge level [" << (getProp(FullPage::keyDeviceSupportBatteryChargeLevel, -1) ? "X" : " ") << "]" << endl;
  cout << " Color                [" << (getProp(FullPage::keyDeviceSupportColor, -1) ? "X" : " ") << "]" << endl;
  cout << " External buzzer      [" << (getProp(FullPage::keyDeviceSupportExternalBuzzer, -1) ? "X" : " ") << "]" << endl;
  cout << " External LED         [" << (getProp(FullPage::keyDeviceSupportExternalStatusLed, -1) ? "X" : " ") << "]" << endl;
  cout << " Glare reduction      [" << (getProp(FullPage::keyDeviceSupportGlareReduction, -1) ? "X" : " ") << "]" << endl;
  cout << " Graphical display    [" << (getProp(FullPage::keyDeviceSupportGraphicalDisplay, -1) ? "X" : " ") << "]" << endl;
  cout << " Text display         [" << (getProp(FullPage::keyDeviceSupportTextDisplay, -1) ? "X" : " ") << "]" << endl;
  cout << " Magnetic stripe      [" << (getProp(FullPage::keyDeviceSupportMsr, -1) ? "X" : " ") << "]" << endl;
  cout << " UV scan              [" << (getProp(FullPage::keyDeviceSupportUvLight, -1) ? "X" : " ") << "]" << endl;

}
// --------------------------------------------------------------------------


string expandEnv(const string & Str)
{
  char buf[MAX_PATH];
  memset (buf, 0, MAX_PATH);

  ExpandEnvironmentStrings(Str.c_str(),buf, MAX_PATH);

  return buf;
}
/// --------------------------------------------------------------------------

void feedbackGood()
{
  FullPage::TPSABuzzerSettings2 buzzer;
  buzzer.Duration = 100;
  buzzer.HighTime = 100;
  buzzer.LowTime = 0;
  buzzer.Volume = 190;

  assertResult(FullPage::SetBuzzerSettings2(buzzer));
  assertResult(FullPage::UseBuzzer());
  FullPage::TPSAStatusLEDSettings led;
  led.Color = FullPage::slcGreen;
  led.Duration = 1000;
  led.Enabled = true;
  led.HighTime = 1000;
  led.LowTime = 0;
  led.Usage = FullPage::sluPermanent;

  assertResult(FullPage::SetStatusLEDSettings(true, led));
  assertResult(FullPage::UseStatusLED(true));
}
/// --------------------------------------------------------------------------
void feedbackBad()
{
  FullPage::TPSABuzzerSettings2 buzzer;
  buzzer.Duration = 600;
  buzzer.HighTime = 100;
  buzzer.LowTime = 100;
  buzzer.Volume = 190;

  assertResult(FullPage::SetBuzzerSettings2(buzzer));
  assertResult(FullPage::UseBuzzer());

  FullPage::TPSAStatusLEDSettings led;
  led.Color = FullPage::slcRed;
  led.Duration = 1000;
  led.Enabled = true;
  led.HighTime = 200;
  led.LowTime = 200;
  led.Usage = FullPage::sluFlashing;

  assertResult(FullPage::SetStatusLEDSettings(true, led));
  assertResult(FullPage::UseStatusLED(true));
}
/// --------------------------------------------------------------------------


struct HandleScope {
  Mrz::DMRZObjectHandle handle;
  HandleScope(Mrz::DMRZObjectHandle h) : handle(h) {}
  ~HandleScope() {
    Mrz::DMRZDestroyHandle(handle);
  }
};
/// --------------------------------------------------------------------------

void analyseMrz(const vector<char> &mrzAscii)
{
  std::wstring mrz(mrzAscii.begin(), mrzAscii.end());
  HandleScope descr(Mrz::DMRZCreateMrzDescriptor());
  Mrz::DMRZBool validateChecksum = false;
  Mrz::DMRZResultIndex res;
  wchar_t holderName[TEXT_BUFFER_SIZE];
  std::fill_n(holderName, TEXT_BUFFER_SIZE, L'\0');

  Mrz::DMRZParseMrz(descr.handle, mrz.c_str());
  
  wcout << L"Parsed MRZ:" << endl;
  res = Mrz::DMRZValidateAllChecksums(descr.handle, &validateChecksum);

  if (res != Mrz::DMRZ_RESULT_SUCCESS) { wcout << "MRZ analysis failed."; return; }
  
  wcout << L"Checksums:      " << (validateChecksum? "GOOD":"BAD") << endl;

  Mrz::DMRZDocTypeIndex docType;
  res = Mrz::DMRZGetDocType(descr.handle, &docType);

  if (res != Mrz::DMRZ_RESULT_SUCCESS) { wcout << "MRZ analysis failed."; return; }

  wcout << L"Doc type index: " << docType << endl;

  res = Mrz::DMRZGetField(
    descr.handle, Mrz::DMRZ_FIELD_HOLDER_NAME,
    holderName,
    TEXT_BUFFER_SIZE,
    Mrz::DMRZ_FLAGS_SPACE_FILLER | Mrz::DMRZ_FLAGS_TRIM | Mrz::DMRZ_FLAGS_LOWER | Mrz::DMRZ_FLAGS_FIRST_UPPER);

  if (res != Mrz::DMRZ_RESULT_SUCCESS) { wcout << "MRZ analysis failed."; return; }

  wcout << L"Holder Name:    " << holderName << endl;

}
/// --------------------------------------------------------------------------
