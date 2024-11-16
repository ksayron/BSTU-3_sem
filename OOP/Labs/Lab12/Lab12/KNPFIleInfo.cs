using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab12
{
    static class KNPFIleInfo
    {
        public static void PrintInfo(string path)
        {
            try{ FileInfo fileInfo = new FileInfo(path); 
            
            if (!fileInfo.Exists)
            {
                File.Create(path);
            }
            Console.WriteLine($"Полное имя: {fileInfo.FullName}");
            Console.WriteLine($"Время создания: {fileInfo.CreationTime}");
            Console.WriteLine(fileInfo.Name + " " + fileInfo.Extension + " " + fileInfo.Length);
            Lab12.KNPLog.WriteLog(fileInfo.Name, fileInfo.Name, "KNPFileInfo.PrintInfo()");
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}
