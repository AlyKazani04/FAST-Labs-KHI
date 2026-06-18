INCLUDE Irvine32.inc

.data
    inmsg1 db "First number: ", 0
    inmsg2 db "Second number: ", 0
    resmsg db "Product: ", 0
    val1 dd ?
    val2 dd ?

.code
main PROC
    mov edx, offset inmsg1
    call writestring
    call readint
    mov val1, eax

    mov edx, offset inmsg2
    call writestring
    call readint
    mov val2, eax
    call crlf

    mov eax, val1
    mov ebx, val2
    mov ecx, 0
L1:
    test ebx, 1 ; check if odd
    jz skip
    add ecx, eax
skip:
    shl eax, 1
    shr ebx, 1
    jnz L1

    mov edx, offset resmsg
    call writestring
    mov eax, ecx
    call writedec
    call crlf

    exit
main ENDP
END main
