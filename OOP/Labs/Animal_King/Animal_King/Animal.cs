using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animal_King
{
    #region entity
    public class Animal
    {
        int _HP;
        public int HP
        {
            get => _HP;
            set => _HP = value;
        }
        string name;
        public string Name
        {
            get => name;
        }
        int x;
        public int X
        {
            get => x;
        }
        int y;
        public int Y
        {
            get => y;
        }
        public Animal(string name, int x, int y, int HP)
        {
            this.name = name;
            this.x = x;
            this.y = y;
            this._HP = HP;

        }
        public void MoveTo(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
        public void MoveLeft()
        {
            if (x > 0) { this.x--; }
        }
        public void MoveRight(int maxX)
        {
            if (x < maxX) { this.x++; }
        }
        public void MoveUp()
        {
            if (y > 0) { this.y--; }
        }
        public void MoveDown(int maxY)
        {
            if (y < maxY) { this.y++; }
        }
        public virtual void TakeDamage(int damage)
        {
            HP -= damage;
        }

    }
    public class Player : Animal
    {
        int swordDMG = 7;

        public Player(string name, int x, int y, int hP) : base(name, x, y, hP)
        {
        }

        public void AttackSword(ref Animal obj)
        {
            if (obj != null)
            {
                obj.TakeDamage(swordDMG);
            }

        }
    }
    public class Mammal : Animal
    {
        protected Mammal(string name, int x, int y, int hp) : base(name, x, y, hp)
        {

        }
    }

    public class Lion : Mammal
    {
        int Damage = 7;
        public Lion(string name, int x, int y, int hp) : base(name, x, y, hp)
        {
            this.HP = 24;
        }
        public int getHP()
        {
            return HP;
        }
        public Animal ConvertToAnimal()
        {
            Animal ret = new Animal(this.Name, this.X, this.Y, this.HP);
            return ret;
        }
    }

    public class Bird : Animal
    {
        bool isFlying;

        public Bird(string name, int x, int y, int hp) : base(name, x, y, hp)
        {
            this.isFlying = false;
        }

        public void FlyUp()
        {
            this.isFlying = true;
        }

        public void FlyDown()
        {
            this.isFlying = false;
        }
    }

    public class Fish : Animal
    {
        int _z;
        public int z
        {
            get => _z;
            set
            {
                if (value > 0) { throw new Exception("Рыба не может находиться выше уровня моря"); }
                else _z = value;
            }
        }
        protected Fish(string name, int x, int y, int hp) : base(name, x, y, hp)
        {
            this.z = 0;
        }
    }
#endregion
    public class Window
    {
        private int borderX;
        private int borderY;
        public Window(int x, int y)
        {
            borderX = x;
            borderY = y;
        }

    }
}
