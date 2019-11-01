BITS 16

[org 0x7c00]
KERNEL_OFFSET equ 0x1000

start:
    call clearscr_bios

	mov si, BOOTING_MSG
    call printstr_bios

    mov [BOOT_DRIVE], dl

    mov bp, 0x9000
    mov sp, bp              ; Move the stack out of the way

    call load_kernel

    mov si, HYPERSPACE_A
    call printstr_bios

    ;call clearscr_bios

    jmp switch_to_pm

load_kernel:
    ;mov si, MSG_LOAD_KERNEL
    ;call printstr_bios

    mov bx, KERNEL_OFFSET
    mov dh, 15
    mov dl, [BOOT_DRIVE]
    call disk_load_bios

    ret

switch_to_pm:
    cli

    lgdt [gdt_descriptor]
    mov eax, cr0
    or  eax, 0x1
    mov cr0, eax

    jmp CODE_SEG:init_pm   ; Make a far jump to flush the CPU

[bits 32]

init_pm:                   ; Yay! We made it!
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000
    mov esp, ebp

    mov ebx, HYPERSPACE_B
    call printstr

    mov ebx, [KERNEL_OFFSET]
    call printstr
    jmp $
    ;call KERNEL_OFFSET

    mov ebx, END_OS
    call printstr

    jmp $
    jmp exit_os

; -------------------------------- ;
;           My Functions           ;
; -------------------------------- ;

%include "asm/bios/print.asm"
%include "asm/bios/disk.asm"
%include "asm/GDT.asm"
%include "asm/print.asm"

[bits 32]

BOOTING_MSG     db 'Hello, World! CrystalOS is booting...', 0x0D, 0x0A, 0x00
EXIT_MSG        db 'Goodbye! Shutting down now...', 0x0D, 0x0A, 0x00
HYPERSPACE_A    db 'You are in 16-bit Real Mode. Jumping to 32-bit Protected Mode...', 0x0D, 0x0A, 0x00
HYPERSPACE_B    db 'Congratulations, you have made it to 32-bit mode!', 0x00
;MSG_LOAD_KERNEL db "Loading kernel into memory...", 0x0D, 0x0A, 0x00
END_OS          db "CrystalOS finished. Exitting...", 0x00, 0x45, 0x4A

BOOT_DRIVE: db 0

[bits 16]
exit_os:
    mov si, EXIT_MSG
    call printstr_bios

    hlt

	times 510-($-$$) db 0	; Pad remainder of boot sector with 0s
	dw 0xAA55				; The standard PC boot signature

    times  256 dw 0x6500
    times  256 dw 0x6A00

;times KERNEL_OFFSET-($-$$) db 0

;CONTROL_MSG db "Control passed to kernel.", 0

;mov ebx, CONTROL_MSG
;call printstr
;ret
;;call main
;;ret

;;CONTROL_MSG db "Control passed to kernel.", 0