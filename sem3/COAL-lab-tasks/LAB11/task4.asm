INCLUDE Irvine32.inc

.data
	str1 db "string", 0
.code
main proc
	mov edx, offset str1
	call writestring
	call crlf

	mov edx, offset str1
	call str_reverse

	mov edx, offset str1
	call writestring
	call crlf

	exit
main endp

str_reverse proc
	invoke str_length, addr str1
	cmp eax, 0
	je done

	mov esi, edx
	mov edi, edx
	add edi, eax
	dec edi
L1:
	cmp esi, edi
	jae done
	mov al, [esi]
	mov ah, [edi]
	mov [esi], ah
	mov [edi], al

	inc esi
	dec edi
	jmp L1

done:
	ret
str_reverse endp

end main
