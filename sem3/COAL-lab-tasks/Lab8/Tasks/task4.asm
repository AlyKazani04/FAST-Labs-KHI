INCLUDE Irvine32.inc
.data
wordInput BYTE 50 DUP(?)
vowelCount DWORD 0
consCount DWORD 0
prompt BYTE "Enter a word: ",0
vowelMsg BYTE "Vowels: ",0
consMsg BYTE "Consonants: ",0

.code
main PROC
; Prompt user for word
mov edx, OFFSET prompt
call WriteString
mov edx, OFFSET wordInput
mov ecx, SIZEOF wordInput
call ReadString ; returns length in EAX

mov ecx, eax ; number of chars
mov esi, OFFSET wordInput

check_loop:
mov al, [esi]
cmp al, 0
je done

; Convert to lowercase
or al, 20h

; Check if alphabetic
cmp al, 'a'
jb skip_char
cmp al, 'z'
ja skip_char

; Check for vowels
cmp al, 'a'
je is_vowel
cmp al, 'e'
je is_vowel
cmp al, 'i'
je is_vowel
cmp al, 'o'
je is_vowel
cmp al, 'u'
je is_vowel

; Otherwise consonant
inc consCount
jmp next_char

is_vowel:
inc vowelCount

next_char:
inc esi

loop check_loop
jmp done

skip_char:
inc esi
loop check_loop

done:
; Display results
mov edx, OFFSET vowelMsg
call WriteString
mov eax, vowelCount
call WriteDec
call Crlf

mov edx, OFFSET consMsg
call WriteString
mov eax, consCount
call WriteDec
call Crlf

exit
main ENDP
END main