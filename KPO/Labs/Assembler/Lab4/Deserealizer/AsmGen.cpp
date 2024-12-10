#include "AsmGen.h"
#include "stdafx.h"
#include <string>

string Join(string str);

void AsmGen::CreateFile(char* CharArr, bool Bool) // 2 байт беззнаковое
{
	ofstream file(ASMFILE);
	string strChar = string(CharArr);
	string strUshort16 = to_string(Bool);
	strChar = Join(strChar);
	strUshort16 = Join(strUshort16);

	if (file.is_open())
	{
		file ASMHEADER;

		file << "FILECHAR DD " << strChar << endl;
		file << "CHARSTR DB \"char:    \", 0" << endl << endl;
		file << "FILEBOOL DD " << strUshort16 << endl;
		file << "BOOLSTR DB \"bool:     \", 0" << endl << endl
			<< ".CODE\n" << endl
			<< "main PROC\n" << endl;

		string footer = "";
		string cTypes = "";
		int startI = 8;
		int countShort = string(CharArr).size();

		for (int i = 0; i < countShort; i++)
		{
			footer += "\n\nmov eax, FILECHAR " + cTypes;
			footer += "\n";
			footer += "mov CHARSTR +" + to_string(startI++);
			footer += ", al\n";
			cTypes += " + type FILECHAR";
		}

		footer += "invoke MessageBoxA, 0, offset CHARSTR, ADDR TEXT_MESSAGE, OK\n";

		string cTypesUshort = "";
		startI = 10;

		for (int i = 0; i < to_string(Bool).size(); i++)
		{
			footer += "\n\nmov eax, FILEBOOL " + cTypesUshort;
			footer += "\n";
		}

		footer += "push - 1\n";
		footer += "call ExitProcess\n";
		footer += "main ENDP\n";
		footer += "end main\n";

		file << footer;
	}
	else
	{
		cout << "File not open" << endl;
	}
}

string Join(string str)
{
	string newStr = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] <= '0' && str[i] >= '9') {
			newStr += str[i];
		}
		else {
			newStr += '\'';
			newStr += str[i];
			newStr += '\'';
		}
		if (i + 1 != str.size())
		{
			newStr += ", ";
		}
	}
	return newStr;
}