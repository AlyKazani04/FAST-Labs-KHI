INCLUDE Irvine32.inc
.data
    marks db 7 dup(?)
    msgpassed BYTE “Passed students: “, 0
    msgfailed BYTE “Failed students: “, 0
    passcount db 0
    pcount db 0
    fcount db 0

.code
main PROC
    mov ecx, lengthof marks
    mov esi, 0
L1:
    call readint
    mov marks[esi], al
    inc esi
    loop l1
    call countpassfail
    mov edx, OFFSET msgpassed
    call writestring
    movzx eax, pcount
    call writedec
    call crlf
    mov edx, OFFSET msgfailed
    call writestring
    movzx eax, fcount
    call writedec
    call crlf
    exit
main ENDP

countpassfail PROC
    mov ecx, lengthof marks
    mov esi, 0
L1:
    mov al, marks[esi]
    cmp al, 50d
    jb failed
    mov dl, pcount
    inc dl
    mov pcount, dl
    inc esi
    jmp skip
    failed:
    mov dl, fcount
    inc dl
    mov fcount, dl
    inc esi
skip:
    loop L1
    ret
countpassfail ENDP
END main
