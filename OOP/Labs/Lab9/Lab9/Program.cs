using Lab9;
using System;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.IO;

Concert concert = new Concert("Panchiko");
concert.AddTicketPricing("standart", 20);
concert.AddTicketPricing("VIP", 80);
concert.AddTicketPricing("meet & greet", 150);
concert.PrintTicketPricing();
concert.RemoveTicketPricing("meet & greet");
concert.ChangeTicketPricing("VIP", 65);
Console.WriteLine(concert.GetPrice("VIP"));

Console.WriteLine();
foreach(var item in concert)
{
    Console.WriteLine(item);
}
Console.WriteLine();

Dictionary<int,string> collection1 = new Dictionary<int,string>();
collection1.Add(1, "first");
collection1.Add(2, "second");
collection1.Add(3, "third");
foreach (var item in collection1)
{
    Console.WriteLine(item);
}
Console.WriteLine();
List<string> collection2 = new List<string>();
foreach (var item in collection1)
{
    collection2.Add(item.Value);
}
string search = "second";
foreach (var item in collection2)
{
    Console.WriteLine(item);

}
for (int i = 0; i < collection2.Count; i++)
{
    if (collection2[i] == search) { Console.WriteLine("ID: " + (i+1)); }
}

ObservableCollection<string> collection3 = new ObservableCollection<string>();

collection3.CollectionChanged += (sender, e) => 
{
    switch (e.Action)
    {
        case NotifyCollectionChangedAction.Add:
            { 
            if (e.NewItems?[0] is string str)
                Console.WriteLine($"Добавлена новая строка: {str}");
                break;
            }
        case NotifyCollectionChangedAction.Remove:
            { 
            if (e.OldItems?[0] is string str)
                Console.WriteLine($"Удалена строка: {str}");
                break;
            }
     
    }
};

collection3.Add("first");
collection3.Add(search);
collection3.Add("third");
collection3.Remove(search);



