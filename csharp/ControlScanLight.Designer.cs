namespace SampleNet
{
    partial class ControlScanLight
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
            this.pictureBoxFull = new System.Windows.Forms.PictureBox();
            this.stateLabelMove = new SampleNet.StateLabel();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxFull)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBoxFull
            // 
            this.pictureBoxFull.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBoxFull.Location = new System.Drawing.Point(0, 0);
            this.pictureBoxFull.Name = "pictureBoxFull";
            this.pictureBoxFull.Size = new System.Drawing.Size(303, 238);
            this.pictureBoxFull.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBoxFull.TabIndex = 0;
            this.pictureBoxFull.TabStop = false;
            this.pictureBoxFull.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // stateLabelMove
            // 
            this.stateLabelMove.AttentionText = "Attention";
            this.stateLabelMove.BadText = "Moved";
            this.stateLabelMove.GoodText = "Still";
            this.stateLabelMove.Location = new System.Drawing.Point(3, 184);
            this.stateLabelMove.Name = "stateLabelMove";
            this.stateLabelMove.OffText = "Still";
            this.stateLabelMove.Size = new System.Drawing.Size(68, 30);
            this.stateLabelMove.State = SampleNet.LabelState.Off;
            this.stateLabelMove.TabIndex = 1;
            // 
            // ControlScanLight
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.stateLabelMove);
            this.Controls.Add(this.pictureBoxFull);
            this.Name = "ControlScanLight";
            this.Size = new System.Drawing.Size(303, 238);
            this.Load += new System.EventHandler(this.ControlScanLight_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxFull)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBoxFull;
        private StateLabel stateLabelMove;
    }
}
