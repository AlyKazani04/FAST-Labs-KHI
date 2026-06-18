INCLUDE Irvine32.inc

.data
	string db "PROGRAMMING", 0
	target db 'G'
	count db 0
	msgpart1 db "Character ", 0
	msgpart2 db " occurs ", 0
	msgpart3 db " times", 0

.code
main proc
	
	mov ecx, lengthof string
	mov esi, offset string
L1:
	mov al, [esi]
	cmp al, target
	jne skip
	mov al, count
	inc al
	mov count, al
skip:
	inc esi
	loop L1

	mov edx, offset msgpart1
	call writestring

	mov al, target
	call writechar

	mov edx, offset msgpart2
	call writestring

	movzx eax, count
	call writedec

	mov edx, offset msgpart3
	call writestring
	call crlf

	exit
main endp
end main
