using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab12
{
    static class KNPDirInfo
    {
        public static void PrintInfo(string path)
        {
            try{DirectoryInfo dirInfo = new DirectoryInfo(path);
            var a = dirInfo.EnumerateFiles();
            var b = dirInfo.EnumerateDirectories();
            
            Console.WriteLine($"Название каталога: {dirInfo.Name}");
            Console.WriteLine($"Кол-во файлов: {a.Count()}");
            Console.WriteLine($"Кол-во поддиректориев: {b.Count()}");
            Console.WriteLine($"Время создания каталога: {dirInfo.CreationTime}");
            Console.WriteLine($"Родительские директории: {dirInfo.Parent}");
            Lab12.KNPLog.WriteLog(dirInfo.Name, dirInfo.Name, "KNPFileInfo.PrintInfo()");
            }
            catch (Exception ex) { Console.WriteLine(ex.Message); }
        }
    }
}
