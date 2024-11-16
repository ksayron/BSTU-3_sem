using Lab12;
KNPDiskInfo.PrintInfo();
Console.WriteLine();
KNPDirInfo.PrintInfo(@"D:\BSTU\3sem\OOP\Labs\Lab12\Lab12");
Console.WriteLine(); 
KNPFIleInfo.PrintInfo("file.txt");
var entries = KNPFileManager.GetFilesAndDir(@"D:\");
Console.WriteLine();
foreach (var entry in entries)
{
    Console.WriteLine(entry);
}
Console.WriteLine();
//task 1
KNPFileManager.CreateDir("KNPInspect");
KNPFileManager.CreateFile("KNPdirinfo.txt");
KNPFileManager.WriteFile("KNPdirinfo.txt", "очень крутой директорий");
KNPFileManager.CopyFile("KNPdirinfo.txt", "copy.txt");
KNPFileManager.DeleteFile("KNPdirinfo.txt"); // за что добряка :((
//task 2
KNPFileManager.CreateDir("KNPFiles");
KNPFileManager.CopyFilesTo(@"D:\BSTU\3sem\OOP\Labs\Lab12\Lab12", "KNPFiles", ".cs");
KNPFileManager.MoveDirTo("KNPFiles", "KNPInspect");
//task 3
KNPFileManager.ZipDir("KNPFiles", @"KNPInspect\ZipKNPFiles.zip");
KNPFileManager.UnzipDir(@"KNPInspect\ZipKNPFiles.zip", @"KNPInspect\Unzip");