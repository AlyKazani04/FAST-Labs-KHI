INCLUDE Irvine32.inc

.data
	target db "AAEBDCFBBC",0
	freqTable dd 256 DUP(0)
.code
main proc
	get_frequencies proto, ptrstring:ptr byte, ptrTable:ptr dword

	invoke get_frequencies, addr target, addr freqTable

	mov esi, offset freqTable
	mov ecx,lengthof freqTable
	call printarr

	exit
main endp

get_frequencies proc,
	ptrstring:ptr byte,
	ptrTable:ptr dword

	mov esi, ptrstring
	mov edi, ptrTable
L1:
	movzx eax, byte ptr [esi]
	cmp al, 0
	je Lend
	inc dword ptr [edi + eax*4]
	inc esi
	jmp L1
Lend:	
	ret
get_frequencies endp

printarr proc
	mov ebx, 0

L2:
	mov eax, [esi]
	cmp eax, 0
	je skip
	mov eax, ebx
	call writechar
	mov al, ':'
	call writechar
	mov eax, [esi]
	call writedec
	mov al, ' '
	call writechar
skip:
	add esi, 4
	inc ebx
	loop L2
	ret
printarr endp

end main
