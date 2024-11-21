using Lab13;
using System.IO;
using System.Xml.Serialization;
using System.Xml;
using System.Xml.Linq;
using System.Runtime.Serialization.Formatters.Soap;

internal class Program
{
    private static void Main(string[] args)
    {
        Tiger tiger = new Tiger("Jambo", 0, 0, 1991, 235);

        SerializerXML<Tiger> tiger_xml = new SerializerXML<Tiger>("tiger.xml");
        tiger_xml.Serialize(tiger);
        var xml_des = tiger_xml.Deserialize();

        SerializerJSON<Tiger> serializer_JSON = new SerializerJSON<Tiger>("tiger.json");
        serializer_JSON.Serialize(tiger);
        var animal = serializer_JSON.Deserialize();
        Console.WriteLine(animal.ToString());

        SerializerSOAP tiger_soap = new SerializerSOAP("tiger.soap");
        //SoapFormatter soap = new SoapFormatter();
        //using (FileStream fs = new FileStream("tiger.soap", FileMode.OpenOrCreate))
        //{
        //    soap.Serialize(fs, tiger);

        //    Console.WriteLine("Объект сериализован");
        //}
        //Console.WriteLine(animal.Name + " успешно сериализирован в файл: tiger.soap");


        Tiger bro = new Tiger("Firo", 5, 3, 2001, 135);
        Tiger sis = new Tiger("Lila", 2, 7, 1995, 200);

        List<Tiger> animals = new List<Tiger>();
        animals.Add(tiger);
        animals.Add(bro);
        animals.Add(sis);

        XmlSerializer xml = new XmlSerializer(typeof(List<Tiger>));
        using (StreamWriter writer = new StreamWriter("tigers.xml"))
        {
            xml.Serialize(writer, animals);
        }
        Console.WriteLine("animals успешно сериализирован в файл: tigers.xml");

        XmlDocument xmlDoc = new XmlDocument();
        xmlDoc.Load("tigers.xml");
        XmlElement xRoot = xmlDoc.DocumentElement;

        Console.WriteLine();
        XmlNodeList? nodes = xRoot?.SelectNodes("*");
        if (nodes is not null)
        {
            foreach (XmlNode node in nodes)
                Console.WriteLine(node.OuterXml);
        }

        Console.WriteLine();
        XmlNodeList? tigerNodes = xRoot?.SelectNodes("//Tiger/Weigth");
        if (tigerNodes is not null)
        {
            foreach (XmlNode node in tigerNodes)
            {
                Console.WriteLine(node.InnerText);
            }
        }
        
        Console.WriteLine();
        XDocument xDoc = new XDocument();

        XElement storage = new XElement("storage");

        XElement headphones = new XElement("goods");
        XAttribute headphonesNamesAttr = new XAttribute("name", "Major III");
        XElement headphonesProducer = new XElement("producer", "Marshall");
        XElement headphonesAmount = new XElement("amount", 19);
        headphones.Add(headphonesNamesAttr);
        headphones.Add(headphonesProducer);
        headphones.Add(headphonesAmount);

        XElement phone = new XElement("goods");
        XAttribute phoneNamesAttr = new XAttribute("name", "Redmi 10 2022");
        XElement phoneProducer = new XElement("producer", "Xiomi");
        XElement phoneAmount = new XElement("amount", 67);
        phone.Add(phoneNamesAttr);
        phone.Add(phoneProducer);
        phone.Add(phoneAmount);

        storage.Add(headphones);
        storage.Add(phone);

        xDoc.Add(storage);
        xDoc.Save("storage.xml");
        Console.WriteLine("Создан storage.xml\n");
        Console.WriteLine("Товары на скалде:\n");
        foreach (XElement goods in storage.Elements("goods"))
        {

            XAttribute? name = goods.Attribute("name");
            XElement? producer = goods.Element("producer");
            XElement? amount = goods.Element("amount");

            Console.WriteLine($"Person: {name?.Value}");
            Console.WriteLine($"Company: {producer?.Value}");
            Console.WriteLine($"Age: {amount?.Value}");

            Console.WriteLine(); 
        }

        var insufficient_goods = xDoc.Element("storage")?.Elements("goods").Where(p =>Convert.ToInt32( p.Element("amount")?.Value)  <20);
        Console.WriteLine("Недостающие товары на скалде:\n");
        foreach (XElement goods in insufficient_goods)
        {

            XAttribute? name = goods.Attribute("name");
            XElement? producer = goods.Element("producer");
            XElement? amount = goods.Element("amount");

            Console.WriteLine($"Person: {name?.Value}");
            Console.WriteLine($"Company: {producer?.Value}");
            Console.WriteLine($"Age: {amount?.Value}");

            Console.WriteLine();
        }
    }
}