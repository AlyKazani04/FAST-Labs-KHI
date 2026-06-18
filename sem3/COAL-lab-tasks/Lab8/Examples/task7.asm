INCLUDE Irvine32.inc

.data
	var1 dd 5
	var2 dd 6
	msg BYTE "The sum of the two numbers is: ", 0
	
.code
main PROC
	call addtwo
	mov edx, OFFSET msg
	call writestring
	call writedec
	call crlf
	exit
main ENDP

addtwo PROC
	mov eax, var1
	add eax, var2
	ret
addtwo ENDP

END main
