using System;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Diagnostics;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Lab15
{
    static class TPL
    {

        static bool[] sieve=new bool[1000001];    
        static List<int>? primes; 
        static string symbols="abcdefghijklmnopqrstuvwxyz";
        static Random random = new Random();
        static ConcurrentDictionary<string, bool> guessmap = new ConcurrentDictionary<string, bool>();
        static object locker = new();

        public static void TaskPrime(int n)
        {
            Stopwatch sw = new();
            Task primes = new Task(() => compute_primes(n,sw));
            sw.Start();
            primes.Start();
            Console.WriteLine($"Статус после запуска: {primes.Status}");
            primes.Wait();
        }
        static void compute_primes(int n,Stopwatch sw)
        {
            primes = new List<int>();
            for (int i = 2; i <= n; i++)
            {  
                sieve[i] = true;
            }

            for (int i = 2; i <= n; i++)
            {
                if (sieve[i])
                {     
                    primes.Add(i);

                    for (long j = i * i; j <= n; j += i)
                    {   
                        if (!(j < 0 || j > n)) sieve[j] = false;
                    }
                }
            }

            sw.Stop();
  
            Console.WriteLine("Простые числа: ");
            foreach (int i in primes)
            {
                Console.Write(" "+i);
            }

            Console.WriteLine($"\n\nВремя выполнения: {sw.Elapsed}\n");
        }

        public static void TaskPrimeCancel(int n)
        {
            CancellationTokenSource cts = new CancellationTokenSource();
            CancellationToken token = cts.Token;
            Stopwatch sw = new();
            Task primes = new Task(() => compute_primes(n,ref token),token);
            sw.Start();
            primes.Start();

            Thread.Sleep(100);
            Console.WriteLine($"\nСтатус после запуска: {primes.Status}");
            cts.Cancel();

            cts.Dispose(); // освобождаем ресурсы

            Console.WriteLine($"Статус после отмены: {primes.Status}");
        }

        static void compute_primes(int n,ref CancellationToken token)
        {
            primes = new List<int>();
            for (int i = 2; i <= n; i++)
            {
                sieve[i] = true;
            }

            Console.WriteLine("Простые числа: ");
            for (int i = 2; i <= n; i++)
            {
                if (token.IsCancellationRequested)  // проверяем наличие сигнала отмены задачи
                {
                    Console.WriteLine("\nОперация прервана");
                    return;     //  выходим из метода и тем самым завершаем задачу
                }

                if (sieve[i])
                {
                    Console.Write(" " + i);
                    primes.Add(i);

                    for (long j = i * i; j <= n; j += i)
                    {
                        if (!(j < 0 || j > n)) sieve[j] = false;
                    }
                }
            }
        }
        public static int Combine(int n) => n += n; 
        public static int Square(int n) => n * n;

        public static void TaskCombination(int x)
        {
            var length = Task.Run(() => Combine(x));
            var width = Task.Run(() => Square(x));
            var heigth = Task.Run(() => x*10);

            Console.WriteLine($"Объем фигуры: {length.Result*width.Result*heigth.Result}");

        }

        public static void TaskContinuationConseq(int n)
        {

            var task1 =  Task.Run(() => Combine(n));
            var task2 = task1.ContinueWith(x => Square(x.Result));
            var task3 = task2.ContinueWith(x => Combine(x.Result));  

            Console.WriteLine($"Результат всех операций: {task3.Result}");
        }

        public static void TaskContinuationAwaitResult(int n)
        {
            Task<int> lengthTask = Task.Run(() => Combine(n));

            Task<int> widthTask = Task.Run(() => Square(lengthTask.GetAwaiter().GetResult()));
            Task<int> heigthTask = Task.Run(() => widthTask.GetAwaiter().GetResult() * 10);
            int result = heigthTask.GetAwaiter().GetResult();
            Console.WriteLine($"Результат всех операций: {result}");

        }


        public static void For()
        {
            Stopwatch sw = Stopwatch.StartNew();
           

            // вычисляем квадрат числа
            for(int n=0;n<primes.Count;n++)
            {
                Console.WriteLine($"Выполняется задача {Task.CurrentId}");
                Console.WriteLine($"Плюс числа {primes[n]} равен {primes[n] + 1}");

            }
            sw.Stop();
            Console.WriteLine($"\n\nВремя выполнения: {sw.Elapsed}\n");
        }
        public static void ParallelFor()
        {
            Stopwatch sw = Stopwatch.StartNew();
            Parallel.For(1, primes.Count, Plus);

            // вычисляем квадрат числа
            void Plus(int n)
            {
                Console.WriteLine($"Выполняется задача {Task.CurrentId}");
                Console.WriteLine($"Плюс числа {primes[n]} равен {primes[n] + 1}");

            }
            sw.Stop();
            Console.WriteLine($"\n\nВремя выполнения: {sw.Elapsed}\n");
        }

        public static void ParallelForEach()
        {
            Stopwatch sw = Stopwatch.StartNew();
            Parallel.ForEach(primes, Plus);
                // вычисляем квадрат числа
            void Plus(int n)
            {
                Console.WriteLine($"Выполняется задача {Task.CurrentId}");
                Console.WriteLine($"Плюс числа {n} равен {n+1}");

            }
            sw.Stop();
            Console.WriteLine($"\n\nВремя выполнения: {sw.Elapsed}\n");
        }

        public static void BruteForce(string password)
        {
            CancellationTokenSource cts = new CancellationTokenSource();
            CancellationToken token = cts.Token;
            Stopwatch sw = Stopwatch.StartNew();


            try
            {
                Parallel.Invoke(
                    () => Brute(password, ref token, 1),
                    () => Brute(password, ref token, 2),
                    () => Brute(password, ref token, 3)
                );
            }
            catch (OperationCanceledException e)
            {
                Console.WriteLine("\n\nПароль был найден");
                cts.Cancel();
            }

            sw.Stop();
            Console.WriteLine($"\n\n\n\n\n\nВремя выполнения: {sw.Elapsed}\n");

           
        }
        static void Brute(string password, ref CancellationToken token, int taskId)
        {
            string brute = "";
            while (password != brute)
            {
                if (token.IsCancellationRequested)
                {
                    return;
                }
                brute = GenerateString(password.Length);
                if (!guessmap.ContainsKey(brute))
                {

                    if (brute != password)
                    {

                        lock (locker){
                            Console.SetCursorPosition(0, taskId); // Set cursor position to the dedicated line for the task
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.Write($"Попытка ввода от {taskId}: {brute}");
                            Console.ForegroundColor = ConsoleColor.White;
                            guessmap.TryAdd(brute, false);
                            if (token.IsCancellationRequested)
                            {
                                return;
                            }
                        }
                    }
                    if (brute == password)
                    {
                        Console.SetCursorPosition(0, taskId); // Set cursor position to the dedicated line for the task
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.Write($"Попытка ввода от {taskId}: {brute}");
                        Console.ForegroundColor = ConsoleColor.White;
                        token.ThrowIfCancellationRequested();

                        return;

                    }
                }

            }
        }

        public static string GenerateString(int lenght)
        {
            string gen = "";
            for (int i = 0; i < lenght; i++)
            {
                int id = random.Next(symbols.Length);
                gen += symbols[id];
            }
            return gen;
            
        }
        public static  async Task wait()
        {
            var tomTask = PrintNameAsync("Tom");
            var bobTask = PrintNameAsync("Bob");
            var samTask = PrintNameAsync("Sam");

            await tomTask;
            await bobTask;
            await samTask;
            // определение асинхронного метода
            async Task PrintNameAsync(string name)
            {
                await Task.Delay(3000);     // имитация продолжительной работы
                Console.WriteLine(name);
            }
        }
       
        
    }

}
