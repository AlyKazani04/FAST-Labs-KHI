INCLUDE Irvine32.inc
.data
nums DWORD 5 DUP(?)
prompt BYTE "Enter numbers:",0
largestMsg BYTE "Largest number: ",0
smallestMsg BYTE "Smallest number: ",0
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
mov esi, OFFSET nums
mov eax, [esi] ; eax = first number
mov ebx, eax ; ebx = largest
mov edx, eax ; edx = smallest
mov ecx, 4
add esi, 4
compare_loop:
mov eax, [esi]
cmp eax, ebx
jg update_largest
cmp eax, edx
jl update_smallest
jmp next_num
update_largest:
mov ebx, eax
jmp next_num
update_smallest:
mov edx, eax
push edx
next_num:
add esi, 4
loop compare_loop

mov edx, OFFSET largestMsg
call WriteString
mov eax, ebx
call WriteDec
call Crlf
mov edx, OFFSET smallestMsg
call WriteString
pop eax
call WriteDec
call Crlf
exit
main ENDP
END main