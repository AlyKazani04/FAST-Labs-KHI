INCLUDE Irvine32.inc

.data
	arrB BYTE 11h, 22h, 33h
	arrW WORD 4444h, 5555h, 6666h

.code
main PROC
	;a
	mov esi, OFFSET arrB
	mov ecx, LENGTHOF arrB
L1:
	movzx eax, BYTE PTR [esi]
	call writehex
	call crlf
	inc esi
	loop L1
	;b
	mov esi, OFFSET arrW
	mov ecx, LENGTHOF arrW ; ecx = 3
L2:
	movzx eax, WORD PTR [esi]
	call writehex
	call crlf
	add esi, 2
	loop L2
	exit
main ENDP
END main
