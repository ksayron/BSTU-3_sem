﻿#include "stdafx.h"
#include <iostream>
#include <cwchar>
#include <time.h>

#include "Error.h"		//обработка ошибок
#include "Parm.h"		//обработка параметров
#include "Log.h"		//работа с протоколом
#include "In.h"			//ввод исходного файла
#include "Out.h"


using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "russian");


	cout << "--------- тест geterror ---------\n\n";
	try { throw ERROR_THROW(100); }
	catch (Error::ERROR e)
	{
		cout << "Ошибка " << e.id << ": " << e.message << "\n\n";
	};


	cout << "--------- тест geterrorin ---------\n\n";
	try { throw ERROR_THROW_IN(111, 2, 3); }
	catch (Error::ERROR e)
	{
		cout << "Ошибка " << e.id << ": " << e.message << ", строка " << e.inext.line << ", позиция " << e.inext.col << " \n\n";
	};


	cout << "--------- тест getparm ---------\n\n";
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << "\n\n";


	}
	catch (Error::ERROR e)
	{
		cout << "Ошибка " << e.id << ": " << e.message << "\n\n";
	}


	cout << "--------- getin ----------\n\n";
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		if ((wcscmp(parm.in, parm.log) == 0) or (wcscmp(parm.out, parm.log) == 0) or (wcscmp(parm.in, parm.out) == 0)) {
			throw ERROR_THROW(101);
		}
		cout << in.text << endl;
		cout << "Всего символов: " << in.size << endl;
		cout << "Всего строк: " << in.lines << endl;
		cout << "Пропущено: " << in.ignor << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "Ошибка " << e.id << ": " << e.message << endl;
		if (e.id == 111) {
			cout << "Cтрока " << e.inext.line << " позиция " << e.inext.col << "\n\n";
		}
	}

	Out::OUT out = Out::INITOUT;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		out = Out::getOut(parm.out);
		In::IN in = In::getin(parm.in);
		Out::WriteOut(out, in);
		Out::Close(out);

	}
	catch (Error::ERROR e)
	{
		Out::WriteError(out, e);

	}

	Log::LOG log = Log::INITLOG;

	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		if ((wcscmp(parm.in, parm.log) == 0) or (wcscmp(parm.out, parm.log) == 0) or (wcscmp(parm.in, parm.out) == 0)) {
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
			throw ERROR_THROW(101);
		}
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"Тест", (char*)" без ошибок \n", "");
		Log::WriteLine(log, (wchar_t*)L"Тест", (wchar_t*)L" без ошибок \n", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	};
	system("pause");

	return 0;
}

