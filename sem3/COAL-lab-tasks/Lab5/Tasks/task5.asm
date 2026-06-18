INCLUDE Irvine32.inc

.data
	arrayD DWORD 1000h, 2000h, 3000h, 4000h

.code
main PROC
	;a
	mov esi, 1
	mov eax, arrayD[esi * TYPE arrayD]
	call writehex
	call crlf
	;b
	mov esi, (LENGTHOF arrayD) - 1
	mov eax, arrayD[esi * TYPE arrayD]
	call writehex
	exit
main ENDP
END main
