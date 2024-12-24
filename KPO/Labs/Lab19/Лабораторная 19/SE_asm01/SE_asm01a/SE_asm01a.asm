.586P
.MODEL FLAT, STDCALL

getmin PROTO : DWORD, : DWORD
getmax PROTO : DWORD, : DWORD

.STACK 4096

.CONST

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
	ret

getmin ENDP

getmax PROC parm1 : DWORD, parm2 : DWORD
START:
	mov ecx, parm2
	mov esi, parm1
	mov eax, [esi]

	loop_start:
		cmp eax, [esi]
		jge move_next
		mov eax, [esi]

		move_next:
		add esi, type parm1

	loop loop_start
	ret
getmax ENDP
end
