#include "stdafx.h"
#include "AsmGen.h"

void main()
{
	setlocale(LC_ALL, "ru");
	char charArrVal[10];
	bool boolVal;
	string str = charArrVal;
	Desearealizer des;
	des.Deserialize(charArrVal, &boolVal);

	cout << charArrVal << " " << boolVal << endl;

	AsmGen AG;
	AG.CreateFile(charArrVal, boolVal);
}