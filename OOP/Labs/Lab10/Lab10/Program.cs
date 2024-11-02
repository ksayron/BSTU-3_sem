

using Lab10;

string[] months = { "December","January","February","March","April","May","June","July","August","September","October","November"};

var LenghtOfN = months.Where(n => n.Length == 5).ToArray();
foreach (var month in LenghtOfN)
{
    Console.WriteLine(month);
}
Console.WriteLine();
var SummerOrWinter = months.Where(n => n == "June" || n == "July" || n == "August" || n == "December" || n == "January" || n == "February").ToArray();
foreach (var month in SummerOrWinter)
{
    Console.WriteLine(month);
}
Console.WriteLine();
var Sort = months.OrderBy(p=>p).ToArray();
foreach (var month in Sort)
{
    Console.WriteLine(month);
}
Console.WriteLine();
var result = months.Where(n =>n.Contains("u") && n.Length>=4).ToArray();
foreach (var month in result)
{
    Console.WriteLine(month);
}
Console.WriteLine();

List<Stack> stacks = new List<Stack>();
stacks.Add(new Stack());
stacks.Add(new Stack());
stacks.Add(new Stack());
stacks.Add(new Stack());
stacks.Add(new Stack(1));
stacks.Add(new Stack());
stacks.Add(new Stack());
stacks.Add(new Stack());
stacks.Add(new Stack(3));
stacks.Add(new Stack());
Console.WriteLine("Мега-лист:");    
foreach (var stack in stacks)
{
    Console.Write("Стэк: ");
    stack.Print();
    Console.WriteLine();
}

var MaxEl = stacks.OrderByDescending(n=>n.topelement()).First();
Console.WriteLine("\nСтэк с макс верхушкой:"+MaxEl+'\n');

var HasNegs = stacks.Where(n => n.ContainNeg()).ToList();
Console.WriteLine("\nСодержат отриц. элементы:");
foreach (var n in HasNegs)
{
    n.Print();
    Console.WriteLine();
}


var MinStack = stacks.OrderBy(n => n.SumOf()).First();
Console.WriteLine("\nСтэк с мин суммой:" + MinStack + '\n');

var SizeOf1And3 = stacks.Where(n => n.Size==1||n.Size==3).ToList();
Console.WriteLine("\nДлина 1 или 3:");
foreach (var n in SizeOf1And3)
{
    n.Print();
    Console.WriteLine();
}

var HasZero = stacks.FirstOrDefault(n=>n.Contains(0));
if (HasZero != null) Console.WriteLine("\nПервый стэк с нулем:" + HasZero + '\n');
else Console.WriteLine("\nСтэка с нулем нет\n");

var SortSum = stacks.OrderBy(n => n.SumOf()).ToList();
Console.WriteLine("\nОтсортированный по сумме элементов:\n");
foreach (var n in SortSum)
{
    n.Print();
    Console.WriteLine();
}



List<Stack> stacks2 = new List<Stack>();
stacks2.Add(new Stack(3));
stacks2.Add(new Stack(3));
stacks2.Add(new Stack(3));
stacks2.Add(new Stack(3));
stacks2.Add(new Stack(3));
stacks2.Add(new Stack(3));
stacks2.Add(new Stack(3));
stacks2.Add(new Stack(3));
stacks2.Add(new Stack(3));
stacks2.Add(new Stack(3));
Console.WriteLine("Мега-лист 2:");
foreach (var stack in stacks2)
{
    Console.Write("Стэк: ");
    stack.Print();
    Console.WriteLine();
}

var test1 = stacks.Where(n => !n.ContainNeg()).ToList();
Console.WriteLine("\nСодержат отриц. элементы:");
foreach (var n in test1)
{
    n.Print();
    Console.WriteLine();
}

var test2 = stacks2.Where(n => !n.ContainNeg()).ToList();
Console.WriteLine("\nСодержат отриц. элементы:");
foreach (var n in test2)
{
    n.Print();
    Console.WriteLine();
}

var stacks3 = stacks.Skip(2).Where(p => !p.ContainNeg()).Join(stacks2.Where(c => !c.ContainNeg()),p => !p.ContainNeg(),c => !c.ContainNeg(),(p, c) => new Stack(p.GetStack(), c.GetStack()))
    .OrderBy(n=>n.ElementAt(0)).ToList();
Console.WriteLine("\nГига-лист положительных:");
foreach (var n in stacks3)
{
    n.Print();
    Console.WriteLine();
}

