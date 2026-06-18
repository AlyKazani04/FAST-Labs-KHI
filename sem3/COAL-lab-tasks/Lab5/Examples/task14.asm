INCLUDE Irvine32.inc

.data
    arrayW WORD 1000h, 2000h, 3000h

.code
main PROC
    mov eax, 0
    mov esi, OFFSET arrayW ; ESI = address of first element
    mov ax, [esi] ; AX = 1000h
    call writehex
    call crlf
    add esi, 2 ; Move to next element
    mov ax, [esi] ; AX = 2000h
    call writehex
    call crlf
    exit
main ENDP
END main