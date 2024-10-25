using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    public partial class Lion
    {
        public void Jump()
        {
            Console.WriteLine("прыг");
        }
        public void TryAssert(bool condition)
        {
            Debug.Assert(condition);
        }
    }
}
