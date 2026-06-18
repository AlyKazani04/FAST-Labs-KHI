INCLUDE Irvine32.inc

.data
    bVal BYTE ?
    wVal WORD ?
    dVal DWORD ?
    dVal2 DWORD ?

.code
main PROC
    ; If bVal is located at offset 00404000h, we would get:
    mov esi, OFFSET bval ; ESI = 00404000
    mov esi, OFFSET wVal ; ESI = 00404001
    mov esi, OFFSET dVal ; ESI = 00404003
    mov esi, OFFSET dVal2 ; ESI = 00404007
    call dumpregs
    exit
main ENDP
END main