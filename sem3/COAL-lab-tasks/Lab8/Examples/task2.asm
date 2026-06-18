INCLUDE Irvine32.inc

.data
	num1 dw 15
	num2 dw 25
	msg1 BYTE "Initial Numbers: ", 0
	msg2 BYTE "Sum after POP (a + b): ", 0
	msg3 BYTE "Final Result after PUSH & POP: ", 0
	space BYTE " ", 0

.code
main PROC
	call crlf
	mov edx, OFFSET msg1
	call writestring

	movzx eax, num1
	call writedec
	mov edx, OFFSET space
	call writestring
	movzx eax, num2
	call writedec
	call crlf

	mov ax, num1
	push ax
	mov ax, num2
	push ax

	pop bx
	pop ax
	add ax, bx

	call crlf
	mov edx, OFFSET msg2
	call writestring
	movzx eax, ax
	call writedec
	call crlf

	push ax
	pop bx

	call crlf
	mov edx, OFFSET msg3
	call writestring
	movzx eax, bx
	call writedec
	call crlf

	exit
main ENDP
END main
