using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{

    public class Printer
    {
        public static void IAmPrinting( Animal obj)
        {
            Console.WriteLine(obj.ToString() );
        }
        public static void LionJump(Animal a)
        {
            Lion l = a as Lion;
            if (l != null)
            {
                l.Jump(); 
            }
        }
    }
}
