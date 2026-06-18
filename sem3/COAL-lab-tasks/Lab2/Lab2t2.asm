INCLUDE Irvine32.inc
;BYTE or DB 8 BIT
;WORD or DW 16 BIT
;DWORD or DD 32 BIT
;DO 64 BIT
.data
.code
main PROC
; 1
mov edx, 0 ; initial edx value assumed
mov eax, 1 ; initial eax value assumed
mov ebx, 2 ; initial ebx value assumed
mov ecx, 3 ; initial ecx value assumed
mov edx, eax
add edx, 3
add edx, ebx
sub edx, ecx
add edx, 12h
sub edx, 45o
add edx, 89d
mov eax, edx
Call WriteInt
Call CrLf
; 2
mov edx, 0 ; initial edx value assumed
mov eax, 1 ; initial eax value assumed
mov ebx, 2 ; initial ebx value assumed
mov ecx, 3 ; initial ecx value assumed
mov eax, 4C2h
sub eax, ebx
add eax, 72o
add eax, 55d
sub eax, 11011001b
add eax, 6Ch
Call WriteInt
Call CrLf
; 3
mov edx, 0 ; initial edx value assumed
mov eax, 1 ; initial eax value assumed
mov ebx, 2 ; initial ebx value assumed
mov ecx, 3 ; initial ecx value assumed

mov ebx, 6F1h
sub ebx, eax
add ebx, 92d
add ebx, 47o
sub ebx, 11011001b
add ebx, 6Ch
mov eax, ebx
Call Writeint
Call CrLf
; 4
mov edx, 0 ; initial edx value assumed
mov eax, 1 ; initial eax value assumed
mov ebx, 2 ; initial ebx value assumed
mov ecx, 3 ; initial ecx value assumed
mov ecx, 101011010110b
add ecx, 3Ah
sub ecx, 64o
add ecx, ebx
sub ecx, ecx
add ecx, 5
mov eax, ecx
Call WriteInt
Call CrLf
exit
main ENDP
END main