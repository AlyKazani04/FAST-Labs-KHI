INCLUDE Irvine32.inc

.data
	line1 db "Welcome", 0
	line2 db "You should not see this line", 0
	line3 db "Goodbye", 0

.code
main PROC
	mov edx, OFFSET line1
	call writestring
	call crlf
	jmp to

	mov edx, OFFSET line2
	call writestring
	call crlf
to:
	mov edx, OFFSET line3
	call writestring
	call crlf
	exit
main ENDP
END main
