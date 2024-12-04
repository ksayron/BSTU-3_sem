#include "stdafx.h"
#include "iostream"
#include "Error.h"
#include "In.h"
#include "Log.h"
#include "Parm.h"
#include "Out.h"
#include "FST.h"
#include "Lexer.h"
#include "LT.h"
#include "MFST.h"
#include "GRB.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "RU");
	Log::LOG log = Log::INITLOG;
	Out::OUT out = Out::INITOUT;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		out = Out::getout(parm.out);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Out::WriteToFile(out, in);
		LT::LexTable lexTab = LT::Create(LT_MAXSIZE - 1);
		IT::IdTable idTab= IT::Create(TI_MAXSIZE-1);
		Lexer::Run(lexTab, idTab, in);
		MFST_TRACE_START
			MFST::Mfst mfst(lexTab, GRB::getGreibach());
		mfst.start();
		mfst.savededucation();
		mfst.printrules();
		LT::Delete(lexTab);
		IT::Delete(idTab);
		Log::Close(log);
		Out::CloseFile(out);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
		Out::WriteToError(out, e);
	}
	system("pause");
	return 0;
}