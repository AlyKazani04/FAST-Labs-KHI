INCLUDE Irvine32.inc

.data
	a SBYTE ?
	b SBYTE ?
	enter_msg BYTE "Enter two numbers: ", 0
	true_cond BYTE "Condition True", 0
	false_cond BYTE "Condition False", 0


.code
main PROC
	
	; print enter_msg
	mov edx, OFFSET enter_msg
	call writestring
	call crlf
	
	; read val 1
	call readint
	mov a, al

	; read val 2
	call readint
	mov b, al

	movsx eax, a
	cmp al, b
	jbe false_j
	cmp al, 100
	jge false_j

	; true condition
	mov edx, OFFSET true_cond
	call writestring
	call crlf
	jmp done

	; false condition
false_j:
	mov edx, OFFSET false_cond
	call writestring
	call crlf

done:
	exit
main ENDP
END main