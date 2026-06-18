INCLUDE Irvine32.inc

.data
    myDouble DWORD 12345678h

.code
main PROC
    movzx eax, WORD PTR myDouble ; 5678
    call writehex
    call crlf
    mov ax, WORD PTR [myDouble + 2] ; 1234
    call writehex
    call crlf
    mov bl, BYTE PTR myDouble ; 78
    movzx eax, bl
    call writehex
    call crlf
    exit
main ENDP
END main