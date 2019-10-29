[bits 16]

printstr_bios:			; Routine: output string in SI to screen
    pusha
	mov ah, 0Eh			; int 10h 'print char' function
.repeat:
	lodsb				; Get character from string
	cmp al, 0
	je .done			; If char is zero, end of string
	int 10h				; Otherwise, print it
	jmp .repeat
.done:
    popa
	ret

printchar_bios:
    pusha
    mov ah, 0x0e
    int 0x10
    popa
    ret