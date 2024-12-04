#include "Error.h";
#include "In.h";
#include <fstream>
#include <iostream>
#include <string>

using namespace In;
using namespace std;

IN In::getin(wchar_t infile[])
{
	IN in;
	wifstream file(infile);
	if (!file.is_open())
	{
		ERROR_THROW(110);
	}

	in.size = 0;
	in.lines = 1;
	in.ignor = 0;
	in.text = new unsigned char[IN_MAX_LEN_TEXT];
	char prev = NULL;

	const int code_table[] = IN_CODE_TABLE;
	for (int i = 0; i < 256; i++)
	{
		in.code[i] = code_table[i];
	}

	wchar_t buf;
	int index = 0;

	while (file.get(buf) && index < IN_MAX_LEN_TEXT - 1)
	{
		if (in.code[static_cast<unsigned int>(buf)] == IN::F)
		{
			ERROR_THROW_IN(111, in.lines, index);
		}
		else if (in.code[static_cast<unsigned int>(buf)] == IN::I)
		{
			in.ignor++;
		}
		else if (in.code[static_cast<unsigned int>(buf)] == IN::T)
		{

			in.text[index++] = static_cast<unsigned char>(buf);

		}
		else
		{
			in.text[index] = in.code[static_cast<unsigned int>(buf)];
			index++;
		}
	}
	in.text[index++] = '\0';
	in.size = index;

	file.close();

	int j = 0;
	unsigned char* textWithoutSpaces = new unsigned char[IN_MAX_LEN_TEXT];
	int countSpaces = 0;

	for (int i = 0; i < in.size; i++)
	{
		if (in.text[i] == '\0')
		{
			break;
		}
		else {
			if (i == 0 && in.text[i] == ' ')
			{
				int k = 0;
				while (in.text[k] == ' ')
				{
					in.countSpaces++;
					k++;
					continue;
				}
				i = k - 1;
			}
			else
				if (in.text[i] == ' ' && in.text[i + 1] == ' ')
				{
					in.countSpaces++;
					continue;
				}
				else if (in.text[i] == ' ' && in.text[i - 1] == '\n')
				{
					in.countSpaces++;
					continue;
				}
				else if (in.text[i] == ' ' && (in.text[i + 1] == '(' || in.text[i + 1] == '{' || in.text[i + 1] == '{' || in.text[i + 1] == ')' || in.text[i + 1] == '}' || in.text[i + 1] == '=' || in.text[i + 1] == '+' || in.text[i + 1] == '-' || in.text[i + 1] == '*' || in.text[i + 1] == '/' || in.text[i + 1] == '%' || in.text[i + 1] == '\n' || in.text[i + 1] == '\0'))
				{
					in.countSpaces++;
					continue;
				}
				else if (in.text[i] == ' ' && (textWithoutSpaces[j - 1] == '(' || textWithoutSpaces[j - 1] == '{' || textWithoutSpaces[j - 1] == '{' || textWithoutSpaces[j - 1] == ')' || textWithoutSpaces[j - 1] == '}' || textWithoutSpaces[j - 1] == '=' || textWithoutSpaces[j - 1] == '+' || textWithoutSpaces[j - 1] == '-' || textWithoutSpaces[j - 1] == '*' || textWithoutSpaces[j - 1] == '/' || textWithoutSpaces[j - 1] == '%'))
				{
					in.countSpaces++;
					continue;
				}
				else {
					textWithoutSpaces[j++] = in.text[i];
				}
		}
	}
	int lines = 1;
	int index2 = 0;
	unsigned char* arr = new unsigned char[IN_MAX_LEN_TEXT];
	for (int i = 0; i < j; i++)
	{
		if (textWithoutSpaces[i] == '\0')
		{
			break;
		}
		if (textWithoutSpaces[i] == L'\n')
		{
			arr[index2++] = '|';
			string lineNumber = to_string(lines);
			for (char c : lineNumber) {
				arr[index2++] = c;
			}

			arr[index2++] = textWithoutSpaces[i];
			lines++;
		}
		else
		{
			arr[index2++] = textWithoutSpaces[i];
		}
	}
	arr[index2++] = '|';
	string lineNumber = to_string(lines);
	for (char c : lineNumber) {
		arr[index2++] = c;
	}
	in.lines = lines;
	in.text = arr;
	in.text[index2++] = '\0';
	delete[] textWithoutSpaces;
	return in;
}
