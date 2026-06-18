INCLUDE Irvine32.inc

.data
	arr1 db 1d,2d,3d,4d,5d,6d,7d,8d,9d,10d
	multiplier db 3d
.code
main proc
	
	mov esi, offset arr1
	mov ecx,lengthof arr1
	call printarr
	call crlf

	cld
	mov esi, offset arr1
	mov edi, esi
	mov ecx, lengthof arr1
	call load

	mov esi, offset arr1
	mov ecx,lengthof arr1
	call printarr

	exit
main endp

load proc
L1:
	lodsb
	mul multiplier
	stosb
	loop L1
	ret
load endp

printarr proc
L2:
	movzx eax, byte ptr [esi]
	call writedec
	mov al, ' '
	call writechar
	inc esi
	loop L2
	ret
printarr endp

end main
