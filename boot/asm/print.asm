[bits 32]

VIDEO_MEMORY    equ 0xb8000
WHITE_ON_BLACK  equ 0x0f

printstr:
    pusha
    mov edx, VIDEO_MEMORY

printstr_loop:
    mov al, [ebx]
    mov ah, WHITE_ON_BLACK

    cmp al, 0
    je printstr_done

    mov [edx], ax
    add ebx, 1
    add edx, 2

    jmp printstr_loop

printstr_done:
    popa
    ret