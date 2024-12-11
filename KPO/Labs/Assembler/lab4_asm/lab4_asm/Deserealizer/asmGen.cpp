#include "asmGenh.h"
#include "stdafx.h"
#include <string>

string Join(string str);

void AsmGen::CreateFile(wchar_t symb, char chr) 
{
	ofstream file(ASMFILE);

	if (file.is_open())
	{
		file ASMHEADER;

		file << "FILEWCHAR_T DD " << symb << endl;
		file << "FILEINT DD " << int(chr) << endl;
		file << "strINT DB \"char:     \", 0" << endl;
		file << "strWCHAR_T DB \"wchar_t:     \", 0" << endl << endl
			<< ".CODE\n" << endl
			<< "main PROC\n" << endl;

		string footer = "";

		footer += "mov eax,FILEWCHAR_T\n";
		footer += "mov strWCHAR_T+9, al\n";
		footer += "invoke MessageBoxA, 0, offset strWCHAR_T, ADDR TEXT_MESSAGE, OK\n\n\n";
			

		footer += "mov eax,FILEINT\n";
		footer += "mov strINT+5, al\n";
		footer += "invoke MessageBoxA, 0, offset strINT, offset TEXT_MESSAGE, OK\n\n\n";


		footer += "push - 1\n";
		footer += "call ExitProcess\n";
		footer += "main ENDP\n";
		footer += "end main\n";

		file << footer;
		cout << "ASM generated";
	}
	else
	{
		cout << "Asm not open" << endl;
	}
}

string Join(string str)
{
	string newStr = "";
	for (int i = 0; i < str.size(); i++)
	{
		newStr += str[i];
		if (i + 1 != str.size())
		{
			newStr += ", ";
		}
	}
	return newStr;
}