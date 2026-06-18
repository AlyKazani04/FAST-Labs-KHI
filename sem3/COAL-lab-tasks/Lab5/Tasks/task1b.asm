INCLUDE Irvine32.inc

.code
main PROC
	mov eax, 0
	mov eax, 7fh
	sub al, 80h
	call dumpregs	
	exit
main ENDP
END main
