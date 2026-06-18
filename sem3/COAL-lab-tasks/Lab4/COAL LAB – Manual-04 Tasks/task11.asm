INCLUDE Irvine32.inc

.data
    val1 BYTE 10h
    val2 WORD 8000h
    val3 DWORD 0FFFFh
    val4 WORD 7FFFh
    msg1 BYTE "After incrementing val2: ", 0
    msg2 BYTE "After subtracting val3 from EAX: ", 0
    msg3 BYTE "After subtracting val4 from val2: ", 0
    msg4 BYTE "Value of BL after moving val1: ", 0

.code
main PROC
    ; task 1
    inc val2
    mov edx, OFFSET msg1
    call writestring
    movzx eax, val2
    call writehex
    call crlf
    ; task 2
    sub eax, val3
    mov edx, OFFSET msg2
    call writestring
    call writehex
    call crlf
    ; task 3
    movzx eax, val2
    sub ax, val4
    mov edx, OFFSET msg3
    call writestring
    call writehex
    call crlf
    ; task 4
    mov bl, val1
    mov edx, OFFSET msg4
    call writestring
    movzx eax, bl
    call writehex
    exit
main ENDP
END main