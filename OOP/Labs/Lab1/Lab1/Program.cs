// See https://aka.ms/new-console-template for more information
//Примитивные типы
using System.Linq;
using System.Text;
using static System.Net.Mime.MediaTypeNames;

int[][] arr = new int[2][];
arr[0] = new int[2];
Console.Write("Введите int: ");
int i1 = int.Parse(Console.ReadLine());
Console.WriteLine(i1);
i1 = i1.ToString().Length;
Console.WriteLine(i1);
Console.Write("Введите bool: ");
bool b2 = bool.Parse(Console.ReadLine());
Console.WriteLine(b2);

Console.Write("Введите char: ");
char c3 = char.Parse(Console.ReadLine());
Console.WriteLine(c3);

Console.Write("Введите short: ");
short s4 = short.Parse(Console.ReadLine());
Console.WriteLine(s4);

Console.Write("Введите byte: ");
byte bt5 = byte.Parse(Console.ReadLine());
Console.WriteLine(bt5);

Console.Write("Введите long: ");
long l6 = long.Parse(Console.ReadLine());
Console.WriteLine(l6);

Console.Write("Введите double: ");
double d7 = double.Parse(Console.ReadLine());
Console.WriteLine(d7);

Console.Write("Введите float: ");
float f8 = float.Parse(Console.ReadLine());
Console.WriteLine(f8);

int[] arrrr = { 1, 2, 3, 4 };
//неявное преобразование
s4 = bt5;
i1 = s4 +12;
l6 = i1 * 3;
d7 = f8 + 3.4;
f8 = l6 - 5;

//явное преоброзование 
i1 = (int)d7;
l6 = (long)5.9;
d7 = Convert.ToDouble(b2);
b2 = Convert.ToBoolean(1);
c3 = Convert.ToChar(6);

int ii = 4545;
object o1 = ii;
int j213 = (int)o1;

var j2 = (int)j213;


//Строки

string name="Joe";
string place="Canada";
string animal="Bobior";
Console.WriteLine(animal + ' ' +place);
Console.WriteLine(string.Concat(name, " Smith"));
int result = string.Compare(name, animal);
Console.WriteLine(result);

string text=null,empty="";
bool test_res = string.IsNullOrEmpty(empty);
Console.WriteLine(test_res);
if (text != null )
{
    Console.WriteLine(text);
}
StringBuilder sb=new StringBuilder("real human being");
Console.WriteLine(sb.ToString());
sb.Remove(6, 1);
sb.Insert(0,71);
sb.Insert(sb.Length, 71);
Console.WriteLine(sb.ToString());


//Массивы

 int[,] matrix = { { 1, 2, 3 }, { 4, 5, 6 } };

int rows = matrix.GetUpperBound(0) + 1;    // количество строк
int col = matrix.Length / rows;        // количество столбцов
Console.WriteLine();
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < col; j++)
    {
        Console.Write($"{matrix[i, j]} \t");
    }
    Console.WriteLine();
}
Console.WriteLine();
string[] texts = { "Hello","world","!!!"};
for (int i = 0;i < texts.Length; i++)
    {  Console.Write(texts[i]+' '); }
Console.WriteLine(texts.Length);
Console.WriteLine("Выберите изменяемый элемент:");
int change_id = Convert.ToInt32(Console.ReadLine());
Console.WriteLine("Выбранный элемент: " + texts[change_id-1]);
Console.WriteLine("Выберите позицию изменяемого символа и новый символ:");
string line = Console.ReadLine();
string[] splitString = line.Split(' ');
int symbol_pos = Convert.ToInt32(splitString[0]);
texts[change_id-1] = texts[change_id-1].Insert(symbol_pos - 1, splitString[1]);
texts[change_id-1] = texts[change_id-1].Remove(symbol_pos,1);
Console.WriteLine("Измененный элемент: " + texts[change_id - 1]);

float[][] real_arr = new float[3][];
real_arr[0] = new float[2];
real_arr[1] = new float[3];
real_arr[2] = new float[4];
for (int i = 0; i < real_arr.Length; i++)
{
    for(int j=0;j<real_arr[i].Length; j++)
    {
        Console.WriteLine("Введите элемент массива " + (i+1));
        real_arr[i][j]=Convert.ToInt32(Console.ReadLine());
    }
}

Console.WriteLine();
for (int i = 0; i < real_arr.Length; i++)
{
    for (int j = 0; j < real_arr[i].Length; j++)
    {
        Console.Write(real_arr[i][j]+"\t");  
    }
    Console.WriteLine();
}
var unarr =  new float[real_arr.Length];
var unstr = "4322423";


//Кортежи
(int, string, char, string, ulong) tuple = (4, "Задание", 'a', "Подпункт", 5);
Console.WriteLine("Введите желаемые для вывода номера: ");
string input = Console.ReadLine();
if(string.IsNullOrEmpty(input))
{
    Console.WriteLine(tuple.Item1);
    Console.WriteLine(tuple.Item2);
    Console.WriteLine(tuple.Item3);
    Console.WriteLine(tuple.Item4);
    Console.WriteLine(tuple.Item5);
}
else
{
    string[] input_split = input.Split(' ');
    for(int i = 0; i < input_split.Length; i++)
    {
        if (Convert.ToInt32(input_split[i]) == 1) { Console.WriteLine(tuple.Item1); }
        if (Convert.ToInt32(input_split[i]) == 2) { Console.WriteLine(tuple.Item2); }
        if (Convert.ToInt32(input_split[i]) == 3) { Console.WriteLine(tuple.Item3); }
        if (Convert.ToInt32(input_split[i]) == 4) { Console.WriteLine(tuple.Item4); }
        if (Convert.ToInt32(input_split[i]) == 5) { Console.WriteLine(tuple.Item5); }
    }
}
(int, int) tupA = (12, 45);
(int, int) tupB = (12, 46);
var res = tupA.CompareTo(tupB);
Console.WriteLine(res); 

(int,int,int,char) func(int[] arr,string str)
{
    (int, int, int, char) tuple = (arr.Max(), arr.Min(), arr.Length, str[0]);
    return tuple;
}
int[] arr3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
string sss = "sbc";
var resulttt = func(arr3, sss);
Console.WriteLine(resulttt);

int int_max = int.MaxValue;
void func1(int int_max)
{
    try{checked
        {
            int_max++; 
            Console.WriteLine(int_max);
        }
    }
    catch(Exception e) { Console.WriteLine("переполнение"); }
    
}
void func2(int int_max)
{
    unchecked
    {
        int_max++;
    }
    Console.WriteLine(int_max);
}
func1(int_max);
func2(int_max);