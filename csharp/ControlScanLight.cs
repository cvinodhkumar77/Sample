using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SampleNet
{
    public partial class ControlScanLight : UserControl
    {
        ImageViewForm viewForm = new ImageViewForm();
        public ControlScanLight()
        {
            InitializeComponent();
        }


       

       
       

        public void Clear()
        {
            Full = null;
           
            MoveDelta = -1.0;
        }

        public Image Full
        {
            get
            {
                return pictureBoxFull.Image;
            }
            set
            {
                pictureBoxFull.Image = value;
            }
        }


        private void pictureBox_Click(object sender, EventArgs e)
        {
            PictureBox box = (PictureBox)sender;

            viewForm.Clear();
            if (box.Image == null)
                return;

            viewForm.Image = box.Image;
            viewForm.Show();
        }

        private void ControlScanLight_Load(object sender, EventArgs e)
        {
            Clear();
        }

        [
         Category("Appearance"),
         Description("Show document motion info.")
         ]
        public bool ShowMoveInfo
        {
            get {
                return stateLabelMove.Enabled;
            }
            set {
                stateLabelMove.Enabled = value;
                stateLabelMove.Visible = value;
            }
        }

       
      
       
        double moveDelta = -1.0;
        public double MoveDelta
        {
            get { return moveDelta; }
            set
            {
                moveDelta = value;
                if (value < 0.0)
                {
                    stateLabelMove.State = LabelState.Attention;
                    stateLabelMove.Text = "UNKNOWN: " + value.ToString();
                }
                else if (value > 1.0)
                {
                    stateLabelMove.State = LabelState.Bad;
                    stateLabelMove.Text = "MOVED: " + value.ToString();
                }
                else
                {
                    stateLabelMove.State = LabelState.Good;
                    stateLabelMove.Text = "STILL: " + value.ToString();
                }
            }
        }
    }

    public enum MoveType { Unknown, Still, Moving };
}
