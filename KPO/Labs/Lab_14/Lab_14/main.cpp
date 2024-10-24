#include "stdafx.h"
#include <iostream>
#include <cwchar>
#include <time.h>

#include "Error.h"		//��������� ������
#include "Parm.h"		//��������� ����������
#include "Log.h"		//������ � ����������
#include "In.h"			//���� ��������� �����
#include "Out.h"


using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "russian");


	cout << "--------- ���� geterror ---------\n\n";
	try { throw ERROR_THROW(100); }
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << "\n\n";
	};


	cout << "--------- ���� geterrorin ---------\n\n";
	try { throw ERROR_THROW_IN(111, 2, 3); }
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << ", ������ " << e.inext.line << ", ������� " << e.inext.col << " \n\n";
	};


	cout << "--------- ���� getparm ---------\n\n";
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << "\n\n";


	}
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << "\n\n";
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
		cout << "����� ��������: " << in.size << endl;
		cout << "����� �����: " << in.lines << endl;
		cout << "���������: " << in.ignor << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << endl;
		if(e.id==111){
			cout << "C����� " << e.inext.line << " ������� " << e.inext.col << "\n\n";
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
		Out::WriteError(out,e);

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
		Log::WriteLine(log, (char*)"����", (char*)" ��� ������ \n", "");
		Log::WriteLine(log, (wchar_t*)L"����", (wchar_t*)L" ��� ������ \n", L"");
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

