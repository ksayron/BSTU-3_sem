using Lab7;

Set<string> set_int = new Set<string>(3);
set_int.Add("1");
set_int.Add("2");
set_int.Add("3");
set_int.Pop("2");
Console.WriteLine(set_int.GetById(2));
set_int.Print();
Set<Lion> pride=new Set<Lion>(3);
Lion first = new Lion("duba", 0, 0, 2005, 200);
Lion second = new Lion("auba", 0, 0, 2004, 193);
Lion third = new Lion("huba", 0, 0, 1987, 247);
pride.Add(first);
pride.Add(second);
pride.Add(third);
pride.Print();
pride.Pop(third);
Console.WriteLine(pride.GetById(1));

pride.PushToFile();
Set<Lion> aboltusi = new Set<Lion>(3);
aboltusi.ReadFromFile();
aboltusi.Print();

