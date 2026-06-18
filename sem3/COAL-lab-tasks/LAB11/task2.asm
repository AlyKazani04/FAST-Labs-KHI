INCLUDE Irvine32.inc

.data
	str1 db "127&j~3#^&*#*#45^", 0
	foundhash db "Found # at: ", 0
	hashnotfound db "# not found", 0

.code
main proc

	mov edx, offset str1	; arg1
	mov ecx, lengthof str1	; arg2
	mov al, '#'			; arg3
	call scan_string

	exit
main endp

scan_string proc 
	mov esi, 0
L1:
	cmp byte ptr [edx + esi], al ; compare current char with target
	je found
	inc esi
	loop L1
	mov edx, offset hashnotfound
	call writestring
	jmp fin
found:
	mov edx, offset foundhash
	call writestring
	mov eax, esi
	call WriteDec
fin:
	call crlf
	ret
scan_string endp

end main
