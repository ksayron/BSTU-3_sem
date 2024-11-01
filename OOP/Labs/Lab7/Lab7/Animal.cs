using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using System.Diagnostics;

namespace Lab7
{
    interface IAnimal
    {
        void Roar();
        void Jump();
    }

    public abstract class Animal : IComparable
    {

        string name;
        int x;
        int y;
        int birth_year;
        int weight;
        string type;
        string species;
        public virtual string Species { get => species; }
        protected bool predetor;
        public string Name
        {
            get => name;
        }
        public int X
        {
            get => x;
        }
        public int Y
        {
            get => y;
        }
        public virtual int Year { get => birth_year; set { birth_year = value; } }
        public virtual int Weight { get => weight; set { weight = value; } }
        public string Type { get => type; }
        public bool IsPredetor { get { return predetor; } }
        public Animal(string name, int x, int y, int year, int weight)
        {
            this.name = name;
            this.x = x;
            this.y = y;
            this.birth_year = year;
            this.weight = weight;


        }
        public void MoveTo(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
        public virtual void MoveLeft()
        {
            if (x > 0) { this.x--; }
        }
        public virtual void MoveRight(int maxX)
        {
            if (x < maxX) { this.x++; }
        }
        public virtual void MoveUp()
        {
            if (y > 0) { this.y--; }
        }
        public virtual void MoveDown(int maxY)
        {
            if (y < maxY) { this.y++; }
        }
        public abstract void Roar();

        public int CompareTo(object? obj)
        {
            if (obj == null || obj as Animal == null) return 1;
            else
            {
                Animal animal = obj as Animal;
                if(animal.Name == this.name) return 0;
                if (this.Name.CompareTo(animal.Name) < 0) return -1;
                else return 1;
            }
            return 0;

        }

    }
    public class Mammal : Animal
    {
        string type = "Mammal";
        public Mammal(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {

        }
        public override void Roar()
        {
            Console.WriteLine("ррр-ррр-ррр");
        }
        public override string ToString()
        {
            return this.Name + ": " + this.X + " " + this.Y;
        }

    }

    public class Lion : Mammal, IAnimal
    {
        string species = "Lion";

        public override string Species { get => species; }
        public override int Weight
        {
            get => base.Weight;
            set
            {
                if (value > 300 || value < 50)
                {
                    throw new NotValidWeight("Вес льва может находится в диапозоне 50-300");
                }
                else { base.Weight = value; }
            }
        }
        public override int Year
        {
            get => base.Year;
            set
            {
                if (value < 1970)
                {
                    throw new NotValidYear("Неподходящий возраст");
                }
                else { base.Year = value; }
            }
        }
        public override void MoveLeft()
        {
            base.MoveLeft();
            base.MoveLeft();
        }
        public override void MoveRight(int maxX)
        {
            base.MoveRight(maxX);
            base.MoveRight(maxX);
        }
        public override void MoveUp()
        {
            base.MoveUp();
            base.MoveUp();
        }
        public override void MoveDown(int maxY)
        {
            base.MoveDown(maxY);
            base.MoveDown(maxY);
        }
        void IAnimal.Jump()
        {
            Console.WriteLine("скок");
        }
        void IAnimal.Roar()
        {
            Console.WriteLine("rahh");
        }
        public override void Roar()
        {
            Console.WriteLine("вызван от класса");
            base.Roar();
        }
        public Lion(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {
            this.predetor = true;
            this.Weight = weight;
            this.Year = year;
        }
        public override string ToString()
        {
            return this.species + " " + this.Name + ": " + this.X + " " + this.Y + " " + this.Year + " " + this.Weight; ;
        }
        public override bool Equals(object? obj)
        {
            Lion lion1 = obj as Lion;
            if (lion1 == null) return false;
            else
            {
                if (this.Name == lion1.Name && this.X == lion1.X && this.Y == lion1.Y) { return true; }
                else { return false; }
            }
        }
        public override int GetHashCode()
        {
            return (X + Y) % 7;
        }

        

    }

