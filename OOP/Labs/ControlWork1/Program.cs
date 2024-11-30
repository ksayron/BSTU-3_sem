

namespace ControlWork1
{
    internal class Program
    {
        static void Main()
        {
            Console.WriteLine("------------------------Задание 1------------------------");
            string ? input;
            Console.WriteLine("Введите строку: ");
            input = Console.ReadLine();
            if(input!=null)Console.WriteLine(input+input[^1]);
            Random random = new();
            int counter = 0;

            Console.WriteLine("\n\n------------------------Задание 2------------------------");
            int[,] matrix= new int[3,3];
            
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    matrix[i,j] = random.Next(0, 10) - 5;
                    if(matrix[i,j] > 0)counter++;
                }
            }
            Console.WriteLine("двумерный массив в виде матрицы: ");
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    Console.Write(matrix[i,j]+"\t");
                }
                Console.WriteLine();
            }

            Console.WriteLine("\n Кол-во положительных элементов в двумерном массиве: "+counter);
            Console.WriteLine("\n\n------------------------Задание 3------------------------") ;
            Bag bag = new("что в мешочке",7+8);
            Bag bag2 = new("мешочек с картошкой", 4 + 5);
            Console.WriteLine("сумма первого"+bag.sum) ;
            Console.WriteLine("сумма второго" + bag2.sum);
            Console.WriteLine(bag.CompareTo(bag2));
            switch (bag.CompareTo(bag2))
            {
                case 0:Console.WriteLine("мешочки равны");break;
                case 1:Console.WriteLine("мешочек2 больше");break;
                case -1:Console.WriteLine("мешочек1 больше");break;
            }
            bag2.NullSum();
            Console.WriteLine(bag2.sum);

            Cassa cassa = new("сбербанк", 1234 + 9876);
            Console.WriteLine("Метод Minus мешочка");
            Console.WriteLine("\n\n"+bag.Minus(90 + 10));

            Console.WriteLine("Метод Minus кассы");
            Console.WriteLine("\n"+cassa.Minus(50 + 50));


        }

        
    }
}
