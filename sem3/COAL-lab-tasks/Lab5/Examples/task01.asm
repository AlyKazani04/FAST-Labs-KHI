INCLUDE Irvine32.inc

.code
main PROC
    mov AX, 0FFFFH
    inc AX
    call dumpregs
    exit
main ENDP
END main