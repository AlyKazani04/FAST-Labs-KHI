INCLUDE Irvine32.inc

.data
    arrayB BYTE 20, 40, 60, 80

.code
main PROC
    mov eax, 0
    mov esi, 1
    mov al, arrayB[esi] ; AL = 40
    call writedec
    call crlf
    inc esi
    mov al, arrayB[esi] ; AL = 60
    call writedec
    call crlf
    mov esi, 3
    mov al, [arrayB + esi] ; AL = 80
    call writedec
    call crlf
    exit
main ENDP
END main