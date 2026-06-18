INCLUDE Irvine32.inc

.data
    A dw 0FF10h
    B dw 0E10h
    msg1 BYTE "A= ", 0
    msg2 BYTE "B= ", 0

.code
main PROC
    mov edx, OFFSET msg1
    call writestring ; print msg1
    mov eax, 0
    mov ax, A
    call writehex ; print A pre-swap
    call crlf
    push eax ; save eax on stack, freeing eax, so i can print ebx
    mov edx, OFFSET msg2
    call writestring ; print msg2
    mov ebx, 0
    mov bx, B
    mov eax, ebx
    call writehex ; print B pre-swap
    call crlf
    pop eax ; restore eax
    xchg ax, bx ; swap values
    mov A, ax
    mov edx, OFFSET msg1
    call writestring ; print msg1
    mov eax, 0
    mov ax, A
    call writehex ; print A
    call crlf
    mov B, bx
    mov edx, OFFSET msg2
    call writestring ; print msg2
    mov eax, 0
    mov ax, B
    call writehex
    call crlf
    exit
main ENDP
END main