INCLUDE Irvine32.inc

.data
	var1 db ?
	var2 db ?
	var3 db ?
	msg1 BYTE "val1: ", 0
	msg2 BYTE "val2: ", 0
	msg3 BYTE "val3: ", 0
	msg_unsigned BYTE "Largest (Unsigned)= ", 0
	msg_signed BYTE "Largest (Signed)= ", 0

.code
main PROC
	; read user values
	mov edx, OFFSET msg1
	call writestring
	call readint
	mov var1, al

	mov edx, OFFSET msg2
	call writestring
	call readint
	mov var2, al

	mov edx, OFFSET msg3
	call writestring
	call readint
	mov var3, al

	; compare unsigned
	movzx eax, var1
	cmp al, var2
	ja L1			; if var1 > var2, jump to L1
	mov al, var2	; var2 above
L1:
	cmp al, var3
	ja L2			; if al > var3, jump to L2
	mov al, var3	; var3 above
L2:
	mov edx, OFFSET msg_unsigned
	call writestring
	call writedec
	call crlf

	; compare signed
	movsx eax, var1
	cmp al, var2
	jg L3			; if var1 > var2, jump to L3
	mov al, var2	; var2 greater
L3:
	cmp al, var3
	jg L4			; if al > var3, jump to L4
	mov al, var3	; var3 greater
L4:		
	mov edx, OFFSET msg_signed
	call writestring
	call writeint
	call crlf

	exit
main ENDP
END main
