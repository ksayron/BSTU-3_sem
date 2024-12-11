#include "stdafx.h"
#include "asmGenh.h"



void main()
{
	setlocale(LC_ALL, "ru");
	wchar_t wchar_tVal;
	char LiteralVal='a';

	Desearealizer des;
	des.Deserialize(&wchar_tVal, &LiteralVal);

	cout << char(wchar_tVal) << " " << LiteralVal << endl;

	AsmGen AG;
	AG.CreateFile(wchar_tVal, LiteralVal);
}