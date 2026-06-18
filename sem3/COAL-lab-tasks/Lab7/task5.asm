INCLUDE Irvine32.inc

.code
main PROC

	mov eax, 10 ;	eax = 10
L1:
	call writeint
	call crlf
	sub eax, 3

	cmp eax, 0
	jge L1

	call writeint
	call crlf

	exit
main ENDP
END main
