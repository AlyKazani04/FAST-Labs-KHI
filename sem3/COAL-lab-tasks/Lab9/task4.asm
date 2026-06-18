INCLUDE Irvine32.inc

.data
    inmsg db "Enter key: ", 0
    outmsg db "Encrypted key: ", 0
    strkey db 9 dup(0)
    binkey db 0b

.code
main PROC
    mov edx, offset inmsg
    call writestring
    mov edx, offset strkey
    mov ecx, sizeof strkey - 1
    call readstring

    mov ebx, 0
    mov esi, offset strkey
conversion:
    mov al, [esi]
    cmp al, 0 ; check if string end
    je endconversion

    shl ebx, 1
    cmp al, '1'
    jne nextchar
    inc ebx
nextchar:
    inc esi
    jmp conversion
endconversion:
    mov binkey, bl

    mov edx, offset outmsg
    call writestring
    movzx eax, binkey
    call writebin
    call crlf
    exit
main ENDP
END main
