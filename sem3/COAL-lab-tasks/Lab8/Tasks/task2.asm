INCLUDE Irvine32.inc
.data
nums DWORD 5 DUP(?)
prompt BYTE "Enter 5 numbers:",0
revMsg BYTE "Reversed order: ",0

.code
main PROC
mov ecx, 5
mov esi, OFFSET nums

mov edx, OFFSET prompt
call WriteString
call Crlf

input_loop:
call ReadInt
mov [esi], eax
add esi, 4
loop input_loop

mov edx, OFFSET revMsg
call WriteString

mov ecx, 5
mov esi, OFFSET nums
add esi, 4 * (5 - 1) ; move to the last element

print_reverse:
mov eax, [esi] ; load number
call WriteDec
mov al, ' '
call WriteChar
sub esi, 4 ; move backward
loop print_reverse

call Crlf
exit
main ENDP
END main