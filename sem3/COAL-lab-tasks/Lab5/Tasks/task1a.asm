INCLUDE Irvine32.inc

.code
main PROC
	mov eax, 0
	mov eax, 7fh
	add al, 1
	call dumpregs	
	exit
main ENDP
END main
