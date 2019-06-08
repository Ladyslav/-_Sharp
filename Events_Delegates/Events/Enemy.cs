using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Events
{
    class Enemy
    {        
        private int _health = 100;
        public event DeadHandler OnEnemyDead;
        public bool isDead => _health <= 0;

        public Enemy(DeadHandler onEnemyDead, int heath = 100)
        {
            OnEnemyDead = onEnemyDead;
        }

        public void Attack(int damage)
        {
            if (!isDead)
            {
                _health -= damage;
                if (isDead)
                {
                    OnEnemyDead?.Invoke(this);
                }
            }
        }

        public void Update()
        {
            Attack(1);
        }
    }
}
