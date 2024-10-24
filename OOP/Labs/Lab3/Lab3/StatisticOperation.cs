using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3
{
    static class StatisticOperation
    {
        public static int Sum(Set set)
        {
            return set.all_els.Sum();
        }
        public static int Average(Set set)
        {
            return set.all_els.Sum() / set.all_els.Length;
        }
        public static int Count(Set set)
        {
            return set.all_els.Length;
        }

        #region ExtensionMethods
        public static Set pop(this Set set,int a)
        {
            set.Remove(a);
            return set;
        }
        public static char GetFirstNum(this string sentence)
        {
            foreach (char c in sentence) { 
                if (c>='0' && c<='9') { return c; }
            }
            return '\0';
        }
        #endregion

    }
}
