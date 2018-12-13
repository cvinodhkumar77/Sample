using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Desko.FullPage;

namespace SampleNet
{
    public partial class FeedbackControl : UserControl
    {
        public FeedbackControl()
        {
            InitializeComponent();
        }


      
        private void buttonGetBuzzer_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                BuzzerSettings settings = Api.GetBuzzer();
                numericBuzzerVolume.Value = settings.Volume;
                numericBuzzerDuration.Value = settings.Duration;
                numericBuzzerHighTime.Value = settings.HighTime;
                numericBuzzerLowTime.Value = settings.LowTime;
            });
        }

        private void buttonSetBuzzer_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                BuzzerSettings settings = new BuzzerSettings();
                settings.Volume = (byte)numericBuzzerVolume.Value;
                settings.Duration = (int)numericBuzzerDuration.Value;
                settings.HighTime = (int)numericBuzzerHighTime.Value;
                settings.LowTime = (int)numericBuzzerLowTime.Value;
                Api.SetBuzzer(settings);
            });
        }

        private void buttonUseBuzzer_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                Api.UseBuzzer();
            });
        }

        private void buttonLedGet_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                LedSettings settings = Api.GetStatusLed(checkLedActive.Checked);
                comboLedColor.SelectedIndex = (int)settings.Color;
                numericLedDuration.Value = settings.Duration;
                numericLedHighTime.Value = settings.HighTime;
                numericLedLowTime.Value = settings.LowTime;
                checkBoxLedEnabled.Checked = settings.Enabled;
                comboLedUsage.SelectedIndex = (int)settings.Usage;
            });
        }

        private void buttonLedSet_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                LedSettings settings = new LedSettings();
                settings.Color = (LedColor)comboLedColor.SelectedIndex;
                settings.Duration = (int)numericLedDuration.Value;
                settings.HighTime = (int)numericLedHighTime.Value;
                settings.LowTime = (int)numericLedLowTime.Value;
                settings.Usage = (LedUsage)comboLedUsage.SelectedIndex;
                settings.Enabled = checkBoxLedEnabled.Checked;
                Api.SetStatusLed(checkLedActive.Checked, settings);
            });
        }

        private void buttonLedUse_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                Api.UseStatusLed(checkLedActive.Checked);
            });
        }

        private void panel5_Paint(object sender, PaintEventArgs e)
        {

        }
        
        private void buttonDisplaySetText_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                Api.ShowDisplay(Tools.ApplyEscape(textBoxDisplay.Text));
            });
        }

        private void buttonDisplaySwitch_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                Api.ShowDisplay((int) numericUpDownDisplayPage.Value, (int) numericUpDownDisplayPosition.Value);
            });
        }

        private void buttonDisplaySwitchWithText_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                Api.ShowDisplay((int)numericUpDownDisplayPage.Value, (int)numericUpDownDisplayPosition.Value, Tools.ApplyEscape(textBoxDisplay.Text));
            });
        }

        private void buttonDisplayClear_Click(object sender, EventArgs e)
        {
            if (DialogResult.OK != MessageBox.Show("Clear stored image on page " + numericUpDownDisplayPage.Value + ", position " + numericUpDownDisplayPosition.Value + "?","Clear image",MessageBoxButtons.OKCancel,MessageBoxIcon.Question))
                return;

            Tools.HandleApiExceptions(delegate()
            {
                Api.ClearDisplay((int)numericUpDownDisplayPage.Value, (int)numericUpDownDisplayPosition.Value);
            });

        }

        private void buttonDisplayShow_Click(object sender, EventArgs e)
        {
            if (pictureBoxDisplay.Image == null)
            {
                MessageBox.Show("Failed: no image loaded.", "Error on show image", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            Tools.HandleApiExceptions(delegate()
            {
                Api.ShowDisplay(pictureBoxDisplay.Image);
            });
            
        }

        private void buttonDisplayShowWithText_Click(object sender, EventArgs e)
        {
            if (pictureBoxDisplay.Image == null)
            {
                MessageBox.Show("Failed: no image loaded.", "Error on show image", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            Tools.HandleApiExceptions(delegate()
            {
                Api.ShowDisplay(pictureBoxDisplay.Image, Tools.ApplyEscape(textBoxDisplay.Text));
            });
        }

        private void buttonDisplayStore_Click(object sender, EventArgs e)
        {
            if (pictureBoxDisplay.Image == null)
            {
                MessageBox.Show("Failed: no image loaded.", "Error on show image", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            if (DialogResult.OK != MessageBox.Show("Overwrite stored image on page " + numericUpDownDisplayPage.Value + ", position " + numericUpDownDisplayPosition.Value + "?", "Overwrite image", MessageBoxButtons.OKCancel, MessageBoxIcon.Question))
                return;

            Tools.HandleApiExceptions(delegate()
            {
                Api.StoreDisplay((int)numericUpDownDisplayPage.Value, (int)numericUpDownDisplayPosition.Value, pictureBoxDisplay.Image);
            });
        }

        Bitmap loadedImage = null;
        private void buttonDisplayLoad_Click(object sender, EventArgs e)
        {
            if (DialogResult.OK != openFileDialogDisplay.ShowDialog())
                return;

            loadedImage = new Bitmap(Image.FromFile(openFileDialogDisplay.FileName));
            pictureBoxDisplay.Image = (Bitmap) loadedImage.Clone();
            pictureBoxDisplay.Cursor = Cursors.Hand;
        }


        private void drawCross(TouchEventArgs args, Brush brush)
        {
            if (loadedImage == null)
            {
                loadedImage = new Bitmap(pictureBoxDisplay.Width, pictureBoxDisplay.Height);
            }

            pictureBoxDisplay.Image = new Bitmap(loadedImage);

            Graphics g;
            g = Graphics.FromImage(pictureBoxDisplay.Image);

            Pen mypen = new Pen(brush);
            int posx = (int)(args.Position.X * loadedImage.Width);
            int posy = (int)(args.Position.Y * loadedImage.Height);
            int x0 = Math.Max(0, posx - 4);
            int x1 = Math.Min(loadedImage.Width - 1, posx + 4);
            int y0 = Math.Max(0, posy - 4);
            int y1 = Math.Min(loadedImage.Width - 1, posy + 4);
            mypen.Width = 3;
            g.DrawLine(mypen, x0, posy, x1, posy);
            g.DrawLine(mypen, posx, y0, posx, y1);
            //            g.Clear(Color.White);
            g.Dispose();
        }

        public void OnTouchDown(Object sender, TouchEventArgs args)
        {
            drawCross(args, Brushes.LightGreen);
        }

        public void OnTouchUp(Object sender, TouchEventArgs args)
        {
            drawCross(args, Brushes.Pink);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
           {
               Pair<int> dims = Api.GetDisplayDimensions();
               textBoxDisplayDims.Text = dims.X + "x" + dims.Y;
           });
        }

        private void buttonSetExtStatusLed_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                Api.SetExtStatusLed((LedColor) comboBoxColorExtern.SelectedIndex);
            });
        }

    }
}
