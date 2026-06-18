INCLUDE Irvine32.inc

.data
	vara dd 3
	varb dd 4
	varc dd 5
	var1 EQU [ebp + 8]
	var2 EQU [ebp + 12]
	var3 EQU [ebp + 16]
	msg db "Result: ", 0

.code
main PROC
	push vara
	push varb
	push varc
	call threeprod

	mov edx, offset msg
	call writestring
	call writedec
	call crlf
	exit
main ENDP

threeprod proc
	push ebp
	mov ebp, esp
	mov eax, var1
	mov ebx, var2
	mul ebx
	mov ebx, var3
	mul ebx

	pop ebp
	ret 12
threeprod endp
END main
