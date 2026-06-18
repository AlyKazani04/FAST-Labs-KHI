INCLUDE Irvine32.inc

.data
	versionHistory dw 101, 102, 103, 104, 105
	rollbackHistory dw 5 dup(?)
	msg1 BYTE "Version History (Latest Last): ", 0
	msg2 BYTE "Rollback Order (After using PUSH & POP): ", 0
	space BYTE " ", 0

.code
main PROC
	call crlf
	mov edx, OFFSET msg1
	call writestring
	call crlf

	mov ecx, LENGTHOF versionHistory
	mov esi, OFFSET versionHistory
display_original:
	movzx eax, WORD PTR [esi]
	call writedec
	mov edx, OFFSET space
	call writestring
	add esi, TYPE versionHistory
	loop display_original

	mov ecx, LENGTHOF versionHistory
	mov esi, OFFSET versionHistory
push_versions:
	mov ax, [esi]
	push ax
	add esi, TYPE versionHistory
	loop push_versions

	mov ecx, LENGTHOF rollbackHistory
	mov edi, OFFSET rollbackHistory
pop_versions:
	pop ax
	mov [edi], ax
	add edi, TYPE rollbackHistory
	loop pop_versions

	call crlf
	mov edx, OFFSET msg2
	call writestring
	call crlf

	mov ecx, LENGTHOF rollbackHistory
	mov esi, OFFSET rollbackHistory
display_rollback:
	movzx eax, WORD PTR [esi]
	call writedec
	mov edx, OFFSET space
	call writestring
	add esi, TYPE rollbackHistory
	loop display_rollback

	call crlf

	exit
main ENDP
END main