    public class Tiger : Mammal
    {
        string species = "Tiger";
        public override string Species { get => species; }
        public override void MoveLeft()
        {
            base.MoveLeft();
            base.MoveLeft();
            base.MoveLeft();
        }
        public override void MoveRight(int maxX)
        {
            base.MoveRight(maxX);
            base.MoveRight(maxX);
            base.MoveRight(maxX);
        }
        public override void MoveUp()
        {
            base.MoveUp();
            base.MoveUp();
            base.MoveUp();
        }
        public override void MoveDown(int maxY)
        {
            base.MoveDown(maxY);
            base.MoveDown(maxY);
            base.MoveDown(maxY);
        }
        public Tiger(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {
            this.predetor = true;
        }
        public override string ToString()
        {
            return this.species + " " + this.Name + ": " + this.X + " " + this.Y + " " + this.Year + " " + this.Weight + " " + this.Year + " " + this.Weight;
        }

    }

    public class Bird : Animal
    {
        string type = "Bird";
        bool isFlying;

        public Bird(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
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
        public override void Roar()
        {
            if (this == null) { throw new NullReferenceException("балбес"); }
            Console.WriteLine("чик-чирик");
        }
        public override string ToString()
        {
            return this.Name + ": " + this.X + " " + this.Y;
        }
    }
    public class Owl : Bird
    {
        public string species = "Owl";
        public override string Species { get => species; }
        const bool Nightvision = true;
        public Owl(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {
            this.predetor = true;
        }
        public override string ToString()
        {
            return this.species + " " + this.Name + ": " + this.X + " " + this.Y + " " + this.Year + " " + this.Weight; ;
        }

    }
    public class Parrot : Bird
    {
        public string species = "Parrot";
        public override string Species { get => species; }
        public Parrot(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {
            this.predetor = false;
        }
        public override string ToString()
        {
            return this.species + " " + this.Name + ": " + this.X + " " + this.Y + " " + this.Year + " " + this.Weight; ;
        }
    }

    public class Fish : Animal
    {
        string type = "Fish";
        int _z = 0;
        public int z
        {
            get => _z;
            set
            {
                if (_z + value > 0) { throw new NotValidZ("Рыба не может находиться выше уровня моря"); }
                else _z = value;
            }
        }
        public Fish(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {

        }
        public void SwimDown(int z)
        {
            this.z -= z;
        }
        public void SwimUp(int z)
        {
            this.z += z;
        }
        public override void Roar()
        {
            Console.WriteLine("бульк-бульк");
        }
        public void Jump()
        {
            try
            {
                this.z += 15;
            }
            catch (NotValidZ ex)
            {
                Console.WriteLine("Первая передача");
                throw ex;
            }
        }
    }

    public class Shark : Fish
    {
        public string species = "Shark";
        public override string Species { get => species; }
        public Shark(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {
            this.predetor = true;
        }
        public override string ToString()
        {
            return this.species + " " + this.Name + ": " + this.X + " " + this.Y + " " + this.Year + " " + this.Weight + " " + this.z;
        }
    }
    public sealed class Crocodile : Fish
    {
        public string species = "Crocodile";
        public override string Species { get => species; }
        public Crocodile(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {
            this.predetor = true;
        }
        public override string ToString()
        {
            return this.species + " " + this.Name + ": " + this.X + " " + this.Y + " " + this.Year + " " + this.Weight + " " + this.z;
        }
    }

    struct AnimalBowl
    {
        int radius;
        int depth;
        enum color
        {
            Red = 2,
            Green = 5,
            Blue = Green,
        }
    }
    public class AnimalComparer : IComparer<Animal>
    {
        public int Compare(Animal a1, Animal a2)
        {
            if (a1 is null || a2 is null)
                throw new ArgumentException("Некорректное значение параметра");
            return a1.Year - a2.Year;
        }
    }
}
