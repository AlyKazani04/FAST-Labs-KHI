INCLUDE Irvine32.inc
.data
    array1 db 2d, 4d, 6d, 8d, 10d    
    array2 db 1d, 4d, 6d, 9d, 10d
    matchcount db 0d
    msg BYTE "Matching elements: ", 0
.code
main PROC    
    mov esi, 0 ; i
    mov ecx, lengthof array1
L1:
    mov ebx, 0 ; j
    push ecx
    mov ecx, lengthof array2
L2:
    movzx eax, array2[ebx]
    cmp al, array1[esi]
    jne skip
    movzx eax, matchcount
    inc eax
    mov matchcount, al
skip:
    inc ebx
    loop L2

    inc esi
    pop ecx
    loop L1

    mov edx, OFFSET msg
    call writestring
    movzx eax, matchcount
    call writedec
    call crlf

    exit
main ENDP
END main
