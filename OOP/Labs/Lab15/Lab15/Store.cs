using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Transactions;
using static System.Formats.Asn1.AsnWriter;

namespace Lab15
{
    public class Store
    {
        public string name;
        int balance = 1500;
        public bool isOpen = true;
        public BlockingCollection<Good> goods;
        public string transactions = "";
        public Store(string name)
        {
            this.name = name;
            goods = new BlockingCollection<Good>();
        }
        public void RunStore(Producer producer,Buyer buyer)
        {
            Parallel.Invoke(
                () => ShowInfo(),
                () => OpenShop(),
                () => producer.Produce(this),
                () => buyer.Buy(this)
                );
            
        }
        public void ShowInfo()
        {
            while (isOpen)
            {
                Console.Clear();
                Console.WriteLine($"Магазин {name}");
                Console.WriteLine($"баланс магазина {balance}");
                Console.WriteLine("Операции:");

                // Display the produce and buy operations
                Console.WriteLine(transactions);

                Thread.Sleep(1000);
            }

        }
        public void OpenShop()
        {
            Thread.Sleep(30000);
            isOpen = false;
            Thread.Sleep(5000);
            Console.WriteLine("\n\nМагазин закрыт.");
        }
        public void AddGood(Good good,int amount)
        {
            for(int i=0;i<amount;i++)
            { goods.Add(good); }
            balance -= good.price*amount;

        }
        public bool BuyGood(Good item,int patience)
        {
            if(goods.TryTake(out item,patience)){
            balance += item.price*2;
                return true;
            }
            else { return false; }
        }
    }

    public class Good
    {
        public string name;
        public int price;
        public Good(string name,int price)
        {
            this.name = name;
            this.price = price; 
        }
    }
    public class Producer
    {
        public string name;
        public Good production;
        public int price;
        public int amount;
        public int time;
        string transanction;
        public Producer(string name,Good production,int amount,int time)
        {
            this.name = name;
            this.production = production;
            this.amount = amount;
            this.time = time;
            transanction = $"{name} завез в магазин {production.name} в количестве {amount} за {amount * production.price}$\n";
        }
        public void Produce(Store store)
        {
            while(store.isOpen)
            {
                store.AddGood(production, amount);
                store.transactions=transanction+store.transactions;
                Thread.Sleep(time * 1000);
            }
        }

    }

    public class Buyer
    {
        public string name;
        public Good loved_item;
        int patience;
        string transanction_succes;
        string transanction_failed= "Ушел разочарованный покупатель\n";
        public Buyer(string name,Good item,int patience)
        {
            this.name = name;
            this.loved_item = item;
            this.patience = patience;
            transanction_succes = $"{name} купила {loved_item.name} за {loved_item.price*2}$\n";
        }
        public void Buy(Store store)
        {
            Thread.Sleep(1000);
            while(store.isOpen)
            {
                if (store.BuyGood(loved_item,patience*1000))
                {
                    store.transactions = transanction_succes + store.transactions;
                }
                else { store.transactions = transanction_failed + store.transactions; }

                Thread.Sleep(3000);
            }
        }
    }
}
