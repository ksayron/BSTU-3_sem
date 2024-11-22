using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Lab14
{
    static class Processes
    {
        public static void ShowAll()
        {
            var all = Process.GetProcesses();

            foreach (var process in all)
            {
                try
                {
                    Console.WriteLine($"Id процесса: {process.Id}\n" +
                                  $"Имя процесса: {process.ProcessName}\n" +
                                  $"Приоритет процесса: {process.BasePriority}\n" +
                                  $"Время запуска процесса: {process.StartTime}\n" +
                                  $"Текущее состояние процесса: {process.Responding}\n" +
                                  $"Время работы процесса: {process.TotalProcessorTime}\n" +
                                  $"Время загрузки процесса: {process.UserProcessorTime}\n");
                }
                catch
                {

                }
            }
            Console.WriteLine("\nВсего процессов: "+all.Length+"\n");
        }

        public static void ShowDomains()
        {

            AppDomain domain = AppDomain.CurrentDomain; // текущий домен приложения
            Console.WriteLine($"Имя домена: {domain.FriendlyName}");
            Console.WriteLine("Базовый каталог:\n" + domain.BaseDirectory);
            Console.WriteLine($"Детали конфигурации: {domain.SetupInformation}");
            Assembly[] assemblies = domain.GetAssemblies();
            Console.WriteLine($"Всего загруженно сборок: {assemblies.Length}");
            Console.WriteLine("Сборки, загруженные в домен:");

            
            foreach (Assembly asm in assemblies)
            {
                Console.WriteLine(asm.GetName().Name);
            }

            //AppDomain newDomain = AppDomain.CreateDomain("New Domain");  создание нового домена
            //newDomain.Load(Assembly.GetExecutingAssembly().FullName);    загрузка сборки
            //AppDomain.Unload(newDomain);                                 выгрузка домена + всех содержащихся в нём сборок*/
        }
    }
}
