INCLUDE Irvine32.inc

.data
    signed sbyte -10d

.code
main PROC
    movsx eax, signed
    call writeint ; shows -10, eax = 0xFFFFFFF6
    call crlf
    movzx eax, signed ; shows +246, eax = 0x000000F6
    call writeint
    exit
main ENDP
END main