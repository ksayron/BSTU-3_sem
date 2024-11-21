using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using System.Diagnostics;
using System.Text.Json.Serialization;

namespace Lab13
{
    interface IAnimal
    {
        void Roar();
        void Jump();
    }
    [Serializable]
    public abstract class Animal 
    {

        string name;

        [NonSerialized]
        int x;

        [NonSerialized]
        int y;
        int birth_year;
        int weigth;
        string species;
        public virtual string Species { get => species; }
        protected bool predetor;
        public virtual string Name
        {
            get => name;
            set => name = value;
        }
        [JsonIgnore]
        public int X
        {
            get => x;
        }
        [JsonIgnore]
        public int Y
        {
            get => y;
        }
        public virtual int Year { get => birth_year; set { birth_year = value; } }
        public virtual int Weigth { get => weigth;set { weigth = value; } }

        public bool IsPredetor { get; set; }
        public Animal(string name,int x,int y,int year,int weight)
        {
            this.name = name;
            this.x = x; 
            this.y = y;
            this.birth_year = year;
            this.weigth = weight;
        }
        public Animal(string name, int year, int weight)
        {
            this.name = name;
            this.x = 0;
            this.y = 0;
            this.birth_year = year;
            this.weigth = weight;
        }
        public Animal() 
        {
            this.name = "";
            this.x = 0;
            this.y = 0;
            this.birth_year = 2024;
            this.weigth= 0;
        }
        public void MoveTo(int x,int y)
        {
            this.x = x;
            this.y = y;
        }
        public virtual void MoveLeft()
        {
            if(x>0){ this.x--; }
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
        public override string ToString()
        {
            return $"{this.name}+{this.Species}+{this.Year}+{this.Weigth}+{this.IsPredetor}";
        }

    }
    [Serializable]
    public class Mammal : Animal
    {
        string type = "Mammal";
        public Mammal(string name, int x, int y,int year,int weight) : base(name, x, y,year,weight)
        {
            
        }
        public Mammal() { }
        public override void Roar()
        {
            Console.WriteLine("ррр-ррр-ррр");
        }
        public override string ToString()
        {
            return this.Name + ": " + this.X + " " + this.Y;
        }
    }
    [Serializable]
    public partial class Lion : Mammal , IAnimal
    {
        string species = "Lion";

        public override string Species { get => species; }
        public override int Weigth {
            get => base.Weigth;
            set { if (value > 300 || value < 50)
                {
                    throw new Exception("Вес льва может находится в диапозоне 50-300");
                }
                else { base.Weigth = value; }
            }    
        }
        public override int Year 
        { 
            get => base.Year;
            set
            {
                if (value < 1970)
                {
                    throw new Exception("Неподходящий возраст");
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
        public Lion(string name, int x, int y, int year, int weight) : base(name, x, y, year,weight)
        {
            this.predetor = true;
            this.Weigth = weight;
            this.Year = year;
        }
        public Lion(){}
        public override string ToString()
        {
            return this.species + " " + this.Name + ": " + this.X + " " + this.Y+ " " + this.Year+ " " + this.Weigth;;
        }
        public override bool Equals(object? obj)
        {
            Lion lion1 = obj as Lion;
            if (lion1 == null) return false;
            else
            {
                if(this.Name==lion1.Name &&this.X == lion1.X && this.Y == lion1.Y) { return true; }
                else { return false; }
            }
        }
        public override int GetHashCode()
        {
            return (X+Y)%7;
        }

    }
    [Serializable]
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
        public Tiger()
        {
            this.predetor = true;
        }

        public override string ToString()
        {
            return this.species + " " + this.Name + ": " + this.X + " " + this.Y+ " " + this.Year+ " " + this.Weigth;
        }

    }
    [Serializable]
    public class Bird : Animal
    {
        string type = "Bird";
        bool isFlying;

        public Bird(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {
            this.isFlying = false;
        }
        public Bird() { }

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
    [Serializable]
    public class Owl : Bird
    {
        public string species = "Owl";
        public override string Species { get => species; }
        const bool Nightvision = true;
        public Owl(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {
            this.predetor = true;
        }
        public Owl() { }
        public override string ToString()
        {
            return this.species + " " + this.Name + ": " + this.X + " " + this.Y+ " " + this.Year+ " " + this.Weigth;;
        }

    }
    [Serializable]
    public class Parrot : Bird
    {
        public string species = "Parrot";
        public override string Species { get => species; }
        public Parrot(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {
            this.predetor = false;
        }
        public Parrot() { }
        public override string ToString()
        {
            return this.species + " " + this.Name + ": " + this.X + " " + this.Y+ " " + this.Year+ " " + this.Weigth;;
        }
    }
    [Serializable]
    public class Fish : Animal
    {
        string type = "Fish";
        int _z=0;
        public int z
        {
            get => _z;
            set
            {
                if (_z+value > 0) { throw new Exception("Рыба не может находиться выше уровня моря"); }
                else _z = value;
            }
        }
        public Fish(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {

        }
        public Fish() { }
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
            
                this.z += 15;
            
            
        }
    }
    [Serializable]
    public class Shark : Fish
    {
        public string species = "Shark";
        public override string Species { get => species; }
        public Shark(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {
            this.predetor = true;
        }
        public Shark() { }
        public override string ToString()
        {
            return this.species + " " + this.Name + ": " + this.X + " " + this.Y+ " " + this.Year+ " " + this.Weigth + " "+this.z;
        }
    }
    [Serializable]
    public sealed class Crocodile : Fish
    {
        public string species = "Crocodile";
        public override string Species { get => species; }
        public Crocodile(string name, int x, int y, int year, int weight) : base(name, x, y, year, weight)
        {
            this.predetor = true;
        }
        public Crocodile() { }
        public override string ToString()
        {
            return this.species + " " + this.Name + ": " + this.X + " " + this.Y+ " " + this.Year+ " " + this.Weigth +" "+this.z;
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
            Blue = Green ,
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
