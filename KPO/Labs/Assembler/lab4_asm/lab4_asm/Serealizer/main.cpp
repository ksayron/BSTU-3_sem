#include "stdafx.h"


using namespace std;
enum types {
	WCHAR_T = 1,
	CHAR = 2
};


class Serealizer
{
public:
	void Serialize(wchar_t str, char number);

private:
	const char* FILENAME = "bin.bin";
};

void Serealizer::Serialize(wchar_t str, char symb)
{
	ofstream file(Serealizer::FILENAME, ios::binary);
	if (file.is_open())
	{
		uint8_t type = types::WCHAR_T;
		file.write(reinterpret_cast<char*>(&type), sizeof(type));
		file.write(reinterpret_cast<char*>(&str), sizeof(str));
		type = types::CHAR;
		file.write(reinterpret_cast<char*>(&type), sizeof(type));
		file.write(reinterpret_cast<char*>(&symb), sizeof(char));
		
		file.close();
	}
	else
	{
		cout << "Не удалось открыть файл" << endl;
	}
}

void main()
{
	setlocale(LC_ALL, "ru");
	Serealizer serealizer;
	wchar_t symb;
	char input;
    
	cout << "Введите wchar_t: ";
	wcin>>symb;

	cout << "Введите символьный литерал: ";
	cin>>input;

	cout << symb << " " << input << endl;

	serealizer.Serialize(symb, input);
}
