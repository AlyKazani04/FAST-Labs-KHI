INCLUDE Irvine32.inc

.data
	var1 dd 5
	var2 dd 6
	msg1 BYTE "The sum is calculated in AddTwo is: ", 0
	msg2 BYTE "Values printed inside AddTwo1: ", 0
	
.code
main PROC
	call AddTwo
	call crlf
	exit
main ENDP

AddTwo PROC USES ebx
	mov eax, var1
	mov ebx, var2
	add eax, ebx

	mov edx, OFFSET msg1
	call writestring
	call writeint
	call crlf

	call AddTwo1
	ret
AddTwo ENDP

AddTwo1 PROC USES ebx ecx edx
	mov ecx, var1
	mov edx, var2

	mov ebx, OFFSET msg2
	call writestring
	call crlf

	mov eax, ecx
	call writeint
	call crlf

	mov eax, edx
	call writeint
	call crlf
	ret
AddTwo1 ENDP

END main
