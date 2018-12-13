using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Imaging;
using System.IO;

namespace SampleNet
{
    public partial class ImageViewForm : Form
    {
        public ImageViewForm()
        {
            InitializeComponent();
        }

        public Image Image
        {
            get { return picture.Image; }
            set { picture.Image = value; }
        }

 

        public void Clear()
        {
            picture.Image = null;
            picture.SizeMode = PictureBoxSizeMode.Zoom;
        }

        private void ImageViewForm_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
            {
                picture.Image = null;
                Visible = false;
            }
        }

        public void Close()
        {
            picture.Image = null;
            Visible = false;
        }
        
        private void buttonClose_Click(object sender, EventArgs e)
        {
            Close();
        }

        public void OriginalSize()
        {
            picture.SizeMode = PictureBoxSizeMode.AutoSize;
            picture.Dock = DockStyle.None;
        }

        private void buttonOrigSize_Click(object sender, EventArgs e)
        {
            OriginalSize();
        }

        public void Zoom()
        {
            picture.SizeMode = PictureBoxSizeMode.Zoom;
            picture.Dock = DockStyle.Fill;
        }

        private void buttonZoom_Click(object sender, EventArgs e)
        {
            Zoom();
        }

        private void ImageViewForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            WindowState = FormWindowState.Normal;
            e.Cancel = true;
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {

            try 
            { 
                if (DialogResult.OK != saveDialog.ShowDialog())
                    return;

                System.Drawing.Imaging.ImageFormat format = System.Drawing.Imaging.ImageFormat.Png;
                if (saveDialog.FileName.ToLower().EndsWith(".jpg"))
                {
                    format = System.Drawing.Imaging.ImageFormat.Jpeg;
                }
                if (saveDialog.FileName.ToLower().EndsWith(".jpeg"))
                {
                    format = System.Drawing.Imaging.ImageFormat.Jpeg;
                }
                else if (saveDialog.FileName.ToLower().EndsWith(".bmp"))
                {
                    format = System.Drawing.Imaging.ImageFormat.Bmp;
                }
                else if (saveDialog.FileName.ToLower().EndsWith(".png"))
                {
                    format = System.Drawing.Imaging.ImageFormat.Png;
                }
                else if (saveDialog.FileName.ToLower().EndsWith(".gif"))
                {
                    format = System.Drawing.Imaging.ImageFormat.Gif;
                }

                Bitmap bmp = new Bitmap(picture.Image);
                bmp.SetResolution(picture.Image.HorizontalResolution, picture.Image.VerticalResolution);

                bmp.Save(saveDialog.FileName, format);
            }
            catch (System.Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

 
    }

   
}
