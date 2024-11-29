#include "stdafx.h"
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	Log::LOG log = Log::INITLOG;
	Out::OUT out = Out::INIOUT;
	Parm::PARM parm = Parm::getparm(argc, argv);
	log = Log::getlog(parm.log);
	try
	{

		In::IN in = In::getin(parm.in);
		Lexer::LexAnaliz(parm, in);
	}
	catch (Error::ERROR e)
	{
		WriteError(log, e);
	};
	system("pause");
	return 0;
}