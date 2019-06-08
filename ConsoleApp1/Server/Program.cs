using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace Server
{
    class Program
    {
        static Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        static byte[] buffer = new byte[1024];
        static MemoryStream stream = new MemoryStream(buffer);
        static BinaryReader reader = new BinaryReader(stream);
    

        static void Main(string[] args)
        {
            Title = "Server";
            socket.Bind(new IPEndPoint(IPAddress.Any, 904));
            socket.Listen(5);

            Socket client = socket.Accept();
            client.Receive(buffer);

            string login = reader.ReadString();
            string password = reader.ReadString();

            stream.Position = 0;

            WriteLine(login);
            WriteLine(password);


            ReadLine();
        }
    }
}
