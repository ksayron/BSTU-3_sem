#include "Searealizer.h"
#include "stdafx.h"

void Serealizer::Serialize(char* charArr, bool boolVal)
{
	ofstream file(FILENAME, ios::binary);
	if (file.is_open())
	{
		//запись в файл
		short charType = TYPECHAR;
		short boolType = TYPEBOOL;

		file.write(reinterpret_cast<char*>(&charType), sizeof(char));
		file.write(reinterpret_cast<char*>(charArr), sizeof(char)*10);
		file.write(reinterpret_cast<char*>(&boolType), sizeof(char));
		file.write(reinterpret_cast<char*>(&boolVal), sizeof(bool));
		file.close();
	}
	else
	{
		cout << "File not open" << endl;
	}
}