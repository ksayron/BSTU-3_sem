.586P                          
.MODEL FLAT, STDCALL                  
includelib kernel32.lib              

ExitProcess PROTO :DWORD                
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD    

.STACK 4096                    

.CONST                          

.DATA        
    a dd 4  
    b dd 5
    str0 db "Ìמÿ געמנמאÿ ןנמדנאללא", 0 
    str1 db "ÐÅÇÓËÜÒÀÒ = < >", 0 


.CODE                          

main PROC                        
START :                          
    mov eax, a                      
    add eax, b                    
    add eax, 48                     
    
    mov str1+13, al                  
    
    invoke MessageBoxA, 0, offset str1, offset str0, 0

    push 0                      
    call ExitProcess                
main ENDP

end main