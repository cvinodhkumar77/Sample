using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Globalization;

namespace SampleNet
{
    public partial class LogTextControl : UserControl
    {
        long startTicks = 0;
        public LogTextControl()
        {
            InitializeComponent();
        }

        private void checkWrap_CheckedChanged(object sender, EventArgs e)
        {
            textBox.WordWrap = checkWrap.Checked;
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            textBox.Clear();
            startTicks = 0;
        }

        public void AppendTimestampLine(string text)
        {
            AppendText(String.Format("{0:yyyy-MM-ddTHH-mm-ss,fff}", DateTime.Now) + " " + text + "\r\n");
        }

        public void AppendTicksLine(string text)
        {
            if (startTicks == 0)
                startTicks = DateTime.Now.Ticks;

            long elapsedTicks = DateTime.Now.Ticks - startTicks;
            TimeSpan elapsedSpan = new TimeSpan(elapsedTicks);

            AppendText(
                elapsedSpan.TotalSeconds.ToString("000000.000000", CultureInfo.InvariantCulture) + " " + text + "\r\n");
        }

        public void AppendLine(string text)
        {
            AppendText(text + "\r\n");
        }

        public void AppendText(string text)
        {
            textBox.AppendText(text);

            if (checkBoxLog.Checked)
            {
                try
                {
                    using (StreamWriter sw = File.AppendText(textBoxLogFile.Text))
                    {
                        sw.Write(text);
                    }	
                }
                catch (System.Exception ex) { }
            }

            if (textBox.Lines.Count() > numericMaxLines.Value)
            {

                int start_index = 0;
                int count = textBox.GetFirstCharIndexFromLine(textBox.Lines.Count() - (int) numericMaxLines.Value);
                textBox.Text = textBox.Text.Remove(start_index, count);
            }
//            textBox.SelectionStart = myrichTextBox.Text.Length; //Set the current caret position at the end
            textBox.ScrollToCaret(); //Now scroll it automatically
        }

        public string LogFile
        {
            get { return textBoxLogFile.Text; }
            set { textBoxLogFile.Text = value; }
        }

        public void Clear()
        {
            textBox.Clear();
            startTicks = 0;
        }
    }
}
