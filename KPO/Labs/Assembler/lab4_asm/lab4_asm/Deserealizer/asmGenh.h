#pragma once
#include <string>
#define ASMHEADER \
\
<< ".586P" << endl \
<< ".MODEL FLAT, STDCALL" << endl \
<< "includelib kernel32.lib\n" << endl \
<< "ExitProcess PROTO : DWORD" << endl \
<< "MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD\n" << endl \
<< ".STACK 4096\n" << endl \
<< ".CONST\n" << endl \
<< ".DATA\n" << endl \
<< "OK			EQU	0" << endl \
<< "TEXT_MESSAGE		DB \"SE_Asm04\", 0" << endl \
<< "HW			DD ?\n" << endl \


class AsmGen
{
public:
	void CreateFile(wchar_t str, char chr);

private:
	const char* ASMFILE = "../lab4_asm/asmFile.asm";
};
