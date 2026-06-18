INCLUDE Irvine32.inc

.data
    arrayW WORD 1000h, 2000h, 3000h, 4000h

.code
main PROC
    mov eax, 0
    mov esi, 1
    mov ax, arrayW[esi * TYPE arrayW] ; AX = 2000h
    call writehex
    call crlf
    mov esi, 2
    mov bx, arrayW[esi * TYPE arrayW] ; BX = 3000h
    mov ax, bx
    call writehex
    call crlf
    mov esi, 3
    mov cx, arrayW[esi * TYPE arrayW] ; CX = 4000h
    mov ax, cx
    call writehex
    call crlf
    exit
main ENDP
END main