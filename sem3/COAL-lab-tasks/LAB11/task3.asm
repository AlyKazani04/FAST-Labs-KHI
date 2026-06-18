INCLUDE Irvine32.inc

.data
	str1 db "check", 0
	str2 db "cheque", 0
	equal db "Strings are equal", 0
	unequal db "Strings are not equal", 0
.code
main proc
	mov edx, offset str1
	call writestring
	call crlf
	mov edx, offset str2
	call writestring
	call crlf
	call iscompare
	exit
main endp

iscompare proc 
	str_compare proto
	invoke str_compare, addr str1, addr str2
	jne notequal
	mov edx, offset equal
	call writestring
	jmp fin
notequal:
	mov edx, offset unequal
	call writestring
fin:
	ret
iscompare endp

end main
