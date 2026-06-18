INCLUDE Irvine32.inc

.data
	arr SBYTE 5 dup(?)

.code
main PROC

	; user inputs
	mov esi, 0
	mov ecx, 5
L1:
	; read user values
	call readint

	mov arr[esi], al
	inc esi

	cmp al, 0
	LOOPNZ L1
	
	call crlf
	; print non-zeros
	mov esi, 0
	mov ecx, 5
L2:
	cmp arr[esi], 0
	jz done
	movsx eax, arr[esi]
	call writeint
	call crlf
	inc esi
	LOOP L2
done: 
	
	exit
main ENDP
END main