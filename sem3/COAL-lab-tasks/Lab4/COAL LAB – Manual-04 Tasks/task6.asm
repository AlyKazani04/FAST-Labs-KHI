INCLUDE Irvine32.inc

.data
    val byte 10d

.code
main PROC
    movzx eax, val ; 10
    inc eax ; 11
    inc eax ; 12
    inc eax ; 13
    dec eax ; 12
    dec eax ; 11
    call writedec
    exit
main ENDP
END main