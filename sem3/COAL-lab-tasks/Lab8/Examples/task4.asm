INCLUDE Irvine32.inc

.data
	multp dd 2
	msg BYTE "Hello Fastian! The product of the three integers is: ", 0
	
.code
main PROC
	mov eax, 1
	mov ecx, 3
push_loop:
	push multp
	add multp, 2
	loop push_loop
	mov ecx, 3
multiply_loop:
	pop ebx
	mul ebx
	loop multiply_loop
	mov edx, OFFSET msg
	call writestring
	call writedec
	call crlf

	exit
main ENDP
END main
