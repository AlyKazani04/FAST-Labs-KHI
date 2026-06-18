INCLUDE Irvine32.inc

.data
	msg1 BYTE "Original Flags saved on stack: ", 0
	msg2 BYTE "Flags restored from stack: ", 0
	
.code
main PROC
	mov eax, 5
	sub eax, 5
	pushfd
	mov edx, OFFSET msg1
	call writestring
	call crlf
	mov eax, 10
	add eax, 1
	popfd
	mov edx, OFFSET msg2
	call writestring
	call crlf
	call dumpregs

	exit
main ENDP
END main
