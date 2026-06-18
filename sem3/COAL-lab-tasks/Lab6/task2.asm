INCLUDE Irvine32.inc

.code
main PROC
	mov ecx, 11
	mov eax, 5
L1:
	call writeint
	call crlf
	inc eax
	loop L1
	exit
main ENDP
END main
