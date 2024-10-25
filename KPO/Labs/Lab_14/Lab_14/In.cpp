#include "stdafx.h"

namespace In
{
	IN getin(wchar_t infile[]) //������ ������� ������ �� �����
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
			throw ERROR_THROW(110);

		inputChar = fileInput.get(); //����������� ���� ��� ������ � �������������� ����, ����������� � ���������.
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
				int size = trunc(log10(in.lines)) + 1;
				for (int i = 0; i < size; i++) {
					int del = pow(10,size-1-i);
					int input = (in.lines % (del*10)) / del;
					char input_C = input+'0';
					inText[in.size++] =input_C;
				}

				inText[in.size] = ' ';
				in.size++;
				position = -1;
			}
			
			switch (in.code[(unsigned char)inputChar]) // �������� �� ���� T, F(Err111), I, default(������ �������)
			{
			case IN::T: // T = 1024
				position++;
				inText[in.size] = inputChar;
				in.size++;
				break;

			case IN::F: // F = 2048
				throw ERROR_THROW_IN(111, in.lines, position);

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


		//�������� ������������� �������� �� ��������� ������
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
		in.size = j; // �������������� ����� �������� ��� ��������

		fileInput.close();

		return in;
	}
};