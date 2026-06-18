INCLUDE Irvine32.inc
.data
msg BYTE "Aly Muhammad Kazani 24K-0512", 0
.code
main PROC
mov edx, OFFSET msg
call WriteString
exit
main ENDP
END main