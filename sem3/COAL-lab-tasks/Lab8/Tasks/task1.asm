INCLUDE Irvine32.inc
.data
nums DWORD 5 DUP(?)
posCount DWORD 0
negCount DWORD 0
zeroCount DWORD 0
prompt BYTE "Enter number ",0
posMsg BYTE "Positive numbers: ",0
negMsg BYTE "Negative numbers: ",0
zeroMsg BYTE "Zeros: ",0

.code
main PROC
mov ecx, 5 ; loop counter
mov esi, OFFSET nums ; point to nums array
mov ebx, 1 ; number counter

input_loop:
mov edx, OFFSET prompt
call WriteString
mov eax, ebx
call WriteDec
call Crlf

call ReadInt
mov [esi], eax
add esi, 4
inc ebx
loop input_loop

; reset counters
mov ecx, 5
mov esi, OFFSET nums

count_loop:
mov eax, [esi]
cmp eax, 0
jg is_positive
jl is_negative
inc zeroCount
jmp next_num

is_positive:
inc posCount
jmp next_num

is_negative:
inc negCount

next_num:
add esi, 4
loop count_loop

; display results
mov edx, OFFSET posMsg
call WriteString
mov eax, posCount
call WriteDec
call Crlf

mov edx, OFFSET negMsg
call WriteString
mov eax, negCount
call WriteDec
call Crlf

mov edx, OFFSET zeroMsg
call WriteString
mov eax, zeroCount
call WriteDec
call Crlf

exit
main ENDP
END main