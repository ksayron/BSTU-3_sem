using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Text.Json;
using System.Runtime.Serialization.Formatters.Soap;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization;

namespace Lab13
{
    public class SerializerXML<T> : ISerializer<T> where T : Animal
    {
        string path;
        public SerializerXML(string path)
        {
            this.path = path;
        }
        public void Serialize(T animal)
        {
            try
            {
                XmlSerializer xml = new XmlSerializer(typeof(T));
                using (StreamWriter writer = new StreamWriter(path))
                {
                    xml.Serialize(writer, animal);
                }
                Console.WriteLine(animal.Name + " успешно сериализирован в файл: " + path);
            }
            catch (Exception e) { Console.WriteLine(e.Message); }
        }

        public T Deserialize()
        {
            try
            {
                XmlSerializer xml = new XmlSerializer(typeof(T));
                using (FileStream fs = new FileStream(path, FileMode.OpenOrCreate))
                {
                    T? animal = xml.Deserialize(fs) as T;
                    Console.WriteLine(animal.ToString());
                    return animal;
                }
            }
            catch (Exception e) { Console.WriteLine(e.Message); return null; }
        }

    }

    public class SerializerJSON<T> : ISerializer<T> where T : Animal
    {
        string path;
        public SerializerJSON(string path)
        {
            this.path = path;
        }
        public void Serialize(T animal)
        {
            try
            {
                using (StreamWriter writer = new StreamWriter(path))
                {
                    var ser = JsonSerializer.Serialize(animal);
                    writer.Write(ser);
                }
                Console.WriteLine(animal.Name + " успешно сериализирован в файл: " + path);
            }
            catch (Exception e) { Console.WriteLine(e.Message); }
        }

        public T Deserialize() 
        {
            using (StreamReader reader = new StreamReader(path))
            {
                var json = reader.ReadToEnd();
                T animal = JsonSerializer.Deserialize<T>(json);
                return animal;
            }
        }

    }

    public class SerializerSOAP 
    {
        public string path;
        public SerializerSOAP(string path)
        {
            this.path = path;
        }

        public Tiger Deserialize()
        {
            SoapFormatter soap = new SoapFormatter();
            using (FileStream fs = new FileStream("people.soap", FileMode.OpenOrCreate))
            {
                Tiger tiger = soap.Deserialize(fs) as Tiger;

                Console.WriteLine("Объект десериализован");
                return tiger;
            }
        }

        public void Serialize(Tiger animal)
        {
            try
            {
                SoapFormatter soap = new SoapFormatter();
                using (FileStream fs = new FileStream(path, FileMode.OpenOrCreate))
                {
                    soap.Serialize(fs, animal);

                    Console.WriteLine("Объект сериализован");
                }
                Console.WriteLine(animal.Name + " успешно сериализирован в файл: " + path);
            }
            catch (Exception e) { Console.WriteLine(e.Message); }
        }
    }

}
