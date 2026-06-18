include irvine32.inc

.data
prompt byte "enter a number: ",0
recmsg byte "recursive fact time (ms): ",0
loopmsg byte "loop fact time (ms): ",0
resultmsg byte "factorial is: ",0

.code
main proc
    mov edx, offset prompt
    call writestring
    call readint
    mov esi, eax            ; save input n

    ; --- Recursive factorial ---
    call getmseconds
    mov ebx, eax            ; start time
    push esi
    call fact_recursive
    mov ecx, eax            ; save factorial result
    call getmseconds
    sub eax, ebx            ; elapsed
    mov ebx, eax            ; save elapsed

    mov edx, offset recmsg
    call writestring
    mov eax, ebx
    call writedec
    call crlf

    mov edx, offset resultmsg
    call writestring
    mov eax, ecx            ; eax now has factorial
    call writeint
    call crlf

    ; --- Loop factorial ---
    call getmseconds
    mov edx, eax           ; start time
    push esi
    call fact_loop
    mov ecx, eax
    call getmseconds
    sub eax, edx
    mov ebx, eax

    mov edx, offset loopmsg
    call writestring
    mov eax, ebx
    call writedec
    call crlf

    mov edx, offset resultmsg
    call writestring
    mov eax, ecx            ; factorial result
    call writeint
    call crlf

    exit
main endp

; Recursive factorial
fact_recursive proc
    push ebp
    mov ebp, esp
    mov eax, [ebp+8]    ; n
    cmp eax, 1
    jle done
    dec eax
    push eax            ; push n-1
    call fact_recursive
    mov ebx, eax        ; result of fact(n-1)
    mov eax, [ebp+8]    ; original n
    imul eax, ebx       ; n * fact(n-1)
done:
    pop ebp
    ret 4               ; return 4 bytes (the pushed n-1)
fact_recursive endp

; Loop factorial
fact_loop proc
    push ebp
    mov ebp, esp
    mov eax,[ebp+8]
    cmp eax,1
    jle done_loop
    mov ecx,eax
    mov eax,1
loop_start:
    imul eax,ecx
    dec ecx
    cmp ecx,1
    jg loop_start
done_loop:
    pop ebp
    ret 4
fact_loop endp

end main
