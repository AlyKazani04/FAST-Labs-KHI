INCLUDE Irvine32.inc
.data
prompt BYTE "Enter a number: ",0
resultMsg BYTE "Factorial: ",0
num DWORD ?
fact DWORD 1

.code
main PROC
mov edx, OFFSET prompt
call WriteString
call ReadInt
mov num, eax
mov ecx, eax
mov eax, 1

fact_loop:
cmp ecx, 0
je done
mul ecx
loop fact_loop

done:
mov edx, OFFSET resultMsg
call WriteString
call WriteDec
call Crlf
exit
main ENDP
END main