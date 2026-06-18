INCLUDE Irvine32.inc

.data
	char db '*'
	temp dd ?
	stars dd 1
	rows dd 5
.code
main PROC
	mov ecx, rows
	mov al, char
L1:
	mov temp, ecx
	mov ecx, stars
L2:
	call writechar
	loop L2
	call crlf
	inc stars
	mov ecx, temp
	loop L1
	exit
main ENDP
END main
