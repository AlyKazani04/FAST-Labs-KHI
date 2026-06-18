INCLUDE Irvine32.inc

.data
    var1 dw 10d
    var2 dw 20d
    msg1 BYTE "var1= ", 0
    msg2 BYTE "var2= ", 0

.code
main PROC
    mov edx, OFFSET msg1
    call writestring ; print msg1
    mov eax, 0
    mov ax, var1
    call writedec ; print var1 pre-swap
    call crlf
    push eax ; save eax on stack, freeing eax, so i can print ebx
    mov edx, OFFSET msg2
    call writestring ; print msg2
    mov ebx, 0
    mov bx, var2
    mov eax, ebx
    call writedec ; print var2 pre-swap
    call crlf
    pop eax ; restore eax
    xchg ax, bx ; swap values
    mov var1, ax
    mov edx, OFFSET msg1
    call writestring ; print msg1
    mov eax, 0
    mov ax, var1
    call writedec ; print var1
    call crlf
    mov var2, bx
    mov edx, OFFSET msg2
    call writestring ; print msg2
    mov eax, 0
    mov ax, var2
    call writedec
    call crlf
    exit
main ENDP
END main