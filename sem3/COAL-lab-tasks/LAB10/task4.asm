Include irvine32.inc

.data
prompt db "enter an integer: ", 0
result db "the square is: ", 0

.code
main proc
    call localsquare
    exit
main endp

localsquare proc
    enter 4, 0
    mov edx, offset prompt
    call writestring
    call readint
    mov [ebp - 4], eax
    mov eax, [ebp - 4]
    imul eax, eax
    mov edx, offset result
    call writestring
    call writeint
    call crlf
    leave
    ret
localsquare endp

end main
