INCLUDE Irvine32.inc

.code
main PROC
    mov al , 0Fh
    add al ,1
    call dumpregs
    exit
main ENDP
END main