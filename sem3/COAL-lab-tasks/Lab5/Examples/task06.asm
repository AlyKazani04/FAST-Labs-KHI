INCLUDE Irvine32.inc

.data
    arrayB BYTE 10h,20h,30h,40h
    arrayW WORD 100h,200h,300h

.code
main PROC
    mov al,arrayB
    mov al,[arrayB+1]
    mov ax,arrayW
    mov ax,[arrayW+2]
    call dumpregs
    exit
main ENDP
END main