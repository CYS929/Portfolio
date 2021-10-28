using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Random r = new Random();
           // for(int i=1;i<=6;i++)
            //{
            textBox1.Text=r.Next(1, 54).ToString();
            textBox2.Text = r.Next(1, 54).ToString();
            textBox3.Text = r.Next(1, 54).ToString();
            textBox4.Text = r.Next(1, 54).ToString();
            textBox5.Text = r.Next(1, 54).ToString();
            textBox6.Text = r.Next(1, 54).ToString();

            // }
        }
    }
}
