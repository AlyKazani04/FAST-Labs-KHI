INCLUDE Irvine32.inc

.data
	msg_on BYTE "Bit 0 is ON", 0
	msg_off BYTE "Bit 0 is OFF", 0

.code
main PROC
	mov al, 20h		; 0010 0000 b
	mov bl, 3Dh		; 0011 1101 b
	mov cl, 88h		; 1000 1000 b
	
	and al, 01010101b	; clear odd bits
	or al, 10101010b	; set even bits
	xor al, 11111111b	; toggle all bits

	test al, 1		; test bit 0
	jnz bit_on		; jump to bit_on, if bit 0 is on
	jmp bit_off		; jump to bit_off, if bit 0 is off

bit_on: 
	mov edx, OFFSET msg_on
	call writestring
	jmp done

bit_off:
	mov edx, OFFSET msg_off
	call writestring

done: 
	call crlf
	exit
main ENDP
END main
