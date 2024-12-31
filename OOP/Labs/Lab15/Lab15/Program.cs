using System.Threading.Tasks;
using Lab15;

namespace Lab15
{
    internal class Program
    {
        static void Main(string[] args)
        {

            //TPL.TaskPrime(1000000);
            //Thread.Sleep(2000);
            ////TPL.TaskPrimeCancel(1000000);
            //TPL.TaskCombination(3);
            //TPL.TaskContinuationConseq(10);
            //TPL.TaskContinuationAwaitResult(13);
            //TPL.For();
            //Thread.Sleep(2000);
            //TPL.ParallelFor();
            //Thread.Sleep(2000);
            //TPL.ParallelForEach();
            //TPL.BruteForce("kol");
            //Thread.Sleep(2000);
            Good kvas = new("Лидский квас", 40);
            Good chips = new("Чипсоны Лейс", 20);
            Good pelmeni = new("Пачка пельменей", 65); 
            Producer lidskiy = new("Лидиский завод", kvas, 30, 45);
            Producer lays = new("Lays", chips, 45, 25);
            Producer brestmayso = new("Брестский мясокомбинат", pelmeni, 6, 10);
            Producer[] producers = {lidskiy, lays, brestmayso};

            Buyer Katya = new("Жучкевич Екатерина", 1);
            Buyer Karina = new("Карина Кожух", 2);
            Buyer Lesha = new("Шилов Алексей", 3);
            Buyer Alina = new("Альшевская Алина", 4);
            Buyer Kolya = new("Кучерук Николай", 5);
            Buyer[] buyers = {Karina,Katya,Lesha, Alina, Kolya};


            Store groshik = new("Грошык");
            groshik.RunStore(producers, buyers);
            //TPL.wait();
            //Thread.Sleep(10000);

        }
    }

}
