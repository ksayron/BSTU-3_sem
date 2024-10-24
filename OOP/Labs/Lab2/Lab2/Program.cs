using Lab2;
Stack[] stacks = new Stack[3];

Stack stack2 = new Stack(5);

stacks[0] = new Stack();
stacks[0].Push(62);
stacks[0].Push(-8);
stacks[0].Push(87);
stacks[0].Push(17);

stacks[1] = new Stack();
stacks[1].Push(73.5);
stacks[1].Push(56.4);
stacks[1].Push(241);
stacks[1].Push(25.1);
stacks[1].Push(55);

stacks[2] = new Stack();
stacks[2].Push(63);
stacks[2].Push(-1.1);
stacks[2].Push(2.8);
stacks[2].Push(-90);
stacks[2].Push(33);
stacks[2].Push(-56.2);
stacks[2].Push(32.9);

double min = double.MaxValue;
double max = 0;
int neg_count = 0;

int minIndex = 0, maxIndex = 0;

for (int i = 0; i < stacks.Length; i++)
{
    if (stacks[i].topelement() < min)
    {
        min = stacks[i].topelement();
        minIndex = i;
    }
    if (stacks[i].topelement() > max)
    {
        max = stacks[i].topelement();
        maxIndex = i;  
    }
}

Stack.Print(stacks[maxIndex]);
Stack.Print(stacks[minIndex]);


Console.WriteLine($"стеки, содержащие отрицательные элементы: ");
for (int i = 0; i < stacks.Length; i++)
{
    if (stacks[i].Negative())
    {
        Stack.Print(stacks[i]);
    }


}
var anon = new { stack = new double [3]{ 3.2,4,-5.8} , size =3};

Person person =  new Person ();
person.Move();
person.Eat();
Stack.Print(stacks[0]);
Stack stack = Stack.Create(3);
stack.Push(7.2);
Stack.Print(stack);
Stack priv = Stack.Create(3);
bool fff = priv == null;
Console.WriteLine(fff);

