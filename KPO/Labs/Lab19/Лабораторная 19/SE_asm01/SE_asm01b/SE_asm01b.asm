.586
.MODEL FLAT, STDCALL
includelib kernel32.lib
includelib msvcrt.lib
includelib "..\Debug\SE_asm01a.lib"
getmin PROTO : DWORD, : DWORD
getmax PROTO : DWORD, : DWORD

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD
SetConsoleTitleA PROTO : DWORD
GetStdHandle PROTO :DWORD
WriteConsoleA PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD

.STACK 4096

.CONST

.DATA

INT_ARRAY		DWORD		-9, -6, -5, -8, -3, -4, -1, -8, -2, -12
TitleCon		DB			"console",0
Text			DB			"getmin+getmax=", 0
output			DB			10 dup(0)
consolehandle	DD			0h
max				DWORD		?

.CODE			

int_to_char PROC pstr : dword, intfield : sdword
  mov edi, pstr                                                    
  mov esi, 0                                                      
  mov eax, intfield                                                 
  cdq                                                               
  mov ebx, 10                                                       
  idiv ebx                                                          
  test eax, 80000000h                                               
  jz plus                                                           
  neg eax                                                           
  neg edx                                                           
  mov cl, '-'                                                       
  mov[edi], cl                                                      
  inc edi                                                           
  plus :                                                            
  push dx                                                           
  inc esi                                                           
  test eax, eax                                                     
  jz fin                                                            
  cdq                                                               
  idiv ebx                                                          
  jmp plus                                                          
  fin :                                                             
  mov ecx, esi
  write :                                                          
  pop bx                                                           
  add bl, '0'                                                      
  mov[edi], bl                                                     
  inc edi                                                          
  loop write                                                       
  ret
int_to_char ENDP

main proc 

	push offset TitleCon
	call SetConsoleTitleA

	push -11
	call GetStdHandle
	mov consolehandle, eax

	push 0 
	push 0
	push sizeof Text
	push offset Text
	push consolehandle
	call WriteConsoleA

	INVOKE getmax, OFFSET INT_ARRAY, LENGTHOF INT_ARRAY
	mov max, eax
	INVOKE getmin, OFFSET INT_ARRAY, LENGTHOF INT_ARRAY
	add eax, max

	INVOKE int_to_char, OFFSET output, eax
	push 0
	push 0
	push sizeof output
	push offset output
	push consolehandle
	call WriteConsoleA
	push -1
	call ExitProcess

main ENDP

end main
