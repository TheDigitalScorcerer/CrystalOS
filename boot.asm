BITS 16

    [org 0x7c00]

start:
	mov si, BOOTING_MSG
    call printstr

    mov bp, 0x9000
    mov sp, bp              ; Move the stack out of the way

    mov si, [0x9000]
    call printstr_bios

    mov si, [0x9000 + 512]
    call printstr_bios

    mov si, HYPERSPACE_A
    call printstr_bios

    ; PREPARE FOR 32-BITS!

    mov si, HYPERSPACE_B
    call printstr_bios

    lgdt [gdt_descriptor]
    mov eax, cr0
    or  eax, 0x1
    mov cr0, eax

    jmp CODE_SEG:start_protected_mode   ; Make a far jump to flush the CPU

    [bits 32]
    start_protected_mode:               ; Yay! We made it!

    jmp $
    jmp exit_os

; -------------------------------- ;
;           My Functions           ;
; -------------------------------- ;

%include "asm/bios/print.asm"
%include "asm/bios/disk.asm"
%include "asm/GDT.asm"

BOOTING_MSG     db 'Hello, World! CrystalOS is booting...', 0x0D, 0x0A, 0x00
EXIT_MSG        db 'Goodbye! Shutting down now...', 0x0D, 0x0A, 0x00
HYPERSPACE_A    db 'You are in 16-bit Real Mode. Preparing to make the jump to 32-bit Protected Mode...', 0x0D, 0x0A, 0x00
HYPERSPACE_B    db 'Making the jump to 32-bit! See you soon!', 0x0D, 0x0A, 0x00

BOOT_DRIVE: db 0

exit_os:
    mov si, EXIT_MSG
    call printstr

    hlt

	times 510-($-$$) db 0	; Pad remainder of boot sector with 0s
	dw 0xAA55				; The standard PC boot signature

    times  256 dw 0x6500
    times  256 dw 0x6A00