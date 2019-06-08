using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Events
{
    class Player
    {
        public void AttackEnemys(Enemy[] enemys)
        {
            Enemy e = enemys[Program.R.Next(0, enemys.Length)];
            e.Attack(10);
        }
    }
}
