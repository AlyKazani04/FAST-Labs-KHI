INCLUDE Irvine32.inc

INTEGER_COUNT = 3

.data
	str1 BYTE "Enter a signed integer: ", 0
	str2 BYTE "The sum of the integers is: ", 0
	array dd INTEGER_COUNT dup(?)
	
.code
main PROC
	call clrscr
	mov esi, OFFSET array
	mov ecx, INTEGER_COUNT
	call promptforintegers
	call arraysum
	call displaysum
	exit
main ENDP

promptforintegers PROC USES ecx edx esi
	mov edx, OFFSET str1
L1:
	call writestring
	call readint
	call crlf
	mov [esi], eax
	add esi, TYPE DWORD
	loop L1
	ret
promptforintegers endp

arraysum PROC USES esi ecx
	mov eax, 0
L1:
	add eax, [esi]
	add esi, TYPE DWORD
	loop L1
	ret
arraysum ENDP

displaysum PROC
	mov edx, OFFSET str2
	call writestring
	call writeint
	call crlf
	ret
displaysum endp

END main
