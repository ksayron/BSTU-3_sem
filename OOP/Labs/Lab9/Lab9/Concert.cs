using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.ObjectModel;
using System.Collections;

namespace Lab9
{
    public class Concert : IEnumerable
    {
        public string Artist { get; private set; }
        Dictionary<string, int> TicketPrice;
        
        public void AddTicketPricing(string name, int price) => TicketPrice.Add(name, price);
        public void RemoveTicketPricing(string name) => TicketPrice.Remove(name); 
        public void ChangeTicketPricing(string name, int price) => TicketPrice[name] = price;
        public int GetPrice(string name) => TicketPrice[name];
        public void PrintTicketPricing()
        {
            foreach(var item in TicketPrice)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return TicketPrice.GetEnumerator();
        }

        public Concert(string artist)
        {
            Artist = artist;
            TicketPrice = new Dictionary<string, int>();
        }
        public Concert(string artist, Dictionary<string, int> ticketPrice)
        {
            Artist = artist;
            TicketPrice = ticketPrice;
        }

        
    }
}
