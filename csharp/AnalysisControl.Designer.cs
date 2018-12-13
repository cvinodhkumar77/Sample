namespace SampleNet
{
    partial class MrzControl
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MrzControl));
            this.dataGridViewDocFields = new System.Windows.Forms.DataGridView();
            this.comboBoxSubstitutionField = new System.Windows.Forms.ComboBox();
            this.checkBoxSubstitute = new System.Windows.Forms.CheckBox();
            this.label4 = new System.Windows.Forms.Label();
            this.checkBoxAutoParse = new System.Windows.Forms.CheckBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.numericUpDownMinDaysTillExpiry = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.numericUpDownMinAge = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.panelChecks = new System.Windows.Forms.Panel();
            this.stateLabelDocType = new SampleNet.StateLabel();
            this.stateLabelPixelDensityDpi = new SampleNet.StateLabel();
            this.stateLabelPixelDensityPpm = new SampleNet.StateLabel();
            this.checkBoxPixelDensity = new System.Windows.Forms.CheckBox();
            this.stateLabelClippedSize = new SampleNet.StateLabel();
            this.stateLabelClippedShape = new SampleNet.StateLabel();
            this.stateLabelVisMoved = new SampleNet.StateLabel();
            this.stateLabelIrMoved = new SampleNet.StateLabel();
            this.stateLabelB900Ink = new SampleNet.StateLabel();
            this.stateLabelUvDull = new SampleNet.StateLabel();
            this.stateLabelChecksumValid = new SampleNet.StateLabel();
            this.stateLabelCharsValid = new SampleNet.StateLabel();
            this.stateLabelDaysTillExpiry = new SampleNet.StateLabel();
            this.stateLabelMinAge = new SampleNet.StateLabel();
            this.checkBoxClippedSize = new System.Windows.Forms.CheckBox();
            this.checkBoxClippedShape = new System.Windows.Forms.CheckBox();
            this.checkBoxVisMoved = new System.Windows.Forms.CheckBox();
            this.checkBoxIrMoved = new System.Windows.Forms.CheckBox();
            this.checkBoxB900Ink = new System.Windows.Forms.CheckBox();
            this.checkBoxUvDull = new System.Windows.Forms.CheckBox();
            this.panelMrz = new System.Windows.Forms.Panel();
            this.buttonClean = new System.Windows.Forms.Button();
            this.textBoxMrz = new System.Windows.Forms.TextBox();
            this.buttonParse = new System.Windows.Forms.Button();
            this.textBoxSubstitutions = new System.Windows.Forms.TextBox();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPageChecks = new System.Windows.Forms.TabPage();
            this.tabPageMrzFields = new System.Windows.Forms.TabPage();
            this.panel2 = new System.Windows.Forms.Panel();
            this.listBoxGetFlags = new System.Windows.Forms.ListBox();
            this.tabPageSubstitutionRules = new System.Windows.Forms.TabPage();
            this.panel1 = new System.Windows.Forms.Panel();
            this.stateLabelIcao = new SampleNet.StateLabel();
            this.labelIcao = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDocFields)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownMinDaysTillExpiry)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownMinAge)).BeginInit();
            this.panelChecks.SuspendLayout();
            this.panelMrz.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPageChecks.SuspendLayout();
            this.tabPageMrzFields.SuspendLayout();
            this.panel2.SuspendLayout();
            this.tabPageSubstitutionRules.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridViewDocFields
            // 
            this.dataGridViewDocFields.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewDocFields.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridViewDocFields.Location = new System.Drawing.Point(3, 91);
            this.dataGridViewDocFields.Name = "dataGridViewDocFields";
            this.dataGridViewDocFields.RowHeadersVisible = false;
            this.dataGridViewDocFields.Size = new System.Drawing.Size(920, 317);
            this.dataGridViewDocFields.TabIndex = 3;
            // 
            // comboBoxSubstitutionField
            // 
            this.comboBoxSubstitutionField.FormattingEnabled = true;
            this.comboBoxSubstitutionField.Location = new System.Drawing.Point(120, 3);
            this.comboBoxSubstitutionField.Name = "comboBoxSubstitutionField";
            this.comboBoxSubstitutionField.Size = new System.Drawing.Size(133, 21);
            this.comboBoxSubstitutionField.TabIndex = 0;
            // 
            // checkBoxSubstitute
            // 
            this.checkBoxSubstitute.AutoSize = true;
            this.checkBoxSubstitute.Location = new System.Drawing.Point(6, 5);
            this.checkBoxSubstitute.Name = "checkBoxSubstitute";
            this.checkBoxSubstitute.Size = new System.Drawing.Size(108, 17);
            this.checkBoxSubstitute.TabIndex = 1;
            this.checkBoxSubstitute.Text = "Apply substitution";
            this.checkBoxSubstitute.UseVisualStyleBackColor = true;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(3, 159);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(53, 13);
            this.label4.TabIndex = 14;
            this.label4.Text = "Doc type:";
            // 
            // checkBoxAutoParse
            // 
            this.checkBoxAutoParse.AutoSize = true;
            this.checkBoxAutoParse.Location = new System.Drawing.Point(3, 9);
            this.checkBoxAutoParse.Name = "checkBoxAutoParse";
            this.checkBoxAutoParse.Size = new System.Drawing.Size(124, 17);
            this.checkBoxAutoParse.TabIndex = 20;
            this.checkBoxAutoParse.Text = "MRZ parse && check:";
            this.checkBoxAutoParse.UseVisualStyleBackColor = true;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(3, 107);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(60, 13);
            this.label6.TabIndex = 16;
            this.label6.Text = "Checksum:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(3, 81);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(37, 13);
            this.label5.TabIndex = 15;
            this.label5.Text = "Chars:";
            // 
            // numericUpDownMinDaysTillExpiry
            // 
            this.numericUpDownMinDaysTillExpiry.Location = new System.Drawing.Point(67, 55);
            this.numericUpDownMinDaysTillExpiry.Maximum = new decimal(new int[] {
            9999,
            0,
            0,
            0});
            this.numericUpDownMinDaysTillExpiry.Name = "numericUpDownMinDaysTillExpiry";
            this.numericUpDownMinDaysTillExpiry.Size = new System.Drawing.Size(59, 20);
            this.numericUpDownMinDaysTillExpiry.TabIndex = 8;
            this.numericUpDownMinDaysTillExpiry.Value = new decimal(new int[] {
            30,
            0,
            0,
            0});
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(3, 56);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(59, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Days valid:";
            // 
            // numericUpDownMinAge
            // 
            this.numericUpDownMinAge.Location = new System.Drawing.Point(67, 29);
            this.numericUpDownMinAge.Maximum = new decimal(new int[] {
            150,
            0,
            0,
            0});
            this.numericUpDownMinAge.Name = "numericUpDownMinAge";
            this.numericUpDownMinAge.Size = new System.Drawing.Size(59, 20);
            this.numericUpDownMinAge.TabIndex = 6;
            this.numericUpDownMinAge.Value = new decimal(new int[] {
            21,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(48, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Min age:";
            // 
            // panelChecks
            // 
            this.panelChecks.AutoScroll = true;
            this.panelChecks.Controls.Add(this.stateLabelIcao);
            this.panelChecks.Controls.Add(this.labelIcao);
            this.panelChecks.Controls.Add(this.stateLabelDocType);
            this.panelChecks.Controls.Add(this.stateLabelPixelDensityDpi);
            this.panelChecks.Controls.Add(this.stateLabelPixelDensityPpm);
            this.panelChecks.Controls.Add(this.checkBoxPixelDensity);
            this.panelChecks.Controls.Add(this.stateLabelClippedSize);
            this.panelChecks.Controls.Add(this.label4);
            this.panelChecks.Controls.Add(this.stateLabelClippedShape);
            this.panelChecks.Controls.Add(this.stateLabelVisMoved);
            this.panelChecks.Controls.Add(this.stateLabelIrMoved);
            this.panelChecks.Controls.Add(this.stateLabelB900Ink);
            this.panelChecks.Controls.Add(this.stateLabelUvDull);
            this.panelChecks.Controls.Add(this.stateLabelChecksumValid);
            this.panelChecks.Controls.Add(this.stateLabelCharsValid);
            this.panelChecks.Controls.Add(this.stateLabelDaysTillExpiry);
            this.panelChecks.Controls.Add(this.stateLabelMinAge);
            this.panelChecks.Controls.Add(this.checkBoxClippedSize);
            this.panelChecks.Controls.Add(this.checkBoxClippedShape);
            this.panelChecks.Controls.Add(this.checkBoxVisMoved);
            this.panelChecks.Controls.Add(this.checkBoxIrMoved);
            this.panelChecks.Controls.Add(this.checkBoxB900Ink);
            this.panelChecks.Controls.Add(this.checkBoxUvDull);
            this.panelChecks.Controls.Add(this.label6);
            this.panelChecks.Controls.Add(this.label5);
            this.panelChecks.Controls.Add(this.checkBoxAutoParse);
            this.panelChecks.Controls.Add(this.label1);
            this.panelChecks.Controls.Add(this.numericUpDownMinAge);
            this.panelChecks.Controls.Add(this.label2);
            this.panelChecks.Controls.Add(this.numericUpDownMinDaysTillExpiry);
            this.panelChecks.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelChecks.Location = new System.Drawing.Point(0, 0);
            this.panelChecks.Name = "panelChecks";
            this.panelChecks.Size = new System.Drawing.Size(926, 411);
            this.panelChecks.TabIndex = 21;
            // 
            // stateLabelDocType
            // 
            this.stateLabelDocType.AttentionText = "Attention";
            this.stateLabelDocType.BadText = "Fail";
            this.stateLabelDocType.GoodText = "Valid";
            this.stateLabelDocType.Location = new System.Drawing.Point(67, 159);
            this.stateLabelDocType.Name = "stateLabelDocType";
            this.stateLabelDocType.OffText = "";
            this.stateLabelDocType.Size = new System.Drawing.Size(107, 20);
            this.stateLabelDocType.State = SampleNet.LabelState.Off;
            this.stateLabelDocType.TabIndex = 61;
            // 
            // stateLabelPixelDensityDpi
            // 
            this.stateLabelPixelDensityDpi.AttentionText = "Attention";
            this.stateLabelPixelDensityDpi.BadText = "Fail";
            this.stateLabelPixelDensityDpi.GoodText = "Valid";
            this.stateLabelPixelDensityDpi.Location = new System.Drawing.Point(446, 149);
            this.stateLabelPixelDensityDpi.Name = "stateLabelPixelDensityDpi";
            this.stateLabelPixelDensityDpi.OffText = "???";
            this.stateLabelPixelDensityDpi.Size = new System.Drawing.Size(150, 20);
            this.stateLabelPixelDensityDpi.State = SampleNet.LabelState.Off;
            this.stateLabelPixelDensityDpi.TabIndex = 60;
            // 
            // stateLabelPixelDensityPpm
            // 
            this.stateLabelPixelDensityPpm.AttentionText = "Attention";
            this.stateLabelPixelDensityPpm.BadText = "Fail";
            this.stateLabelPixelDensityPpm.GoodText = "Valid";
            this.stateLabelPixelDensityPpm.Location = new System.Drawing.Point(445, 123);
            this.stateLabelPixelDensityPpm.Name = "stateLabelPixelDensityPpm";
            this.stateLabelPixelDensityPpm.OffText = "???";
            this.stateLabelPixelDensityPpm.Size = new System.Drawing.Size(150, 20);
            this.stateLabelPixelDensityPpm.State = SampleNet.LabelState.Off;
            this.stateLabelPixelDensityPpm.TabIndex = 59;
            // 
            // checkBoxPixelDensity
            // 
            this.checkBoxPixelDensity.AutoSize = true;
            this.checkBoxPixelDensity.Location = new System.Drawing.Point(424, 100);
            this.checkBoxPixelDensity.Name = "checkBoxPixelDensity";
            this.checkBoxPixelDensity.Size = new System.Drawing.Size(87, 17);
            this.checkBoxPixelDensity.TabIndex = 58;
            this.checkBoxPixelDensity.Text = "Pixel density:";
            this.checkBoxPixelDensity.UseVisualStyleBackColor = true;
            // 
            // stateLabelClippedSize
            // 
            this.stateLabelClippedSize.AttentionText = "Attention";
            this.stateLabelClippedSize.BadText = "Fail";
            this.stateLabelClippedSize.GoodText = "Valid";
            this.stateLabelClippedSize.Location = new System.Drawing.Point(445, 75);
            this.stateLabelClippedSize.Name = "stateLabelClippedSize";
            this.stateLabelClippedSize.OffText = "???";
            this.stateLabelClippedSize.Size = new System.Drawing.Size(150, 20);
            this.stateLabelClippedSize.State = SampleNet.LabelState.Off;
            this.stateLabelClippedSize.TabIndex = 57;
            // 
            // stateLabelClippedShape
            // 
            this.stateLabelClippedShape.AttentionText = "Attention";
            this.stateLabelClippedShape.BadText = "Fail";
            this.stateLabelClippedShape.GoodText = "Valid";
            this.stateLabelClippedShape.Location = new System.Drawing.Point(445, 27);
            this.stateLabelClippedShape.Name = "stateLabelClippedShape";
            this.stateLabelClippedShape.OffText = "???";
            this.stateLabelClippedShape.Size = new System.Drawing.Size(150, 20);
            this.stateLabelClippedShape.State = SampleNet.LabelState.Off;
            this.stateLabelClippedShape.TabIndex = 56;
            // 
            // stateLabelVisMoved
            // 
            this.stateLabelVisMoved.AttentionText = "n/a";
            this.stateLabelVisMoved.BadText = "Fail";
            this.stateLabelVisMoved.GoodText = "Valid";
            this.stateLabelVisMoved.Location = new System.Drawing.Point(341, 87);
            this.stateLabelVisMoved.Name = "stateLabelVisMoved";
            this.stateLabelVisMoved.OffText = "Off";
            this.stateLabelVisMoved.Size = new System.Drawing.Size(42, 20);
            this.stateLabelVisMoved.State = SampleNet.LabelState.Off;
            this.stateLabelVisMoved.TabIndex = 55;
            // 
            // stateLabelIrMoved
            // 
            this.stateLabelIrMoved.AttentionText = "n/a";
            this.stateLabelIrMoved.BadText = "Fail";
            this.stateLabelIrMoved.GoodText = "Valid";
            this.stateLabelIrMoved.Location = new System.Drawing.Point(341, 61);
            this.stateLabelIrMoved.Name = "stateLabelIrMoved";
            this.stateLabelIrMoved.OffText = "Off";
            this.stateLabelIrMoved.Size = new System.Drawing.Size(42, 20);
            this.stateLabelIrMoved.State = SampleNet.LabelState.Off;
            this.stateLabelIrMoved.TabIndex = 54;
            // 
            // stateLabelB900Ink
            // 
            this.stateLabelB900Ink.AttentionText = "n/a";
            this.stateLabelB900Ink.BadText = "Fail";
            this.stateLabelB900Ink.GoodText = "Valid";
            this.stateLabelB900Ink.Location = new System.Drawing.Point(341, 35);
            this.stateLabelB900Ink.Name = "stateLabelB900Ink";
            this.stateLabelB900Ink.OffText = "Off";
            this.stateLabelB900Ink.Size = new System.Drawing.Size(42, 20);
            this.stateLabelB900Ink.State = SampleNet.LabelState.Off;
            this.stateLabelB900Ink.TabIndex = 53;
            // 
            // stateLabelUvDull
            // 
            this.stateLabelUvDull.AttentionText = "n/a";
            this.stateLabelUvDull.BadText = "Fail";
            this.stateLabelUvDull.GoodText = "Valid";
            this.stateLabelUvDull.Location = new System.Drawing.Point(341, 9);
            this.stateLabelUvDull.Name = "stateLabelUvDull";
            this.stateLabelUvDull.OffText = "Off";
            this.stateLabelUvDull.Size = new System.Drawing.Size(42, 20);
            this.stateLabelUvDull.State = SampleNet.LabelState.Off;
            this.stateLabelUvDull.TabIndex = 52;
            // 
            // stateLabelChecksumValid
            // 
            this.stateLabelChecksumValid.AttentionText = "n/a";
            this.stateLabelChecksumValid.BadText = "Fail";
            this.stateLabelChecksumValid.GoodText = "Valid";
            this.stateLabelChecksumValid.Location = new System.Drawing.Point(132, 107);
            this.stateLabelChecksumValid.Name = "stateLabelChecksumValid";
            this.stateLabelChecksumValid.OffText = "Off";
            this.stateLabelChecksumValid.Size = new System.Drawing.Size(42, 20);
            this.stateLabelChecksumValid.State = SampleNet.LabelState.Off;
            this.stateLabelChecksumValid.TabIndex = 51;
            // 
            // stateLabelCharsValid
            // 
            this.stateLabelCharsValid.AttentionText = "n/a";
            this.stateLabelCharsValid.BadText = "Fail";
            this.stateLabelCharsValid.GoodText = "Valid";
            this.stateLabelCharsValid.Location = new System.Drawing.Point(132, 81);
            this.stateLabelCharsValid.Name = "stateLabelCharsValid";
            this.stateLabelCharsValid.OffText = "Off";
            this.stateLabelCharsValid.Size = new System.Drawing.Size(42, 20);
            this.stateLabelCharsValid.State = SampleNet.LabelState.Off;
            this.stateLabelCharsValid.TabIndex = 50;
            // 
            // stateLabelDaysTillExpiry
            // 
            this.stateLabelDaysTillExpiry.AttentionText = "n/a";
            this.stateLabelDaysTillExpiry.BadText = "Fail";
            this.stateLabelDaysTillExpiry.GoodText = "Valid";
            this.stateLabelDaysTillExpiry.Location = new System.Drawing.Point(132, 55);
            this.stateLabelDaysTillExpiry.Name = "stateLabelDaysTillExpiry";
            this.stateLabelDaysTillExpiry.OffText = "Off";
            this.stateLabelDaysTillExpiry.Size = new System.Drawing.Size(42, 20);
            this.stateLabelDaysTillExpiry.State = SampleNet.LabelState.Off;
            this.stateLabelDaysTillExpiry.TabIndex = 49;
            // 
            // stateLabelMinAge
            // 
            this.stateLabelMinAge.AttentionText = "n/a";
            this.stateLabelMinAge.BadText = "Fail";
            this.stateLabelMinAge.GoodText = "Valid";
            this.stateLabelMinAge.Location = new System.Drawing.Point(133, 29);
            this.stateLabelMinAge.Name = "stateLabelMinAge";
            this.stateLabelMinAge.OffText = "Off";
            this.stateLabelMinAge.Size = new System.Drawing.Size(42, 20);
            this.stateLabelMinAge.State = SampleNet.LabelState.Off;
            this.stateLabelMinAge.TabIndex = 48;
            // 
            // checkBoxClippedSize
            // 
            this.checkBoxClippedSize.AutoSize = true;
            this.checkBoxClippedSize.Location = new System.Drawing.Point(424, 52);
            this.checkBoxClippedSize.Name = "checkBoxClippedSize";
            this.checkBoxClippedSize.Size = new System.Drawing.Size(85, 17);
            this.checkBoxClippedSize.TabIndex = 47;
            this.checkBoxClippedSize.Text = "Clipped size:";
            this.checkBoxClippedSize.UseVisualStyleBackColor = true;
            // 
            // checkBoxClippedShape
            // 
            this.checkBoxClippedShape.AutoSize = true;
            this.checkBoxClippedShape.Location = new System.Drawing.Point(424, 9);
            this.checkBoxClippedShape.Name = "checkBoxClippedShape";
            this.checkBoxClippedShape.Size = new System.Drawing.Size(96, 17);
            this.checkBoxClippedShape.TabIndex = 45;
            this.checkBoxClippedShape.Text = "Clipped shape:";
            this.checkBoxClippedShape.UseVisualStyleBackColor = true;
            // 
            // checkBoxVisMoved
            // 
            this.checkBoxVisMoved.AutoSize = true;
            this.checkBoxVisMoved.Location = new System.Drawing.Point(212, 84);
            this.checkBoxVisMoved.Name = "checkBoxVisMoved";
            this.checkBoxVisMoved.Size = new System.Drawing.Size(81, 17);
            this.checkBoxVisMoved.TabIndex = 43;
            this.checkBoxVisMoved.Text = "VIS moved:";
            this.checkBoxVisMoved.UseVisualStyleBackColor = true;
            this.checkBoxVisMoved.CheckedChanged += new System.EventHandler(this.checkBoxVisMoved_CheckedChanged);
            // 
            // checkBoxIrMoved
            // 
            this.checkBoxIrMoved.AutoSize = true;
            this.checkBoxIrMoved.Location = new System.Drawing.Point(212, 61);
            this.checkBoxIrMoved.Name = "checkBoxIrMoved";
            this.checkBoxIrMoved.Size = new System.Drawing.Size(75, 17);
            this.checkBoxIrMoved.TabIndex = 41;
            this.checkBoxIrMoved.Text = "IR moved:";
            this.checkBoxIrMoved.UseVisualStyleBackColor = true;
            // 
            // checkBoxB900Ink
            // 
            this.checkBoxB900Ink.AutoSize = true;
            this.checkBoxB900Ink.Location = new System.Drawing.Point(212, 35);
            this.checkBoxB900Ink.Name = "checkBoxB900Ink";
            this.checkBoxB900Ink.Size = new System.Drawing.Size(104, 17);
            this.checkBoxB900Ink.TabIndex = 39;
            this.checkBoxB900Ink.Text = "B900 ink check:";
            this.checkBoxB900Ink.UseVisualStyleBackColor = true;
            // 
            // checkBoxUvDull
            // 
            this.checkBoxUvDull.AutoSize = true;
            this.checkBoxUvDull.Location = new System.Drawing.Point(212, 9);
            this.checkBoxUvDull.Name = "checkBoxUvDull";
            this.checkBoxUvDull.Size = new System.Drawing.Size(96, 17);
            this.checkBoxUvDull.TabIndex = 38;
            this.checkBoxUvDull.Text = "UV dull check:";
            this.checkBoxUvDull.UseVisualStyleBackColor = true;
            // 
            // panelMrz
            // 
            this.panelMrz.Controls.Add(this.buttonClean);
            this.panelMrz.Controls.Add(this.textBoxMrz);
            this.panelMrz.Controls.Add(this.buttonParse);
            this.panelMrz.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelMrz.Location = new System.Drawing.Point(0, 0);
            this.panelMrz.Name = "panelMrz";
            this.panelMrz.Size = new System.Drawing.Size(934, 63);
            this.panelMrz.TabIndex = 22;
            // 
            // buttonClean
            // 
            this.buttonClean.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonClean.Location = new System.Drawing.Point(3, 32);
            this.buttonClean.Name = "buttonClean";
            this.buttonClean.Size = new System.Drawing.Size(75, 23);
            this.buttonClean.TabIndex = 22;
            this.buttonClean.Text = "Clean";
            this.buttonClean.UseVisualStyleBackColor = true;
            this.buttonClean.Click += new System.EventHandler(this.buttonClean_Click);
            // 
            // textBoxMrz
            // 
            this.textBoxMrz.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxMrz.BackColor = System.Drawing.SystemColors.Control;
            this.textBoxMrz.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBoxMrz.Font = new System.Drawing.Font("Consolas", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxMrz.Location = new System.Drawing.Point(84, 3);
            this.textBoxMrz.Multiline = true;
            this.textBoxMrz.Name = "textBoxMrz";
            this.textBoxMrz.Size = new System.Drawing.Size(850, 54);
            this.textBoxMrz.TabIndex = 23;
            this.textBoxMrz.WordWrap = false;
            // 
            // buttonParse
            // 
            this.buttonParse.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonParse.Location = new System.Drawing.Point(3, 3);
            this.buttonParse.Name = "buttonParse";
            this.buttonParse.Size = new System.Drawing.Size(75, 23);
            this.buttonParse.TabIndex = 21;
            this.buttonParse.Text = "Parse now";
            this.buttonParse.UseVisualStyleBackColor = true;
            this.buttonParse.Click += new System.EventHandler(this.buttonParse_Click);
            // 
            // textBoxSubstitutions
            // 
            this.textBoxSubstitutions.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBoxSubstitutions.Font = new System.Drawing.Font("Consolas", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxSubstitutions.Location = new System.Drawing.Point(3, 31);
            this.textBoxSubstitutions.Multiline = true;
            this.textBoxSubstitutions.Name = "textBoxSubstitutions";
            this.textBoxSubstitutions.Size = new System.Drawing.Size(920, 377);
            this.textBoxSubstitutions.TabIndex = 0;
            this.textBoxSubstitutions.Text = resources.GetString("textBoxSubstitutions.Text");
            this.textBoxSubstitutions.WordWrap = false;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPageChecks);
            this.tabControl1.Controls.Add(this.tabPageMrzFields);
            this.tabControl1.Controls.Add(this.tabPageSubstitutionRules);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 63);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(934, 437);
            this.tabControl1.SizeMode = System.Windows.Forms.TabSizeMode.Fixed;
            this.tabControl1.TabIndex = 20;
            // 
            // tabPageChecks
            // 
            this.tabPageChecks.Controls.Add(this.panelChecks);
            this.tabPageChecks.Location = new System.Drawing.Point(4, 22);
            this.tabPageChecks.Name = "tabPageChecks";
            this.tabPageChecks.Size = new System.Drawing.Size(926, 411);
            this.tabPageChecks.TabIndex = 2;
            this.tabPageChecks.Text = "Checks";
            this.tabPageChecks.UseVisualStyleBackColor = true;
            // 
            // tabPageMrzFields
            // 
            this.tabPageMrzFields.Controls.Add(this.dataGridViewDocFields);
            this.tabPageMrzFields.Controls.Add(this.panel2);
            this.tabPageMrzFields.Location = new System.Drawing.Point(4, 22);
            this.tabPageMrzFields.Name = "tabPageMrzFields";
            this.tabPageMrzFields.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageMrzFields.Size = new System.Drawing.Size(926, 411);
            this.tabPageMrzFields.TabIndex = 0;
            this.tabPageMrzFields.Text = "MRZ Fields";
            this.tabPageMrzFields.UseVisualStyleBackColor = true;
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.listBoxGetFlags);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(3, 3);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(920, 88);
            this.panel2.TabIndex = 4;
            // 
            // listBoxGetFlags
            // 
            this.listBoxGetFlags.FormattingEnabled = true;
            this.listBoxGetFlags.Location = new System.Drawing.Point(3, 3);
            this.listBoxGetFlags.Name = "listBoxGetFlags";
            this.listBoxGetFlags.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
            this.listBoxGetFlags.Size = new System.Drawing.Size(133, 82);
            this.listBoxGetFlags.TabIndex = 20;
            // 
            // tabPageSubstitutionRules
            // 
            this.tabPageSubstitutionRules.Controls.Add(this.textBoxSubstitutions);
            this.tabPageSubstitutionRules.Controls.Add(this.panel1);
            this.tabPageSubstitutionRules.Location = new System.Drawing.Point(4, 22);
            this.tabPageSubstitutionRules.Name = "tabPageSubstitutionRules";
            this.tabPageSubstitutionRules.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageSubstitutionRules.Size = new System.Drawing.Size(926, 411);
            this.tabPageSubstitutionRules.TabIndex = 1;
            this.tabPageSubstitutionRules.Text = "Substitution Rules";
            this.tabPageSubstitutionRules.UseVisualStyleBackColor = true;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.comboBoxSubstitutionField);
            this.panel1.Controls.Add(this.checkBoxSubstitute);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(3, 3);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(920, 28);
            this.panel1.TabIndex = 1;
            // 
            // stateLabelIcao
            // 
            this.stateLabelIcao.AttentionText = "n/a";
            this.stateLabelIcao.BadText = "Fail";
            this.stateLabelIcao.GoodText = "Valid";
            this.stateLabelIcao.Location = new System.Drawing.Point(132, 133);
            this.stateLabelIcao.Name = "stateLabelIcao";
            this.stateLabelIcao.OffText = "Off";
            this.stateLabelIcao.Size = new System.Drawing.Size(42, 20);
            this.stateLabelIcao.State = SampleNet.LabelState.Off;
            this.stateLabelIcao.TabIndex = 63;
            // 
            // labelIcao
            // 
            this.labelIcao.AutoSize = true;
            this.labelIcao.Location = new System.Drawing.Point(3, 133);
            this.labelIcao.Name = "labelIcao";
            this.labelIcao.Size = new System.Drawing.Size(62, 13);
            this.labelIcao.TabIndex = 62;
            this.labelIcao.Text = "ICAO 9303:";
            // 
            // MrzControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.panelMrz);
            this.Name = "MrzControl";
            this.Size = new System.Drawing.Size(934, 500);
            this.Load += new System.EventHandler(this.MrzControl_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDocFields)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownMinDaysTillExpiry)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownMinAge)).EndInit();
            this.panelChecks.ResumeLayout(false);
            this.panelChecks.PerformLayout();
            this.panelMrz.ResumeLayout(false);
            this.panelMrz.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.tabPageChecks.ResumeLayout(false);
            this.tabPageMrzFields.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.tabPageSubstitutionRules.ResumeLayout(false);
            this.tabPageSubstitutionRules.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewDocFields;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown numericUpDownMinDaysTillExpiry;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown numericUpDownMinAge;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panelChecks;
        private System.Windows.Forms.Panel panelMrz;
        public System.Windows.Forms.CheckBox checkBoxB900Ink;
        public System.Windows.Forms.CheckBox checkBoxUvDull;
        public System.Windows.Forms.CheckBox checkBoxAutoParse;
        public System.Windows.Forms.CheckBox checkBoxClippedSize;
        public System.Windows.Forms.CheckBox checkBoxClippedShape;
        public System.Windows.Forms.CheckBox checkBoxVisMoved;
        public System.Windows.Forms.CheckBox checkBoxIrMoved;
        public SampleNet.StateLabel stateLabelClippedSize;
        public SampleNet.StateLabel stateLabelClippedShape;
        public SampleNet.StateLabel stateLabelVisMoved;
        public SampleNet.StateLabel stateLabelIrMoved;
        public SampleNet.StateLabel stateLabelB900Ink;
        public SampleNet.StateLabel stateLabelUvDull;
        public SampleNet.StateLabel stateLabelChecksumValid;
        public SampleNet.StateLabel stateLabelCharsValid;
        public SampleNet.StateLabel stateLabelDaysTillExpiry;
        public SampleNet.StateLabel stateLabelMinAge;
        public StateLabel stateLabelPixelDensityDpi;
        public StateLabel stateLabelPixelDensityPpm;
        public System.Windows.Forms.CheckBox checkBoxPixelDensity;
        private System.Windows.Forms.TextBox textBoxSubstitutions;
        private System.Windows.Forms.ComboBox comboBoxSubstitutionField;
        private System.Windows.Forms.CheckBox checkBoxSubstitute;
        public StateLabel stateLabelDocType;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPageMrzFields;
        private System.Windows.Forms.TabPage tabPageSubstitutionRules;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TabPage tabPageChecks;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.TextBox textBoxMrz;
        private System.Windows.Forms.Button buttonClean;
        private System.Windows.Forms.ListBox listBoxGetFlags;
        private System.Windows.Forms.Button buttonParse;
        public StateLabel stateLabelIcao;
        private System.Windows.Forms.Label labelIcao;
    }
}
