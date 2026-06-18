INCLUDE Irvine32.inc

.data
	string db "ASSEMBLY", 0
	target db 'E'
	found db 0
	foundstr db "Character Found!", 0
	notfoundstr db "Character Not Found!", 0

.code
main proc
	
	mov ecx, lengthof string
	mov esi, offset string
L1:
	mov al, [esi]
	cmp al, target
	jne skip
	mov eax, 1
	mov found, al
	jmp exitloop
skip:
	inc esi
	loop L1

exitloop:

	mov al, found
	cmp al, 0
	je notfound

	mov edx, offset foundstr
	call writestring
	call crlf
	jmp done

notfound:
	mov edx, offset notfoundstr
	call writestring
	call crlf
done:
	exit
main endp
end main
