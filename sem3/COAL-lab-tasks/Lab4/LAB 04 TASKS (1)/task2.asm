INCLUDE Irvine32.inc
.data
num1 SBYTE -50d
num2 BYTE 200
.code
main PROC
movzx eax, num2
movsx edx, num1
call dumpregs
exit
main ENDP
END main