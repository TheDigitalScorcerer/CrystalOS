VIDEO_MEMORY equ 0xb8000

printstr:
    pusha
    mov edx, VIDEO_MEMORY