INCLUDE Irvine32.inc

.data
	string db "PROGRAMMING", 0
	stringlength db lengthof string
	temp db ?
	msg db "Reversed String: ", 0
	
.code
main proc
	movzx ecx, stringlength
	dec ecx						; stringlength - 1

	mov edx, 0
	mov eax, ecx
	mov ebx, 2
	div ebx
	mov ecx, eax
	
	mov esi, 0
	movzx edi, stringlength		; edi = 12, string length = 11, edi should be 10, bcuz of zero-indexing
	sub edi, 2
L1:
	mov al, string[esi]
	mov temp, al			; temp = string[i];

	mov al, string[edi]
	mov string[esi], al		; string[i] = string[length - i - 1];

	mov al, temp
	mov string[edi], al		; string[length - i - 1] = temp;

	inc esi
	dec edi
	loop L1

	mov edx, offset msg
	call writestring

	mov edx, offset string
	call writestring

	call crlf

	exit
main endp
end main
