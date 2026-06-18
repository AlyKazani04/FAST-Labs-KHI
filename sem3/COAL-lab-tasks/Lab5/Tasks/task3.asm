INCLUDE Irvine32.inc

.data
	arr1 BYTE 10, 20, 30, 40
	arr2 WORD 100h, 200h, 300h
	arr3 DWORD 5 DUP(0)

.code
main PROC
	;a
	mov eax, LENGTHOF arr1
	call writedec
	call crlf
	mov eax, LENGTHOF arr2
	call writedec
	call crlf
	mov eax, LENGTHOF arr3
	call writedec
	call crlf
	;b and c 
	mov ax, SIZEOF arr1
	call writedec
	call crlf
	mov bx, SIZEOF arr2
	movzx eax, bx
	call writedec
	call crlf
	mov cx, SIZEOF arr3
	movzx eax, cx
	call writedec
	call crlf
	exit
main ENDP
END main
