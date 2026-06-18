INCLUDE Irvine32.inc
.data
num1 dw 1234h
num2 dw 5678h
.code
main PROC
movzx eax, num1 ; ax = 1234h
movzx edx, num2 ; dx = 5678h
xchg ax, dx ; swap
mov num1, ax ; num1 = ax
movzx eax, num1
call writehex
call crlf
mov num2, dx ; num2 = dx
movzx eax, num2
call writehex
exit
main ENDP
END main