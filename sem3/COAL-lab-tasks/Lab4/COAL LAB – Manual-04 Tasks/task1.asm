INCLUDE Irvine32.inc

.data
    sub1 db 45
    sub2 db 35
    msg1 BYTE "45 + 35 = ", 0
    msg2 BYTE "45 - 35 = ", 0

.code
main PROC
    mov edx, OFFSET msg1
    call writestring
    mov eax, 0 ; clear eax register
    mov al, sub1
    add al, sub2
    call writedec
    call crlf
    mov edx, OFFSET msg2
    call writestring
    mov eax, 0 ; clear eax register
    mov al, sub1
    sub al, sub2
    call writedec
    exit
main ENDP
END main