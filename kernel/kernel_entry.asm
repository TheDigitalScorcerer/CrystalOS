[bits 32]
;[org 0x1000]
[extern main]

;db "This'll do it."
;mov ebx, CONTROL_MSG
;call printstr
ret
;call main
;ret

CONTROL_MSG db "Control passed to kernel.", 0

;%include "../boot/asm/print.asm"