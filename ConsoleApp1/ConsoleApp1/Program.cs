using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace Client
{
    class Program
    {
        static Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        static byte[] buffer = new byte[1024];
        static MemoryStream stream = new MemoryStream(buffer);
        static BinaryWriter writer = new BinaryWriter(stream);
       

        static void Main(string[] args)
        {
            Title = "Client";
            socket.Connect("127.0.0.1", 904);
            buffer = Encoding.ASCII.GetBytes("password" + "@" + "login");

            writer.Write("login");
            writer.Write("password");

            socket.Send(buffer);

            ReadLine();

        }
    }
}
