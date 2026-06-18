INCLUDE Irvine32.inc

.data
    intArray WORD 32 DUP(0)

.code
main PROC
    mov eax, 0
    mov eax, SIZEOF intArray ; returns 64 = 32 * 2
    call writedec
    call crlf
    exit
main ENDP
END main