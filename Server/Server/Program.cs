using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace Server
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                TcpListener serverSocket = new TcpListener(IPAddress.Any, 7000);
                Console.WriteLine("Server started");
                serverSocket.Start();


                while (true)
                {
                    TcpClient clientSocket = serverSocket.AcceptTcpClient();
                    NetworkStream stream = clientSocket.GetStream();

                    byte[] bytes = new byte[256];
                   int lenght = stream.Read(bytes, 0, bytes.Length);
                    string request = Encoding.ASCII.GetString(bytes, 0, lenght);
                    Console.WriteLine("Got request" + request);


                    string message = "Length of your request:" + request.Length;
                    bytes = Encoding.ASCII.GetBytes(message);
                    stream.Write(bytes, 0, bytes.Length);
                    stream.Flush();


                    Console.WriteLine("Send Message: " + message);
                    clientSocket.Close();
                }


                serverSocket.Stop();
                Console.WriteLine("Server stopped");
            }

            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            Console.ReadKey();
        }
    }
}
