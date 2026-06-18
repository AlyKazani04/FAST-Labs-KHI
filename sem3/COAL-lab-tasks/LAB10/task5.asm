include irvine32.inc

.data
prompt byte "enter a number: ", 0
resultmsg byte "factorial is: ", 0

.code
main proc
    mov edx, offset prompt
    call writestring
    call readint
    push eax
    call fact
    mov edx, offset resultmsg
    call writestring
    call writeint
    call crlf
    exit
main endp

fact proc
    push ebp
    mov ebp, esp
    mov eax, [ebp+8]
    cmp eax, 1
    jg recurse
    mov eax, 1
    jmp done
recurse:
    dec eax
    push eax
    call fact
    mov ebx, eax
    mov eax, [ebp+8]
    imul eax, ebx
done:
    pop ebp
    ret 4
fact endp

end main
