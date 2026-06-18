INCLUDE Irvine32.inc

.data
    SecondsInDay EQU 24*60*60
    val dword SecondsInDay

.code
main PROC
    mov eax, 0
    mov eax, val
    call writedec
    exit
main ENDP
END main