INCLUDE Irvine32.inc

.data
    byteVal BYTE 10h

.code
main PROC
    mov eax, 0
    mov esi, OFFSET byteVal ; ESI = address of byteVal
    mov al, [esi] ; AL = 10h
    call writedec
    call crlf
    exit
main ENDP
END main