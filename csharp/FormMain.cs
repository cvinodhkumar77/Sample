using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using Desko.FullPage;

namespace SampleNet
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        #region Helpers


        public void onOperationResult(object sender, EventArgsOperationResult eventArgs)
        {
            if (eventArgs.Result.Result == Result.Success)
            {
                stateLabelLastResult.State = LabelState.Good;
                labelLastResultMessage.Text = null;
            }
            else
            {
                stateLabelLastResult.State = LabelState.Bad;
                stateLabelLastResult.Text = eventArgs.Result.Result.ToString();
                labelLastResultMessage.Text = eventArgs.Result.Message;
                logTextControl.AppendTicksLine("Operation failed: " + eventArgs.Result.Result.ToString() + " " + eventArgs.Result.Message);
            }
        }
        //---------------------------------------------------------------------------------------

        public class SystemInfoEntry
        {
            public SystemInfoEntry(string feature, string value)
            {
                Feature = feature;
                Value = value;
            }
            public string Feature { get; set; }
            public string Value { get; set; }
        }

        #endregion

        void updateDeviceInfo()
        {

            bool connected = Api.IsDeviceConnected();

            List<SystemInfoEntry> list = new List<SystemInfoEntry>();
            list.Add(new SystemInfoEntry("API", Api.GetProperty(PropertyKey.ApiVersionString, "n/a")));
            list.Add(new SystemInfoEntry("DLL", String.Format("{0} ({1} {2})",
                Api.GetProperty(PropertyKey.DllVersionString, "?"),
                Api.GetProperty(PropertyKey.DllCompileDate, "?"),
                Api.GetProperty(PropertyKey.DllCompileTime, "?")
                )));


            if (connected)
            {
                list.Add(new SystemInfoEntry("Firmware", String.Format("{0} ({1} {2})",
                    Api.GetProperty(PropertyKey.DeviceFirmwareVersionString, "n/a"),
                    Api.GetProperty(PropertyKey.DeviceFirmwareDate, "n/a"),
                    Api.GetProperty(PropertyKey.DeviceFirmwareTime, "n/a")
                    )));

                list.Add(new SystemInfoEntry("S/N", Api.GetProperty(PropertyKey.DeviceSerialNumber, "n/a")));
                list.Add(new SystemInfoEntry("Production", Api.GetProperty(PropertyKey.DeviceProductionId, "n/a")));
                list.Add(new SystemInfoEntry("PCB", Api.GetProperty(PropertyKey.DevicePcbRevision, "n/a")));
                list.Add(new SystemInfoEntry("USB VID/PID", String.Format("{0}/{1}",
                    Api.GetProperty(PropertyKey.DeviceVid, (uint)0).ToString("X4"),
                    Api.GetProperty(PropertyKey.DevicePid, (uint)0).ToString("X4"))));
                list.Add(new SystemInfoEntry("Illumination",
                    String.Format(
                        "{0}.{1}/{2}",
                        Api.GetProperty(PropertyKey.DeviceIlluminationGenerationVerbose, "?"),
                        Api.GetProperty(PropertyKey.DeviceIlluminationRevisionVerbose, "?"),
                        Api.GetProperty(PropertyKey.DeviceIlluminationVariantVerbose, "?")
                    )));

                DeviceInfo info = Api.GetDeviceInfo();
                foreach (DeviceInfoFlags flag in Enum.GetValues(typeof(DeviceInfoFlags)))
                {
                    if (flag != DeviceInfoFlags.None)
                        if (0 != (flag & info.Features))
                        {
                            list.Add(new SystemInfoEntry(flag.ToString(), "YES"));
                        }
                        else
                        {
                            list.Add(new SystemInfoEntry(flag.ToString(), "NO"));
                        }
                }
            }

            dataGridViewSystemInfo.DataSource = list;
            dataGridViewSystemInfo.Columns[0].AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            dataGridViewSystemInfo.Columns[1].AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            dataGridViewSystemInfo.ClearSelection();
        }
        //---------------------------------------------------------------------------------------

        void updatePlugState(object o, PlugEventArgs args)
        {
            Tools.RunInGui(this, delegate()
            {
                if (args.State == PlugState.Plugged)
                {
                    stateLabelPlug.State = LabelState.Good;
                    if (checkBoxConnectOnPlug.Checked)
                    {
                        toggleAutoConnect();
                    }
                }
                else
                {
                    stateLabelPlug.State = LabelState.Off;
                    stateLabelConnect.State = LabelState.Off;
                    stateLabelDocState.State = LabelState.Off;
                }
                updateDeviceInfo();
            });

        }
        //---------------------------------------------------------------------------------------

        void setScanSettings()
        {


            logTextControl.AppendTicksLine("Setting scan settings...");
            Refresh();
            ScanSettings settings = new ScanSettings();

            {
                ScanLightFlags flags = ScanLightFlags.None;
                if (checkBoxInfrared.Checked || checkBoxMrzOnScan.Checked || analysisControl.checkBoxB900Ink.Checked)
                {
                    flags |= ScanLightFlags.Use;
                }
                if (checkBoxAntiBg.Checked)
                {
                    flags |= ScanLightFlags.AmbientLightElimination;
                }
                settings.Infrared = flags;
            }
            {
                ScanLightFlags flags = ScanLightFlags.None;
                if (checkBoxVisible.Checked)
                {
                    flags |= ScanLightFlags.Use;
                }
                if (checkBoxAntiBg.Checked)
                {
                    flags |= ScanLightFlags.AmbientLightElimination;
                }
                settings.Visible = flags;
            }
            {
                ScanLightFlags flags = ScanLightFlags.None;
                if (checkBoxUltraviolet.Checked || analysisControl.checkBoxUvDull.Checked)
                {
                    flags |= ScanLightFlags.Use;
                }
                if (checkBoxAntiBg.Checked)
                {
                    flags |= ScanLightFlags.AmbientLightElimination;
                }
                settings.Ultraviolet = flags;
            }

            if (comboBoxResolution.Text == "high")
            {
                settings.Resolution = ScanResolution.High;
            }
            else if (comboBoxResolution.Text == "default")
            {
                settings.Resolution = ScanResolution.Default;
            }
            else if (comboBoxResolution.Text == "low")
            {
                settings.Resolution = ScanResolution.Low;
            }
            else
            {
                throw new PsaException(Result.Fail, "invalid resolution: " + comboBoxResolution.SelectedText);
            }

            Api.SetScanSettings(settings);
            logTextControl.AppendTicksLine("Scan settings done.");
            Refresh();

        }
        //---------------------------------------------------------------------------------------

        bool skipUpdate = false;
        void updateScanSettings(object o, EventArgs args)
        {
            Tools.HandleApiExceptions(delegate()
            {
                if (Api.IsDeviceConnected() && !skipUpdate)
                {
                    setScanSettings();
                }
            });
        }
        //---------------------------------------------------------------------------------------

        private void FormMain_Load(object sender, EventArgs e)
        {
            Tools.OnOperationResultAvailable += onOperationResult;
            this.Text = this.Text + " – DLL: " + Api.GetApiInfo().DllVersion;

            Api.OnDevicePlugged += updatePlugState;
            checkBoxInfrared.CheckedChanged += updateScanSettings;
            checkBoxAntiBg.CheckedChanged += updateScanSettings;
            checkBoxVisible.CheckedChanged += updateScanSettings;
            checkBoxUltraviolet.CheckedChanged += updateScanSettings;
            comboBoxResolution.SelectedIndexChanged += updateScanSettings;
            checkBoxMrzOnScan.CheckedChanged += updateScanSettings;



            analysisControl.checkBoxVisMoved.Checked = false;
            analysisControl.checkBoxVisMoved.Enabled = false;
            analysisControl.checkBoxIrMoved.Checked = false;
            analysisControl.checkBoxIrMoved.Enabled = false;


            Api.OnDocumentPresent += onDocPresented;
            Api.OnDocumentRemove += onDocRemoved;
            Api.OnOcr += onOcr;
            Api.OnMsr += onMsr;
            Api.OnBarcode += onBcr;
            Api.OnTouchDown += onTouchDown;
            Api.OnTouchUp += onTouchUp;

            splitContainer.Panel2Collapsed = true;

            updateDeviceInfo();

        }
        //---------------------------------------------------------------------------------------

        private void buttonConnect_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                logTextControl.AppendTicksLine("Connecting...");
                Refresh();
                stateLabelConnect.State = LabelState.Off;
                stateLabelDocState.State = LabelState.Off;
                Api.ConnectToDevice();
                setScanSettings();

                DeviceInfo info = Api.GetDeviceInfo();
                logTextControl.AppendTicksLine("FW: " + info.Version.ToString("X8") + "." + info.Number.ToString("X8"));
                logTextControl.AppendTicksLine("Date/Time: " + info.CompileDate + " / " + info.CompileTime);
                logTextControl.AppendTicksLine("VID/PID: " + info.Vid.ToString("X4") + " / " + info.Pid.ToString("X4"));
                logTextControl.AppendTicksLine("Features: " + info.Features.ToString());
                int generation = Api.GetPropertyInt(PropertyKey.DeviceIlluminationGeneration);
                int revision = Api.GetPropertyInt(PropertyKey.DeviceIlluminationRevision);
                int variant = Api.GetPropertyInt(PropertyKey.DeviceIlluminationVariant);
                string variantVerb = Api.GetPropertyString(PropertyKey.DeviceIlluminationVariantVerbose);
                logTextControl.AppendTicksLine("Illumination: " + generation + "." + revision + "/" + variant + "(" + variantVerb + ")");
                if (generation >= 4 && revision >= 3)
                {
                    controlScanLightInfrared.ShowMoveInfo = true;
                    controlScanLightVisible.ShowMoveInfo = true;
                    analysisControl.checkBoxVisMoved.Enabled = true;
                    analysisControl.checkBoxIrMoved.Enabled = true;
                }
                else
                {
                    controlScanLightInfrared.ShowMoveInfo = false;
                    controlScanLightVisible.ShowMoveInfo = false;
                    analysisControl.checkBoxVisMoved.Checked = false;
                    analysisControl.checkBoxVisMoved.Enabled = false;
                    analysisControl.checkBoxIrMoved.Checked = false;
                    analysisControl.checkBoxIrMoved.Enabled = false;
                }

                updateDeviceInfo();
                stateLabelConnect.State = LabelState.Good;
                logTextControl.AppendTicksLine("Connected.");
            });
        }
        //---------------------------------------------------------------------------------------

        private void buttonDisconnect_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                logTextControl.AppendTicksLine("Disconnecting...");
                Refresh();
                Api.DisconnectFromDevice();
                stateLabelConnect.State = LabelState.Off;
                stateLabelDocState.State = LabelState.Off;
                logTextControl.AppendTicksLine("Disconnected.");
                updateDeviceInfo();
            });
        }
        //---------------------------------------------------------------------------------------

        void buzzerStart()
        {
            if (!checkBoxBuzzer.Checked) return;

            BuzzerSettings settings = new BuzzerSettings();
            settings.Duration = 50;
            settings.HighTime = 5;
            settings.LowTime = 5;
            settings.Volume = 255;

            Api.SetBuzzer(settings);
            Api.UseBuzzer();
        }
        //---------------------------------------------------------------------------------------

        void buzzerReady()
        {
            if (!checkBoxBuzzer.Checked) return;

            BuzzerSettings settings = new BuzzerSettings();
            settings.Duration = 100;
            settings.HighTime = 100;
            settings.LowTime = 0;
            settings.Volume = 255;
            Api.SetBuzzer(settings);
            Api.UseBuzzer();
        }
        //---------------------------------------------------------------------------------------

        void onScanOcr()
        {
            if (checkBoxMrzOnScan.Checked)
            {
                logTextControl.AppendTicksLine("MRZ...");

                string mrz = Api.GetOcrPc();
                if (mrz == null)
                {
                    mrz = "<none>";
                }
                else
                {
                    analysisControl.RunForMrz(mrz.Replace("\r", "\r\n"));
                    textBoxMrzPc.Text = mrz.Replace("\r", "\r\n");
                }
                logTextControl.AppendTicksLine(mrz.Replace('\r', '|'));
                Refresh();
            }
        }
        //---------------------------------------------------------------------------------------

        void scan()
        {
            Tools.HandleApiExceptions(delegate()
            {
                controlScanLightInfrared.Clear();
                controlScanLightVisible.Clear();
                controlScanLightUv.Clear();
                controlScanLightFace.Clear();
                textBoxMrzPc.Clear();
                analysisControl.Clear();
                logTextControl.AppendTicksLine("Scan...");
                Refresh();

                buzzerStart();

                Api.Scan();
                logTextControl.AppendTicksLine("Scan done.");
                Refresh();

                buzzerReady();

                if (analysisControl.checkBoxPixelDensity.Checked)
                {
                    var dens = Api.GetCurrentPixelPerMeter();
                    analysisControl.stateLabelPixelDensityPpm.Text = String.Format("{0} x {1} [pm/m] ", dens.X, dens.Y);
                    analysisControl.stateLabelPixelDensityDpi.Text = String.Format("{0:0.#} x {1:0.#} [dpi] ", dens.X * 0.0254f, dens.Y * 0.0254f);
                }

                onScanOcr();

                if (checkBoxInfrared.Checked)
                {
                    logTextControl.AppendTicksLine("GetImage IR...");

                    var ctrl = controlScanLightInfrared;
                    var lght = LightSource.Infrared;

                    if (ctrl.ShowMoveInfo)
                    {
                        ctrl.MoveDelta = Api.EstimateDocumentMotion(lght);
                        if (analysisControl.checkBoxIrMoved.Checked)
                        {
                            string text = String.Format("{0:0.##}", ctrl.MoveDelta);
                            if (ctrl.MoveDelta > 0.1)
                            {
                                analysisControl.stateLabelIrMoved.State = LabelState.Bad;
                            }
                            else if (ctrl.MoveDelta < 0.0)
                                analysisControl.stateLabelIrMoved.State = LabelState.Attention;
                            else
                                analysisControl.stateLabelIrMoved.State = LabelState.Good;

                            analysisControl.stateLabelIrMoved.Text = text;

                        }
                    }

                    if (!checkBoxDocCrop.Checked)
                    {
                        ctrl.Full = Api.GetImage(
                            lght,
                            ImageClipping.None);
                        logTextControl.AppendTicksLine("GetImage IR done.");

                        Refresh();
                    }
                    try
                    {
                        if (checkBoxDocCrop.Checked)
                        {
                            logTextControl.AppendTicksLine("GetImage IR doc crop...");

                            ctrl.Full = Api.GetImage(
                                lght,
                                ImageClipping.Document);
                            logTextControl.AppendTicksLine("GetImage IR doc crop done.");
                            Refresh();



                        }

                        if (analysisControl.checkBoxClippedShape.Checked)
                        {
                            try
                            {
                                analysisControl.stateLabelClippedShape.Text = Api.GetClippedDocumentShape().ToString();
                            }
                            catch (PsaException ex)
                            {
                            }


                        }
                        if (analysisControl.checkBoxClippedSize.Checked)
                        {
                            try
                            {

                                var sizePair = Api.GetClippedDocumentSizeMillimeters();
                                analysisControl.stateLabelClippedSize.Text = String.Format("{0:0.#} mm x {1:0.#} mm", sizePair.X, sizePair.Y);
                            }
                            catch (PsaException ex)
                            {
                            }

                        }
                    }
                    catch (PsaException ex) { }
                }
                Refresh();

                ////

                if (checkBoxVisible.Checked)
                {
                    var ctrl = controlScanLightVisible;
                    var lightSource = LightSource.Visible;

                    logTextControl.AppendTicksLine("GetImage VIS...");
                    Refresh();

                    if (ctrl.ShowMoveInfo)
                    {
                        if (ctrl.ShowMoveInfo)
                        {
                            ctrl.MoveDelta = Api.EstimateDocumentMotion(lightSource);
                            if (analysisControl.checkBoxIrMoved.Checked)
                            {
                                if (ctrl.MoveDelta > 0.1)
                                    analysisControl.stateLabelVisMoved.State = LabelState.Bad;
                                else if (ctrl.MoveDelta < 0.0)
                                    analysisControl.stateLabelVisMoved.State = LabelState.Attention;
                                else
                                    analysisControl.stateLabelVisMoved.State = LabelState.Good;

                                analysisControl.stateLabelVisMoved.Text = String.Format("{0:0.##}", ctrl.MoveDelta);
                            }
                        }

                    }

                    if (!checkBoxDocCrop.Checked)
                    {

                        ctrl.Full = Api.GetImage(
                            lightSource,
                            ImageClipping.None);

                        logTextControl.AppendTicksLine("GetImage VIS done.");

                        Refresh();
                    }

                    try
                    {
                        if (checkBoxDocCrop.Checked)
                        {
                            logTextControl.AppendTicksLine("GetImage VIS doc crop...");

                            ctrl.Full = Api.GetImage(
                                lightSource,
                                ImageClipping.Document);
                            Refresh();
                            logTextControl.AppendTicksLine("GetImage VIS doc crop done.");

                        }
                        if (checkBoxFaceCrop.Checked)
                        {
                            logTextControl.AppendTicksLine("GetImage VIS face crop...");

                            controlScanLightFace.Full = Api.GetImage(
                                lightSource,
                                ImageClipping.Face);
                            logTextControl.AppendTicksLine("GetImage VIS face crop done.");
                            Refresh();
                        }
                    }
                    catch (PsaException ex) { }
                }

                ////

                if (checkBoxUltraviolet.Checked)
                {
                    var ctrl = controlScanLightUv;
                    var lght = LightSource.Ultraviolet;

                    logTextControl.AppendTicksLine("GetImage UV...");
                    Refresh();

                    if (!checkBoxDocCrop.Checked)
                    {

                        ctrl.Full = Api.GetImage(
                            lght,
                            ImageClipping.None);
                        logTextControl.AppendTicksLine("GetImage UV done.");


                        Refresh();
                    }
                    try
                    {
                        if (checkBoxDocCrop.Checked)
                        {
                            logTextControl.AppendTicksLine("GetImage UV doc crop...");
                            ctrl.Full = Api.GetImage(
                                lght,
                                ImageClipping.Document);
                            logTextControl.AppendTicksLine("GetImage UV doc crop done.");
                            Refresh();
                        }
                    }
                    catch (PsaException ex) { }
                }
                Refresh();

                if (analysisControl.checkBoxB900Ink.Checked)
                {
                    try
                    {
                        if (Api.CheckB900Ink())
                        {
                            analysisControl.stateLabelB900Ink.State = LabelState.Good;
                            logTextControl.AppendTicksLine("B900 Ink: found.");
                        }
                        else
                        {
                            analysisControl.stateLabelB900Ink.State = LabelState.Bad;
                            logTextControl.AppendTicksLine("B900 Ink: missing.");
                        }
                    }
                    catch (PsaException ex)
                    {
                        analysisControl.stateLabelB900Ink.State = LabelState.Off;
                        logTextControl.AppendTicksLine("B900 Ink: " + ex.Message);
                    }
                }

                if (analysisControl.checkBoxUvDull.Checked)
                    try
                    {
                        if (Api.CheckUvDullness())
                        {
                            analysisControl.stateLabelUvDull.State = LabelState.Good;
                            logTextControl.AppendTicksLine("UV paper: dull.");
                        }
                        else
                        {
                            analysisControl.stateLabelUvDull.State = LabelState.Bad;
                            logTextControl.AppendTicksLine("UV paper: bright.");
                        }
                    }
                    catch (PsaException ex)
                    {
                        analysisControl.stateLabelUvDull.State = LabelState.Off;
                        logTextControl.AppendTicksLine("UV paper: " + ex.Message);
                    }

                Refresh();

                ////
            });
        }

        private void buttonScan_Click(object sender, EventArgs e)
        {
            scan();
        }
        //---------------------------------------------------------------------------------------

        private void buttonClear_Click(object sender, EventArgs e)
        {
            controlScanLightInfrared.Clear();
            controlScanLightVisible.Clear();
            controlScanLightUv.Clear();
            controlScanLightFace.Clear();
            textBoxMrzPc.Clear();
            textBox.Clear();
            analysisControl.Clear();
        }
        //---------------------------------------------------------------------------------------

        void onDocPresented(object sender, EventArgs args)
        {
            Tools.RunInGui(this, delegate()
            {
                logTextControl.AppendTicksLine("DOC ON");
                stateLabelDocState.State = LabelState.Good;
                Tools.HandleApiExceptions(delegate()
                {

                    if (checkBoxTriggerOnDoc.Checked)
                    {
                        scan();
                    }
                });
            });
        }
        //---------------------------------------------------------------------------------------

        void onDocRemoved(object sender, EventArgs args)
        {
            Tools.RunInGui(this, delegate()
            {
                logTextControl.AppendTicksLine("DOC OFF");
                stateLabelDocState.State = LabelState.Bad;
            });
        }
        //---------------------------------------------------------------------------------------

        
        Desko.Mrz.SubstitutionRules mapIcaoCountries = null;
        //---------------------------------------------------------------------------------------


        void onOcr(object sender, OcrEventArgs args)
        {
            Tools.RunInGui(this, delegate()
            {
                logTextControl.AppendTicksLine("OCR: " + args.Data.Replace('\r', '|'));
                textBox.AppendText(args.Data.Replace("\r", "\r\n"));
                analysisControl.RunForMrz(args.Data.Replace("\r", "\r\n") + "\r\n");
            });
        }
        //---------------------------------------------------------------------------------------

        void onMsr(object sender, MsrEventArgs args)
        {
            Tools.RunInGui(this, delegate()
            {
                string theText = Tools.MaskNonAscii(args.Data);
                logTextControl.AppendTicksLine("MSR: " + theText);
                textBox.AppendText(theText + "\r\n");
            });
        }
        //---------------------------------------------------------------------------------------

        void onBcr(object sender, BarcodeEventArgs args)
        {
            Tools.RunInGui(this, delegate()
            {
                string theText = Tools.MaskNonAscii(args.Data);
                logTextControl.AppendTicksLine("BCR: " + theText);
                textBox.AppendText(theText + "\r\n");
            });
        }
        //---------------------------------------------------------------------------------------

        void onTouchDown(object sender, TouchEventArgs args)
        {
            Tools.RunInGui(this, delegate()
            {
                string theText = String.Format("TOUCH DOWN ({0},{1})", args.Position.X, args.Position.Y);
                logTextControl.AppendTicksLine(theText);
                textBox.AppendText(theText + "\r\n");
            });
        }
        //---------------------------------------------------------------------------------------

        void onTouchUp(object sender, TouchEventArgs args)
        {
            Tools.RunInGui(this, delegate()
            {
                string theText = String.Format("TOUCH UP   ({0},{1})", args.Position.X, args.Position.Y);
                logTextControl.AppendTicksLine(theText);
                textBox.AppendText(theText + "\r\n");
            });
        }
        //---------------------------------------------------------------------------------------

        private void checkBoxListenDocOn_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBoxListenDocOn.Checked)
                Api.OnDocumentPresent += onDocPresented;
            else
            {
                Api.OnDocumentPresent -= onDocPresented;
                stateLabelDocState.State = LabelState.Off;
            }
        }
        //---------------------------------------------------------------------------------------

        private void checkBoxListenDocOff_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBoxListenDocOn.Checked)
                Api.OnDocumentRemove += onDocRemoved;
            else
            {
                Api.OnDocumentRemove -= onDocRemoved;
            }
        }
        //---------------------------------------------------------------------------------------

        private void checkBoxListenMrz_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBoxListenMrz.Checked)
                Api.OnOcr += onOcr;
            else
                Api.OnOcr -= onOcr;
        }
        //---------------------------------------------------------------------------------------

        private void checkBoxListenMsr_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBoxListenMsr.Checked)
                Api.OnMsr += onMsr;
            else
                Api.OnMsr -= onMsr;
        }
        //---------------------------------------------------------------------------------------

        private void checkBoxListenBcr_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBoxListenBcr.Checked)
                Api.OnBarcode += onBcr;
            else
                Api.OnBarcode -= onBcr;
        }
        //---------------------------------------------------------------------------------------

        private void checkBoxListenTouchDown_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBoxListenBcr.Checked)
                Api.OnTouchDown += onTouchDown;
            else
                Api.OnTouchDown -= onTouchDown;
        }
        //---------------------------------------------------------------------------------------

        private void checkBoxListenTouchUp_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBoxListenBcr.Checked)
                Api.OnTouchUp += onTouchUp;
            else
                Api.OnTouchUp -= onTouchUp;
        }
        //---------------------------------------------------------------------------------------

        private void buttonQuickMrz_Click(object sender, EventArgs e)
        {
            buttonClear_Click(sender, e);
            Tools.HandleApiExceptions(delegate()
            {
                skipUpdate = true;
                try
                {
                    comboBoxResolution.SelectedIndex = 1;
                    checkBoxInfrared.Checked = true;
                    checkBoxVisible.Checked = false;
                    checkBoxUltraviolet.Checked = false;
                    checkBoxAntiBg.Checked = false;
                    checkBoxDocCrop.Checked = false;
                    checkBoxFaceCrop.Checked = false;
                    checkBoxTriggerOnDoc.Checked = true;
                    checkBoxMrzOnScan.Checked = true;
                    checkBoxBuzzer.Checked = true;
                    analysisControl.checkBoxB900Ink.Checked = false;
                    analysisControl.checkBoxUvDull.Checked = false;
                    analysisControl.checkBoxAutoParse.Checked = true;
                    analysisControl.checkBoxIrMoved.Checked = false;
                    analysisControl.checkBoxVisMoved.Checked = false;
                    analysisControl.checkBoxClippedShape.Checked = false;
                    analysisControl.checkBoxClippedSize.Checked = false;
                    analysisControl.checkBoxPixelDensity.Checked = false;
                    checkBoxListenMrz.Checked = false;
                    checkBoxListenBcr.Checked = false;
                    checkBoxListenMsr.Checked = false;
                    tabControlMain.SelectedTab = tabPageMrz;

                }
                finally
                {
                    skipUpdate = false;
                }
                if (Api.IsDeviceConnected() && !skipUpdate)
                {
                    setScanSettings();
                }
            });
        }
        //---------------------------------------------------------------------------------------

        private void buttonQuickCroppedMrz_Click(object sender, EventArgs e)
        {
            buttonClear_Click(sender, e);
            Tools.HandleApiExceptions(delegate()
            {
                skipUpdate = true;
                try
                {
                    comboBoxResolution.SelectedIndex = 0;
                    checkBoxInfrared.Checked = true;
                    checkBoxVisible.Checked = true;
                    checkBoxUltraviolet.Checked = true;
                    checkBoxAntiBg.Checked = true;
                    checkBoxDocCrop.Checked = true;
                    checkBoxFaceCrop.Checked = true;
                    checkBoxTriggerOnDoc.Checked = true;
                    checkBoxMrzOnScan.Checked = true;
                    checkBoxBuzzer.Checked = true;
                    analysisControl.checkBoxB900Ink.Checked = true;
                    analysisControl.checkBoxUvDull.Checked = true;
                    analysisControl.checkBoxAutoParse.Checked = true;
                    analysisControl.checkBoxIrMoved.Checked = true;
                    analysisControl.checkBoxVisMoved.Checked = true;
                    analysisControl.checkBoxClippedShape.Checked = true;
                    analysisControl.checkBoxClippedSize.Checked = true;
                    analysisControl.checkBoxPixelDensity.Checked = true;
                    checkBoxListenMrz.Checked = false;
                    checkBoxListenBcr.Checked = false;
                    checkBoxListenMsr.Checked = false;
                    tabControlMain.SelectedTab = tabPageScan;
                }
                finally
                {
                    skipUpdate = false;
                }
                if (Api.IsDeviceConnected() && !skipUpdate)
                {
                    setScanSettings();
                }
            });
        }
        //---------------------------------------------------------------------------------------

        private void buttonQuickFullImages_Click(object sender, EventArgs e)
        {
            buttonClear_Click(sender, e);
            Tools.HandleApiExceptions(delegate()
            {
                skipUpdate = true;
                try
                {
                    comboBoxResolution.SelectedIndex = 0;
                    checkBoxInfrared.Checked = true;
                    checkBoxVisible.Checked = true;
                    checkBoxUltraviolet.Checked = true;
                    checkBoxAntiBg.Checked = true;
                    checkBoxDocCrop.Checked = false;
                    checkBoxFaceCrop.Checked = false;
                    checkBoxTriggerOnDoc.Checked = true;
                    checkBoxMrzOnScan.Checked = false;
                    checkBoxBuzzer.Checked = true;
                    analysisControl.checkBoxB900Ink.Checked = false;
                    analysisControl.checkBoxUvDull.Checked = false;
                    analysisControl.checkBoxAutoParse.Checked = false;
                    analysisControl.checkBoxIrMoved.Checked = false;
                    analysisControl.checkBoxVisMoved.Checked = false;
                    analysisControl.checkBoxClippedShape.Checked = false;
                    analysisControl.checkBoxClippedSize.Checked = false;
                    analysisControl.checkBoxPixelDensity.Checked = false;
                    checkBoxListenMrz.Checked = false;
                    checkBoxListenBcr.Checked = false;
                    checkBoxListenMsr.Checked = false;
                    tabControlMain.SelectedTab = tabPageScan;

                }
                finally
                {
                    skipUpdate = false;
                }
                if (Api.IsDeviceConnected() && !skipUpdate)
                {
                    setScanSettings();
                }
            });
        }
        //---------------------------------------------------------------------------------------

        private void buttonQuickCroppedIamges_Click(object sender, EventArgs e)
        {
            buttonClear_Click(sender, e);
            Tools.HandleApiExceptions(delegate()
            {
                skipUpdate = true;
                try
                {
                    comboBoxResolution.SelectedIndex = 0;
                    checkBoxInfrared.Checked = true;
                    checkBoxVisible.Checked = true;
                    checkBoxUltraviolet.Checked = true;
                    checkBoxAntiBg.Checked = true;
                    checkBoxDocCrop.Checked = true;
                    checkBoxFaceCrop.Checked = true;
                    checkBoxTriggerOnDoc.Checked = true;
                    checkBoxMrzOnScan.Checked = false;
                    checkBoxBuzzer.Checked = true;
                    analysisControl.checkBoxB900Ink.Checked = false;
                    analysisControl.checkBoxUvDull.Checked = false;
                    analysisControl.checkBoxAutoParse.Checked = false;
                    analysisControl.checkBoxIrMoved.Checked = false;
                    analysisControl.checkBoxVisMoved.Checked = false;
                    analysisControl.checkBoxClippedShape.Checked = false;
                    analysisControl.checkBoxClippedSize.Checked = false;
                    analysisControl.checkBoxPixelDensity.Checked = false;
                    checkBoxListenMrz.Checked = false;
                    checkBoxListenBcr.Checked = false;
                    checkBoxListenMsr.Checked = false;
                    tabControlMain.SelectedTab = tabPageScan;

                }
                finally
                {
                    skipUpdate = false;
                }
                if (Api.IsDeviceConnected() && !skipUpdate)
                {
                    setScanSettings();
                }
            });
        }
        //---------------------------------------------------------------------------------------

        private void buttonQuickAnalysis_Click(object sender, EventArgs e)
        {
            buttonClear_Click(sender, e);
            Tools.HandleApiExceptions(delegate()
            {
                skipUpdate = true;
                try
                {
                    comboBoxResolution.SelectedIndex = 1;
                    checkBoxAntiBg.Checked = true;
                    checkBoxDocCrop.Checked = false;
                    checkBoxFaceCrop.Checked = false;
                    checkBoxTriggerOnDoc.Checked = true;
                    checkBoxMrzOnScan.Checked = true;
                    checkBoxBuzzer.Checked = true;
                    analysisControl.checkBoxB900Ink.Checked = true;
                    analysisControl.checkBoxUvDull.Checked = true;
                    analysisControl.checkBoxAutoParse.Checked = true;
                    analysisControl.checkBoxIrMoved.Checked = true;
                    analysisControl.checkBoxVisMoved.Checked = true;
                    analysisControl.checkBoxClippedShape.Checked = true;
                    analysisControl.checkBoxClippedSize.Checked = true;
                    analysisControl.checkBoxPixelDensity.Checked = true;
                    checkBoxListenMrz.Checked = false;
                    checkBoxListenBcr.Checked = false;
                    checkBoxListenMsr.Checked = false;

                    tabControlMain.SelectedTab = tabPageMrz;

                }
                finally
                {
                    skipUpdate = false;
                }
                if (Api.IsDeviceConnected() && !skipUpdate)
                {
                    setScanSettings();
                }
            });
        }
        //---------------------------------------------------------------------------------------

        private void buttonDataEvents_Click(object sender, EventArgs e)
        {
            buttonClear_Click(sender, e);
            Tools.HandleApiExceptions(delegate()
            {
                skipUpdate = true;
                try
                {
                    comboBoxResolution.SelectedIndex = 1;
                    checkBoxInfrared.Checked = false;
                    checkBoxVisible.Checked = false;
                    checkBoxUltraviolet.Checked = false;
                    checkBoxAntiBg.Checked = false;
                    checkBoxDocCrop.Checked = false;
                    checkBoxFaceCrop.Checked = false;
                    checkBoxTriggerOnDoc.Checked = false;
                    checkBoxMrzOnScan.Checked = false;
                    checkBoxBuzzer.Checked = true;
                    analysisControl.checkBoxB900Ink.Checked = false;
                    analysisControl.checkBoxUvDull.Checked = false;
                    analysisControl.checkBoxAutoParse.Checked = true;
                    analysisControl.checkBoxIrMoved.Checked = false;
                    analysisControl.checkBoxVisMoved.Checked = false;
                    analysisControl.checkBoxClippedShape.Checked = false;
                    analysisControl.checkBoxClippedSize.Checked = false;
                    analysisControl.checkBoxPixelDensity.Checked = false;
                    checkBoxListenMrz.Checked = true;
                    checkBoxListenBcr.Checked = true;
                    checkBoxListenMsr.Checked = true;

                    tabControlMain.SelectedTab = tabPageEvents;


                }
                finally
                {
                    skipUpdate = false;
                }
                if (Api.IsDeviceConnected() && !skipUpdate)
                {
                    setScanSettings();
                }
            });
        }
        //---------------------------------------------------------------------------------------

        private void buttonShowLog_Click(object sender, EventArgs e)
        {
            splitContainer.Panel2Collapsed = !splitContainer.Panel2Collapsed;
        }
        //---------------------------------------------------------------------------------------

        private void tabControlMain_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControlMain.SelectedTab == tabPageFeedback)
            {
                Api.OnTouchDown += feedbackControl.OnTouchDown;
                Api.OnTouchUp += feedbackControl.OnTouchUp;
            }
            else
            {

                Api.OnTouchDown -= feedbackControl.OnTouchDown;
                Api.OnTouchUp -= feedbackControl.OnTouchUp;

            }
        }

        bool autoconnect = false;

        void toggleAutoConnect()
        {
            lock (this)
            {

                autoconnect = true;
            }
        }


        private void timerConnector_Tick(object sender, EventArgs e)
        {

            bool doIt = false;
            lock (this)
            {
                doIt = autoconnect;
                autoconnect = false;
            }

            if (doIt)
            {
                buttonConnect_Click(this, new EventArgs());
            }

        }
        //---------------------------------------------------------------------------------------





    }
}
