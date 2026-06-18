INCLUDE Irvine32.inc
.data
x db 12h
y db 14h

z db 5h
w db 10h
FinalResult byte ?
.code
main PROC
movzx eax, x
add al, y
mov dl, z
add dl, w
sub al, dl
mov FinalResult, al
call writehex
exit
main ENDP
END main