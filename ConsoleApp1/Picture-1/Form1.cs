using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace wfClient
{
    public partial class Form1 : Form
    {
        Socket socket;
        Socket client;

        byte[] buffer;
        MemoryStream stream;


        public Form1()
        {
            InitializeComponent();

            socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            buffer = new byte[10000];
            stream = new MemoryStream(buffer);

            try
            {
                socket.Connect("127.0.0.1", 904);
            }

            catch
            {
                MessageBox.Show("Connection Error");
                Application.Exit();
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            var fileDialog = new OpenFileDialog()
            {
                Filter = "Images only. |*.jpg; *.png; *.gif"
            };
            fileDialog.ShowDialog();

            pictureBox1.Image = Image.FromFile(fileDialog.FileName);
        }



        private void button2_click(object sender, EventArgs e)
        {
            if(pictureBox1.Image != null)
            {
                pictureBox1.Image.Save(stream, System.Drawing, Imaging.ImageFormat.Png);
                socket.Send(buffer);
            }
        }
    }
}
