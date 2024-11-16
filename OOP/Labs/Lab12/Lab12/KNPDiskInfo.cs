using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.Json;
using static System.Collections.Specialized.BitVector32;

namespace Lab12
{
    static class KNPDiskInfo
    {

        public static void PrintInfo()
        {
            try{DriveInfo[] drives = DriveInfo.GetDrives();

                foreach (DriveInfo drive in drives)
                {
                    Console.WriteLine($"Название: {drive.Name}");
                    Console.WriteLine($"Тип: {drive.DriveType}");
                    Console.WriteLine($"файловая система: {drive.DriveFormat}");
                    if (drive.IsReady)
                    {
                        Console.WriteLine($"Объем диска: {drive.TotalSize / (1024 * 1024 * 1024)} GB");
                        Console.WriteLine($"Свободное пространство: {drive.TotalFreeSpace / (1024 * 1024 * 1024)} GB");
                        Console.WriteLine($"Метка диска: {drive.VolumeLabel}");
                    }
                    Console.WriteLine();
                    Lab12.KNPLog.WriteLog(drive.Name, drive.Name,"KNPDISKInfo.PrintInfo()");
                }
                
            }
            catch (Exception ex) { Console.WriteLine(ex.Message); }
        }
        
    }
}
