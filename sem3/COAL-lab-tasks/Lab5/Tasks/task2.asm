INCLUDE Irvine32.inc

.data
	myByte BYTE 12h
	myWord WORD 1234h
	myDword DWORD 12345678h

.code
main PROC
	;a
	mov esi, OFFSET myByte
	mov eax, esi
	call writehex
	call crlf
	mov esi, OFFSET myWord
	mov eax, esi
	call writehex
	call crlf
	mov esi, OFFSET myDword
	mov eax, esi
	call writehex
	call crlf
	;b
	mov eax, 0
	mov ax, WORD PTR [esi + 2]
	call writehex
	call crlf
	;c
	mov bx, TYPE myByte
	movzx eax, bx
	call writedec
	call crlf
	mov bx, TYPE myWord
	movzx eax, bx
	call writedec
	call crlf
	mov bx, TYPE myDword
	movzx eax, bx
	call writedec
	exit
main ENDP
END main
