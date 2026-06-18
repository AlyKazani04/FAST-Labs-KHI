INCLUDE Irvine32.inc

.data
    msg1 db "Enter first number: ", 0
    msg2 db "Enter second number: ", 0
    resmsg db "The GCD is: ", 0
    espMessage db "ESP: ", 0
    num1 dd ?
    num2 dd ?
    gcdResult dd ?

.code
main proc
    call TakeInput
    call GCD
    
    call Display
    exit
main endp

TakeInput PROC
    mov edx, OFFSET msg1
    call WriteString
    call ReadInt
    mov num1, eax

    mov edx, OFFSET msg2
    call WriteString
    call ReadInt
    mov num2, eax

    ret
TakeInput ENDP

GCD PROC
    call DisplayESP
    
    mov eax, num1
    mov ebx, num2
GCD_LOOP:
    cmp ebx, 0
    je GCD_DONE
    
    mov edx, 0
    div ebx          
    mov eax, ebx     
    mov ebx, edx
    jmp GCD_LOOP

GCD_DONE:
    mov gcdResult, eax
    call DisplayESP
    
    ret
GCD ENDP

Display PROC
    mov edx, OFFSET resmsg
    call WriteString
    
    mov eax, gcdResult
    call WriteInt
    call Crlf

    ret
Display ENDP

DisplayESP PROC
    sub esp, 4        
    mov eax, esp      
    mov edx, OFFSET espMessage
    call WriteString
    call Writehex
    add esp, 4        
    call Crlf
    
    ret
DisplayESP ENDP

END main
