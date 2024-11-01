#include "Error.h"
#include "In.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace In;
using namespace std;

IN In::getin(wchar_t infile[])
{

	IN in;

	in.lines = 1;
	in.size = 0;
	in.ignor = 0;
	int position = 0;


	unsigned char* inText = new unsigned char[IN_MAX_LEN_TEXT];
	unsigned char inputChar = ' ';

	ifstream fileInput(infile);

	if (fileInput.fail())
	{
		ERROR_THROW(110);
	}
	
	inputChar = fileInput.get(); //ќткрываетс€ файл дл€ чтени€ с использованием пути, переданного в аргументе.
	inText[in.size++] = '1';
	inText[in.size++] = ' ';
	while (in.size <= IN_MAX_LEN_TEXT)
	{
		if (fileInput.eof())
		{
			inText[in.size] = '\0';
			break;
		}

		if (inputChar == '\n' && in.code['\n'] != IN::F)
		{

			in.lines++;
			inText[in.size++] = inputChar;
			

			inText[in.size] = ' ';
			in.size++;
			position = -1;
		}

		switch (in.code[(unsigned char)inputChar]) // проверка на типы T, F(Err111), I, default(замена символа)
		{
		case IN::T: // T = 1024
			position++;
			inText[in.size] = inputChar;
			in.size++;
			break;

		case IN::F: // F = 2048
			ERROR_THROW_IN(111, in.lines, position);

		case IN::I: //I = 4096
			in.ignor++;
			break;

		default:
			inText[in.size] = in.code[(unsigned char)inputChar];
			position++;
			in.size++;
		}

		inputChar = fileInput.get();
	}


	//”даление повтор€ющихс€ пробелов из исходного текста
	unsigned char* textWithoutSpaces = new unsigned char[IN_MAX_LEN_TEXT];
	int j = 0;
	bool isString = false;
	for (int i = 0; i < in.size; i++)
	{
		if (inText[i] == (char)39) {
			if (!isString) {
				isString = true;
			}
			else isString = false;
		}
		if (!isString && inText[i] == ' ' && inText[i + 1] == ' ')
			continue;

		else
		{
			textWithoutSpaces[j] = inText[i];
			j++;
		}
	}

	in.text = textWithoutSpaces;
	in.text[j] = '\0';
	in.size = j; // переопредел€ем длину согласно без пробелов

	fileInput.close();

	return in;
}
