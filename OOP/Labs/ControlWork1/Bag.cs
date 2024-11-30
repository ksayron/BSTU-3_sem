using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ControlWork1
{
    public class Bag(string name, int sum) : IComparable<Bag>,IBank
    {
        public string name = name;
        public int sum = sum;


        public int CompareTo(Bag? other)
        {
            if (other == null) {  return -1; }
            if (other.sum == this.sum) return 0;
            if (other.sum > this.sum) return 1;
            if (this.sum > other.sum) return -1;
            return 1;
        }

        public virtual  int Minus(int sum)
        {
            return (sum * 90)/100;
        }
    }

    public class Cassa(string name, int sum) : Bag(name, sum), IBank
    {
        public override int Minus(int sum)
        {
            return sum / 2;
        }
    }

}
