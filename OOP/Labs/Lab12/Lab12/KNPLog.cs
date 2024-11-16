using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Encodings.Web;
using System.Text.Json;
using System.Threading.Tasks;

namespace Lab12
{
    public class KNPLogRecord
    {
        public string Action { get; set; }
        public string Filename { get; set; }
        public string Filepath { get; set; }
        public DateTime Date { get; set; }
    }
    public static class KNPLog
    {
        public const string _filepath = @"logfile.json";

        public static void WriteLog(string filename, string filepath, string action)
        {

            var record = new { Action = action, Filename = filename, Filepath = filepath, Date = DateTime.Now };
            if (!File.Exists(_filepath))
            {
                File.Create(_filepath).Close();
            }

            List<object> records = new List<object>();

            string text = File.ReadAllText(_filepath);
            if (string.IsNullOrEmpty(text) == false)
            {
                if (JsonSerializer.Deserialize<List<object>>(text) == null)
                {
                    records = new List<object>();
                }
                else
                {
                    records = JsonSerializer.Deserialize<List<object>>(text);
                }

            }
            records.Add(record);



            string result = JsonSerializer.Serialize(records, new JsonSerializerOptions { WriteIndented = true, Encoder = JavaScriptEncoder.UnsafeRelaxedJsonEscaping });

            File.WriteAllText(_filepath, result, System.Text.Encoding.UTF8);
        }
        public static void ReadLog()
        {
            using (StreamReader reader = new StreamReader(_filepath))
            {
                string buff;
                while ((buff = reader.ReadLine()) != null)
                {
                    Console.WriteLine(buff);
                }
            }
        }
        public static void SearchLogByAction(string action)
        {
            string jsonrecords = File.ReadAllText(_filepath);

            List<KNPLogRecord> records = new List<KNPLogRecord>();
            records = JsonSerializer.Deserialize<List<KNPLogRecord>>(jsonrecords);

            foreach (var record in records)
            {
                if (record.Action == action)
                {
                    Console.WriteLine($"action: {record.Action}, filename: {record.Filename}, filepath: {record.Filepath}, date: {record.Date}");

                }
            }
        }
        public static void SearchByTimeRange(DateTime from, DateTime to)
        {
            int counter = 0;

            string jsonrecords = File.ReadAllText(_filepath);

            List<KNPLogRecord> records = new List<KNPLogRecord>();
            records = JsonSerializer.Deserialize<List<KNPLogRecord>>(jsonrecords);

            foreach (var record in records)
            {
                Console.WriteLine($"action: {record.Action}, filename: {record.Filename}, filepath: {record.Filepath}, date: {record.Date}");
                counter++;
            }



            Console.WriteLine("кол-во записей : " + counter);
        }
        public static void RemoveOldLogs()
        {
            string jsonrecords = File.ReadAllText(_filepath);

            List<KNPLogRecord> records = new List<KNPLogRecord>();
            records = JsonSerializer.Deserialize<List<KNPLogRecord>>(jsonrecords);

            foreach (var record in records)
            {
                if (record.Date >= DateTime.Now.AddHours(-1))
                {
                    Console.WriteLine($"action: {record.Action}, filename: {record.Filename}, filepath: {record.Filepath}, date: {record.Date}");

                }
            }

        }


    }
}
