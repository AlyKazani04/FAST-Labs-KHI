INCLUDE Irvine32.inc
.data
MAX EQU 100d
MIN EQU 10d
var1 dw MAX
var2 dw MIN
.code
main PROC
movzx eax, var1
add ax, var2
call writeint
exit
main ENDP
END main