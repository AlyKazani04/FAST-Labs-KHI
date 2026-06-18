INCLUDE Irvine32.inc

.data
    items db 50d
    sold db 7d
    restock db 15d

.code
main PROC
    movzx eax, items ; 50 items
    sub al, sold ; 50 - 7 = 43
    add al, restock ; 43 + 15 = 58
    call writedec
    exit
main ENDP
END main