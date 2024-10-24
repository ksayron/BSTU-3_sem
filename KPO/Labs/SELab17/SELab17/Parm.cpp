#include "stdafx.h"
#include "Parm.h"
#include "Error.h"
namespace Parm
{
	PARM getparm(int argc, _TCHAR* argv[])
	{
		PARM parm;

		bool hasIn = false;
		bool hasOut = false;
		bool hasLog = false;

		for (int i = 0; i < argc; i++)
		{
			if (wcsstr(argv[i], PARM_IN))
				hasIn = true;

			if (wcsstr(argv[i], PARM_OUT))
				hasOut = true;

			if (wcsstr(argv[i], PARM_LOG))
				hasLog = true;
		}

		if (!hasIn)
			throw ERROR_THROW(100)

			for (int i = 0; i < argc; i++)
			{
				if (wcslen(argv[i]) > PARM_MAX_SIZE)
					throw ERROR_THROW(104);

				if (wcsstr(argv[i], PARM_IN))
					wcscpy_s(parm.in, wcsstr(argv[i], L":") + 1);

				if (wcsstr(argv[i], PARM_OUT))
					wcscpy_s(parm.out, wcsstr(argv[i], L":") + 1);

				if (wcsstr(argv[i], PARM_LOG))
					wcscpy_s(parm.log, wcsstr(argv[i], L":") + 1);
			}

		if (!hasOut)
		{
			wcscpy_s(parm.out, parm.in);
			wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
		}

		if (!hasLog)
		{
			wcscpy_s(parm.log, parm.in);
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
		}

		return parm;
	}
};