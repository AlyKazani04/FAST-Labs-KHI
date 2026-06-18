INCLUDE Irvine32.inc

.data
    account dw 5000d

.code
main PROC
    movzx eax, account
    add eax, 1200d ; deposits 1200
    sub eax, 2000d; withdraws 2000
    call writedec
    exit
main ENDP
END main