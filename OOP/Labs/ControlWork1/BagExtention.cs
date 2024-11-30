using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace ControlWork1
{
    static class BagExtention
    {
        public static void NullSum(this Bag bag)
        {
            bag.sum = 0;
        }
    }
}
