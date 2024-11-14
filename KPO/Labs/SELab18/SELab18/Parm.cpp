#include "Parm.h"
#include "Error.h"

using namespace Parm;

PARM Parm::getparm(int argc, _TCHAR* argv[])
{
    PARM parm;
    bool enterIN = false, enterOut = false, enterLog = false;

    for (int i = 1; i < argc; i++)
    {
        if (wcsncmp(argv[i], PARM_IN, wcslen(PARM_IN)) == 0)
        {
            if (wcslen(argv[i] + wcslen(PARM_IN)) >= PARM_MAX_SIZE)
            {
                ERROR_THROW(104);
            }
            wcscpy_s(parm.in, argv[i] + wcslen(PARM_IN));
            enterIN = true;
        }
        else if (wcsncmp(argv[i], PARM_OUT, wcslen(PARM_OUT)) == 0)
        {
            if (wcslen(argv[i] + wcslen(PARM_OUT)) >= PARM_MAX_SIZE)
            {
                ERROR_THROW(104);
            }
            wcscpy_s(parm.out, argv[i] + wcslen(PARM_OUT));
            enterOut = true;
        }
        else if (wcsncmp(argv[i], PARM_LOG, wcslen(PARM_LOG)) == 0)
        {
            if (wcslen(argv[i] + wcslen(PARM_LOG)) >= PARM_MAX_SIZE)
            {
                ERROR_THROW(104);
            }
            wcscpy_s(parm.log, argv[i] + wcslen(PARM_LOG));
            enterLog = true;
        }
    }

    if (!enterIN)
    {
        ERROR_THROW(100);
    }

    if (!enterOut)
    {
        wcscpy_s(parm.out, parm.in);
        short len = wcslen(parm.out);
        if (len + wcslen(PARM_OUT_DEFAULT_EXT) >= PARM_MAX_SIZE)
        {
            ERROR_THROW(104);
        }
        wcsncat_s(parm.out, PARM_OUT_DEFAULT_EXT, wcslen(PARM_OUT));
    }

    if (!enterLog)
    {
        wcscpy_s(parm.log, parm.in);
        short len = wcslen(parm.log);
        if (len + wcslen(PARM_LOG_DEFAULT_EXT) >= PARM_MAX_SIZE)
        {
            ERROR_THROW(104);
        }
        wcsncat_s(parm.log, PARM_LOG_DEFAULT_EXT, wcslen(PARM_LOG));
    }

    return parm;
}

