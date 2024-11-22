using System.Threading;

namespace Lab14
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Processes.ShowAll();
            Processes.ShowDomains();
            MultiThreading.Count(15);
            Console.WriteLine();
            MultiThreading.MultiCount(15);
        }
    }
}
