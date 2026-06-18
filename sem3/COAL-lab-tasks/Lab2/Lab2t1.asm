INCLUDE Irvine32.inc
;BYTE or DB 8 BIT
;WORD or DW 16 BIT
;DWORD or DD 32 BIT
;DO 64 BIT
.data
; 1
result DD ?
total DD ?
var1 DD 25
var2 DD 47
var3 DD 88
var4 DD 64
var5 DD 120h
var6 DD 27o
; 2
balance DD ?
; 3
va DD 101110b
vb DD 50Ah
vc DD 67d
vd DD 1010001b
ve DD 0Fh
; 4
v1 DD 11010110b
v2 DD 9C4h
v3 DD 220
v4 DD 18
v5 DD 1011110b
v6 DD 0Dh
v7 DD 12
; 5
vara DD 111b
varb DD 12
varc DD 1F3h
vard DD 745o
.code

main PROC
; 1
mov eax, var1
add eax, var2
add eax, var3
add eax, var4
add eax, var5
add eax, var6
sub eax, 0Ah
mov total, eax
call WriteInt
call CrLf
; 2
mov ebx, 95
sub ebx, 31
add ebx, 240
sub ebx, 125
mov eax, ebx
call WriteInt
call CrLf
; 3
mov ecx, va
add ecx, vb
add ecx, vc
add ecx, vd
add ecx, ve
mov eax, ecx
call WriteInt
call CrLf
; 4
mov edx, v1
sub edx, v2
add edx, v3
add edx, v4
add edx, v5
sub edx, v6
add edx, v7
mov eax, edx
call WriteInt
call CrLf
; 5
mov eax, vara
sub eax, varb
add eax, varc
sub eax, vard
call WriteInt
exit
main ENDP
END main