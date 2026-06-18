INCLUDE Irvine32.inc

.data
	arr dd 1d,2d,3d,4d,5d,6d,7d,8d,9d,10d,11d,12d,13d,14d,15d,16d,17d,18d,19d,20d
	copy_arr dd 1d,2d,3d,4d,5d,6d,7d,8d,9d,10d,11d,12d,13d,14d,15d,16d,17d,18d,19d,20d
	min10 dd 10 dup(?)
	max10 dd 10 dup(?)
	param1 equ [ebp + 8]
	param2 equ [ebp + 12]
	space db " ", 0
	LARGE_VAL dd 7FFFFFFFh
	SMALL_VAL dd 80000000h
	temp dd ?
	count dd 0

.code
main proc
	push offset arr
	push offset min10
	call fillmin10

	push offset copy_arr
	push offset max10
	call fillmax10
	
	push offset min10
	call display10

	push offset max10
	call display10
	exit
main endp

fillmin10 proc
	push ebp
	mov ebp, esp
	push esi
	push edi
	push ebx

	mov edi, param1
	mov esi, param2
	mov count, 0
	mov ecx, 10
L1:
	mov ebx, 0
	mov eax, DWORD PTR [esi]
	mov edx, 0
L2:
	cmp edx, 20
	jge foundMin
	push ebx
	mov ebx, DWORD PTR [esi + edx * 4]
	cmp ebx, eax
	mov temp, ebx
	pop ebx
	jge skip
	mov eax, temp
	mov ebx, edx
skip:
	inc edx
	jmp L2
foundMin:
	mov DWORD PTR [edi], eax
	add edi, 4

	mov eax, LARGE_VAL
	mov DWORD PTR [esi + ebx * 4], eax

	loop L1

	pop ebx
	pop edi
	pop esi
	pop ebp
	ret 8
fillmin10 endp

fillmax10 proc
	push ebp
	mov ebp, esp
	push esi
	push edi
	push ebx

	mov esi, param2
	mov edi, param1

	mov ecx, 10
L1:
	mov ebx, 0
	mov eax, DWORD PTR [esi]
	mov edx, 0

L2:
	cmp edx, 20
	jge foundMax
	push ebx
	mov ebx, DWORD PTR [esi + edx * 4]
	cmp ebx, eax
	mov temp, ebx
	pop ebx
	jle skip
	mov eax, temp
	mov ebx, edx
skip:
	inc edx
	jmp L2
foundMax:
	mov [edi], eax
	add edi, 4

	mov eax, SMALL_VAL
	mov DWORD PTR [esi + ebx * 4], eax
	loop L1

	pop ebx
	pop edi
	pop esi
	pop ebp
	ret 8
fillmax10 endp

display10 proc
	push ebp
	mov ebp, esp
	mov esi, param1 ; mov address of first index to esi
	mov ecx, 10
L1:
	mov eax, [esi]
	call writedec
	mov edx, offset space
	call writestring
	add esi, 4
	loop L1
	call crlf
	
	pop ebp
	ret 4
display10 endp

END main
