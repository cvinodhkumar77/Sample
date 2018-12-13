namespace SampleNet
{
    partial class LogTextControl
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
            this.buttonClear = new System.Windows.Forms.Button();
            this.numericMaxLines = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.checkBoxLog = new System.Windows.Forms.CheckBox();
            this.textBoxLogFile = new System.Windows.Forms.TextBox();
            this.checkWrap = new System.Windows.Forms.CheckBox();
            this.textBox = new System.Windows.Forms.RichTextBox();
            ((System.ComponentModel.ISupportInitialize)(this.numericMaxLines)).BeginInit();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonClear
            // 
            this.buttonClear.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonClear.Location = new System.Drawing.Point(565, 3);
            this.buttonClear.Name = "buttonClear";
            this.buttonClear.Size = new System.Drawing.Size(75, 23);
            this.buttonClear.TabIndex = 0;
            this.buttonClear.Text = "Clear";
            this.buttonClear.UseVisualStyleBackColor = true;
            this.buttonClear.Click += new System.EventHandler(this.buttonClear_Click);
            // 
            // numericMaxLines
            // 
            this.numericMaxLines.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.numericMaxLines.Location = new System.Drawing.Point(439, 6);
            this.numericMaxLines.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.numericMaxLines.Name = "numericMaxLines";
            this.numericMaxLines.Size = new System.Drawing.Size(120, 20);
            this.numericMaxLines.TabIndex = 1;
            this.numericMaxLines.Value = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(383, 8);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(50, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "max lines";
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.checkBoxLog);
            this.panel1.Controls.Add(this.textBoxLogFile);
            this.panel1.Controls.Add(this.checkWrap);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.numericMaxLines);
            this.panel1.Controls.Add(this.buttonClear);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel1.Location = new System.Drawing.Point(0, 361);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(643, 32);
            this.panel1.TabIndex = 3;
            // 
            // checkBoxLog
            // 
            this.checkBoxLog.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.checkBoxLog.AutoSize = true;
            this.checkBoxLog.Location = new System.Drawing.Point(309, 7);
            this.checkBoxLog.Name = "checkBoxLog";
            this.checkBoxLog.Size = new System.Drawing.Size(68, 17);
            this.checkBoxLog.TabIndex = 6;
            this.checkBoxLog.Text = "log to file";
            this.checkBoxLog.UseVisualStyleBackColor = true;
            // 
            // textBoxLogFile
            // 
            this.textBoxLogFile.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxLogFile.Location = new System.Drawing.Point(58, 5);
            this.textBoxLogFile.Name = "textBoxLogFile";
            this.textBoxLogFile.Size = new System.Drawing.Size(245, 20);
            this.textBoxLogFile.TabIndex = 5;
            this.textBoxLogFile.Text = "C:\\temp\\log.txt";
            // 
            // checkWrap
            // 
            this.checkWrap.AutoSize = true;
            this.checkWrap.Location = new System.Drawing.Point(3, 7);
            this.checkWrap.Name = "checkWrap";
            this.checkWrap.Size = new System.Drawing.Size(49, 17);
            this.checkWrap.TabIndex = 3;
            this.checkWrap.Text = "wrap";
            this.checkWrap.UseVisualStyleBackColor = true;
            this.checkWrap.CheckedChanged += new System.EventHandler(this.checkWrap_CheckedChanged);
            // 
            // textBox
            // 
            this.textBox.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBox.Font = new System.Drawing.Font("Consolas", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox.Location = new System.Drawing.Point(0, 0);
            this.textBox.Name = "textBox";
            this.textBox.ReadOnly = true;
            this.textBox.Size = new System.Drawing.Size(643, 361);
            this.textBox.TabIndex = 4;
            this.textBox.Text = "";
            this.textBox.WordWrap = false;
            // 
            // LogTextControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.textBox);
            this.Controls.Add(this.panel1);
            this.Name = "LogTextControl";
            this.Size = new System.Drawing.Size(643, 393);
            ((System.ComponentModel.ISupportInitialize)(this.numericMaxLines)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonClear;
        private System.Windows.Forms.NumericUpDown numericMaxLines;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.CheckBox checkWrap;
        private System.Windows.Forms.RichTextBox textBox;
        private System.Windows.Forms.CheckBox checkBoxLog;
        private System.Windows.Forms.TextBox textBoxLogFile;
    }
}
