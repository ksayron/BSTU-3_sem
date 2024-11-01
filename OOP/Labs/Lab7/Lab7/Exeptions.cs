using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab7
{
    public class ExeptionHandle
    {
        public static void Handle(Exception ex)
        {
            if (ex is NotValid notValid) { Console.WriteLine($"Тип Ошибки: {notValid.Type}"); }
            Console.WriteLine($"Исключение: {ex.Message}");
            Console.WriteLine($"Метод: {ex.TargetSite}");

        }
    }

    public class NotValid : Exception
    {
        public readonly string Type = "Not Valid";
        public NotValid() { }
        public NotValid(string message) : base(message) { }
    }
        public class NotValidYear : NotValid
    {
        
        public NotValidYear() { }
        public NotValidYear(string message) : base(message) { }
    }
    public class NotValidWeight : NotValid
    {

        public NotValidWeight() { }
        public NotValidWeight(string message) : base(message) { }
    }

    public class NotValidZ : NotValid
    {

        public NotValidZ() { }
        public NotValidZ(string message) : base(message) { }
    }


}
