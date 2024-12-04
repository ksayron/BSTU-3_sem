#include "stdafx.h"
#include "Log.h"
#include <iostream>
#include <fstream>
#include "Error.h"
#include <cstdarg>
#include <ctime>

using namespace Log;
using namespace std;
using namespace Parm;
using namespace In;

LOG Log::getlog(wchar_t logfile[])
{
    LOG log;
    ofstream* file = new ofstream(logfile, std::ios::trunc);
    if (!file->is_open())
    {
        delete file;
        ERROR_THROW(112);
    }
    wcscpy_s(log.logfile, logfile);
    log.stream = file;
    return log;
}

void Log::WriteLine(LOG log, char* c, ...)
{
    char** p = &c;
    int j = 0;
    while (p[j] != "") {
        *log.stream << p[j];
        j++;
    }
}


void Log::WriteLine(LOG log, wchar_t* c, ...)
{
    wchar_t** p = &c;
    char buf[50];
    int j = 0;
    while (p[j] != L"") {
        wcstombs(buf, p[j++], 50);
        *log.stream << buf;
    }
}

void Log::WriteLog(LOG log)
{
    time_t rantime;
    struct tm timeinfo;
    char buffer[80];
    time(&rantime);
    localtime_s(&timeinfo, &rantime);

    strftime(buffer, sizeof(buffer), "%d.%m.%Y %I:%M:%S", &timeinfo);
    (*log.stream) << "---Протокол---" << buffer << " ---" << endl;
}

void Log::WriteParm(LOG log, PARM parm)
{
    char buf[80];
    wcstombs(buf, parm.in, sizeof(buf));
    (*log.stream) << buf << endl;
    wcstombs(buf, parm.out, sizeof(buf));
    (*log.stream) << buf << endl;
    wcstombs(buf, parm.log, sizeof(buf));
    (*log.stream) << buf << endl;
}

void Log::WriteIn(LOG log, IN in)
{
    (*log.stream) << "Количество символов: " << in.size << endl
        << "Пропущено: " << in.ignor << endl
        << "Количество строк: " << in.lines << endl
        << "Количество удаленных пробелов: " << in.countSpaces << endl;
}

void Log::WriteError(LOG log, Error::ERROR er)
{
    if (log.stream) {
        *log.stream << "Ошибка " << er.id << ": " << er.message;
        if (er.inext.line != -1) {
            *log.stream << ", строка " << er.inext.line << ", позиция " << er.inext.col << '\n';
        }
        else {
            *log.stream << '\n';
        }
    }
    else {
        cout << "Ошибка " << er.id << ": " << er.message << '\n';
        cout << "Строка " << er.inext.line << ", позиция " << er.inext.col << '\n';
    }

}

void Log::WriteLexTable(LOG log, LT::LexTable& lextable)
{
    int currentLine = 1;
    *log.stream << "\n\nТаблица лексем:\n";
    *log.stream << setw(2) << setfill('0') << currentLine << " ";
    for (int i = 0; i < lextable.size; i++) {
        if (lextable.table[i].sn != currentLine) {
            currentLine++;
            *log.stream << "\n";
            *log.stream << setw(2) << setfill('0') << currentLine << " ";
            *log.stream << LT::GetEntry(lextable, i).lexema;
        }
        else {
            *log.stream << LT::GetEntry(lextable, i).lexema;
        }
    }
}

void Log::WriteIdTable(LOG log, IT::IdTable& idtable)
{
    int currentLine = 1;
    *log.stream << "\n\nТаблица идентификаторов:\n";
    for (int i = 0; i < idtable.size; i++) {
        IT::Entry ent = IT::GetEntry(idtable, i);
        *log.stream << ent.id << ", ";
        if (ent.iddatatype == 1)
        {
            *log.stream << "INT";
        }
        else {
            *log.stream << "STR";
        }

        *log.stream << ", ";

        if (ent.idtype == 1)
        {
            *log.stream << "V";
        }
        else if (ent.idtype == 2) {
            *log.stream << "F";
        }
        else
        {
            *log.stream << "P";
        }

        *log.stream << ", " << ent.idxfirstLE << ", ";

        if (ent.iddatatype == IT::INT)
        {
            *log.stream << ent.value.vint;
        }
        else {
            for (int j = 0; j < ent.value.vstr->len; j++)
            {
                *log.stream << ent.value.vstr->str[j];
            }
        }
        *log.stream << endl;
    }
}

void Log::Close(LOG log)
{
    if (log.stream->is_open())
    {
        log.stream->close();
        delete log.stream;
    }
}

