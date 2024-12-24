.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD
SetConsoleTitleA PROTO : DWORD

getmin PROTO : DWORD, : DWORD

.STACK 4096

.CONST

.DATA

INT_ARRAY		DWORD		9, 6, 5, 8, 3, 4, 1, 8, 2, 10
consoletitle	DB			"console", 0

.CODE


getmin PROC parm1 : DWORD, parm2 : DWORD
START:
	mov ecx, parm2
	mov esi, parm1
	mov eax, [esi]

	loop_start:
		cmp eax, [esi]
		jle move_next
		mov eax, [esi]

		move_next:
		add esi, type parm1

	loop loop_start

getmin ENDP
main PROC

	INVOKE getmin, OFFSET INT_Array, LENGTHOF INT_ARRAY
	push offset consoletitle
	call SetConsoleTitleA
	push 0
	call ExitProcess
main ENDP
end main
