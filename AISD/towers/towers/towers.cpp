//---------------------------------------------------------------------------

#include <iostream>


using namespace std;

void bashnya(int disk_num, int start, int dest, int miduse)
{
    if (disk_num != 0)
    {
        bashnya(disk_num - 1, start, miduse, dest);
        cout << "Переместить диск " << disk_num << " с " << start << " на " << dest << " стержень" << endl;
        bashnya(disk_num - 1, miduse, dest, start);
    }
}

int main()
{
    setlocale(LC_ALL, "russian");
    int disk_num;
    cout << "Введите число дисков: "<<endl;
    cin >> disk_num;
    int start=0;
    cout << endl <<"Введите начальный стержень: " << endl;
    cin >> start;
    int dest=0;
    cout << endl << "Введите конечный стержень: " << endl;
    cin >> dest;
    cout << endl;
    int miduse = 6 - (start + dest);
    if (dest == start) { return 0; }
    bashnya(disk_num, start, dest, miduse);
    return 0;
}
