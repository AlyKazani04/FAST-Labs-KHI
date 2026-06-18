INCLUDE Irvine32.inc

.data
	arr db 1, 2, 3
		db 4, 5, 6
		db 7, 8, 9
	row_size dd 3
	col_size dd 3
	sum db 0
	msg db "Sum of all elements: ", 0

.code
main proc
	
	mov edi, 0					; current row index
	mov ecx, col_size			; size of row = size of cols (square array)
L1:
	push ecx
	mov ebx, offset arr			; base address
	mov esi, 0					; current col index, reset to 0

	movzx eax, byte ptr row_size
	mul edi
	add ebx, eax				; updated row offset

	mov ecx, row_size
L2:
	mov eax, 0					; clear accumulator
	mov al, sum
	add al, [ebx + esi]			; [base + (rowindex * rowsize) + (colindex * typeof data)]
	mov sum, al
	inc esi						; next element
	loop L2

	pop ecx

	inc edi						; next row
	loop L1

	mov edx, offset msg
	call writestring

	movzx eax, sum
	call writedec

	call crlf

	exit
main endp
end main
