using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Desko.Mrz;
using Desko.FullPage;

namespace SampleNet
{
    public partial class MrzControl : UserControl
    {
        public MrzControl()
        {
            InitializeComponent();
        }

        BindingList<MrzEntry> entries = new BindingList<MrzEntry>();


        private void initSelection()
        {
            if (comboBoxSubstitutionField.Items.Count == 0)
            {
                foreach (Desko.Mrz.DocField v in Enum.GetValues(typeof(Desko.Mrz.DocField)))
                {
                    comboBoxSubstitutionField.Items.Add(v);
                    if (v == Desko.Mrz.DocField.HolderNationality)
                        comboBoxSubstitutionField.SelectedItem = v;
                }
            }

            if (listBoxGetFlags.Items.Count == 0)
            {
                foreach (Desko.Mrz.GetFlags v in Enum.GetValues(typeof(Desko.Mrz.GetFlags)))
                {
                    listBoxGetFlags.Items.Add(v);
                }
            }

        }
        private void MrzControl_Load(object sender, EventArgs e)
        {
            dataGridViewDocFields.DataSource = entries;
            initSelection();
            
        }

        private void buttonParse_Click(object sender, EventArgs e)
        {
            Tools.HandleApiExceptions(delegate()
            {
                initSelection();
                entries.Clear();
                using (Desko.Mrz.MrzDescriptor desc = new Desko.Mrz.MrzDescriptor())
                {


                    GetFlags getFlags = GetFlags.None;
                    foreach (GetFlags f in listBoxGetFlags.SelectedItems)
                    {
                        getFlags = (getFlags | f);
                    }

                    desc.ParseMrz(textBoxMrz.Text);

                    Desko.Mrz.DocField subfield = (Desko.Mrz.DocField) comboBoxSubstitutionField.SelectedItem;
                    foreach (Desko.Mrz.DocField v in Enum.GetValues(typeof(Desko.Mrz.DocField)))
                    {
                        if (v == subfield && checkBoxSubstitute.Checked)
                        {
                            using (SubstitutionRules rules = new SubstitutionRules())
                            {
                                rules.InitFromString(textBoxSubstitutions.Text);

                                entries.Add(new MrzEntry { Field = v.ToString(), Text = rules.Substitute(desc.GetField(v, getFlags)) });
                            }
                        }
                        else
                        {
                            entries.Add(new MrzEntry { Field = v.ToString(), Text = desc.GetField(v, getFlags) });
                        }
                    }

                    try
                    {
                        stateLabelIcao.State = desc.ValidateIcao() ? LabelState.Good : LabelState.Bad;
                    }
                    catch (MrzException ex)
                    {
                        stateLabelIcao.State = LabelState.Attention;
                    }
                    try
                    {
                        stateLabelChecksumValid.State = desc.ValidateAllChecksums() ? LabelState.Good : LabelState.Bad; 
                    } catch (MrzException ex) {
                        stateLabelChecksumValid.State = LabelState.Attention;
                    }
                    try
                    {
                        stateLabelCharsValid.State = desc.ValidateCharacters() ? LabelState.Good : LabelState.Bad;
                    }
                    catch (MrzException ex)
                    {
                        stateLabelCharsValid.State = LabelState.Attention;
                    }
                    try
                    {
                    stateLabelDaysTillExpiry.State = desc.ValidateExpiryDate((int)numericUpDownMinDaysTillExpiry.Value) ? LabelState.Good : LabelState.Bad;
                    }
                    catch (MrzException ex)
                    {
                        stateLabelDaysTillExpiry.State = LabelState.Attention;
                    }
                    try
                    {
                        stateLabelMinAge.State = desc.ValidateMinimumAge((int)numericUpDownMinAge.Value) ? LabelState.Good : LabelState.Bad;
                    }
                    catch (MrzException ex)
                    {
                        stateLabelMinAge.State = LabelState.Attention;
                    }
                    stateLabelDocType.Text = desc.DocType.ToString();

                    dataGridViewDocFields.DataSource = entries;
                    dataGridViewDocFields.Columns[0].AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCellsExceptHeader;
                    dataGridViewDocFields.Columns[1].AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCellsExceptHeader;
                }
            });

            
        }

        private void buttonClean_Click(object sender, EventArgs e)
        {
            stateLabelDocType.Text = "";
            textBoxMrz.Clear();
            entries.Clear();
            stateLabelPixelDensityDpi.Text = "";
            stateLabelPixelDensityPpm.Text = "";
            stateLabelMinAge.State = LabelState.Off;
            stateLabelDaysTillExpiry.State = LabelState.Off;
            stateLabelCharsValid.State = LabelState.Off;
            stateLabelChecksumValid.State = LabelState.Off;
            stateLabelUvDull.State = LabelState.Off;
            stateLabelB900Ink.State = LabelState.Off;
            stateLabelIrMoved.State = LabelState.Off;
            stateLabelVisMoved.State = LabelState.Off;
            stateLabelClippedShape.State = LabelState.Off;
            stateLabelClippedSize.State = LabelState.Off;
        }


        public void Clear()
        {
            buttonClean_Click(this, new EventArgs());
        }

        public void RunForMrz(String mrz)
        {
            textBoxMrz.Text = mrz;
            if (checkBoxAutoParse.Checked)
            {
                if (mrz == null || mrz == "")
                    buttonClean_Click(this, new EventArgs());
                else
                    buttonParse_Click(this, new EventArgs());
            }
        }

        private void checkBoxVisMoved_CheckedChanged(object sender, EventArgs e)
        {

        }

       

     
    }



    public class MrzEntry
    {
        public string Field { get; set; }
        public string Text { get; set; }
    }
}
