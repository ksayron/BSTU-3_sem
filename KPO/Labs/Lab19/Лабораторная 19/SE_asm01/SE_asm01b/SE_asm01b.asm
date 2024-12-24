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
  mov edi, pstr                                                     ; копирует из pstr в edi
  mov esi, 0                                                        ; количество символов в результате 
  mov eax, intfield                                                 ; число -> в eax
  cdq                                                               ; знак числа распространяется с eax на edx
  mov ebx, 10                                                       ; основание системы счисления (10) -> ebx
  idiv ebx                                                          ; eax = eax/ebx, остаток в edx (деление целых со знаком)
  test eax, 80000000h                                               ; тестируем знаковый бит
  jz plus                                                           ; если положительное число - на plus
  neg eax                                                           ; иначе мнеяем знак eax
  neg edx                                                           ; edx = -edx
  mov cl, '-'                                                       ; первый символ результата '-'
  mov[edi], cl                                                      ; первый символ результата '-'
  inc edi                                                           ; ++edi
  plus :                                                            ; цикл разложения по степеням 10
  push dx                                                           ; остаток -> стек
  inc esi                                                           ; ++esi
  test eax, eax                                                     ; eax == ?
  jz fin                                                            ; если да, то на fin
  cdq                                                               ; знак распространяется с eax на edx 
  idiv ebx                                                          ; eax = eax/ebx, остаток в edx
  jmp plus                                                          ; безусловный переход на plus
  fin :                                                             ; в ecx кол-во не 0-вых остатков = кол-ву символов результата
  mov ecx, esi
  write :                                                           ; цикл записи результата
  pop bx                                                            ; остаток из стека -> bx
  add bl, '0'                                                       ; сформировали символ в bl
  mov[edi], bl                                                      ; bl -> в результат
  inc edi                                                           ; edi++
  loop write                                                        ; если (--ecx)>0 переход на write
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
