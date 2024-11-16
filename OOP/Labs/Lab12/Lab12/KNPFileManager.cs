using System.IO;
using System.IO.Compression;
namespace Lab12
{
    static class KNPFileManager
    {
        public static List<string> GetFilesAndDir(string disk)
        {
            try
            {
                DriveInfo drive = new DriveInfo(disk);
                List<string> entries = new List<string>();
                var buffer = drive.RootDirectory.EnumerateFiles();
                foreach (var file in buffer)
                {
                    entries.Add(file.Name);
                }
                var buffer2 = drive.RootDirectory.EnumerateDirectories();
                foreach (var dir in buffer2)
                {
                    entries.Add(dir.Name);
                }
                Lab12.KNPLog.WriteLog(drive.Name, drive.Name, "KNPFileManager.GetFilesAndDir()");
                return entries;
            }
            catch (Exception ex) { Console.WriteLine(ex.Message); return null; }

        }
        public static void CreateDir(string path)
        {
            try { 
                if(!Directory.Exists(path))Directory.CreateDirectory(path); 
                Lab12.KNPLog.WriteLog(path, path, "KNPFileManager.CreateDir()"); }
            catch (Exception e) { Console.WriteLine(e.Message); }
        }
        public static void DeleteDir(string path)
        {
            try { Directory.Delete(path); Lab12.KNPLog.WriteLog(path, path, "KNPFileManager.DeleteDir()"); }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
        public static void CreateFile(string path)
        {
            try { File.Create(path).Close(); Lab12.KNPLog.WriteLog(path, path, "KNPFileManager.CreateFile()"); }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
        public static void DeleteFile(string path)
        {
            try { File.Delete(path); Lab12.KNPLog.WriteLog(path, path, "KNPFileManager.DeleteFile()"); }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
        public static void WriteFile(string path, string text)
        {
            try
            {
                using (StreamWriter sw = new StreamWriter(path)) { sw.WriteLine(text);  }
                Lab12.KNPLog.WriteLog(path, path, "KNPFileManager.WriteFile()");
                
            }
            catch (Exception e) { Console.WriteLine(e.Message); }
        }
        public static void CopyFilesTo(string from, string to)
        {
            try
            {
                DirectoryInfo source = new DirectoryInfo(from);
                var files = source.GetFiles();
                foreach (var file in files)
                {
                    file.CopyTo(to);
                }
                Lab12.KNPLog.WriteLog(from, from, "KNPFileManager.CopyFilesTO() источник для копирования");
                Lab12.KNPLog.WriteLog(to, to, "KNPFileManager.CopyFilesTO() результат копирования");
            }
            catch (Exception e) { Console.WriteLine(e.Message); }
        }
        public static void CopyFilesTo(string from, string to, string extension)
        {
            try
            {
                DirectoryInfo source = new DirectoryInfo(from);
                var files = source.GetFiles();
                foreach (var file in files)
                {
                    var copy = @$"{to}\{file.Name}";
                    if (file.Extension == extension && !File.Exists(copy)) file.CopyTo(copy);
                }
                Lab12.KNPLog.WriteLog(from, from, "KNPFileManager.CopyFilesTO() источник для копирования");
                Lab12.KNPLog.WriteLog(extension, extension, "KNPFileManager.CopyFilesTO() фильтр расширений копирования");
                Lab12.KNPLog.WriteLog(to, to, "KNPFileManager.CopyFilesTO() результат копирования");
            }
            catch (Exception e) { Console.WriteLine(e.Message); }
        }

        public static void CopyFile(string from, string name)
        {
            try
            {
                FileInfo source = new FileInfo(from);
                var dir = source.Directory;
                if (!File.Exists(@$"{dir.FullName}\{name}"))
                {
                    File.Create(dir.FullName + name);
                }
                 List<string> buffer= new List<string>();
                using (StreamReader reader = new StreamReader(from))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        buffer.Add(line);
                    }
                    Lab12.KNPLog.WriteLog(from, from, "KNPFileManager.CopyFiles() источник для копирования");
                }
                using (StreamWriter writer = new StreamWriter(@$"{dir.FullName}\{name}"))
                {
                    
                    foreach(var line in buffer){

                        Console.WriteLine($"Копирование: {line}");
                        writer.WriteLine(line);

                    }
                }
                
                Lab12.KNPLog.WriteLog(name, @$"{dir.FullName}\{name}", "KNPFileManager.CopyFiles() результат копирования");

            }
            catch (Exception e) { Console.WriteLine(e.Message); }
        }
        public static void MoveDirTo(string dir, string dest)
        {
            try {if(!Directory.Exists(dest)) Directory.Move(dir, dest);
                Lab12.KNPLog.WriteLog(dir, dir, "KNPFileManager.CopyFilesTO() переносимая директория");
                Lab12.KNPLog.WriteLog(dest, dest, "KNPFileManager.CopyFilesTO() место переноса");
            }
            catch (Exception e) { Console.WriteLine(e.Message); }
        }
        public static async void ZipFile(string source,string name)
        {
           try
            {
                await Zip(source, name);
                KNPLog.WriteLog(source, source, "KNPFileManager.ZipFile() сжимаемый файл");
                KNPLog.WriteLog(name, name, "KNPFileManager.ZipFile() полученный архив");
            }
            catch (Exception e) { Console.WriteLine(e.Message) ; }
        }
        public static async void ZipDir(string source, string name)
        {
            
            try
            {
                if(!File.Exists(name)) System.IO.Compression.ZipFile.CreateFromDirectory(source, name);
                KNPLog.WriteLog(source, source, "KNPFileManager.ZipFile() сжимаемый файл");
                KNPLog.WriteLog(name, name, "KNPFileManager.ZipFile() полученный архив");
            }
            catch (Exception e) { Console.WriteLine(e.Message); }
        }

        async static Task Zip(string sourceFile, string compressedFile)
        {
            // поток для чтения исходного файла
            using FileStream sourceStream = new FileStream(sourceFile, FileMode.OpenOrCreate);
            // поток для записи сжатого файла
            using FileStream targetStream = File.Create(compressedFile);

            // поток архивации
            using GZipStream compressionStream = new GZipStream(targetStream, CompressionMode.Compress);
            await sourceStream.CopyToAsync(compressionStream); // копируем байты из одного потока в другой

            Console.WriteLine($"Сжатие файла {sourceFile} завершено.");
            Console.WriteLine($"Исходный размер: {sourceStream.Length}  сжатый размер: {targetStream.Length}");
        }

        public static async void UnzipFile(string source, string name)
        {
            try
            {
                await Unzip(source, name);
                KNPLog.WriteLog(source, source, "KNPFileManager.UnzipFile() разжимаемый архив");
                KNPLog.WriteLog(name, name, "KNPFileManager.UnzipFile() востановленный файл");
            }
            catch (Exception e) { Console.WriteLine(e.Message); }
        }
        public static async void UnzipDir(string source, string name)
        {
            try
            {
                System.IO.Compression.ZipFile.ExtractToDirectory(source, name);
                KNPLog.WriteLog(source, source, "KNPFileManager.ZipFile() разжимамемый архив");
                KNPLog.WriteLog(name, name, "KNPFileManager.ZipFile() полученный файл");
            }
            catch (Exception e) {  }
        }

        async static Task Unzip(string compressedFile, string targetFile)
        {
            
            using FileStream sourceStream = new FileStream(compressedFile, FileMode.OpenOrCreate);
            using FileStream targetStream = File.Create(targetFile);
            using GZipStream decompressionStream = new GZipStream(sourceStream, CompressionMode.Decompress);
            await decompressionStream.CopyToAsync(targetStream);
            Console.WriteLine($"получен файл: {targetFile}");
        }

    }
}
