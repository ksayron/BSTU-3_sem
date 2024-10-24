using Lab3;

Set first = new Set(5);
Set second = new Set(3);

first.Insert(1);
first.Insert(2);
first.Insert(5);
first.Insert(4);
first.Insert(3);
first.Print();
Set.Production production = new Set.Production();
Set.Developer developer = new Set.Developer();


second.Insert(4);
second.Insert(2);
second.Insert(3);
second.Print();

Console.WriteLine(first>second);
Console.WriteLine(first<second);

second.pop(3);

second.Insert(7);
second.Print();

Set res = first * second;
res.Print();

Console.WriteLine(first > 6);
Console.WriteLine(first > 5);


string bebra = "bebra8",s="";
s+= bebra.GetFirstNum();
Console.WriteLine(s);