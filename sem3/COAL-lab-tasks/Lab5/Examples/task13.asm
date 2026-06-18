INCLUDE Irvine32.inc

.data
    arrayB BYTE 10h, 20h, 30h

.code
main PROC
    mov eax, 0
    mov esi, OFFSET arrayB ; ESI = address of first element
    mov al, [esi] ; AL = 10h
    call writehex
    call crlf
    inc esi ; Move to next element
    mov al, [esi] ; AL = 20h
    call writehex
    call crlf
    exit
main ENDP
END main