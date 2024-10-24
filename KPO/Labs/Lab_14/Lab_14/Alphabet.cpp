#include"Alphabet.h"
#include"stdafx.h"
#include"In.h"
#include"Error.h"
#include <stdio.h>
#include <string.h>
#include <iomanip>



namespace LA
{
	LT::LexTable __LexTable = LT::Create(LT_MAXSIZE - 1);
	IT::IdTable __IdTable = IT::Create(TI_MAXSIZE - 1);
	bool stringFlag = false;
	char* str = new char[MAX_LEX_SIZE];
	bool declareFlag = false;

	char FST()
	{
		FST_INT
			FST_STRING
			FST_FUNC
			FST_DECLARE
			FST_RETURN
			FST_MAIN
			FST_PRINT
			FST_LITERAL
			FST_IDENF
			if (FST::Execute(_int))
				return LEX_INTEGER;
		if (FST::Execute(_string))
		{
			stringFlag = true;
			return LEX_STRING;
		}
		if (FST::Execute(_function))
			return LEX_FUNCTION;
		if (FST::Execute(_declare))
			return LEX_DECLARE;
		if (FST::Execute(_return))
			return LEX_RETURN;
		if (FST::Execute(_main))
		{
			return LEX_MAIN;
		}
		if (FST::Execute(_print))
			return LEX_PRINT;
		if (FST::Execute(literal_int))
			return LEX_LITERAL;
		if (FST::Execute(idenf))
			return LEX_ID;
		return NULL;
	}
	void LA(Parm::PARM parm, In::IN in)
	{
		int indexIT;
		setlocale(LC_ALL, "rus");
		LT::Entry current_entry_LT;
		int bufferIndex = 0;
		current_entry_LT.sn = 0;
		current_entry_LT.idxTI = 0;
		current_entry_LT.lexema[0] = NULL;
		std::stack<IT::Entry*> scope;
		scope.push(NULL);
		int number_literal = 0;
		bool addedToITFlag = false;
		bool declareFunctionflag = false;
		IT::Entry current_entry_IT;
		__LexTable.size = 0;
		int currentLine = 1;
		std::ofstream LT_file;
		std::ofstream IT_file;
		LT_file.open("LT.txt");
		IT_file.open("IT.txt");
		for (int i = 0; i < in.size; i++)
		{
			if (((in.text[i] >= 'A' && in.text[i] <= 'Z') || (in.text[i] >= 'a' && in.text[i] <= 'z') || (in.text[i] >= '0' && in.text[i] <= '9') || in.text[i] == '\'') && in.text[i] != ' ')
			{
				str[bufferIndex] = in.text[i];
				bufferIndex++;
				if (bufferIndex >= MAX_LEX_SIZE)
				{
					throw ERROR_THROW(119);
				}
			}
			else
			{
				str[bufferIndex] = '\0';
				current_entry_LT.lexema[0] = FST();
				if (current_entry_LT.lexema[0] == LEX_MAIN)
				{
					current_entry_LT.idxTI = __IdTable.size;
					memcpy(current_entry_IT.id, str, 5);
					current_entry_IT.id[5] = '\0';
					current_entry_IT.iddatatype = IT::INT;
					current_entry_IT.idtype = IT::F;
					current_entry_IT.value.vint = NULL;
					current_entry_IT.idxfirstLE = currentLine;
					current_entry_IT.scope = NULL;
					indexIT = IT::search(__IdTable, current_entry_IT);
					if (indexIT >= 0)
					{
						throw ERROR_THROW(105);
					}
					if (indexIT == -1)
					{
						current_entry_LT.idxTI = __IdTable.size;
						IT::Add(__IdTable, current_entry_IT);
					}
				}
				if (current_entry_LT.lexema[0] == LEX_LITERAL)
				{
					current_entry_LT.idxTI = __IdTable.size;
					sprintf_s(current_entry_IT.id, "L%d", number_literal);
					current_entry_IT.iddatatype = IT::INT;
					current_entry_IT.idtype = IT::L;
					current_entry_IT.idxfirstLE = currentLine;
					current_entry_IT.value.vint = atoi(str);
					current_entry_IT.scope = scope.top();
					current_entry_LT.idxTI = __IdTable.size;
					IT::Add(__IdTable, current_entry_IT);
					number_literal++;
				}
				if (current_entry_LT.lexema[0] == LEX_ID)
				{
					if (scope.empty())
						current_entry_IT.scope = NULL; //Åñëè ñòåê ïóñò, òî òåêóùåìó èäåíòèôèêàòîðó current_entry_IT óñòàíàâëèâàåòñÿ îáëàñòü âèäèìîñòè (scope) ðàâíîé NULL
					else
						current_entry_IT.scope = scope.top(); //óñòàíàâëèâàåòñÿ âåðøèíà ñòåêà êàê îáëàñòü âèäèìîñòè òåêóùåãî èäåíòèôèêàòîðà.
					current_entry_LT.idxTI = __IdTable.size;
					memcpy(current_entry_IT.id, str, 5);
					current_entry_IT.id[5] = '\0';
					current_entry_IT.iddatatype = IT::INT;
					current_entry_IT.value.vint = NULL; // íå èíèöèàëèçèðîâàí
					current_entry_IT.idxfirstLE = currentLine;
					current_entry_IT.idtype = IT::V;
					if (__LexTable.table[__LexTable.size - 2].lexema[0] == LEX_DECLARE)
					{
						std::cout << __LexTable.table[__LexTable.size - 1].lexema[0];
						if (__LexTable.table[__LexTable.size - 1].lexema[0] == LEX_STRING && stringFlag)
						{
							current_entry_IT.iddatatype = IT::STR;
							strcpy_s(current_entry_IT.value.vstr->str, "");
							stringFlag = false;
						}
						indexIT = IT::search(__IdTable, current_entry_IT);//ïîèñê òåêóùåãî èäåíòèôèêàòîðà â òàáëèöå èäåíòèôèêàòîðîâ 
						if (indexIT >= 0) //Åñëè èäåíòèôèêàòîð óæå ñóùåñòâóåò
						{
							throw ERROR_THROW(105);
						}
						if (indexIT == -1)
						{
							current_entry_LT.idxTI = __IdTable.size;
							IT::Add(__IdTable, current_entry_IT);
							addedToITFlag = true;
						}

					}
					if (__LexTable.table[__LexTable.size - 1].lexema[0] == LEX_FUNCTION)
					{
						current_entry_IT.idtype = IT::F;
						declareFunctionflag = true;
						if (__LexTable.table[__LexTable.size - 2].lexema[0] == LEX_STRING && stringFlag)
						{
							current_entry_IT.iddatatype = IT::STR;
							strcpy_s(current_entry_IT.value.vstr->str, "");
							stringFlag = false;
						}
						indexIT = IT::search(__IdTable, current_entry_IT);
						if (indexIT >= 0)
						{
							throw ERROR_THROW(105);
						}
						if (indexIT == -1)
						{

							current_entry_LT.idxTI = __IdTable.size;
							IT::Add(__IdTable, current_entry_IT);
							addedToITFlag = true;
						}
					}
					if (__LexTable.table[__LexTable.size - 2].lexema[0] == LEX_LEFTTHESIS &&
						__LexTable.table[__LexTable.size - 3].lexema[0] == LEX_ID &&
						__LexTable.table[__LexTable.size - 3].idxTI == __IdTable.size - 1 &&
						__IdTable.table[__IdTable.size - 1].idtype == IT::F) //òåêóùèé èäåíòèôèêàòîð - ïàðàìåòð ôóíêöèè
					{
						current_entry_IT.idtype = IT::P;
						if (__LexTable.table[__LexTable.size - 1].lexema[0] == LEX_STRING && stringFlag)
						{
							current_entry_IT.iddatatype = IT::STR;
							strcpy_s(current_entry_IT.value.vstr->str, "");
							stringFlag = false;
						}
						indexIT = IT::search(__IdTable, current_entry_IT);
						if (indexIT >= 0)
						{
							throw ERROR_THROW(105);
						}
						current_entry_LT.idxTI = __IdTable.size;
						IT::Add(__IdTable, current_entry_IT);
						addedToITFlag = true;
					}
					if (__LexTable.table[__LexTable.size - 2].lexema[0] == LEX_COMMA && __IdTable.table[__LexTable.table[__LexTable.size - 2].idxTI].idtype == IT::P)
					{
						current_entry_IT.idtype = IT::P;
						if (__LexTable.table[__LexTable.size - 1].lexema[0] == LEX_STRING && stringFlag)
						{
							current_entry_IT.iddatatype = IT::STR;
							strcpy_s(current_entry_IT.value.vstr->str, "");
							stringFlag = false;
						}
						indexIT = IT::search(__IdTable, current_entry_IT);
						if (indexIT >= 0)
						{
							throw ERROR_THROW(105);
						}
						IT::Add(__IdTable, current_entry_IT);
						addedToITFlag = true;
					}
					if (!addedToITFlag)
					{
						indexIT = IT::search(__IdTable, current_entry_IT);
						if (indexIT >= 0)
						{
							for (int i = 0; i < strlen(current_entry_IT.id); i++)
								std::cout << current_entry_IT.id[i];
							std::cout << __IdTable.table[indexIT].scope->id;
							std::cout << std::endl;
							current_entry_LT.idxTI = indexIT;
						}
					}
					std::memset(current_entry_IT.id, NULL, 5);
					current_entry_IT.iddatatype = IT::INT;
					current_entry_IT.value.vint = NULL;
					addedToITFlag = false;
				}

				bufferIndex = 0;
				std::memset(str, NULL, bufferIndex + 1);
			}
			if (current_entry_LT.lexema[0] != NULL)
			{
				current_entry_LT.sn = currentLine;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;

			}
			switch (in.text[i])
			{
			case MARK:
				if (str[0] == '\'' && bufferIndex != 1)
				{
					current_entry_LT.idxTI = __IdTable.size;
					str[bufferIndex] = '\0';
					current_entry_LT.lexema[0] = LEX_LITERAL;
					number_literal++;
					sprintf_s(current_entry_IT.id, "L%d", number_literal);
					current_entry_IT.iddatatype = IT::STR;
					current_entry_IT.idtype = IT::L;
					current_entry_IT.idxfirstLE = currentLine;
					for (int i = 0; i < strlen(str); i++)
					{
						current_entry_IT.value.vstr->str[i] = str[i];
					}
					current_entry_IT.value.vstr->str[strlen(str)] = '\0';
					current_entry_IT.value.vstr->len = strlen(current_entry_IT.value.vstr->str);
					current_entry_LT.sn = currentLine;
					current_entry_IT.scope = scope.top();
					LT::Add(__LexTable, current_entry_LT);
					IT::Add(__IdTable, current_entry_IT);
					current_entry_LT.lexema[0] = NULL;
					break;
				}
				break;
			case NEW_LINE:
				current_entry_LT.lexema[0] = '\n';
				current_entry_LT.sn = currentLine;
				currentLine++;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;
				break;
			case SEMICOLON:
				current_entry_LT.lexema[0] = LEX_SEMICOLON;
				current_entry_LT.sn = currentLine;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;
				break;
			case COMMA:
				current_entry_LT.lexema[0] = LEX_COMMA;
				current_entry_LT.sn = currentLine;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;
				break;
			case LEFT_BRACE:
				current_entry_LT.lexema[0] = LEX_LEFTBRACE;
				current_entry_LT.sn = currentLine;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;
				for (int j = __IdTable.size - 1; j >= 0; j--)
				{
					if (__IdTable.table[j].idtype == IT::F)
					{
						scope.push(&__IdTable.table[j]);
						break;
					}
				}
				break;
			case RIGHT_BRACE:
				current_entry_LT.lexema[0] = LEX_BRACELET;
				current_entry_LT.sn = currentLine;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;
				if (!scope.empty())
					scope.pop();
				break;
			case LEFTTHESIS:
				current_entry_LT.lexema[0] = LEX_LEFTTHESIS;
				current_entry_LT.sn = currentLine;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;
				if (declareFunctionflag)
				{
					for (int j = __IdTable.size - 1; j >= 0; j--)
					{
						if (__IdTable.table[j].idtype == IT::F)
						{
							scope.push(&__IdTable.table[j]);
							break;
						}
					}
				}
				break;
			case RIGHTTHESIS:
				current_entry_LT.lexema[0] = LEX_RIGHTTHESIS;
				current_entry_LT.sn = currentLine;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;
				if (!scope.empty() && declareFunctionflag)
				{
					scope.pop();
					declareFunctionflag = false;
				}
				break;
			case PLUS:
				current_entry_LT.lexema[0] = LEX_PLUS;
				current_entry_LT.sn = currentLine;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;
				break;
			case MINUS:
				current_entry_LT.lexema[0] = LEX_MINUS;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;
				break;
			case STAR:
				current_entry_LT.lexema[0] = LEX_STAR;
				current_entry_LT.sn = currentLine;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;
				break;
			case DIRSLASH:
				current_entry_LT.lexema[0] = LEX_DIRSLASH;
				current_entry_LT.sn = currentLine;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;
				break;
			case EQUAL:
				current_entry_LT.lexema[0] = LEX_EQUAL;
				current_entry_LT.sn = currentLine;
				LT::Add(__LexTable, current_entry_LT);
				current_entry_LT.lexema[0] = NULL;
				break;
			}
		}
		currentLine = 1;
		LT_file << currentLine;
		LT_file << '\t';
		for (int i = 0; i < __LexTable.size; i++)
		{
			current_entry_LT = LT::GetEntry(__LexTable, i);
			if (currentLine != current_entry_LT.sn)
			{
				currentLine = current_entry_LT.sn;
				LT_file << currentLine;
				LT_file << '\t';
			}
			LT_file << current_entry_LT.lexema[0];
		}
		LT_file.close();
		IT_file << std::setw(5) << "id"
			<< std::setw(10) << "datatype"
			<< std::setw(10) << "idtype"
			<< std::setw(10) << "Line"
			<< std::setw(10) << "value"
			<< std::setw(10) << "Scope" << std::endl;

		for (int i = 0; i < __IdTable.size; i++) {
			current_entry_IT = IT::GetEntry(__IdTable, i);
			IT_file << std::setw(5) << current_entry_IT.id;
			if (current_entry_IT.iddatatype == 1)
				IT_file << std::setw(10) << "INT";
			if (current_entry_IT.iddatatype == 2)
				IT_file << std::setw(10) << "STR";
			if (current_entry_IT.idtype == IT::V)
				IT_file << std::setw(10) << "V";
			if (current_entry_IT.idtype == IT::L)
				IT_file << std::setw(10) << "L";
			if (current_entry_IT.idtype == IT::F)
				IT_file << std::setw(10) << "F";
			if (current_entry_IT.idtype == IT::P)
				IT_file << std::setw(10) << "P";
			IT_file << std::setw(10) << current_entry_IT.idxfirstLE;

			if (current_entry_IT.iddatatype == IT::INT) {
				IT_file << std::setw(10) << current_entry_IT.value.vint;
			}
			if (current_entry_IT.iddatatype == IT::STR) {
				IT_file << std::setw(7);
				for (int j = 0; j < strlen(current_entry_IT.value.vstr->str); j++) {
					IT_file << current_entry_IT.value.vstr->str[j];
				}
				IT_file << std::setw(10);
			}
			IT_file << std::setw(10);
			if (current_entry_IT.scope != NULL) {
				for (int j = 0; j < strlen(current_entry_IT.scope->id); j++)
				{
					IT_file << current_entry_IT.scope->id[j];
				}
			}
			IT_file << std::endl;
		}
		IT_file.close();
	}
}