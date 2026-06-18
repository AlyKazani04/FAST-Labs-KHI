INCLUDE Irvine32.inc
.data
valA SBYTE -15
valB BYTE 25
valC WORD ?
.code
main PROC
mov eax, 0
movsx eax, valA
add eax, DWORD ptr valB
sub al, 5
mov valC, ax
movsx eax, valC
call writeint
exit
main ENDP
END main