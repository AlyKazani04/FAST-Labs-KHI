INCLUDE Irvine32.inc

.data
    daytemp db 30d
    nighttemp db 18d
    msg1 BYTE "Difference: ", 0
    msg2 BYTE "New Night Temp: ", 0

.code
main PROC
    mov edx, OFFSET msg1
    call writestring
    movzx eax, daytemp
    sub al, nighttemp
    call writedec
    call crlf
    mov edx, OFFSET msg2
    call writestring
    add nighttemp, 2
    movzx eax, nighttemp
    call writedec
    exit
main ENDP
END main