INCLUDE Irvine32.inc

.code
main PROC
    mov AX,12AEH

    sub AX,12AFH
    call dumpregs
    exit
main ENDP
END main