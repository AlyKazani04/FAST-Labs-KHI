INCLUDE Irvine32.inc

.code
main PROC
    mov AL, 0FH
    add AL, 0F1H
    call dumpregs
    exit
main ENDP
END main