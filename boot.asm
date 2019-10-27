BITS 16

    [org 0x7c00]

start:
	mov si, BOOTING_MSG
    call printstr
    mov si, EXIT_MSG
    call printstr

    mov [BOOT_DRIVE], dl
    mov bp, 0x8000
    mov sp, bp              ; Move the stack out of the way

    mov bx, 0x9000
    mov dh, 5
    mov dl, [BOOT_DRIVE]    ; Load 5 sectors of the boot disk
    call disk_load

    mov si, [0x9000]
    call printstr

    mov si, [0x9000 + 512]
    call printstr

    mov si, HYPERSPACE_A
    call printstr

    ; PREPARE FOR 32-BITS!

    mov si, HYPERSPACE_B
    call printstr

    jmp exit_os

; -------------------------------- ;
;           My Functions           ;
; -------------------------------- ;

%include "asm/print.asm"
%include "asm/disk.asm"

BOOTING_MSG     db 'Hello, World! CrystalOS is booting...', 0x0D, 0x0A, 0x00
EXIT_MSG        db 'Goodbye! Shutting down now...', 0x0D, 0x0A, 0x00
HYPERSPACE_A    db 'You are in 16-bit Real Mode. Preparing to make the jump to 32-bit Protected Mode...', 0x0D, 0x0A, 0x00
HYPERSPACE_B    db 'Making the jump to 32-bit! See you soon!', 0x0D, 0x0A, 0x00

BOOT_DRIVE: db 0

exit_os:
    hlt

	times 510-($-$$) db 0	; Pad remainder of boot sector with 0s
	dw 0xAA55				; The standard PC boot signature

    times  256 dw 0x6500
    times  256 dw 0x6A00