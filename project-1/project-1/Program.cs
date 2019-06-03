using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace project_1
{
    class Program
    {
        static void Main(string[] args)
        {
            TcpListener serverSocket = new TcpListener(7000);
            Console.WriteLine("Server started");
            TcpClient clientSocket = serverSocket.AcceptTcpClient();


            clientSocket.Close();
            serverSocket.Stop();
            Console.WriteLine("Server stopped");
        }
    }
}
