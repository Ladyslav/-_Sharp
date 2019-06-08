using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Events
{
    delegate void DeadHandler(Enemy e);
    delegate void Message();
    class Program
    {

       public static Random R = new Random();
        static void Main(string[] args)
        {
            //Message messages = GetMessage();
            //messages = A;
            //messages();

            DeadHandler handlers = WriteDeadMessage;
            handlers += AchivmentUnlock;
            
            Enemy[] enemys = 
            {
                new Enemy(WriteDeadMessage),
                new Enemy(handlers),
                new Enemy(WriteDeadMessage)
            };
            //enemys[0].OnEnemyDead(enemys[0]);
            //enemys[0].OnEnemyDead += AchivmentUnlock;
            //Enemy e = new Enemy(null);
            //e.OnEnemyDead += WriteDeadMessage;
            //enemys[1].OnEnemyDead -= AchivmentUnlock;

            Player player = new Player();

            while (true)
            {
                foreach (var e in enemys)
                {
                    e.Update();
                }
                player.AttackEnemys(enemys);
              
            }
        }


        static void A()
        {
            Console.WriteLine("A");
        }


        static void B()
        {
            Console.WriteLine("B");
        }

        static void C()
        {
            Console.WriteLine("C");
        }


        static Message GetMessage()
        {
            return A;
        }

        static void AchivmentUnlock(Enemy e)
        {
            Console.WriteLine("Unblock achivment");
        }

        static void WriteDeadMessage(Enemy e)
        {
            Console.WriteLine("Someone is dead");
        }
    }
}
