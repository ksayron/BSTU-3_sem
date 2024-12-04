#include "stdafx.h"
#include "FST.h"
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>

namespace Lexer
{
	FST::FST typeInteger("", 8,
		FST::NODE(1, FST::RELATION('i', 1)),
		FST::NODE(1, FST::RELATION('n', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE(1, FST::RELATION('e', 4)),
		FST::NODE(1, FST::RELATION('g', 5)),
		FST::NODE(1, FST::RELATION('e', 6)),
		FST::NODE(1, FST::RELATION('r', 7)),
		FST::NODE()
	);

	FST::FST typeString("", 7,
		FST::NODE(1, FST::RELATION('s', 1)),
		FST::NODE(1, FST::RELATION('t', 2)),
		FST::NODE(1, FST::RELATION('r', 3)),
		FST::NODE(1, FST::RELATION('i', 4)),
		FST::NODE(1, FST::RELATION('n', 5)),
		FST::NODE(1, FST::RELATION('g', 6)),
		FST::NODE()
	);

	FST::FST typeFunction("", 9,
		FST::NODE(1, FST::RELATION('f', 1)),
		FST::NODE(1, FST::RELATION('u', 2)),
		FST::NODE(1, FST::RELATION('n', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE(1, FST::RELATION('t', 5)),
		FST::NODE(1, FST::RELATION('i', 6)),
		FST::NODE(1, FST::RELATION('o', 7)),
		FST::NODE(1, FST::RELATION('n', 8)),
		FST::NODE()
	);

	FST::FST typeDeclare("", 8,
		FST::NODE(1, FST::RELATION('d', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('c', 3)),
		FST::NODE(1, FST::RELATION('l', 4)),
		FST::NODE(1, FST::RELATION('a', 5)),
		FST::NODE(1, FST::RELATION('r', 6)),
		FST::NODE(1, FST::RELATION('e', 7)),
		FST::NODE()
	);

	FST::FST typeReturn("", 7,
		FST::NODE(1, FST::RELATION('r', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE(1, FST::RELATION('u', 4)),
		FST::NODE(1, FST::RELATION('r', 5)),
		FST::NODE(1, FST::RELATION('n', 6)),
		FST::NODE()
	);

	FST::FST typeMain("", 5,
		FST::NODE(1, FST::RELATION('m', 1)),
		FST::NODE(1, FST::RELATION('a', 2)),
		FST::NODE(1, FST::RELATION('i', 3)),
		FST::NODE(1, FST::RELATION('n', 4)),
		FST::NODE()
	);

	FST::FST typePrint("", 6,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('i', 3)),
		FST::NODE(1, FST::RELATION('n', 4)),
		FST::NODE(1, FST::RELATION('t', 5)),
		FST::NODE()
	);

	FST::FST typeSpace("", 2,
		FST::NODE(1, FST::RELATION(' ', 1)),
		FST::NODE()
	);
	FST::FST typeLeftBrace("", 2,
		FST::NODE(1, FST::RELATION('{', 1)),
		FST::NODE()
	);
	FST::FST typeRightBrace("", 2,
		FST::NODE(1, FST::RELATION('}', 1)),
		FST::NODE()
	);
	FST::FST typeLeftThesis("", 2,
		FST::NODE(1, FST::RELATION('(', 1)),
		FST::NODE()
	);
	FST::FST typeRightThesis("", 2,
		FST::NODE(1, FST::RELATION(')', 1)),
		FST::NODE()
	);
	FST::FST typeSemicolon("", 2,
		FST::NODE(1, FST::RELATION(';', 1)),
		FST::NODE()
	);
	FST::FST typeComma("", 2,
		FST::NODE(1, FST::RELATION(',', 1)),
		FST::NODE()
	);
	FST::FST typePlus("", 2,
		FST::NODE(1, FST::RELATION('+', 1)),
		FST::NODE());
	FST::FST typeMinus("", 2,
		FST::NODE(1, FST::RELATION('-', 1)),
		FST::NODE());
	FST::FST typeDel("", 2,
		FST::NODE(1, FST::RELATION('/', 1)),
		FST::NODE());
	FST::FST typeMulti("", 2,
		FST::NODE(1, FST::RELATION('*', 1)),
		FST::NODE());
	FST::FST typeEquals("", 2,
		FST::NODE(1, FST::RELATION('=', 1)),
		FST::NODE());

	FST::FST typeIdentificator("", 2,
		FST::NODE(52,
			FST::RELATION('a', 0), FST::RELATION('b', 0),
			FST::RELATION('c', 0), FST::RELATION('d', 0),
			FST::RELATION('e', 0), FST::RELATION('f', 0),
			FST::RELATION('g', 0), FST::RELATION('h', 0),
			FST::RELATION('i', 0), FST::RELATION('j', 0),
			FST::RELATION('k', 0), FST::RELATION('l', 0),
			FST::RELATION('m', 0), FST::RELATION('n', 0),
			FST::RELATION('o', 0), FST::RELATION('p', 0),
			FST::RELATION('q', 0), FST::RELATION('r', 0),
			FST::RELATION('s', 0), FST::RELATION('t', 0),
			FST::RELATION('u', 0), FST::RELATION('v', 0),
			FST::RELATION('w', 0), FST::RELATION('x', 0),
			FST::RELATION('y', 0), FST::RELATION('z', 0),
			FST::RELATION('a', 1), FST::RELATION('b', 1),
			FST::RELATION('c', 1), FST::RELATION('d', 1),
			FST::RELATION('e', 1), FST::RELATION('f', 1),
			FST::RELATION('g', 1), FST::RELATION('h', 1),
			FST::RELATION('i', 1), FST::RELATION('j', 1),
			FST::RELATION('k', 1), FST::RELATION('l', 1),
			FST::RELATION('m', 1), FST::RELATION('n', 1),
			FST::RELATION('o', 1), FST::RELATION('p', 1),
			FST::RELATION('q', 1), FST::RELATION('r', 1),
			FST::RELATION('s', 1), FST::RELATION('t', 1),
			FST::RELATION('u', 1), FST::RELATION('v', 1),
			FST::RELATION('w', 1), FST::RELATION('x', 1),
			FST::RELATION('y', 1), FST::RELATION('z', 1)
		),

		FST::NODE()
	);


	FST::FST typeStringLiteral("", 4,

		FST::NODE(1,
			FST::RELATION('\'', 1)),
		FST::NODE(384,
			FST::RELATION('!', 2), FST::RELATION('@', 2), FST::RELATION('#', 2), FST::RELATION('$', 2), FST::RELATION('%', 2), FST::RELATION('^', 2),
			FST::RELATION('&', 2), FST::RELATION('*', 2), FST::RELATION('(', 2), FST::RELATION(')', 2), FST::RELATION('-', 2), FST::RELATION('_', 2),
			FST::RELATION('+', 2), FST::RELATION('=', 2), FST::RELATION('~', 2), FST::RELATION('`', 2), FST::RELATION('1', 2), FST::RELATION('2', 2),
			FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2),
			FST::RELATION('9', 2), FST::RELATION('0', 2), FST::RELATION('	', 2), FST::RELATION(' ', 2), FST::RELATION('q', 2), FST::RELATION('w', 2),
			FST::RELATION('e', 2), FST::RELATION('r', 2), FST::RELATION('t', 2), FST::RELATION('y', 2), FST::RELATION('u', 2), FST::RELATION('i', 2),
			FST::RELATION('o', 2), FST::RELATION('p', 2), FST::RELATION('{', 2), FST::RELATION('[', 2), FST::RELATION('}', 2), FST::RELATION(']', 2),
			FST::RELATION('\\', 2), FST::RELATION('|', 2), FST::RELATION('Q', 2), FST::RELATION('W', 2), FST::RELATION('R', 2), FST::RELATION('T', 2), FST::RELATION('Y', 2),
			FST::RELATION('U', 2), FST::RELATION('I', 2), FST::RELATION('O', 2), FST::RELATION('P', 2), FST::RELATION('a', 2), FST::RELATION('s', 2),
			FST::RELATION('d', 2), FST::RELATION('f', 2), FST::RELATION('g', 2), FST::RELATION('h', 2), FST::RELATION('j', 2), FST::RELATION('k', 2),
			FST::RELATION('l', 2), FST::RELATION(':', 2), FST::RELATION(';', 2), FST::RELATION('\'', 2), FST::RELATION('"', 2), FST::RELATION('A', 2),
			FST::RELATION('S', 2), FST::RELATION('D', 2), FST::RELATION('F', 2), FST::RELATION('G', 2), FST::RELATION('H', 2), FST::RELATION('J', 2),
			FST::RELATION('K', 2), FST::RELATION('L', 2), FST::RELATION('z', 2), FST::RELATION('x', 2), FST::RELATION('c', 2), FST::RELATION('v', 2),
			FST::RELATION('b', 2), FST::RELATION('n', 2), FST::RELATION('m', 2), FST::RELATION(',', 2), FST::RELATION('.', 2), FST::RELATION('/', 2),
			FST::RELATION('Z', 2), FST::RELATION('X', 2), FST::RELATION('C', 2), FST::RELATION('V', 2), FST::RELATION('B', 2), FST::RELATION('N', 2),
			FST::RELATION('M', 2), FST::RELATION('<', 2), FST::RELATION('>', 2), FST::RELATION('?', 2), FST::RELATION('¸', 2), FST::RELATION('¨', 2),
			FST::RELATION('é', 2), FST::RELATION('ö', 2), FST::RELATION('ó', 2), FST::RELATION('ê', 2), FST::RELATION('å', 2), FST::RELATION('í', 2),
			FST::RELATION('ã', 2), FST::RELATION('ø', 2), FST::RELATION('ù', 2), FST::RELATION('ç', 2), FST::RELATION('õ', 2), FST::RELATION('ú', 2),
			FST::RELATION('É', 2), FST::RELATION('Ö', 2), FST::RELATION('Ó', 2), FST::RELATION('Ê', 2), FST::RELATION('Å', 2), FST::RELATION('Í', 2),
			FST::RELATION('Ã', 2), FST::RELATION('Ø', 2), FST::RELATION('Ù', 2), FST::RELATION('Ç', 2), FST::RELATION('Õ', 2), FST::RELATION('Ú', 2),
			FST::RELATION('ô', 2), FST::RELATION('û', 2), FST::RELATION('â', 2), FST::RELATION('à', 2), FST::RELATION('ï', 2), FST::RELATION('ð', 2),
			FST::RELATION('î', 2), FST::RELATION('ë', 2), FST::RELATION('ä', 2), FST::RELATION('æ', 2), FST::RELATION('ý', 2), FST::RELATION('Ô', 2),
			FST::RELATION('Û', 2), FST::RELATION('Â', 2), FST::RELATION('À', 2), FST::RELATION('Ï', 2), FST::RELATION('Ð', 2), FST::RELATION('Î', 2),
			FST::RELATION('Ë', 2), FST::RELATION('Ä', 2), FST::RELATION('Æ', 2), FST::RELATION('Ý', 2), FST::RELATION('ÿ', 2), FST::RELATION('÷', 2),
			FST::RELATION('ñ', 2), FST::RELATION('ì', 2), FST::RELATION('è', 2), FST::RELATION('ò', 2), FST::RELATION('ü', 2), FST::RELATION('á', 2),
			FST::RELATION('þ', 2), FST::RELATION('ß', 2), FST::RELATION('×', 2), FST::RELATION('Ñ', 2), FST::RELATION('Ì', 2), FST::RELATION('È', 2),
			FST::RELATION('Ò', 2), FST::RELATION('Ü', 2), FST::RELATION('Á', 2), FST::RELATION('Þ', 2),
			FST::RELATION('!', 1), FST::RELATION('@', 1), FST::RELATION('#', 1), FST::RELATION('$', 1), FST::RELATION('%', 1), FST::RELATION('^', 1),
			FST::RELATION('&', 1), FST::RELATION('*', 1), FST::RELATION('(', 1), FST::RELATION(')', 1), FST::RELATION('-', 1), FST::RELATION('_', 1),
			FST::RELATION('+', 1), FST::RELATION('=', 1), FST::RELATION('~', 1), FST::RELATION('`', 1), FST::RELATION('1', 1), FST::RELATION('2', 1),
			FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1),
			FST::RELATION('9', 1), FST::RELATION('0', 1), FST::RELATION('	', 1), FST::RELATION(' ', 1), FST::RELATION('q', 1), FST::RELATION('w', 1),
			FST::RELATION('e', 1), FST::RELATION('r', 1), FST::RELATION('t', 1), FST::RELATION('y', 1), FST::RELATION('u', 1), FST::RELATION('i', 1),
			FST::RELATION('o', 1), FST::RELATION('p', 1), FST::RELATION('{', 1), FST::RELATION('[', 1), FST::RELATION('}', 1), FST::RELATION(']', 1),
			FST::RELATION('\\', 1), FST::RELATION('|', 1), FST::RELATION('Q', 1), FST::RELATION('W', 1), FST::RELATION('R', 1), FST::RELATION('T', 1), FST::RELATION('Y', 1),
			FST::RELATION('U', 1), FST::RELATION('I', 1), FST::RELATION('O', 1), FST::RELATION('P', 1), FST::RELATION('a', 1), FST::RELATION('s', 1),
			FST::RELATION('d', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('j', 1), FST::RELATION('k', 1),
			FST::RELATION('l', 1), FST::RELATION(':', 1), FST::RELATION(';', 1), FST::RELATION('\'', 1), FST::RELATION('"', 1), FST::RELATION('A', 1),
			FST::RELATION('S', 1), FST::RELATION('D', 1), FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1), FST::RELATION('J', 1),
			FST::RELATION('K', 1), FST::RELATION('L', 1), FST::RELATION('z', 1), FST::RELATION('x', 1), FST::RELATION('c', 1), FST::RELATION('v', 1),
			FST::RELATION('b', 1), FST::RELATION('n', 1), FST::RELATION('m', 1), FST::RELATION(',', 1), FST::RELATION('.', 1), FST::RELATION('/', 1),
			FST::RELATION('Z', 1), FST::RELATION('X', 1), FST::RELATION('C', 1), FST::RELATION('V', 1), FST::RELATION('B', 1), FST::RELATION('N', 1),
			FST::RELATION('M', 1), FST::RELATION('<', 1), FST::RELATION('>', 1), FST::RELATION('?', 1), FST::RELATION('¸', 1), FST::RELATION('¨', 1),
			FST::RELATION('é', 1), FST::RELATION('ö', 1), FST::RELATION('ó', 1), FST::RELATION('ê', 1), FST::RELATION('å', 1), FST::RELATION('í', 1),
			FST::RELATION('ã', 1), FST::RELATION('ø', 1), FST::RELATION('ù', 1), FST::RELATION('ç', 1), FST::RELATION('õ', 1), FST::RELATION('ú', 1),
			FST::RELATION('É', 1), FST::RELATION('Ö', 1), FST::RELATION('Ó', 1), FST::RELATION('Ê', 1), FST::RELATION('Å', 1), FST::RELATION('Í', 1),
			FST::RELATION('Ã', 1), FST::RELATION('Ø', 1), FST::RELATION('Ù', 1), FST::RELATION('Ç', 1), FST::RELATION('Õ', 1), FST::RELATION('Ú', 1),
			FST::RELATION('ô', 1), FST::RELATION('û', 1), FST::RELATION('â', 1), FST::RELATION('à', 1), FST::RELATION('ï', 1), FST::RELATION('ð', 1),
			FST::RELATION('î', 1), FST::RELATION('ë', 1), FST::RELATION('ä', 1), FST::RELATION('æ', 1), FST::RELATION('ý', 1), FST::RELATION('Ô', 1),
			FST::RELATION('Û', 1), FST::RELATION('Â', 1), FST::RELATION('À', 1), FST::RELATION('Ï', 1), FST::RELATION('Ð', 1), FST::RELATION('Î', 1),
			FST::RELATION('Ë', 1), FST::RELATION('Ä', 1), FST::RELATION('Æ', 1), FST::RELATION('Ý', 1), FST::RELATION('ÿ', 1), FST::RELATION('÷', 1),
			FST::RELATION('ñ', 1), FST::RELATION('ì', 1), FST::RELATION('è', 1), FST::RELATION('ò', 1), FST::RELATION('ü', 1), FST::RELATION('á', 1),
			FST::RELATION('þ', 1), FST::RELATION('ß', 1), FST::RELATION('×', 1), FST::RELATION('Ñ', 1), FST::RELATION('Ì', 1), FST::RELATION('È', 1),
			FST::RELATION('Ò', 1), FST::RELATION('Ü', 1), FST::RELATION('Á', 1), FST::RELATION('Þ', 1)
		),
		FST::NODE(1,
			FST::RELATION('\'', 3)),
		FST::NODE()
	);

	FST::FST typeNumbLiteral("", 2,
		FST::NODE(20,
			FST::RELATION('0', 0), FST::RELATION('1', 0), FST::RELATION('2', 0), FST::RELATION('3', 0), FST::RELATION('4', 0),
			FST::RELATION('5', 0), FST::RELATION('6', 0), FST::RELATION('7', 0), FST::RELATION('8', 0), FST::RELATION('9', 0),
			FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),
			FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1)),
		FST::NODE()

	);

	bool isFunc = false;

	bool check(std::string s, FST::FST fst)
	{
		fst.string = s;

		return FST::execute(fst);
	}

	void checkElInIdTable(std::vector<std::pair<std::string, int>> words, int i, LT::LexTable& lextable, IT::IdTable& idtable, int indIdTab)
	{
		IT::Entry ent;

		if (LT::GetEntry(lextable, i - 1).lexema == 'f')
		{
			if (IT::IsId(idtable, words[i].first) == TI_NULLIDX)
			{
				if (words[i - 2].first == "integer")
				{
					ent = { i + 1,words[i].first,IT::INT,IT::F,TI_INT_DEFAULT };
				}
				else if (words[i - 2].first == "string") {

					ent = { i + 1,words[i].first,IT::STR,IT::F , TI_STR_DEFAULT };
				}
				else {
					ERROR_THROW(121);
				}
			}
			IT::Add(idtable, ent);
		}
		else if (LT::GetEntry(lextable, i - 1).lexema == 't' && LT::GetEntry(lextable, i - 2).lexema == 'd')
		{
			int buf = IT::IsId(idtable, words[i].first);
			if ((IT::IsId(idtable, words[i].first) == TI_NULLIDX || idtable.table[buf].idtype == IT::P) || (IT::IsId(idtable, words[i].first) != TI_NULLIDX && isFunc))
			{
				if (words[i - 1].first == "integer")
				{
					ent = { i + 1,words[i].first,IT::INT,IT::V,TI_INT_DEFAULT };
				}
				else if (words[i - 1].first == "string")
				{
					ent = { i + 1,words[i].first,IT::STR,IT::V,TI_STR_DEFAULT };
				}
				else {
					ERROR_THROW(121);
				}
			}
			IT::Add(idtable, ent);
		}
		else if (LT::GetEntry(lextable, i - 2).lexema == ',' || LT::GetEntry(lextable, i - 4).lexema == 'f')
		{

			if (words[i - 1].first == "integer")
			{
				ent = { i + 1, words[i].first, IT::INT, IT::P, TI_INT_DEFAULT };
			}
			else if (words[i - 1].first == "string")
			{
				ent = { i + 1,words[i].first,IT::STR,IT::P,TI_STR_DEFAULT };
			}
			else {
				ERROR_THROW(121);
			}

			IT::Add(idtable, ent);
		}
		else {

		}
		indIdTab++;

	}

	void valueOfINT(LT::LexTable& lextable, IT::IdTable& idtable, int ind, std::vector<std::pair<std::string, int>> words, int indIdTab)
	{
		if (lextable.table[ind - 1].lexema == '=' && lextable.table[ind - 2].lexema == 'i')
		{
			int buf = IT::IsId(idtable, words[ind - 2].first);
			idtable.table[buf].value.vint = std::stoi(words[ind].first);
		}
	}

	void valueOfSTR(LT::LexTable& lextable, IT::IdTable& idtable, int ind, std::vector<std::pair<std::string, int>> words)
	{
		if (lextable.table[ind - 1].lexema == '=' && lextable.table[ind - 2].lexema == 'i')
		{
			int buf = IT::IsId(idtable, words[ind - 2].first);
			std::string strValue = words[ind].first;
			idtable.table[buf].value.vstr->len = (char)(strValue.length());
			strncpy(idtable.table[buf].value.vstr->str, strValue.c_str(), TI_STR_MAXSIZE - 1);
		}
	}

	void Run(LT::LexTable& lextable, IT::IdTable& idtable, In::IN in) {

		int lineNumber = 1;
		string bufWord = "";
		int indLexTab = 0;
		int indIdTab = 0;

		int ind = 0;
		int size = 0;
		bool fCo = true;
		bool fEnd = false;

		std::vector<std::pair<std::string, int>> words;

		for (int i = 0; !fEnd; i++)
		{
			if (in.text[i] == '|')
			{
				int k;
				for (k = i; in.text[k] != '\n'; k++)
				{
					if (in.text[k] == '\0')
					{
						fEnd = true;
						break;
					}
				}
				if (bufWord != "")
				{
					words.push_back({ bufWord,lineNumber });
					bufWord = "";
					size++;
				}
				int bufInd = ind;
				i = ++k;
				lineNumber++;
			}
			if (!fEnd)
			{
				if (in.text[i] == ' ' && fCo)
				{
					if (bufWord != "")
					{
						words.push_back({ bufWord,lineNumber });
						bufWord = "";
						ind++;
						size++;
					}

				}
				else if (in.text[i] == ',' || in.text[i] == ';' || in.text[i] == '{' || in.text[i] == '}' || in.text[i] == '(' || in.text[i] == ')' || in.text[i] == '*' || in.text[i] == '/' || in.text[i] == '+' || in.text[i] == '-' || in.text[i] == '=')
				{
					if (bufWord != "")
					{
						words.push_back({ bufWord,lineNumber });
						bufWord = "";
						size++;
					}
					bufWord += in.text[i];
					words.push_back({ bufWord, lineNumber });
					bufWord = "";
					size++;
				}
				else if (in.text[i] == '\'')
				{
					if (fCo)
					{
						fCo = false;
					}
					else
					{
						fCo = true;
					}
					bufWord += in.text[i];
				}
				else
				{
					bufWord += in.text[i];
				}
			}
		}

		for (int i = 0; i < size; i++)
		{
			cout << words[i].first << endl;
		}

		int ch = 0;
		int currLine = 0;
		int lineNumb = 1;

		for (int i = 0; i < size; i++)
		{
			if (check(words[i].first, typeInteger))
			{
				LT::Entry ent = { LEX_INTEGER, words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeString))
			{
				LT::Entry ent = { LEX_STRING,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeFunction))
			{
				LT::Entry ent = { LEX_FUNCTION,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeDeclare))
			{
				LT::Entry ent = { LEX_DECLARE,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typePrint))
			{
				LT::Entry ent = { LEX_PRINT,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeReturn))
			{
				LT::Entry ent = { LEX_RETURN,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeMain))
			{
				LT::Entry ent = { LEX_MAIN,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeIdentificator))
			{
				LT::Entry ent = { LEX_ID,  words[i].second, indIdTab };
				LT::Add(lextable, ent);
				checkElInIdTable(words, i, lextable, idtable, indIdTab);
			}
			else if (check(words[i].first, typeStringLiteral))
			{
				LT::Entry ent = { LEX_LITERAL,  words[i].second };
				LT::Add(lextable, ent);
				valueOfSTR(lextable, idtable, i, words);
			}
			else if (check(words[i].first, typeNumbLiteral))
			{
				LT::Entry ent = { LEX_LITERAL,  words[i].second };
				LT::Add(lextable, ent);
				valueOfINT(lextable, idtable, i, words, indIdTab);
			}
			else if (check(words[i].first, typeRightBrace))
			{
				LT::Entry ent = { LEX_BRACELET,  words[i].second };
				LT::Add(lextable, ent);
				isFunc = false;
			}
			else if (check(words[i].first, typeLeftBrace))
			{
				LT::Entry ent = { LEX_LEFTBRACE,  words[i].second };
				LT::Add(lextable, ent);
				isFunc = true;
			}
			else if (check(words[i].first, typeRightThesis))
			{
				LT::Entry ent = { LEX_RIGHTHESIS,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeLeftThesis))
			{
				LT::Entry ent = { LEX_LEFTHESIS,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeSemicolon))
			{
				LT::Entry ent = { LEX_SEMICOLON,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeComma))
			{
				LT::Entry ent = { LEX_COMMA,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typePlus))
			{
				LT::Entry ent = { LEX_PLUS,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeMinus))
			{
				LT::Entry ent = { LEX_MINUS,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeMulti))
			{
				LT::Entry ent = { LEX_STAR,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeDel))
			{
				LT::Entry ent = { LEX_DIRSLASH,  words[i].second };
				LT::Add(lextable, ent);
			}
			else if (check(words[i].first, typeEquals))
			{
				LT::Entry ent = { LEX_EQUALS,  words[i].second };
				LT::Add(lextable, ent);
			}
			else {
				ERROR_THROW(120);
			}
		}

		currLine = 0;
		for (int i = 0; i < size; i++) {
			if (words[i].second != currLine) {
				currLine++;
				cout << "\n";
				cout << setw(2) << setfill('0') << currLine << " ";
				cout << LT::GetEntry(lextable, i).lexema;
			}
			else {
				cout << LT::GetEntry(lextable, i).lexema;
			}
		}

		cout << endl;
		for (int i = 0; i < idtable.size; i++) {
			IT::Entry ent = IT::GetEntry(idtable, i);
			cout << ent.id << ", ";
			if (ent.iddatatype == 1)
			{
				cout << "INT";
			}
			else {
				cout << "STR";
			}

			cout << ", ";

			if (ent.idtype == 1)
			{
				cout << "V";
			}
			else if (ent.idtype == 2) {
				cout << "F";
			}
			else
			{
				cout << "P";
			}

			cout << ", " << ent.idxfirstLE << ", ";

			if (ent.iddatatype == IT::INT)
			{
				cout << ent.value.vint;
			}
			else {
				for (int j = 0; j < ent.value.vstr->len; j++)
				{
					cout << ent.value.vstr->str[j];
				}
			}
			cout << endl;
		}
	}
}

