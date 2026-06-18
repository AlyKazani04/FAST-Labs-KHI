INCLUDE Irvine32.inc
.data
num1 db 25
num2 dw 1200h
num3 dd ?
.code
main PROC
mov ax, num2 ; ax = ( ah = 12h, al = 00h )
mov al, num1 ; ah = 12h, al = 19h or 25(decimal)
movzx eax, ax ; eax = 0x1219h
mov num3, eax ; num3 = 0x1219h
call writehex
exit
main ENDP
END main