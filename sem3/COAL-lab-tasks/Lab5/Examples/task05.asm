INCLUDE Irvine32.inc

.code
main PROC
    mov AL, 72H
    add AL, 0EH
    call dumpregs
    exit
main ENDP
END main