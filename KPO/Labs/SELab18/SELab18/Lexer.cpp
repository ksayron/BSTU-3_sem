#include "stdafx.h"

#define MFST_TRACE_START std::cout<<std::setw(4)<<std::left<<"Øàã"<<":"\
						 <<std::setw(20)<<std::left<<"Ïðàâèëî"\
						 <<std::setw(30)<<std::left<<"Âõîäíàÿ ëåíòà"\
						 <<std::setw(20)<<std::left<<"Ñòåê"\
						 <<std::endl;


LT::LexTable lextab = LT::Create(LT_MAXSIZE - 1);
IT::IdTable idtab = IT::Create(TI_MAXSIZE - 1);

bool typeInt(char word[]) {
	FST::FST typeInt(word, 8,
		FST::NODE(1, FST::RELATION('i', 1)),
		FST::NODE(1, FST::RELATION('n', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE(1, FST::RELATION('e', 4)),
		FST::NODE(1, FST::RELATION('g', 5)),
		FST::NODE(1, FST::RELATION('e', 6)),
		FST::NODE(1, FST::RELATION('r', 7)),
		FST::NODE()
	);
	return FST::execute(typeInt);
}
bool typeString(char word[]) {
	FST::FST typeString(word, 7,
		FST::NODE(1, FST::RELATION('s', 1)),
		FST::NODE(1, FST::RELATION('t', 2)),
		FST::NODE(1, FST::RELATION('r', 3)),
		FST::NODE(1, FST::RELATION('i', 4)),
		FST::NODE(1, FST::RELATION('n', 5)),
		FST::NODE(1, FST::RELATION('g', 6)),
		FST::NODE()
	);
	return FST::execute(typeString);
}
bool typeFunction(char word[]) {
	FST::FST typeFunction(word, 9,
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
	return FST::execute(typeFunction);
}
bool strDeclare(char word[]) {
	FST::FST strDeclare(word, 8,
		FST::NODE(1, FST::RELATION('d', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('c', 3)),
		FST::NODE(1, FST::RELATION('l', 4)),
		FST::NODE(1, FST::RELATION('a', 5)),
		FST::NODE(1, FST::RELATION('r', 6)),
		FST::NODE(1, FST::RELATION('e', 7)),
		FST::NODE()
	);
	return FST::execute(strDeclare);
}
bool strReturn(char word[]) {
	FST::FST stReturn(word, 7,
		FST::NODE(1, FST::RELATION('r', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE(1, FST::RELATION('u', 4)),
		FST::NODE(1, FST::RELATION('r', 5)),
		FST::NODE(1, FST::RELATION('n', 6)),
		FST::NODE()
	);
	return FST::execute(stReturn);
}
bool strMain(char word[]) {
	FST::FST strMain(word, 5,
		FST::NODE(1, FST::RELATION('m', 1)),
		FST::NODE(1, FST::RELATION('a', 2)),
		FST::NODE(1, FST::RELATION('i', 3)),
		FST::NODE(1, FST::RELATION('n', 4)),
		FST::NODE()
	);
	return FST::execute(strMain);
}
bool strPrint(char word[]) {
	FST::FST strPrint(word, 6,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('i', 3)),
		FST::NODE(1, FST::RELATION('n', 4)),
		FST::NODE(1, FST::RELATION('t', 5)),
		FST::NODE()
	);
	return FST::execute(strPrint);
}
bool expression(char word[]) {
	FST::FST expression(word, 2,
		FST::NODE(4,
			FST::RELATION('+', 1),
			FST::RELATION('-', 1),
			FST::RELATION('*', 1),
			FST::RELATION('/', 1)),
		FST::NODE()
	);
	return FST::execute(expression);
}
bool leftBrace(char word[]) {
	FST::FST leftBrace(word, 2,
		FST::NODE(1, FST::RELATION('{', 1)),
		FST::NODE()
	);
	return FST::execute(leftBrace);
}
bool rightBrace(char word[]) {
	FST::FST rightbrace(word, 2,
		FST::NODE(1, FST::RELATION('}', 1)),
		FST::NODE()
	);
	return FST::execute(rightbrace);
}
bool leftThesis(char word[]) {
	FST::FST leftthesis(word, 2,
		FST::NODE(1, FST::RELATION('(', 1)),
		FST::NODE()
	);
	return FST::execute(leftthesis);
}
bool rightThesis(char word[]) {
	FST::FST rightthesis(word, 2,
		FST::NODE(1, FST::RELATION(')', 1)),
		FST::NODE()
	);
	return FST::execute(rightthesis);
}
bool semicolon(char word[]) {
	FST::FST semicolon(word, 2,
		FST::NODE(1, FST::RELATION(';', 1)),
		FST::NODE()
	);
	return FST::execute(semicolon);
}
bool comma(char word[]) {
	FST::FST comma(word, 2,
		FST::NODE(1, FST::RELATION(',', 1)),
		FST::NODE()
	);
	return FST::execute(comma);
}
bool strPlus(char word[]) {
	FST::FST pluslife(word, 2,
		FST::NODE(1, FST::RELATION('+', 1)),
		FST::NODE()
	);
	return FST::execute(pluslife);
}
bool strMinus(char word[]) {
	FST::FST minuslife(word, 2,
		FST::NODE(1, FST::RELATION('-', 1)),
		FST::NODE()
	);
	return FST::execute(minuslife);
}
bool del(char word[]) {
	FST::FST del(word, 2,
		FST::NODE(1, FST::RELATION('/', 1)),
		FST::NODE()
	);
	return FST::execute(del);
}
bool multiplic(char word[]) {
	FST::FST mult(word, 2,
		FST::NODE(1, FST::RELATION('*', 1)),
		FST::NODE()
	);
	return FST::execute(mult);
}
bool equal(char word[]) {

	FST::FST equal(word, 2,
		FST::NODE(1, FST::RELATION('=', 1)),
		FST::NODE()
	);
	return FST::execute(equal);
}
bool literalString(char word[]) {

	FST::FST literalString(word, 2,
		FST::NODE(140,
			FST::RELATION('a', 1), FST::RELATION('a', 0), FST::RELATION('b', 1), FST::RELATION('b', 0), FST::RELATION('c', 1), FST::RELATION('c', 0),
			FST::RELATION('d', 1), FST::RELATION('d', 0), FST::RELATION('e', 1), FST::RELATION('e', 0), FST::RELATION('f', 1), FST::RELATION('f', 0),
			FST::RELATION('g', 1), FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('h', 1), FST::RELATION('i', 0), FST::RELATION('i', 1),
			FST::RELATION('j', 0), FST::RELATION('j', 1), FST::RELATION('k', 0), FST::RELATION('k', 1), FST::RELATION('l', 0), FST::RELATION('l', 1),
			FST::RELATION('m', 0), FST::RELATION('m', 1), FST::RELATION('n', 0), FST::RELATION('n', 1), FST::RELATION('o', 0), FST::RELATION('o', 1),
			FST::RELATION('p', 0), FST::RELATION('p', 1), FST::RELATION('q', 0), FST::RELATION('q', 1), FST::RELATION('r', 0), FST::RELATION('r', 1),
			FST::RELATION('s', 0), FST::RELATION('s', 1), FST::RELATION('t', 0), FST::RELATION('t', 1), FST::RELATION('u', 0), FST::RELATION('u', 1),
			FST::RELATION('v', 0), FST::RELATION('v', 1), FST::RELATION('w', 0), FST::RELATION('w', 1), FST::RELATION('x', 0), FST::RELATION('x', 1),
			FST::RELATION('y', 0), FST::RELATION('y', 1), FST::RELATION('z', 0), FST::RELATION('z', 1), FST::RELATION('1', 0), FST::RELATION('1', 1),
			FST::RELATION('2', 0), FST::RELATION('2', 1), FST::RELATION('3', 0), FST::RELATION('3', 1), FST::RELATION('4', 0), FST::RELATION('4', 1),
			FST::RELATION('5', 0), FST::RELATION('5', 1), FST::RELATION('6', 0), FST::RELATION('6', 1), FST::RELATION('7', 0), FST::RELATION('7', 1),
			FST::RELATION('8', 0), FST::RELATION('8', 1), FST::RELATION('9', 0), FST::RELATION('9', 1), FST::RELATION('0', 0), FST::RELATION('0', 1),
			FST::RELATION('é', 1), FST::RELATION('é', 0), FST::RELATION('ö', 1), FST::RELATION('ö', 0), FST::RELATION('¸', 1), FST::RELATION('¸', 0),
			FST::RELATION('ó', 1), FST::RELATION('ó', 0), FST::RELATION('ê', 1), FST::RELATION('ê', 0), FST::RELATION('å', 1), FST::RELATION('å', 0),
			FST::RELATION('í', 1), FST::RELATION('í', 0), FST::RELATION('ã', 1), FST::RELATION('ã', 0), FST::RELATION('ø', 1), FST::RELATION('ø', 0),
			FST::RELATION('ù', 1), FST::RELATION('ù', 0), FST::RELATION('ç', 1), FST::RELATION('ç', 0), FST::RELATION('õ', 1), FST::RELATION('õ', 0),
			FST::RELATION('ú', 1), FST::RELATION('ú', 0), FST::RELATION('ô', 1), FST::RELATION('ô', 0), FST::RELATION('û', 1), FST::RELATION('û', 0),
			FST::RELATION('â', 1), FST::RELATION('â', 0), FST::RELATION('à', 1), FST::RELATION('à', 0), FST::RELATION('ï', 1), FST::RELATION('ï', 0),
			FST::RELATION('ð', 1), FST::RELATION('ð', 0), FST::RELATION('î', 1), FST::RELATION('î', 0), FST::RELATION('ë', 1), FST::RELATION('ë', 0),
			FST::RELATION('ä', 1), FST::RELATION('ä', 0), FST::RELATION('æ', 1), FST::RELATION('æ', 0), FST::RELATION('ý', 1), FST::RELATION('ý', 0),
			FST::RELATION('ÿ', 1), FST::RELATION('ÿ', 0), FST::RELATION('÷', 1), FST::RELATION('÷', 0), FST::RELATION('ñ', 1), FST::RELATION('ñ', 0),
			FST::RELATION('ì', 1), FST::RELATION('ì', 0), FST::RELATION('è', 1), FST::RELATION('è', 0), FST::RELATION('ò', 1), FST::RELATION('ò', 0),
			FST::RELATION('ü', 1), FST::RELATION('ü', 0), FST::RELATION('á', 1), FST::RELATION('á', 0), FST::RELATION('þ', 1), FST::RELATION('þ', 0),
			FST::RELATION(' ', 0), FST::RELATION(' ', 1)),
		FST::NODE()
	);
	return FST::execute(literalString);
}
bool literalInteger(char word[]) {

	FST::FST literalInt(word, 2,
		FST::NODE(20,
			FST::RELATION('0', 0), FST::RELATION('1', 0), FST::RELATION('2', 0),
			FST::RELATION('3', 0), FST::RELATION('4', 0), FST::RELATION('5', 0),
			FST::RELATION('6', 0), FST::RELATION('7', 0), FST::RELATION('8', 0),
			FST::RELATION('9', 0), FST::RELATION('0', 1), FST::RELATION('1', 1),
			FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),
			FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),
			FST::RELATION('8', 1), FST::RELATION('9', 1)),
		FST::NODE()
	);
	return FST::execute(literalInt);
}
bool identif(char word[]) {

	FST::FST identif(word, 2,
		FST::NODE(54,
			FST::RELATION('a', 1), FST::RELATION('a', 0), FST::RELATION('b', 1), FST::RELATION('b', 0),
			FST::RELATION('c', 1), FST::RELATION('c', 0), FST::RELATION('d', 1), FST::RELATION('d', 0), FST::RELATION('e', 1), FST::RELATION('e', 0),
			FST::RELATION('f', 1), FST::RELATION('f', 0), FST::RELATION('g', 1), FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('h', 1), FST::RELATION('i', 0), FST::RELATION('i', 1),
			FST::RELATION('j', 0), FST::RELATION('j', 1), FST::RELATION('k', 0), FST::RELATION('k', 1), FST::RELATION('l', 0), FST::RELATION('l', 1),
			FST::RELATION('m', 0), FST::RELATION('m', 1), FST::RELATION('n', 0), FST::RELATION('n', 1), FST::RELATION('o', 0), FST::RELATION('o', 1),
			FST::RELATION('p', 0), FST::RELATION('p', 1), FST::RELATION('q', 0), FST::RELATION('q', 1), FST::RELATION('r', 0), FST::RELATION('r', 1),
			FST::RELATION('s', 0), FST::RELATION('s', 1), FST::RELATION('t', 0), FST::RELATION('t', 1), FST::RELATION('u', 0), FST::RELATION('u', 1),
			FST::RELATION('v', 0), FST::RELATION('v', 1), FST::RELATION('w', 0), FST::RELATION('w', 1), FST::RELATION('x', 0), FST::RELATION('x', 1),
			FST::RELATION('y', 0), FST::RELATION('y', 1), FST::RELATION('z', 0), FST::RELATION('z', 1)),
		FST::NODE()
	);
	return FST::execute(identif);
}
bool strlenFunc(char word[]) {
	FST::FST strlen(word, 7,
		FST::NODE(1, FST::RELATION('s', 1)),
		FST::NODE(1, FST::RELATION('t', 2)),
		FST::NODE(1, FST::RELATION('r', 3)),
		FST::NODE(1, FST::RELATION('l', 4)),
		FST::NODE(1, FST::RELATION('e', 5)),
		FST::NODE(1, FST::RELATION('n', 6)),
		FST::NODE()
	);
	return FST::execute(strlen);
}
bool substrFunc(char word[]) {
	FST::FST substr(word, 7,
		FST::NODE(1, FST::RELATION('s', 1)),
		FST::NODE(1, FST::RELATION('u', 2)),
		FST::NODE(1, FST::RELATION('b', 3)),
		FST::NODE(1, FST::RELATION('s', 4)),
		FST::NODE(1, FST::RELATION('t', 5)),
		FST::NODE(1, FST::RELATION('r', 6)),
		FST::NODE()
	);
	return FST::execute(substr);
}
bool exprCheck(char* str)
{
	FST::FST expression(str, 2,
		FST::NODE(4,
			FST::RELATION('+', 1),
			FST::RELATION('-', 1),
			FST::RELATION('*', 1),
			FST::RELATION('/', 1)),
			FST::NODE()
	);
	return FST::execute(expression);
}

namespace Lexer
{

	void LexAnaliz(Parm::PARM parm, In::IN in)
	{
		Flags flags;
		char symbol;
		int line = 0;
		char wordFuncParam[255] = "";
		char wordFuncName[255] = "";
		char bufferWord[255] = "";
		int k = 0;
		int countL = 0;
		int type = 0;
		int pr = 0;
		for (int i = 0; i < in.size; i++)
		{
			symbol = in.text[i];

			if (symbol == '\n')
			{
				line++;
				//paste(line, '|');
				continue;
			}
			if (symbol != ' ' || (symbol == ' ' && in.text[i - 1] != '\'' && in.text[i + 1] != '\'' && flags.kavichka_flag))
			{
				bufferWord[k] = in.text[i];
				k++;
				continue;
			}
			else
			{
				bufferWord[k] = '\0';
				pr++;
				if (string(bufferWord) != "")
				{

					if (typeInt(bufferWord))
					{
						paste(line, LEX_INTEGER);
						flags.typedata_flags = true;
						type = 0;
					}
					else if (bufferWord[0] == '\'')
					{
						if (flags.kavichka_flag)
						{
							flags.kavichka_flag = false;
						}
						else
						{
							flags.kavichka_flag = true;
						}
					}
					else if (typeString(bufferWord))
					{
						paste(line, LEX_STRING);
						flags.typedata_flags = true;
						type++;
					}
					else if (typeFunction(bufferWord))
					{
						paste(line, LEX_FUNCTION);
						flags.function_flags = true;
					}
					else if (strDeclare(bufferWord))
					{
						paste(line, LEX_DECLARE);
					}
					else if (strReturn(bufferWord))
					{
						paste(line, LEX_RETURN);
					}
					else if (strMain(bufferWord))
					{
						strcpy(wordFuncName, bufferWord);
						paste(line, LEX_MAINFUNC);
					}
					else if (strPrint(bufferWord))
					{
						paste(line, LEX_PRINT);
					}
					else if (leftBrace(bufferWord))
					{
						paste(line, LEX_LEFTBRACE);
					}
					else if (rightBrace(bufferWord))
					{
						strcpy(wordFuncName, "");
						paste(line, LEX_RIGHTBRACE);
					}
					else if (leftThesis(bufferWord))
					{
						paste(line, LEX_LEFTHESIS);
						flags.thesis_flags = true;
					}
					else if (rightThesis(bufferWord))
					{
						paste(line, LEX_RIGHTHESIS);
						flags.thesis_flags = false;
						flags.static_func_flags = false;
						flags.function_flags = false;
						strcpy(wordFuncParam, "");
					}
					else if (semicolon(bufferWord))
					{
						paste(line, LEX_SEMICOLON);
					}
					else if (comma(bufferWord))
					{
						paste(line, LEX_COMMA);
					}
					else if (strPlus(bufferWord))
					{
						paste(line, LEX_PLUS);
					}
					else if (strMinus(bufferWord))
					{
						paste(line, LEX_MINUS);
					}
					else if (del(bufferWord))
					{
						paste(line, LEX_DIRSLASH);
					}
					else if (multiplic(bufferWord))
					{
						paste(line, LEX_MULTIPLICATION);
					}
					else if (equal(bufferWord))
					{
						paste(line, LEX_EQUAL);
					}
					else if (flags.kavichka_flag && literalString(bufferWord))
					{
						paste(line, LEX_LITERAL);
						char l[5];
						char L[5] = "L";
						IT::Entry buff;
						buff.idxfirstLE = pr;
						itoa(countL, l, 10);
						strcat(L, l);
						strcpy(buff.id, L);
						buff.iddatatype = IT::STR;
						buff.idtype = IT::L;
						buff.value.vstr->len = strlen(bufferWord) - 2;
						strcpy(buff.value.vstr->str, bufferWord);
						IT::Add(idtab, buff);
					}
					else if (!flags.kavichka_flag && literalInteger(bufferWord))
					{
						paste(line, LEX_LITERAL);
						char L[5] = "l";
						char l[5];
						IT::Entry buff;
						buff.idxfirstLE = pr;
						itoa(countL, l, 10);
						strcat(L, l);
						strcpy(buff.id, L);
						buff.iddatatype = IT::INT;
						buff.idtype = IT::L;
						buff.value.vint = atoi(bufferWord);
						IT::Add(idtab, buff);
					}
					else if (identif(bufferWord))
					{
						flags.ident_flags = true;
						paste(line, LEX_ID);
						if (flags.function_flags && !flags.thesis_flags && !substrFunc(bufferWord) && !strlenFunc(bufferWord))
						{
							strcpy(wordFuncParam, bufferWord);
							strcpy(wordFuncName, bufferWord);
						}
						if (substrFunc(bufferWord) || strlenFunc(bufferWord))
						{
							flags.static_func_flags = true;
							strcpy(wordFuncParam, bufferWord);
						}
					}
					else
					{
						throw ERROR_THROW(117);
					}
				}
			}
			if (flags.function_flags && !flags.static_func_flags && !flags.thesis_flags && flags.ident_flags)//function
			{
				IT::Entry buff;
				buff.idxfirstLE = pr;
				strcpy(buff.id, bufferWord);
				if (type == 0)
				{
					buff.iddatatype = IT::INT;
				}
				else {
					buff.iddatatype = IT::STR;
				}
				buff.idtype = IT::F;
				buff.value.vint = 0;
				buff.value.vstr->len = 0;
				strcpy(buff.value.vstr->str, "");
				IT::Add(idtab, buff);
				flags.ident_flags = false;
				flags.declare_flags = false;
			}
			if (flags.static_func_flags && !flags.thesis_flags)
			{
				int k = 0;
				for (int i = 0; i < idtab.size; i++)
				{
					if (strcmp(idtab.table[i].id, bufferWord) == 0)
					{
						k++;
					}
				}
				if (k == 0)
				{
					IT::Entry buff;
					buff.idxfirstLE = pr;
					strcpy(buff.id, bufferWord);
					buff.iddatatype = IT::STR;
					buff.idtype = IT::F;
					buff.value.vint = 0;
					buff.value.vstr->len = 0;
					strcpy(buff.value.vstr->str, "");
					IT::Add(idtab, buff);
				}
				flags.ident_flags = false;
			}

			if (flags.ident_flags && (flags.function_flags || flags.static_func_flags) && flags.thesis_flags && flags.typedata_flags)
			{
				IT::Entry buff;
				buff.idxfirstLE = pr;
				char w[255];
				strcpy(w, wordFuncName);
				strcat(w, bufferWord);
				strcpy(buff.id, w);

				if (type == 0)
				{
					buff.iddatatype = IT::INT;
				}
				else {
					buff.iddatatype = IT::STR;
				}
				buff.idtype = IT::P;
				buff.value.vint = 0;
				buff.value.vstr->len = 0;
				strcpy(buff.value.vstr->str, "");
				IT::Add(idtab, buff);
				flags.ident_flags = false;
				flags.typedata_flags = false;
			}

			if (flags.ident_flags && !flags.function_flags && !flags.static_func_flags && flags.typedata_flags)
			{
				IT::Entry buff;
				buff.idxfirstLE = pr;
				char w[255];
				strcpy(w, wordFuncName);
				strcat(w, bufferWord);
				strcpy(buff.id, w);

				if (type == 0)
				{
					buff.iddatatype = IT::INT;
				}
				else {
					buff.iddatatype = IT::STR;
				}
				buff.idtype = IT::V;
				buff.value.vint = 0;
				buff.value.vstr->len = 0;
				strcpy(buff.value.vstr->str, "");
				IT::Add(idtab, buff);
				flags.ident_flags = false;
				flags.typedata_flags = false;
			}
			flags.ident_flags = false;
			std::memset(bufferWord, '\0', strlen(bufferWord));
			k = 0;
		}
		std::ofstream file;
		file.open(parm.out);
		if (file.fail())
		{
			throw ERROR_THROW(112);
		}
		file << "\n";
		file << "\n\n";
		file << std::setw(1727) << "|Name" << std::setw(2) << '|';
		file << std::setw(10) << "|Type" << std::setw(2) << '|';
		file << std::setw(15) << "|ID type" << std::setw(2) << '|';
		file << std::setw(15) << "|Line" << std::setw(2) << '|';
		file << std::setw(15) << "|Value" << std::setw(2) << '|';
		file << "\n";
		for (int i = 0; i < idtab.size; i++)
		{
			file << std::setw(18) << idtab.table[i].id << std::setw(2);

			if (idtab.table[i].iddatatype == IT::INT)
				file << std::setw(15) << "integer" << std::setw(2);
			if (idtab.table[i].iddatatype == IT::STR)
				file << std::setw(15) << "string" << std::setw(2);

			if (idtab.table[i].idtype == IT::F)
				file << std::setw(15) << "func" << std::setw(2);
			else if (idtab.table[i].idtype == IT::P)
				file << std::setw(15) << "parm" << std::setw(2);
			else if (idtab.table[i].idtype == IT::L)
				file << std::setw(15) << "literal" << std::setw(2);
			else if (idtab.table[i].idtype == IT::V)
				file << std::setw(15) << "variable" << std::setw(2);
			else
				file << std::setw(30);

			file << std::setw(15) << idtab.table[i].idxfirstLE << std::setw(2);
			if (exprCheck(idtab.table[i].id) == false)
			{
				if (idtab.table[i].iddatatype == IT::INT)
					file << std::setw(15) << idtab.table[i].value.vint << std::setw(2) << std::setw(15) << " " << std::setw(2);
			}
			file << "\n\n";
		}
		file << "\n";
		file << '0' << lextab.table[0].sn + 1 << ' ';
		for (int i = 0; i < lextab.size; i++)
		{
			if (lextab.table[i].lexema[0] == '|')
			{
				file << '\n';
				if (i != (lextab.size - 1))
				{
					if (lextab.table[i].sn + 1 < 10)
						file << '0' << lextab.table[i].sn + 1 << ' ';
					else
						file << lextab.table[i].sn + 1 << ' ';
				}
				continue;
			}
			file << lextab.table[i].lexema;
			cout << lextab.table[i].lexema;


		}
		file.close();
		try
		{
			MFST_TRACE_START;
			MFST::Mfst mfst(lextab, GRB::getGreibach());
			mfst.start();
			mfst.savededucation();
			mfst.printrules();
		}
		catch (Error::ERROR e)
		{
			std::cout << "Îøèáêà " << e.id << ": " << e.message << std::endl;
			std::cout << "ñòðîêà: " << e.inext.col << " ïîçèöèÿ: " << e.inext.line;
		}
	}

	void paste(int line, char ch) {
		LT::Entry entry;
		std::memset(entry.lexema, '\0', sizeof(char));
		entry.lexema[0] = ch;
		entry.lexema[1] = '\0';
		entry.sn = line;
		if (ch != 'i')
		{
			entry.idxTI = LT_TI_NULLIDX;
		}
		else {
			entry.idxTI = idtab.size;
		}
		LT::Add(lextab, entry);
	}
}