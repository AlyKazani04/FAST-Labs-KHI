INCLUDE Irvine32.inc

.data
COUNT dw 10
LIMIT EQU 10
Result dw ?
.code
main PROC
mov ax, COUNT
add ax, LIMIT
INC ax
mov Result, ax
movzx eax, Result
call writedec
exit
main ENDP
END main