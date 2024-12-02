using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Lab14
{
    static class MultiThreading
    {
        static ManualResetEvent countFinishedEvent = new ManualResetEvent(false);
        static void ShowInfo(Thread currentThread,string name)
        {

            Console.WriteLine($"\n\nИмя потока: {name}");

            Console.WriteLine($"Запущен ли поток: {currentThread.IsAlive}");
            Console.WriteLine($"Id потока: {currentThread.ManagedThreadId}");
            Console.WriteLine($"Приоритет потока: {currentThread.Priority}");
            Console.WriteLine($"Статус потока: {currentThread.ThreadState}\n\n");
        }
        public static void Count(int n)
        {
        
            Thread thread = new Thread(Print);
            thread.Start();

            void Print()
            {
                for (int i = 0; i < n; i++)
                {
                    if (i == 7)
                    {
                        MultiThreading.ShowInfo(Thread.CurrentThread,"secondary");
                    }
                    Console.WriteLine($"Созданный поток: {i}\n");
                    Thread.Sleep(100);
                }
                countFinishedEvent.Set();
            }
        }

        public static void MultiCount(int n)
        {
            
            countFinishedEvent.WaitOne();
            Thread second = new Thread(PrintNonEven);
            Thread first = new Thread(PrintEven);

            first.Priority = ThreadPriority.Lowest;
            second.Priority = ThreadPriority.Highest;
            first.Start();
            second.Start();


            // действия, выполняемые в главном потоке
            void PrintEven(){
                second.Join();
                for (int i = 0; i <= n; i += 2)
                {
                    Console.WriteLine($"Четный поток: {i}\n");
                    Thread.Sleep(300);
                }
            }

            // действия, выполняемые во втором потокке
            void PrintNonEven()
            {
                for (int i = 1; i <= n; i += 2)
                {
                    Console.WriteLine($"Нечетный поток: {i}\n");
                    Thread.Sleep(300);
                }

            }
        }
        public static void Sekundomer()
        {
            int num = 0;
            // устанавливаем метод обратного вызова
            TimerCallback tm = new TimerCallback(Count);
            // создаем таймер
            Timer timer = new Timer(tm, num, 0, 1000);

            Console.ReadLine();

            void Count(object obj)
            {

                Console.WriteLine("Секунда прошла");
 
            }
        }
    }
}
