// See https://aka.ms/new-console-template for more information
using Lab11;
using Lab4;
Lion lion = new Lion("biba", 0, 0, 2022, 200);
string  assbl =Reflector.AssemblyName(lion);
Console.WriteLine(assbl);
bool pub_constr = Reflector.IsPubConstr(lion);
Console.WriteLine(pub_constr);
var list = Reflector.GetPublicMeth(lion);
Console.WriteLine();
foreach (var item in list)
{
    Console.WriteLine(item);
};
Console.WriteLine();
list = Reflector.publicPropAndFields(lion);
foreach (var item in list)
{
    Console.WriteLine(item);
}
Console.WriteLine();
list = Reflector.publicPropAndFields(lion);
foreach (var item in list)
{
    Console.WriteLine(item);
}
Console.WriteLine();
list = Reflector.GetInterfaces(lion);
foreach (var item in list)
{
    Console.WriteLine(item);
}
Console.WriteLine();
int a=5;
Reflector.PrintMeth(lion,a);
Reflector.Invoke(lion, "MoveTo",new object []{ 0,0});
Console.WriteLine(lion.X+" "+lion.Y);

var bro =Reflector.Create(lion, new object[] { "boba", 5, 2, 2024, 300 });
Console.WriteLine(bro);