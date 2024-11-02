using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Linq;
using System.Collections;

namespace Lab10
{
    public class Stack:IEnumerable<int>
    {
        readonly Guid id;
        private List<int> stack;
        public int size {  get; private set; }
        public int Size
        {
            get => size;
        }
        const string bbb = "B";
        public Stack()
        {
            Random random = new Random();
            id = Guid.NewGuid();
            stack = new List<int>();
            for (int i = 0; i < 6; i++)
            {
                stack.Add((random.Next() % 45)-15);
                this.size++;
            }
            num_of_obj++;
        }

        public Stack(int size)
        {
            Random random = new Random();
            id = Guid.NewGuid();
            stack = new List<int>();
            for (int i = 0; i < size; i++)
            {

                stack.Add((random.Next() % 45)-10); 
                this.size++;
            }
            num_of_obj++;
        }
        public Stack(List<int> stack)
        {
            Random random = new Random();
            id = Guid.NewGuid();
            this.stack = stack;
            size = this.stack.Count;
            num_of_obj++;
        }
        public Stack(List<int> stack, List<int> stack2)
        {
            Random random = new Random();
            id = Guid.NewGuid();
            this.stack = stack;
            foreach (int i in stack2)
            {
                this.stack.Add(i);
            }
            size=this.stack.Count;

            num_of_obj++;
        }
        private Stack(bool priv, int size)
        {
            id = Guid.NewGuid();
            stack = new List<int>();
            for (int i = 0; i < size; i++)
            {
                stack.Add(0);
                this.size++;
            }
            num_of_obj++;
        }
        public Stack(bool useNeg = true)
        {
            Random random = new Random();
            if (useNeg)
            {
                id = Guid.NewGuid();
                stack = new List<int>();
                for (int i = 0; i < 6; i++)
                {
                    stack.Add(((random.Next()%45)*(-1)));
                    this.size++;
                }
            }
            num_of_obj++;
        }
        public List<int> GetStack()
        {
            return stack;   
        }

        static Stack()
        {
            num_of_obj = 0;
        }

        private static int num_of_obj = 0;

        public IEnumerator<int> GetEnumerator()
        {
            return stack.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return stack.GetEnumerator();
        }

        public int this[int index]
        {
            get => stack[index];
            set => stack[index] = value;
        }

        public void Push(int num) => stack.Add(num);

        public int Pop()
        {
            int num = stack[stack.Count - 1];
            stack.RemoveAt(stack.Count - 1);
            return num;
        }
        public bool empty()
        {
            return stack.Count == 0;
        }

        public int topelement() => stack[stack.Count - 1];

        static public int GetNumObj() => num_of_obj;

        public bool Contains(int num)
        {
            return stack.Contains(num);
        }

        public static void IncreaseBy(ref Stack stck, int num)
        {
            for (int i = 0; i < stck.size; i++)
            {
                stck[i] += num;
            }
        }
        public  int SumOf()
        {
            int result = 0;
            for (int i = 0; i < this.size; i++)
            {
                result += this[i];
            }
            return result;

        }
        public override bool Equals(object obj)
        {
            if (obj == null || GetType() != obj.GetType())
            {
                return false;
            }

            Stack other = (Stack)obj;
            return this.stack.Equals(other.stack);
        }
        public bool ContainNeg()
        {
            bool check=false;
            foreach(int i in stack)
            {
                if (i < 0) check = true;
            }
            return check;
        }

        public override int GetHashCode() => stack.GetHashCode();

        public override string ToString() => string.Join("  ", stack);

        public void Print() => Console.WriteLine("("+this.ToString()+")");

        public static Stack Create(int size)
        {
            if (num_of_obj >= 5) { Console.WriteLine(); return null; }
            else { return new Stack(true, size); }
        }

        
    }
}

