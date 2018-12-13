namespace SampleNet
{
    partial class FormMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
            this.panelHead = new System.Windows.Forms.Panel();
            this.buttonShowLog = new System.Windows.Forms.Button();
            this.buttonDisconnect = new System.Windows.Forms.Button();
            this.buttonConnect = new System.Windows.Forms.Button();
            this.buttonClear = new System.Windows.Forms.Button();
            this.buttonScan = new System.Windows.Forms.Button();
            this.panelStatus = new System.Windows.Forms.Panel();
            this.labelLastResultMessage = new System.Windows.Forms.Label();
            this.splitContainer = new System.Windows.Forms.SplitContainer();
            this.tabControlMain = new System.Windows.Forms.TabControl();
            this.tabPageInfoSetup = new System.Windows.Forms.TabPage();
            this.tableLayoutPanel3 = new System.Windows.Forms.TableLayoutPanel();
            this.label2 = new System.Windows.Forms.Label();
            this.dataGridViewSystemInfo = new System.Windows.Forms.DataGridView();
            this.buttonQuickMrz = new System.Windows.Forms.Button();
            this.buttonQuickCroppedIamges = new System.Windows.Forms.Button();
            this.buttonQuickFullImages = new System.Windows.Forms.Button();
            this.buttonQuickCroppedMrz = new System.Windows.Forms.Button();
            this.buttonQuickAnalysis = new System.Windows.Forms.Button();
            this.buttonDataEvents = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.tabPageScan = new System.Windows.Forms.TabPage();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.checkBoxTriggerOnDoc = new System.Windows.Forms.CheckBox();
            this.comboBoxResolution = new System.Windows.Forms.ComboBox();
            this.checkBoxInfrared = new System.Windows.Forms.CheckBox();
            this.checkBoxVisible = new System.Windows.Forms.CheckBox();
            this.checkBoxUltraviolet = new System.Windows.Forms.CheckBox();
            this.checkBoxDocCrop = new System.Windows.Forms.CheckBox();
            this.checkBoxAntiBg = new System.Windows.Forms.CheckBox();
            this.checkBoxFaceCrop = new System.Windows.Forms.CheckBox();
            this.checkBoxMrzOnScan = new System.Windows.Forms.CheckBox();
            this.checkBoxBuzzer = new System.Windows.Forms.CheckBox();
            this.textBoxMrzPc = new System.Windows.Forms.TextBox();
            this.tabPageEvents = new System.Windows.Forms.TabPage();
            this.tableLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this.checkBoxListenTouchUp = new System.Windows.Forms.CheckBox();
            this.checkBoxListenTouchDown = new System.Windows.Forms.CheckBox();
            this.checkBoxListenDocOff = new System.Windows.Forms.CheckBox();
            this.textBox = new System.Windows.Forms.TextBox();
            this.checkBoxListenMrz = new System.Windows.Forms.CheckBox();
            this.checkBoxListenDocOn = new System.Windows.Forms.CheckBox();
            this.checkBoxListenBcr = new System.Windows.Forms.CheckBox();
            this.checkBoxListenMsr = new System.Windows.Forms.CheckBox();
            this.tabPageMrz = new System.Windows.Forms.TabPage();
            this.tabPageFeedback = new System.Windows.Forms.TabPage();
            this.checkBoxConnectOnPlug = new System.Windows.Forms.CheckBox();
            this.controlScanLightFace = new SampleNet.ControlScanLight();
            this.controlScanLightInfrared = new SampleNet.ControlScanLight();
            this.controlScanLightVisible = new SampleNet.ControlScanLight();
            this.controlScanLightUv = new SampleNet.ControlScanLight();
            this.analysisControl = new SampleNet.MrzControl();
            this.feedbackControl = new SampleNet.FeedbackControl();
            this.logTextControl = new SampleNet.LogTextControl();
            this.stateLabelLastResult = new SampleNet.StateLabel();
            this.stateLabelDocState = new SampleNet.StateLabel();
            this.stateLabelConnect = new SampleNet.StateLabel();
            this.stateLabelPlug = new SampleNet.StateLabel();
            this.timerConnector = new System.Windows.Forms.Timer(this.components);
            this.panelHead.SuspendLayout();
            this.panelStatus.SuspendLayout();
            this.splitContainer.Panel1.SuspendLayout();
            this.splitContainer.Panel2.SuspendLayout();
            this.splitContainer.SuspendLayout();
            this.tabControlMain.SuspendLayout();
            this.tabPageInfoSetup.SuspendLayout();
            this.tableLayoutPanel3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewSystemInfo)).BeginInit();
            this.tabPageScan.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            this.flowLayoutPanel1.SuspendLayout();
            this.tabPageEvents.SuspendLayout();
            this.tableLayoutPanel.SuspendLayout();
            this.tabPageMrz.SuspendLayout();
            this.tabPageFeedback.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelHead
            // 
            this.panelHead.Controls.Add(this.stateLabelDocState);
            this.panelHead.Controls.Add(this.stateLabelConnect);
            this.panelHead.Controls.Add(this.buttonShowLog);
            this.panelHead.Controls.Add(this.stateLabelPlug);
            this.panelHead.Controls.Add(this.buttonDisconnect);
            this.panelHead.Controls.Add(this.buttonConnect);
            this.panelHead.Controls.Add(this.buttonClear);
            this.panelHead.Controls.Add(this.buttonScan);
            this.panelHead.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelHead.Location = new System.Drawing.Point(0, 0);
            this.panelHead.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.panelHead.Name = "panelHead";
            this.panelHead.Size = new System.Drawing.Size(1320, 75);
            this.panelHead.TabIndex = 2;
            // 
            // buttonShowLog
            // 
            this.buttonShowLog.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonShowLog.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonShowLog.Location = new System.Drawing.Point(1153, 7);
            this.buttonShowLog.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonShowLog.Name = "buttonShowLog";
            this.buttonShowLog.Size = new System.Drawing.Size(163, 28);
            this.buttonShowLog.TabIndex = 18;
            this.buttonShowLog.Text = "Show/hide log";
            this.buttonShowLog.UseVisualStyleBackColor = true;
            this.buttonShowLog.Click += new System.EventHandler(this.buttonShowLog_Click);
            // 
            // buttonDisconnect
            // 
            this.buttonDisconnect.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonDisconnect.Location = new System.Drawing.Point(4, 42);
            this.buttonDisconnect.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonDisconnect.Name = "buttonDisconnect";
            this.buttonDisconnect.Size = new System.Drawing.Size(81, 28);
            this.buttonDisconnect.TabIndex = 3;
            this.buttonDisconnect.Text = "Disconnect";
            this.buttonDisconnect.UseVisualStyleBackColor = true;
            this.buttonDisconnect.Click += new System.EventHandler(this.buttonDisconnect_Click);
            // 
            // buttonConnect
            // 
            this.buttonConnect.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonConnect.Location = new System.Drawing.Point(4, 6);
            this.buttonConnect.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonConnect.Name = "buttonConnect";
            this.buttonConnect.Size = new System.Drawing.Size(81, 28);
            this.buttonConnect.TabIndex = 0;
            this.buttonConnect.Text = "Connect";
            this.buttonConnect.UseVisualStyleBackColor = true;
            this.buttonConnect.Click += new System.EventHandler(this.buttonConnect_Click);
            // 
            // buttonClear
            // 
            this.buttonClear.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonClear.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonClear.Location = new System.Drawing.Point(1153, 42);
            this.buttonClear.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonClear.Name = "buttonClear";
            this.buttonClear.Size = new System.Drawing.Size(163, 28);
            this.buttonClear.TabIndex = 2;
            this.buttonClear.Text = "Clear";
            this.buttonClear.UseVisualStyleBackColor = true;
            this.buttonClear.Click += new System.EventHandler(this.buttonClear_Click);
            // 
            // buttonScan
            // 
            this.buttonScan.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonScan.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonScan.Location = new System.Drawing.Point(211, 7);
            this.buttonScan.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonScan.Name = "buttonScan";
            this.buttonScan.Size = new System.Drawing.Size(935, 63);
            this.buttonScan.TabIndex = 1;
            this.buttonScan.Text = "Scan now";
            this.buttonScan.UseVisualStyleBackColor = true;
            this.buttonScan.Click += new System.EventHandler(this.buttonScan_Click);
            // 
            // panelStatus
            // 
            this.panelStatus.Controls.Add(this.stateLabelLastResult);
            this.panelStatus.Controls.Add(this.labelLastResultMessage);
            this.panelStatus.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panelStatus.Location = new System.Drawing.Point(0, 1116);
            this.panelStatus.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.panelStatus.Name = "panelStatus";
            this.panelStatus.Size = new System.Drawing.Size(1320, 37);
            this.panelStatus.TabIndex = 3;
            // 
            // labelLastResultMessage
            // 
            this.labelLastResultMessage.AutoSize = true;
            this.labelLastResultMessage.Location = new System.Drawing.Point(93, 10);
            this.labelLastResultMessage.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelLastResultMessage.Name = "labelLastResultMessage";
            this.labelLastResultMessage.Size = new System.Drawing.Size(20, 17);
            this.labelLastResultMessage.TabIndex = 3;
            this.labelLastResultMessage.Text = "...";
            // 
            // splitContainer
            // 
            this.splitContainer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer.Location = new System.Drawing.Point(0, 75);
            this.splitContainer.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.splitContainer.Name = "splitContainer";
            this.splitContainer.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer.Panel1
            // 
            this.splitContainer.Panel1.Controls.Add(this.tabControlMain);
            // 
            // splitContainer.Panel2
            // 
            this.splitContainer.Panel2.Controls.Add(this.logTextControl);
            this.splitContainer.Size = new System.Drawing.Size(1320, 1041);
            this.splitContainer.SplitterDistance = 708;
            this.splitContainer.SplitterWidth = 5;
            this.splitContainer.TabIndex = 4;
            // 
            // tabControlMain
            // 
            this.tabControlMain.Controls.Add(this.tabPageInfoSetup);
            this.tabControlMain.Controls.Add(this.tabPageScan);
            this.tabControlMain.Controls.Add(this.tabPageEvents);
            this.tabControlMain.Controls.Add(this.tabPageMrz);
            this.tabControlMain.Controls.Add(this.tabPageFeedback);
            this.tabControlMain.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControlMain.Location = new System.Drawing.Point(0, 0);
            this.tabControlMain.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabControlMain.Name = "tabControlMain";
            this.tabControlMain.SelectedIndex = 0;
            this.tabControlMain.Size = new System.Drawing.Size(1320, 708);
            this.tabControlMain.SizeMode = System.Windows.Forms.TabSizeMode.Fixed;
            this.tabControlMain.TabIndex = 0;
            this.tabControlMain.SelectedIndexChanged += new System.EventHandler(this.tabControlMain_SelectedIndexChanged);
            // 
            // tabPageInfoSetup
            // 
            this.tabPageInfoSetup.Controls.Add(this.tableLayoutPanel3);
            this.tabPageInfoSetup.Location = new System.Drawing.Point(4, 25);
            this.tabPageInfoSetup.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPageInfoSetup.Name = "tabPageInfoSetup";
            this.tabPageInfoSetup.Size = new System.Drawing.Size(1312, 679);
            this.tabPageInfoSetup.TabIndex = 3;
            this.tabPageInfoSetup.Text = "Info/Setup";
            this.tabPageInfoSetup.UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel3
            // 
            this.tableLayoutPanel3.ColumnCount = 6;
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.66666F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel3.Controls.Add(this.label2, 0, 2);
            this.tableLayoutPanel3.Controls.Add(this.dataGridViewSystemInfo, 0, 3);
            this.tableLayoutPanel3.Controls.Add(this.buttonQuickMrz, 2, 1);
            this.tableLayoutPanel3.Controls.Add(this.buttonQuickCroppedIamges, 4, 1);
            this.tableLayoutPanel3.Controls.Add(this.buttonQuickFullImages, 3, 1);
            this.tableLayoutPanel3.Controls.Add(this.buttonQuickCroppedMrz, 5, 1);
            this.tableLayoutPanel3.Controls.Add(this.buttonQuickAnalysis, 1, 1);
            this.tableLayoutPanel3.Controls.Add(this.buttonDataEvents, 0, 1);
            this.tableLayoutPanel3.Controls.Add(this.label1, 0, 0);
            this.tableLayoutPanel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel3.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel3.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tableLayoutPanel3.Name = "tableLayoutPanel3";
            this.tableLayoutPanel3.RowCount = 4;
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 49F));
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 49F));
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 49F));
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tableLayoutPanel3.Size = new System.Drawing.Size(1312, 679);
            this.tableLayoutPanel3.TabIndex = 20;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.tableLayoutPanel3.SetColumnSpan(this.label2, 6);
            this.label2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(4, 98);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(1304, 49);
            this.label2.TabIndex = 29;
            this.label2.Text = "System Information";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // dataGridViewSystemInfo
            // 
            this.dataGridViewSystemInfo.AllowUserToAddRows = false;
            this.dataGridViewSystemInfo.AllowUserToDeleteRows = false;
            this.dataGridViewSystemInfo.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.DisplayedCells;
            this.dataGridViewSystemInfo.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dataGridViewSystemInfo.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.dataGridViewSystemInfo.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewSystemInfo.ColumnHeadersVisible = false;
            this.tableLayoutPanel3.SetColumnSpan(this.dataGridViewSystemInfo, 6);
            this.dataGridViewSystemInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridViewSystemInfo.GridColor = System.Drawing.SystemColors.Control;
            this.dataGridViewSystemInfo.Location = new System.Drawing.Point(4, 151);
            this.dataGridViewSystemInfo.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.dataGridViewSystemInfo.Name = "dataGridViewSystemInfo";
            this.dataGridViewSystemInfo.ReadOnly = true;
            this.dataGridViewSystemInfo.RowHeadersVisible = false;
            this.dataGridViewSystemInfo.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.CellSelect;
            this.dataGridViewSystemInfo.Size = new System.Drawing.Size(1304, 524);
            this.dataGridViewSystemInfo.TabIndex = 28;
            // 
            // buttonQuickMrz
            // 
            this.buttonQuickMrz.Dock = System.Windows.Forms.DockStyle.Fill;
            this.buttonQuickMrz.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonQuickMrz.Location = new System.Drawing.Point(440, 53);
            this.buttonQuickMrz.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonQuickMrz.Name = "buttonQuickMrz";
            this.buttonQuickMrz.Size = new System.Drawing.Size(210, 41);
            this.buttonQuickMrz.TabIndex = 11;
            this.buttonQuickMrz.Text = "MRZ on PC";
            this.buttonQuickMrz.UseVisualStyleBackColor = true;
            this.buttonQuickMrz.Click += new System.EventHandler(this.buttonQuickMrz_Click);
            // 
            // buttonQuickCroppedIamges
            // 
            this.buttonQuickCroppedIamges.Dock = System.Windows.Forms.DockStyle.Fill;
            this.buttonQuickCroppedIamges.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonQuickCroppedIamges.Location = new System.Drawing.Point(876, 53);
            this.buttonQuickCroppedIamges.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonQuickCroppedIamges.Name = "buttonQuickCroppedIamges";
            this.buttonQuickCroppedIamges.Size = new System.Drawing.Size(210, 41);
            this.buttonQuickCroppedIamges.TabIndex = 15;
            this.buttonQuickCroppedIamges.Text = "Cropped";
            this.buttonQuickCroppedIamges.UseVisualStyleBackColor = true;
            this.buttonQuickCroppedIamges.Click += new System.EventHandler(this.buttonQuickCroppedIamges_Click);
            // 
            // buttonQuickFullImages
            // 
            this.buttonQuickFullImages.Dock = System.Windows.Forms.DockStyle.Fill;
            this.buttonQuickFullImages.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonQuickFullImages.Location = new System.Drawing.Point(658, 53);
            this.buttonQuickFullImages.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonQuickFullImages.Name = "buttonQuickFullImages";
            this.buttonQuickFullImages.Size = new System.Drawing.Size(210, 41);
            this.buttonQuickFullImages.TabIndex = 14;
            this.buttonQuickFullImages.Text = "Full pane";
            this.buttonQuickFullImages.UseVisualStyleBackColor = true;
            this.buttonQuickFullImages.Click += new System.EventHandler(this.buttonQuickFullImages_Click);
            // 
            // buttonQuickCroppedMrz
            // 
            this.buttonQuickCroppedMrz.Dock = System.Windows.Forms.DockStyle.Fill;
            this.buttonQuickCroppedMrz.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonQuickCroppedMrz.Location = new System.Drawing.Point(1094, 53);
            this.buttonQuickCroppedMrz.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonQuickCroppedMrz.Name = "buttonQuickCroppedMrz";
            this.buttonQuickCroppedMrz.Size = new System.Drawing.Size(214, 41);
            this.buttonQuickCroppedMrz.TabIndex = 12;
            this.buttonQuickCroppedMrz.Text = "Cropped && Analysis";
            this.buttonQuickCroppedMrz.UseVisualStyleBackColor = true;
            this.buttonQuickCroppedMrz.Click += new System.EventHandler(this.buttonQuickCroppedMrz_Click);
            // 
            // buttonQuickAnalysis
            // 
            this.buttonQuickAnalysis.Dock = System.Windows.Forms.DockStyle.Fill;
            this.buttonQuickAnalysis.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonQuickAnalysis.Location = new System.Drawing.Point(222, 53);
            this.buttonQuickAnalysis.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonQuickAnalysis.Name = "buttonQuickAnalysis";
            this.buttonQuickAnalysis.Size = new System.Drawing.Size(210, 41);
            this.buttonQuickAnalysis.TabIndex = 16;
            this.buttonQuickAnalysis.Text = "Analysis only";
            this.buttonQuickAnalysis.UseVisualStyleBackColor = true;
            this.buttonQuickAnalysis.Click += new System.EventHandler(this.buttonQuickAnalysis_Click);
            // 
            // buttonDataEvents
            // 
            this.buttonDataEvents.Dock = System.Windows.Forms.DockStyle.Fill;
            this.buttonDataEvents.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonDataEvents.Location = new System.Drawing.Point(4, 53);
            this.buttonDataEvents.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonDataEvents.Name = "buttonDataEvents";
            this.buttonDataEvents.Size = new System.Drawing.Size(210, 41);
            this.buttonDataEvents.TabIndex = 17;
            this.buttonDataEvents.Text = "Data events only";
            this.buttonDataEvents.UseVisualStyleBackColor = true;
            this.buttonDataEvents.Click += new System.EventHandler(this.buttonDataEvents_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.tableLayoutPanel3.SetColumnSpan(this.label1, 6);
            this.label1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(4, 0);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(1304, 49);
            this.label1.TabIndex = 18;
            this.label1.Text = "Quick Presets";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // tabPageScan
            // 
            this.tabPageScan.Controls.Add(this.tableLayoutPanel1);
            this.tabPageScan.Location = new System.Drawing.Point(4, 25);
            this.tabPageScan.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPageScan.Name = "tabPageScan";
            this.tabPageScan.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPageScan.Size = new System.Drawing.Size(1312, 679);
            this.tabPageScan.TabIndex = 0;
            this.tabPageScan.Text = "Scan";
            this.tabPageScan.UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 4;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 27.77778F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 27.77778F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 27.77778F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel1.Controls.Add(this.controlScanLightFace, 3, 1);
            this.tableLayoutPanel1.Controls.Add(this.controlScanLightInfrared, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.controlScanLightVisible, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.controlScanLightUv, 2, 1);
            this.tableLayoutPanel1.Controls.Add(this.flowLayoutPanel1, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.textBoxMrzPc, 1, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(4, 4);
            this.tableLayoutPanel1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 37.5F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 62.5F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(1304, 671);
            this.tableLayoutPanel1.TabIndex = 3;
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.BackColor = System.Drawing.SystemColors.Control;
            this.flowLayoutPanel1.Controls.Add(this.checkBoxTriggerOnDoc);
            this.flowLayoutPanel1.Controls.Add(this.comboBoxResolution);
            this.flowLayoutPanel1.Controls.Add(this.checkBoxInfrared);
            this.flowLayoutPanel1.Controls.Add(this.checkBoxVisible);
            this.flowLayoutPanel1.Controls.Add(this.checkBoxUltraviolet);
            this.flowLayoutPanel1.Controls.Add(this.checkBoxDocCrop);
            this.flowLayoutPanel1.Controls.Add(this.checkBoxAntiBg);
            this.flowLayoutPanel1.Controls.Add(this.checkBoxFaceCrop);
            this.flowLayoutPanel1.Controls.Add(this.checkBoxMrzOnScan);
            this.flowLayoutPanel1.Controls.Add(this.checkBoxBuzzer);
            this.flowLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flowLayoutPanel1.FlowDirection = System.Windows.Forms.FlowDirection.TopDown;
            this.flowLayoutPanel1.Location = new System.Drawing.Point(4, 4);
            this.flowLayoutPanel1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(354, 243);
            this.flowLayoutPanel1.TabIndex = 3;
            this.flowLayoutPanel1.WrapContents = false;
            // 
            // checkBoxTriggerOnDoc
            // 
            this.checkBoxTriggerOnDoc.AutoSize = true;
            this.checkBoxTriggerOnDoc.Checked = true;
            this.checkBoxTriggerOnDoc.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxTriggerOnDoc.Location = new System.Drawing.Point(4, 4);
            this.checkBoxTriggerOnDoc.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxTriggerOnDoc.Name = "checkBoxTriggerOnDoc";
            this.checkBoxTriggerOnDoc.Size = new System.Drawing.Size(123, 21);
            this.checkBoxTriggerOnDoc.TabIndex = 9;
            this.checkBoxTriggerOnDoc.Text = "Trigger on doc";
            this.checkBoxTriggerOnDoc.UseVisualStyleBackColor = true;
            // 
            // comboBoxResolution
            // 
            this.comboBoxResolution.FormattingEnabled = true;
            this.comboBoxResolution.Items.AddRange(new object[] {
            "high",
            "default",
            "low"});
            this.comboBoxResolution.Location = new System.Drawing.Point(4, 33);
            this.comboBoxResolution.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.comboBoxResolution.Name = "comboBoxResolution";
            this.comboBoxResolution.Size = new System.Drawing.Size(163, 24);
            this.comboBoxResolution.TabIndex = 0;
            this.comboBoxResolution.Text = "default";
            // 
            // checkBoxInfrared
            // 
            this.checkBoxInfrared.AutoSize = true;
            this.checkBoxInfrared.Checked = true;
            this.checkBoxInfrared.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxInfrared.Location = new System.Drawing.Point(4, 65);
            this.checkBoxInfrared.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxInfrared.Name = "checkBoxInfrared";
            this.checkBoxInfrared.Size = new System.Drawing.Size(79, 21);
            this.checkBoxInfrared.TabIndex = 11;
            this.checkBoxInfrared.Text = "Infrared";
            this.checkBoxInfrared.UseVisualStyleBackColor = true;
            // 
            // checkBoxVisible
            // 
            this.checkBoxVisible.AutoSize = true;
            this.checkBoxVisible.Checked = true;
            this.checkBoxVisible.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxVisible.Location = new System.Drawing.Point(4, 94);
            this.checkBoxVisible.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxVisible.Name = "checkBoxVisible";
            this.checkBoxVisible.Size = new System.Drawing.Size(71, 21);
            this.checkBoxVisible.TabIndex = 13;
            this.checkBoxVisible.Text = "Visible";
            this.checkBoxVisible.UseVisualStyleBackColor = true;
            // 
            // checkBoxUltraviolet
            // 
            this.checkBoxUltraviolet.AutoSize = true;
            this.checkBoxUltraviolet.Checked = true;
            this.checkBoxUltraviolet.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxUltraviolet.Location = new System.Drawing.Point(4, 123);
            this.checkBoxUltraviolet.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxUltraviolet.Name = "checkBoxUltraviolet";
            this.checkBoxUltraviolet.Size = new System.Drawing.Size(93, 21);
            this.checkBoxUltraviolet.TabIndex = 12;
            this.checkBoxUltraviolet.Text = "Ultraviolet";
            this.checkBoxUltraviolet.UseVisualStyleBackColor = true;
            // 
            // checkBoxDocCrop
            // 
            this.checkBoxDocCrop.AutoSize = true;
            this.checkBoxDocCrop.Checked = true;
            this.checkBoxDocCrop.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxDocCrop.Location = new System.Drawing.Point(4, 152);
            this.checkBoxDocCrop.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxDocCrop.Name = "checkBoxDocCrop";
            this.checkBoxDocCrop.Size = new System.Drawing.Size(87, 21);
            this.checkBoxDocCrop.TabIndex = 6;
            this.checkBoxDocCrop.Text = "Doc crop";
            this.checkBoxDocCrop.UseVisualStyleBackColor = true;
            // 
            // checkBoxAntiBg
            // 
            this.checkBoxAntiBg.AutoSize = true;
            this.checkBoxAntiBg.Checked = true;
            this.checkBoxAntiBg.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxAntiBg.Location = new System.Drawing.Point(4, 181);
            this.checkBoxAntiBg.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxAntiBg.Name = "checkBoxAntiBg";
            this.checkBoxAntiBg.Size = new System.Drawing.Size(79, 21);
            this.checkBoxAntiBg.TabIndex = 5;
            this.checkBoxAntiBg.Text = "Anti-BG";
            this.checkBoxAntiBg.UseVisualStyleBackColor = true;
            // 
            // checkBoxFaceCrop
            // 
            this.checkBoxFaceCrop.AutoSize = true;
            this.checkBoxFaceCrop.Checked = true;
            this.checkBoxFaceCrop.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxFaceCrop.Location = new System.Drawing.Point(4, 210);
            this.checkBoxFaceCrop.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxFaceCrop.Name = "checkBoxFaceCrop";
            this.checkBoxFaceCrop.Size = new System.Drawing.Size(93, 21);
            this.checkBoxFaceCrop.TabIndex = 7;
            this.checkBoxFaceCrop.Text = "Face crop";
            this.checkBoxFaceCrop.UseVisualStyleBackColor = true;
            // 
            // checkBoxMrzOnScan
            // 
            this.checkBoxMrzOnScan.AutoSize = true;
            this.checkBoxMrzOnScan.Checked = true;
            this.checkBoxMrzOnScan.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxMrzOnScan.Location = new System.Drawing.Point(4, 239);
            this.checkBoxMrzOnScan.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxMrzOnScan.Name = "checkBoxMrzOnScan";
            this.checkBoxMrzOnScan.Size = new System.Drawing.Size(114, 21);
            this.checkBoxMrzOnScan.TabIndex = 8;
            this.checkBoxMrzOnScan.Text = "MRZ on scan";
            this.checkBoxMrzOnScan.UseVisualStyleBackColor = true;
            // 
            // checkBoxBuzzer
            // 
            this.checkBoxBuzzer.AutoSize = true;
            this.checkBoxBuzzer.Checked = true;
            this.checkBoxBuzzer.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxBuzzer.Location = new System.Drawing.Point(4, 268);
            this.checkBoxBuzzer.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxBuzzer.Name = "checkBoxBuzzer";
            this.checkBoxBuzzer.Size = new System.Drawing.Size(74, 21);
            this.checkBoxBuzzer.TabIndex = 10;
            this.checkBoxBuzzer.Text = "Buzzer";
            this.checkBoxBuzzer.UseVisualStyleBackColor = true;
            // 
            // textBoxMrzPc
            // 
            this.textBoxMrzPc.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.tableLayoutPanel1.SetColumnSpan(this.textBoxMrzPc, 3);
            this.textBoxMrzPc.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBoxMrzPc.Font = new System.Drawing.Font("Consolas", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxMrzPc.Location = new System.Drawing.Point(366, 4);
            this.textBoxMrzPc.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBoxMrzPc.Multiline = true;
            this.textBoxMrzPc.Name = "textBoxMrzPc";
            this.textBoxMrzPc.ReadOnly = true;
            this.textBoxMrzPc.Size = new System.Drawing.Size(934, 243);
            this.textBoxMrzPc.TabIndex = 5;
            // 
            // tabPageEvents
            // 
            this.tabPageEvents.Controls.Add(this.tableLayoutPanel);
            this.tabPageEvents.Location = new System.Drawing.Point(4, 25);
            this.tabPageEvents.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPageEvents.Name = "tabPageEvents";
            this.tabPageEvents.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPageEvents.Size = new System.Drawing.Size(1312, 679);
            this.tabPageEvents.TabIndex = 1;
            this.tabPageEvents.Text = "Events";
            this.tabPageEvents.UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel
            // 
            this.tableLayoutPanel.ColumnCount = 1;
            this.tableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel.Controls.Add(this.checkBoxConnectOnPlug, 0, 7);
            this.tableLayoutPanel.Controls.Add(this.checkBoxListenTouchUp, 0, 6);
            this.tableLayoutPanel.Controls.Add(this.checkBoxListenTouchDown, 0, 5);
            this.tableLayoutPanel.Controls.Add(this.checkBoxListenDocOff, 0, 1);
            this.tableLayoutPanel.Controls.Add(this.textBox, 0, 8);
            this.tableLayoutPanel.Controls.Add(this.checkBoxListenMrz, 0, 2);
            this.tableLayoutPanel.Controls.Add(this.checkBoxListenDocOn, 0, 0);
            this.tableLayoutPanel.Controls.Add(this.checkBoxListenBcr, 0, 3);
            this.tableLayoutPanel.Controls.Add(this.checkBoxListenMsr, 0, 4);
            this.tableLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel.Location = new System.Drawing.Point(4, 4);
            this.tableLayoutPanel.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tableLayoutPanel.Name = "tableLayoutPanel";
            this.tableLayoutPanel.RowCount = 9;
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 31F));
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 31F));
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 31F));
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 31F));
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 31F));
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 31F));
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 31F));
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 31F));
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel.Size = new System.Drawing.Size(1304, 671);
            this.tableLayoutPanel.TabIndex = 16;
            // 
            // checkBoxListenTouchUp
            // 
            this.checkBoxListenTouchUp.AutoSize = true;
            this.checkBoxListenTouchUp.Checked = true;
            this.checkBoxListenTouchUp.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxListenTouchUp.Location = new System.Drawing.Point(4, 190);
            this.checkBoxListenTouchUp.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxListenTouchUp.Name = "checkBoxListenTouchUp";
            this.checkBoxListenTouchUp.Size = new System.Drawing.Size(191, 21);
            this.checkBoxListenTouchUp.TabIndex = 22;
            this.checkBoxListenTouchUp.Text = "Listen to display touch up";
            this.checkBoxListenTouchUp.UseVisualStyleBackColor = true;
            this.checkBoxListenTouchUp.CheckedChanged += new System.EventHandler(this.checkBoxListenTouchUp_CheckedChanged);
            // 
            // checkBoxListenTouchDown
            // 
            this.checkBoxListenTouchDown.AutoSize = true;
            this.checkBoxListenTouchDown.Checked = true;
            this.checkBoxListenTouchDown.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxListenTouchDown.Location = new System.Drawing.Point(4, 159);
            this.checkBoxListenTouchDown.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxListenTouchDown.Name = "checkBoxListenTouchDown";
            this.checkBoxListenTouchDown.Size = new System.Drawing.Size(208, 21);
            this.checkBoxListenTouchDown.TabIndex = 21;
            this.checkBoxListenTouchDown.Text = "Listen to display touch down";
            this.checkBoxListenTouchDown.UseVisualStyleBackColor = true;
            this.checkBoxListenTouchDown.CheckedChanged += new System.EventHandler(this.checkBoxListenTouchDown_CheckedChanged);
            // 
            // checkBoxListenDocOff
            // 
            this.checkBoxListenDocOff.AutoSize = true;
            this.checkBoxListenDocOff.Checked = true;
            this.checkBoxListenDocOff.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxListenDocOff.Location = new System.Drawing.Point(4, 35);
            this.checkBoxListenDocOff.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxListenDocOff.Name = "checkBoxListenDocOff";
            this.checkBoxListenDocOff.Size = new System.Drawing.Size(188, 21);
            this.checkBoxListenDocOff.TabIndex = 20;
            this.checkBoxListenDocOff.Text = "Listen to DOC OFF event";
            this.checkBoxListenDocOff.UseVisualStyleBackColor = true;
            this.checkBoxListenDocOff.CheckedChanged += new System.EventHandler(this.checkBoxListenDocOff_CheckedChanged);
            // 
            // textBox
            // 
            this.textBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox.Location = new System.Drawing.Point(4, 252);
            this.textBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox.Multiline = true;
            this.textBox.Name = "textBox";
            this.textBox.Size = new System.Drawing.Size(1296, 415);
            this.textBox.TabIndex = 2;
            // 
            // checkBoxListenMrz
            // 
            this.checkBoxListenMrz.AutoSize = true;
            this.checkBoxListenMrz.Checked = true;
            this.checkBoxListenMrz.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxListenMrz.Location = new System.Drawing.Point(4, 66);
            this.checkBoxListenMrz.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxListenMrz.Name = "checkBoxListenMrz";
            this.checkBoxListenMrz.Size = new System.Drawing.Size(157, 21);
            this.checkBoxListenMrz.TabIndex = 17;
            this.checkBoxListenMrz.Text = "Listen to MRZ event";
            this.checkBoxListenMrz.UseVisualStyleBackColor = true;
            this.checkBoxListenMrz.CheckStateChanged += new System.EventHandler(this.checkBoxListenMrz_CheckedChanged);
            // 
            // checkBoxListenDocOn
            // 
            this.checkBoxListenDocOn.AutoSize = true;
            this.checkBoxListenDocOn.Checked = true;
            this.checkBoxListenDocOn.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxListenDocOn.Location = new System.Drawing.Point(4, 4);
            this.checkBoxListenDocOn.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxListenDocOn.Name = "checkBoxListenDocOn";
            this.checkBoxListenDocOn.Size = new System.Drawing.Size(182, 21);
            this.checkBoxListenDocOn.TabIndex = 14;
            this.checkBoxListenDocOn.Text = "Listen to DOC ON event";
            this.checkBoxListenDocOn.UseVisualStyleBackColor = true;
            this.checkBoxListenDocOn.CheckedChanged += new System.EventHandler(this.checkBoxListenDocOn_CheckedChanged);
            // 
            // checkBoxListenBcr
            // 
            this.checkBoxListenBcr.AutoSize = true;
            this.checkBoxListenBcr.Checked = true;
            this.checkBoxListenBcr.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxListenBcr.Location = new System.Drawing.Point(4, 97);
            this.checkBoxListenBcr.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxListenBcr.Name = "checkBoxListenBcr";
            this.checkBoxListenBcr.Size = new System.Drawing.Size(179, 21);
            this.checkBoxListenBcr.TabIndex = 19;
            this.checkBoxListenBcr.Text = "Listen to barcode event";
            this.checkBoxListenBcr.UseVisualStyleBackColor = true;
            this.checkBoxListenBcr.CheckedChanged += new System.EventHandler(this.checkBoxListenBcr_CheckedChanged);
            // 
            // checkBoxListenMsr
            // 
            this.checkBoxListenMsr.AutoSize = true;
            this.checkBoxListenMsr.Checked = true;
            this.checkBoxListenMsr.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxListenMsr.Location = new System.Drawing.Point(4, 128);
            this.checkBoxListenMsr.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkBoxListenMsr.Name = "checkBoxListenMsr";
            this.checkBoxListenMsr.Size = new System.Drawing.Size(223, 21);
            this.checkBoxListenMsr.TabIndex = 18;
            this.checkBoxListenMsr.Text = "Listen to magnetic stripe event";
            this.checkBoxListenMsr.UseVisualStyleBackColor = true;
            this.checkBoxListenMsr.CheckedChanged += new System.EventHandler(this.checkBoxListenMsr_CheckedChanged);
            // 
            // tabPageMrz
            // 
            this.tabPageMrz.Controls.Add(this.analysisControl);
            this.tabPageMrz.Location = new System.Drawing.Point(4, 25);
            this.tabPageMrz.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPageMrz.Name = "tabPageMrz";
            this.tabPageMrz.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPageMrz.Size = new System.Drawing.Size(1312, 679);
            this.tabPageMrz.TabIndex = 2;
            this.tabPageMrz.Text = "Analysis && Checks";
            this.tabPageMrz.UseVisualStyleBackColor = true;
            // 
            // tabPageFeedback
            // 
            this.tabPageFeedback.Controls.Add(this.feedbackControl);
            this.tabPageFeedback.Location = new System.Drawing.Point(4, 25);
            this.tabPageFeedback.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPageFeedback.Name = "tabPageFeedback";
            this.tabPageFeedback.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPageFeedback.Size = new System.Drawing.Size(1312, 679);
            this.tabPageFeedback.TabIndex = 4;
            this.tabPageFeedback.Text = "Feedback";
            this.tabPageFeedback.UseVisualStyleBackColor = true;
            // 
            // checkBoxConnectOnPlug
            // 
            this.checkBoxConnectOnPlug.AutoSize = true;
            this.checkBoxConnectOnPlug.Checked = true;
            this.checkBoxConnectOnPlug.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxConnectOnPlug.Location = new System.Drawing.Point(4, 221);
            this.checkBoxConnectOnPlug.Margin = new System.Windows.Forms.Padding(4);
            this.checkBoxConnectOnPlug.Name = "checkBoxConnectOnPlug";
            this.checkBoxConnectOnPlug.Size = new System.Drawing.Size(176, 21);
            this.checkBoxConnectOnPlug.TabIndex = 23;
            this.checkBoxConnectOnPlug.Text = "Connect on plug event.";
            this.checkBoxConnectOnPlug.UseVisualStyleBackColor = true;
            // 
            // controlScanLightFace
            // 
            this.controlScanLightFace.BackColor = System.Drawing.SystemColors.Control;
            this.controlScanLightFace.Dock = System.Windows.Forms.DockStyle.Fill;
            this.controlScanLightFace.Full = null;
            this.controlScanLightFace.Location = new System.Drawing.Point(1091, 256);
            this.controlScanLightFace.Margin = new System.Windows.Forms.Padding(5);
            this.controlScanLightFace.MoveDelta = -1D;
            this.controlScanLightFace.Name = "controlScanLightFace";
            this.controlScanLightFace.ShowMoveInfo = false;
            this.controlScanLightFace.Size = new System.Drawing.Size(208, 410);
            this.controlScanLightFace.TabIndex = 4;
            // 
            // controlScanLightInfrared
            // 
            this.controlScanLightInfrared.BackColor = System.Drawing.SystemColors.Control;
            this.controlScanLightInfrared.Dock = System.Windows.Forms.DockStyle.Fill;
            this.controlScanLightInfrared.Full = null;
            this.controlScanLightInfrared.Location = new System.Drawing.Point(5, 256);
            this.controlScanLightInfrared.Margin = new System.Windows.Forms.Padding(5);
            this.controlScanLightInfrared.MoveDelta = -1D;
            this.controlScanLightInfrared.Name = "controlScanLightInfrared";
            this.controlScanLightInfrared.ShowMoveInfo = false;
            this.controlScanLightInfrared.Size = new System.Drawing.Size(352, 410);
            this.controlScanLightInfrared.TabIndex = 0;
            // 
            // controlScanLightVisible
            // 
            this.controlScanLightVisible.BackColor = System.Drawing.SystemColors.Control;
            this.controlScanLightVisible.Dock = System.Windows.Forms.DockStyle.Fill;
            this.controlScanLightVisible.Full = null;
            this.controlScanLightVisible.Location = new System.Drawing.Point(367, 256);
            this.controlScanLightVisible.Margin = new System.Windows.Forms.Padding(5);
            this.controlScanLightVisible.MoveDelta = -1D;
            this.controlScanLightVisible.Name = "controlScanLightVisible";
            this.controlScanLightVisible.ShowMoveInfo = false;
            this.controlScanLightVisible.Size = new System.Drawing.Size(352, 410);
            this.controlScanLightVisible.TabIndex = 1;
            // 
            // controlScanLightUv
            // 
            this.controlScanLightUv.BackColor = System.Drawing.SystemColors.Control;
            this.controlScanLightUv.Dock = System.Windows.Forms.DockStyle.Fill;
            this.controlScanLightUv.Full = null;
            this.controlScanLightUv.Location = new System.Drawing.Point(729, 256);
            this.controlScanLightUv.Margin = new System.Windows.Forms.Padding(5);
            this.controlScanLightUv.MoveDelta = -1D;
            this.controlScanLightUv.Name = "controlScanLightUv";
            this.controlScanLightUv.ShowMoveInfo = false;
            this.controlScanLightUv.Size = new System.Drawing.Size(352, 410);
            this.controlScanLightUv.TabIndex = 2;
            // 
            // analysisControl
            // 
            this.analysisControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.analysisControl.Location = new System.Drawing.Point(4, 4);
            this.analysisControl.Margin = new System.Windows.Forms.Padding(5);
            this.analysisControl.Name = "analysisControl";
            this.analysisControl.Size = new System.Drawing.Size(1304, 671);
            this.analysisControl.TabIndex = 0;
            // 
            // feedbackControl
            // 
            this.feedbackControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.feedbackControl.Location = new System.Drawing.Point(4, 4);
            this.feedbackControl.Margin = new System.Windows.Forms.Padding(5);
            this.feedbackControl.Name = "feedbackControl";
            this.feedbackControl.Size = new System.Drawing.Size(1304, 671);
            this.feedbackControl.TabIndex = 0;
            // 
            // logTextControl
            // 
            this.logTextControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.logTextControl.Location = new System.Drawing.Point(0, 0);
            this.logTextControl.LogFile = "C:\\temp\\log.txt";
            this.logTextControl.Margin = new System.Windows.Forms.Padding(5);
            this.logTextControl.Name = "logTextControl";
            this.logTextControl.Size = new System.Drawing.Size(1320, 328);
            this.logTextControl.TabIndex = 2;
            // 
            // stateLabelLastResult
            // 
            this.stateLabelLastResult.AttentionText = "Attention";
            this.stateLabelLastResult.BadText = "fail";
            this.stateLabelLastResult.GoodText = "success";
            this.stateLabelLastResult.Location = new System.Drawing.Point(5, 7);
            this.stateLabelLastResult.Margin = new System.Windows.Forms.Padding(5);
            this.stateLabelLastResult.Name = "stateLabelLastResult";
            this.stateLabelLastResult.OffText = "n/a";
            this.stateLabelLastResult.Size = new System.Drawing.Size(80, 23);
            this.stateLabelLastResult.State = SampleNet.LabelState.Off;
            this.stateLabelLastResult.TabIndex = 4;
            // 
            // stateLabelDocState
            // 
            this.stateLabelDocState.AttentionText = "Doc ATT";
            this.stateLabelDocState.BadText = "Doc OFF";
            this.stateLabelDocState.GoodText = "Doc ON";
            this.stateLabelDocState.Location = new System.Drawing.Point(123, 42);
            this.stateLabelDocState.Margin = new System.Windows.Forms.Padding(5);
            this.stateLabelDocState.Name = "stateLabelDocState";
            this.stateLabelDocState.OffText = "Doc ???";
            this.stateLabelDocState.Size = new System.Drawing.Size(80, 28);
            this.stateLabelDocState.State = SampleNet.LabelState.Off;
            this.stateLabelDocState.TabIndex = 7;
            // 
            // stateLabelConnect
            // 
            this.stateLabelConnect.AttentionText = "Attention";
            this.stateLabelConnect.BadText = "";
            this.stateLabelConnect.GoodText = "";
            this.stateLabelConnect.Location = new System.Drawing.Point(93, 6);
            this.stateLabelConnect.Margin = new System.Windows.Forms.Padding(5);
            this.stateLabelConnect.Name = "stateLabelConnect";
            this.stateLabelConnect.OffText = "";
            this.stateLabelConnect.Size = new System.Drawing.Size(21, 64);
            this.stateLabelConnect.State = SampleNet.LabelState.Off;
            this.stateLabelConnect.TabIndex = 6;
            // 
            // stateLabelPlug
            // 
            this.stateLabelPlug.AttentionText = "Attention";
            this.stateLabelPlug.BadText = "Error";
            this.stateLabelPlug.GoodText = "Plugged";
            this.stateLabelPlug.Location = new System.Drawing.Point(123, 7);
            this.stateLabelPlug.Margin = new System.Windows.Forms.Padding(5);
            this.stateLabelPlug.Name = "stateLabelPlug";
            this.stateLabelPlug.OffText = "Unplugged";
            this.stateLabelPlug.Size = new System.Drawing.Size(80, 27);
            this.stateLabelPlug.State = SampleNet.LabelState.Off;
            this.stateLabelPlug.TabIndex = 5;
            // 
            // timerConnector
            // 
            this.timerConnector.Enabled = true;
            this.timerConnector.Interval = 500;
            this.timerConnector.Tick += new System.EventHandler(this.timerConnector_Tick);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1320, 1153);
            this.Controls.Add(this.splitContainer);
            this.Controls.Add(this.panelStatus);
            this.Controls.Add(this.panelHead);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "FormMain";
            this.Text = "PageScan API Sample";
            this.Load += new System.EventHandler(this.FormMain_Load);
            this.panelHead.ResumeLayout(false);
            this.panelStatus.ResumeLayout(false);
            this.panelStatus.PerformLayout();
            this.splitContainer.Panel1.ResumeLayout(false);
            this.splitContainer.Panel2.ResumeLayout(false);
            this.splitContainer.ResumeLayout(false);
            this.tabControlMain.ResumeLayout(false);
            this.tabPageInfoSetup.ResumeLayout(false);
            this.tableLayoutPanel3.ResumeLayout(false);
            this.tableLayoutPanel3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewSystemInfo)).EndInit();
            this.tabPageScan.ResumeLayout(false);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.tabPageEvents.ResumeLayout(false);
            this.tableLayoutPanel.ResumeLayout(false);
            this.tableLayoutPanel.PerformLayout();
            this.tabPageMrz.ResumeLayout(false);
            this.tabPageFeedback.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControlMain;
        private System.Windows.Forms.TabPage tabPageScan;
        private System.Windows.Forms.TabPage tabPageEvents;
        private System.Windows.Forms.ComboBox comboBoxResolution;
        private ControlScanLight controlScanLightUv;
        private ControlScanLight controlScanLightVisible;
        private ControlScanLight controlScanLightInfrared;
        private System.Windows.Forms.Panel panelHead;
        private System.Windows.Forms.Button buttonConnect;
        private System.Windows.Forms.Panel panelStatus;
        private System.Windows.Forms.Label labelLastResultMessage;
        private System.Windows.Forms.Button buttonDisconnect;
        private System.Windows.Forms.Button buttonScan;
        private System.Windows.Forms.Button buttonClear;
        private LogTextControl logTextControl;
        public System.Windows.Forms.CheckBox checkBoxFaceCrop;
        public System.Windows.Forms.CheckBox checkBoxDocCrop;
        public System.Windows.Forms.CheckBox checkBoxAntiBg;
        public System.Windows.Forms.CheckBox checkBoxMrzOnScan;
        public System.Windows.Forms.CheckBox checkBoxListenDocOn;
        public System.Windows.Forms.CheckBox checkBoxTriggerOnDoc;
        public System.Windows.Forms.CheckBox checkBoxBuzzer;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.SplitContainer splitContainer;
        private System.Windows.Forms.TextBox textBox;
        public System.Windows.Forms.CheckBox checkBoxListenMsr;
        public System.Windows.Forms.CheckBox checkBoxListenBcr;
        public System.Windows.Forms.CheckBox checkBoxListenMrz;
        private System.Windows.Forms.TabPage tabPageMrz;
        private MrzControl analysisControl;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel;
        private System.Windows.Forms.Button buttonQuickCroppedMrz;
        private System.Windows.Forms.Button buttonQuickMrz;
        private System.Windows.Forms.Button buttonQuickCroppedIamges;
        private System.Windows.Forms.Button buttonQuickFullImages;
        private System.Windows.Forms.Button buttonQuickAnalysis;
        private System.Windows.Forms.Button buttonDataEvents;
        private StateLabel stateLabelPlug;
        private StateLabel stateLabelConnect;
        private StateLabel stateLabelDocState;
        private System.Windows.Forms.Button buttonShowLog;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private ControlScanLight controlScanLightFace;
        private System.Windows.Forms.TextBox textBoxMrzPc;
        public System.Windows.Forms.CheckBox checkBoxInfrared;
        public System.Windows.Forms.CheckBox checkBoxVisible;
        public System.Windows.Forms.CheckBox checkBoxUltraviolet;
        private System.Windows.Forms.TabPage tabPageInfoSetup;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dataGridViewSystemInfo;
        private System.Windows.Forms.Label label2;
        private StateLabel stateLabelLastResult;
        public System.Windows.Forms.CheckBox checkBoxListenDocOff;
        private System.Windows.Forms.TabPage tabPageFeedback;
        private FeedbackControl feedbackControl;
        public System.Windows.Forms.CheckBox checkBoxListenTouchUp;
        public System.Windows.Forms.CheckBox checkBoxListenTouchDown;
        public System.Windows.Forms.CheckBox checkBoxConnectOnPlug;
        private System.Windows.Forms.Timer timerConnector;
    }
}

