using Lab4;
using System.Diagnostics;
const int maxX= 15;
const int maxY = 15;
Lion lion = new Lion("leva",0,0,2004,123);
lion.MoveRight(maxX);
Printer.IAmPrinting(lion);
Animal animal = new Owl("Hieghel", 3, 4,2008,8);
if(animal is Owl owl)
{
    owl.Roar();
}
Printer.LionJump(lion);
Printer.LionJump(animal);

Shark shark = new Shark("Zubick", 2, 5,2016,240);
shark.SwimDown(3);
lion.Roar();
if(lion is IAnimal IA)
{
    IA.Roar();
}
Animal[] horde = {lion,animal,shark};
foreach(Animal a in horde)
{
    Printer.IAmPrinting(a);
}
Zoo MegaZoo = new Zoo();
MegaZoo.Add(lion);
MegaZoo.Add(animal);
MegaZoo.Add(shark);
ZooKeeper Joe = new ZooKeeper(MegaZoo);
Console.WriteLine(lion.IsPredetor);
Zoo result = new Zoo();
result.Animals = Joe.GetPredetorBirds();
result.Print();
Console.WriteLine();
result.Animals = Joe.SortByYear();
result.Print();
Console.WriteLine(lion.Species);
Console.WriteLine(Joe.AvgWeightOfSpecies("Lion"));
Console.WriteLine();

try
{
    Lion zaza = new Lion("boris", 0, 0, 2004, 45);
}
catch (NotValidWeight ex)
{
    ExeptionHandle.Handle(ex);
}

finally
{
    Console.WriteLine("Исключения обработаны");
    Console.WriteLine();
}

try
{
    Lion gaza = new Lion("moris", 0, 0, 1004, 145);
}
catch (NotValidYear ex)
{
    ExeptionHandle.Handle(ex);
}
finally
{
    Console.WriteLine("Исключения обработаны");
    Console.WriteLine();
}

try
{
    shark.z = 16;

}
catch (NotValidZ ex)
{
    ExeptionHandle.Handle(ex);
}
finally
{
    Console.WriteLine("Исключения обработаны");
    Console.WriteLine();
}

try
{
    Console.WriteLine(MegaZoo[15]);
}
catch(IndexOutOfRangeException ex)
{
    ExeptionHandle.Handle(ex);
}
finally
{
    Console.WriteLine("Исключения обработаны");
    Console.WriteLine();
    
}

try
{
    Parrot jora = new Parrot("jora", 0, 0, 2004, 7);
    jora.Year = 4 / jora.Y;
}
catch(DivideByZeroException ex)
{
    ExeptionHandle.Handle(ex);
}
finally
{
    Console.WriteLine("Исключения обработаны");
    Console.WriteLine();
}

try
{
    shark.Jump();
}
catch (NotValidZ ex)
{
    ExeptionHandle.Handle(ex);
}
finally
{
    Console.WriteLine("Исключения обработаны");
}
lion.TryAssert(shark.z > 14);