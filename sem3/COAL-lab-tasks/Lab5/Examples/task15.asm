INCLUDE Irvine32.inc

.data
    arrayD DWORD 11111111h, 22222222h, 33333333h

.code
main PROC
    mov eax, 0
    mov esi, OFFSET arrayD ; ESI = address of first element
    mov eax, [esi] ; EAX = 11111111h
    call writehex
    call crlf
    add esi, 4 ; Move to next element
    mov eax, [esi] ; EAX = 22222222h
    call writehex
    call crlf
    exit
main ENDP
END main