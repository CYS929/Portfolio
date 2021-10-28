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

        private void Form1_MouseLeave(object sender, EventArgs e)
        {
            label1.Text = ("游標離開表單");
            //當滑鼠移開表單時(不需點擊只需當游標不在標單上時),讓label1顯示{游標離開表單};
        }

        private void Form1_MouseEnter(object sender, EventArgs e)
        {
            label1.Text = ("游標在表單上");
        } //當滑鼠移入表單時(不需點擊只需當游標在標單上時),讓label1顯示{游標在表單上};

        private void linkLabel1_MouseClick(object sender, MouseEventArgs e)
        {
            System.Diagnostics.Process.Start("https://www.yzu.edu.tw/index.php/tw/");  // 製作一個LINKLABEL1能連結到元智首頁;
            //LinkLabel.Link link = new LinkLabel.Link();       助教解法 
            //link.LinkData = "http://www.yzu.edu.tw"           助教解法
            //linkLabel1.Links.Add(Link);                       助教解法


            linkLabel1.Font = new Font("新細明體", 12, FontStyle.Italic);  //按下連結後讓字體變成斜體


            //https://docs.microsoft.com/zh-tw/dotnet/framework/winforms/controls/how-to-set-font-attributes-for-the-windows-forms-richtextbox-control
        }
        int x = 0,y=0; //要在外面宣告 不然一出去一個FUNCTION就沒了
        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            x++;
            y++;
            label3.Text = y.ToString();
            if (x == 10)
            {
                MessageBox.Show("阿是按夠了沒");

                x = 0;
                
            } //滑鼠點擊10次表單後 MSGBOX顯示{阿是按夠了沒}   延伸:如果要PRINT出點擊次數 你會如何修改程式?
            //label2.Text = click_count.tostring();
           
            
        }
        int kk,k,kkk;
        private void btn_chanColor_Click(object sender, EventArgs e)
        {
            Random r = new Random();
            kk=r.Next(127, 255);
            k = r.Next(127, 255);
            kkk = r.Next(127, 255);
            this.BackColor = Color.FromArgb(k,kk,kkk);
        }
    }
}
