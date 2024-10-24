using Microsoft.VisualBasic.FileIO;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2
{
    public class Stack
    {
        readonly Guid id;
        private List<double> stack;
        private int size;
        public int Size
        {
            get => size;
        }
        const string  bbb = "B";
        public Stack()
        {
            id = Guid.NewGuid();
            stack = new List<double>();
            size = 0;
            num_of_obj++;
        }

        public Stack(int size)
        {
            id = Guid.NewGuid();
            stack = new List<double>();
            for (int i = 0; i < size; i++)
            {
                stack.Add(0);
                this.size++;
            }
            num_of_obj++;
        }
        private Stack(bool priv,int size)
        {
            id = Guid.NewGuid();
            stack = new List<double>();
            for (int i = 0; i < size; i++)
            {
                stack.Add(0);
                this.size++;
            }
            num_of_obj++;
        }
        public Stack(bool useDefault = true)
        {
            if (useDefault)
            {
                id = Guid.NewGuid();
                stack = new List<double>();
                for (int i = 0; i < size; i++)
                {
                    stack.Add(0);
                    this.size++;
                }
            }
            num_of_obj++;
        }

        static Stack()
        {
            num_of_obj = 0;
        }

        private static int num_of_obj = 0;

        public double this[int index]
        {
            get => stack[index];
            set => stack[index] = value;
        }

        public void Push(double num) => stack.Add(num);

        public double Pop()
        {
            double num = stack[stack.Count - 1];
            stack.RemoveAt(stack.Count - 1);
            return num;
        }
        public bool empty()
        {
            return stack.Count == 0;
        }

        public bool Negative()
        {
            foreach (double element in stack)
            {
                if (element < 0)
                {
                    return true;
                }
            }
            return false;
        }

        public double topelement() => stack[stack.Count - 1];

        static public int GetNumObj() => num_of_obj;

        public static void IncreaseBy(ref Stack stck, double num)
        {
            for (int i = 0; i < stck.size; i++)
            {
                stck[i] += num;
            }
        }
        public static void SumOf(Stack stck, out double result)
        {
            result = 0;
            for (int i = 0; i < stck.size; i++)
            {
                result += stck[i];
            }
            
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

        public override int GetHashCode() => stack.GetHashCode();

        public override string ToString() => string.Join(" ", stack);

        public static void Print(Stack s) => Console.WriteLine(s.ToString());

        public static Stack Create(int size)
        {
            if (num_of_obj >= 5) { Console.WriteLine();  return null; }
            else{ return new Stack(true, size); }
        }

    }
}
