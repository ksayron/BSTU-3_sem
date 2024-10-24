using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    public class Zoo
    {
        List<Animal> animals;
        
        public Zoo()
        {
            animals = new List<Animal>();
        }
        public Animal this[int index]
        {
            get
            {
                if (index < animals.Count) { return animals[index]; }
                else { throw new IndexOutOfRangeException(); }
            }
        }
        public void Add(Animal animal)
        {
            animals.Add(animal);
        }
        public void Remove(Animal animal)
        {
            animals.Remove(animal);
        }
        public int Size
        {
            get { return animals.Count; }
        }
        public Animal GetElement(int index)
        {
            return animals[index];
        }

        public void ChangeElement(int index, Animal element)
        {
            animals[index] = element;
        }

        public List<Animal> Animals
        {
            get {
                return animals;
                }
            set { animals = value; }
        }
        public IEnumerator<Animal> GetEnumerator() => new ZooEnumeratoe(animals);
        public void Print()
        {
            foreach (Animal animal in animals)
            {
                Console.WriteLine(animal.ToString());
            }
        }
    }

    public class ZooKeeper 
    {
        Zoo zoo;
        
        public ZooKeeper(Zoo zoo)
        {
            this.zoo = zoo;
        }
        public List<Animal> GetPredetorBirds()
        {
            List<Animal> result = new List<Animal>();
            foreach( Animal animal in zoo.Animals)
            {
                if(animal is Bird bird)
                {
                    if (bird.IsPredetor) { result.Add(bird); }
                }
            }
            return result;
        }
        public List<Animal> SortByYear()
        {
            zoo.Animals.Sort(new AnimalComparer());
            return zoo.Animals;
        }

        public double AvgWeightOfSpecies(string str)
        {
            double avg=0;
            int count=0;
            foreach (Animal animal in zoo.Animals)
            {
                 string spec=animal.Species;
                if (str == animal.Species)
                {
                    avg += animal.Weight;
                    count++;
                }
            }
            return avg/count;
        }
        
    }

    public class ZooEnumeratoe: IEnumerator<Animal>
    {
        Zoo zoo;
        int position = 0;
        public ZooEnumeratoe(List<Animal> zoo) { this.zoo.Animals = zoo; }
        public Animal Current
        {
            get
            {
                if (position == -1 || position >= zoo.Size)
                    throw new ArgumentException();
                return zoo[position];
            }
        }
        object IEnumerator.Current => Current;
        public bool MoveNext()
        {
            if (position < zoo.Size - 1)
            {
                position++;
                return true;
            }
            else
                return false;
        }
        public void Reset() => position = -1;
        public void Dispose() {}

    }
}
