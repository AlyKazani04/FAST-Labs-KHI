INCLUDE Irvine32.inc

.data
    arrayW WORD 1000h, 2000h, 3000h

.code
main PROC
    mov eax, 0
    mov esi, OFFSET arrayW
    mov ax, [esi] ; AX = 1000h
    call writehex
    call crlf
    mov bx, [esi+2] ; BX = 2000h
    mov ax, bx
    call writehex
    call crlf
    mov cx, [esi+4] ; CX = 3000h
    mov ax, cx
    call writehex
    call crlf
    exit
main ENDP
END main