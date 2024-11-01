#include <iostream>
#include "Out.h"
#include "Log.h"
#include <fstream>
#include "Error.h"
#include <cstdarg>
#include <ctime>


using namespace Out;
using namespace std;
using namespace Parm;
using namespace In;


namespace Out {

	OUT getout(wchar_t outfile[])
	{
		OUT out;
		ofstream* file = new ofstream(outfile);
		if (!file->is_open())
		{
			delete file;
			ERROR_THROW(113);
		}
		wcscpy_s(out.outfile, outfile);
		out.stream = file;
		return out;
	}

	void Out::WriteToFile(OUT out, In::IN in)
	{
		*out.stream << in.text;
	}

	void WriteToError(OUT out, Error::ERROR error)
	{
		if (out.stream) {
			*out.stream << "Ошибка " << error.id << ": " << error.message; 
			if (error.inext.line != -1) { 
				*out.stream << ", строка " << error.inext.line << ", позиция " << error.inext.col << '\n';
			}
			else {
				*out.stream << '\n';
			}
		}
		else {
			cout << "Ошибка " << error.id << ": " << error.message << '\n';
			cout << "Строка " << error.inext.line << ", позиция " << error.inext.col << '\n';
		}

	}

	void CloseFile(OUT out)
	{
		out.stream->close();
		delete out.stream;
	}

}
