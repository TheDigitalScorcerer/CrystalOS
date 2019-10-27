BITS 16

    [org 0x7c00]

start:
	mov si, BOOTING_MSG
    call printstr
    mov si, EXIT_MSG
    call printstr
    jmp exit_os

; -------------------------------- ;
;           My Functions           ;
; -------------------------------- ;

printstr:				; Routine: output string in SI to screen
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

printchar:
    pusha
    mov ah, 0x0e
    int 0x10
    popa
    ret


BOOTING_MSG db 'Hello, World! CrystalOS is booting...', 0x0D, 0x0A, 0x00
EXIT_MSG    db 'Goodbye! Shutting down now...', 0x0D, 0x0A, 0x00

DISK_ERROR  db 'Error reading disk!', 0x0D, 0x0A, 0x00

exit_os:
    hlt

	times 510-($-$$) db 0	; Pad remainder of boot sector with 0s
	dw 0xAA55				; The standard PC boot signature