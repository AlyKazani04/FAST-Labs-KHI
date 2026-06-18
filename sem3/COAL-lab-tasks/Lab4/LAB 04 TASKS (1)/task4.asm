INCLUDE Irvine32.inc
.data
Xval dd 25d
Yval dd 15d
Zval dd 40d
Rval dd ?
.code
main PROC
mov eax, Xval ; 25
add eax, Yval ; 25 + 15 = 40
sub eax, Zval ; 40 - 40 = 0
neg eax ; -0 = 0
mov Rval, eax
call writeint
exit
main ENDP
END main