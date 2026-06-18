INCLUDE Irvine32.inc

.data
    v1 BYTE ?
    v2 WORD ?
    v3 DWORD ?
    v4 QWORD ?

.code
main PROC
    mov eax, 0
    mov eax, TYPE v1 ;returns 1
    call writedec
    call crlf
    mov eax, TYPE v2 ;returns 2
    call writedec
    call crlf
    mov eax, TYPE v3 ;returns 4
    call writedec
    call crlf
    mov eax, TYPE v4 ;returns 8
    call writedec
    exit
main ENDP
END main