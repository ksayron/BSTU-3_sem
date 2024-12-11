.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA

OK			EQU	0
TEXT_MESSAGE		DB "SE_Asm04", 0
HW			DD ?

FILEWCHAR_T DD 1083
FILEINT DD 102
strINT DB "char:     ", 0
strWCHAR_T DB "wchar_t:     ", 0

.CODE

main PROC

mov eax,FILEWCHAR_T
mov strWCHAR_T+9, al
invoke MessageBoxA, 0, offset strWCHAR_T, ADDR TEXT_MESSAGE, OK


mov eax,FILEINT
mov strINT+5, al
invoke MessageBoxA, 0, offset strINT, offset TEXT_MESSAGE, OK


push - 1
call ExitProcess
main ENDP
end main
