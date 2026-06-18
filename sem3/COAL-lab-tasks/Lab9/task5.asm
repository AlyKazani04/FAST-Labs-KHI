INCLUDE Irvine32.inc

.data
    readings db 12d, 25d, 30d, 40d, 18d, 22d, 27d, 35d, 20d, 15d
    sum db ?
    avg db ?
    abavg db 0
    beavg db 0
    scaledavg db ?
    encrypted_res db ?

    sumstr db "Sum of readings: ", 0
    avgstr db "Average reading: ", 0
    abavgstr db "Readings Above Average: ", 0
    beavgstr db "Readings Below Average: ", 0
    sclavgstr db "Scaled Average (SHL): ", 0
    encryptstr db "Encrypted Result (ROR): ", 0

.code
main PROC

    call sumall
    mov edx, offset sumstr
    call writestring
    movzx eax, sum
    call writedec
    call crlf

    call average
    mov edx, offset avgstr
    call writestring
    movzx eax, avg
    call writedec
    call crlf

    mov esi, 0
    mov ecx, lengthof readings
L1: 
    mov al, readings[esi]
    cmp al, avg
    ja above
    mov dl, beavg
    inc dl
    mov beavg, dl
    jmp skip
above:
    mov dl, abavg
    inc dl
    mov abavg, dl
skip:
    inc esi
    loop L1

    ; ABOVE AVERAGE ;
    mov edx, offset abavgstr
    call writestring
    movzx eax, abavg
    call writedec
    call crlf

    ; BELOW AVERAGE ;
    mov edx, offset beavgstr
    call writestring
    movzx eax, beavg
    call writedec
    call crlf

    ; SCALED AVERAGE ;
    mov al, avg
    shl al, 1
    mov scaledavg, al

    mov edx, offset sclavgstr
    call writestring
    movzx eax, scaledavg
    call writedec
    call crlf

    ; ENCRYPTED RESULT ;
    mov al, scaledavg
    ror al, 1
    mov encrypted_res, al

    mov edx, offset encryptstr
    call writestring
    movzx eax, encrypted_res
    call writebin
    call crlf

    exit
main ENDP

sumall proc
    mov esi, 0
    mov ecx, lengthof readings
    mov eax, 0
L1: 
    add al, readings[esi]
    inc esi
    loop L1

    mov sum, al
    ret
sumall endp

average proc
    mov bl, lengthof readings
    mov al, sum
    div bl
    mov avg, al
    ret
average endp

END main
