INCLUDE Irvine32.inc

.data
	str1 db "127&j~3#^&*#*#45^", 0
	foundhash db "Found # at: ", 0
	hashnotfound db "# not found", 0

.code
main proc
	call scan_string
	exit
main endp

scan_string proc 
	mov ecx, lengthof str1
	mov esi, 0
L1:
	mov al, str1[esi]
	cmp al, '#'
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
	ret
scan_string endp

end main
