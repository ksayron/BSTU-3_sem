using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8
{
    internal class StringModifier
    {
        public static string RemoveUpper(string str, Func<string, string> func)
        {
            return func(str);
        }
        public static void AddToString(string str, Action<string> action)
        {
            action(str);
        }

        public static bool isNumber(string str, Predicate<string> check)
        {
            return check(str);
        }
        public static string RemoveSpaces(string str, Func<string, string> test3) //удаление пробелов
        {
            return test3(str);
        }
        
        public static string Reverse(string str,Func<string, string> func)
        {
            return func(str);
        }
    }
}
