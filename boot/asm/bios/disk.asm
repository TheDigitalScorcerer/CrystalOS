[bits 16]

disk_load_bios:
    push dx

    mov ah, 0x02
    mov al, dh
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02

    int 0x13
    jc disk_error_bios
    pop dx

    cmp dh, al
    jne disk_error_bios
    ret

disk_error_bios:
    mov si, DISK_ERROR
    call printstr_bios
    jmp $

DISK_ERROR  db 'Error reading disk!', 0x0D, 0x0A, 0x00