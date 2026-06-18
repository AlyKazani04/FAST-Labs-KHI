INCLUDE Irvine32.inc

.data
    byte1 BYTE 10,20,30
    array1 WORD 30 DUP(?),0,0
    array2 WORD 5 DUP(3 DUP(?))
    array3 DWORD 1,2,3,4
    digitStr BYTE "12345678",0

.code
main PROC
    mov eax, 0
    mov ax, LENGTHOF byte1 ;returns 3
    call writedec
    call crlf
    mov ax, LENGTHOF array1 ;returns 30+2
    call writedec
    call crlf
    mov ax, LENGTHOF array2 ;returns 5*3
    call writedec
    call crlf
    mov ax, LENGTHOF array3 ;returns 4
    call writedec
    call crlf
    mov ax, LENGTHOF digitStr ;returns 9
    call writedec
    call crlf
    exit
main ENDP
END main