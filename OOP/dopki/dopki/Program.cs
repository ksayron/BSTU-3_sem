using System.Runtime.CompilerServices;

int a, b,n=0;
double k = 1.0 / 3.0;
bool check=false;
Console.Write("a:");
a=Convert.ToInt32(Console.ReadLine());
Console.Write("b:");
b = Convert.ToInt32(Console.ReadLine());
Console.WriteLine(); 
int lenght = Convert.ToInt32(Math.Pow(b, k));
for (int i = 1; i <= lenght; i+=2)
{
    if(i*i*i>=a && i*i*i<=b)n++;
}
Console.WriteLine(n);
