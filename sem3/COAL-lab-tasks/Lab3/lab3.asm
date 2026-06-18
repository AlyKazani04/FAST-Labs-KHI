INCLUDE Irvine32.inc

.data
  ;task 1
  snum dd -100
  unum dd 200
  uninit dd ?
  ;task 2
  message BYTE "Aly Muhammad CS", 0
  ;task 3
  num1 dd 500
  num2 dd 200
  ;task 4
  msg BYTE "EAX CONTENTS: ", 0
  ;task 6
  marks BYTE 8 DUP(5)
  reserved dw 5 DUP(?)

.code
main PROC
  ;task 3
  mov eax, num1
  mov edx, num1
  add eax, edx
  mov edx, OFFSET msg ; Print msg
  CALL WRITESTRING
  CALL WriteDec ; Print EAX value
  call crlf
  ;task 4
  mov ebx, 90d
  mov eax, ebx
  call WriteDec
  call crlf
  mov ebx, 5Ah
  mov eax, ebx
  call WriteDec
  call crlf
  mov ebx, 01011010b
  mov eax, ebx
  call WriteDec
  call crlf
  mov ebx, &#39;B&#39;
  
  mov eax, ebx
  call WriteDec
  call crlf
  ;task 5
  mov eax, 30000h
  add eax, 60000h
  sub eax, 10000h
  call WriteHex ; printing in hex, it will print 8 hex digits
  call crlf
  exit
main ENDP
END main
