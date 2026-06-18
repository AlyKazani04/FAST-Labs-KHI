INCLUDE Irvine32.inc

.data
    PI EQU 3
    val db 4d

.code
main PROC
    movzx eax, val
    imul eax, PI
    call writedec
    exit
main ENDP
END main