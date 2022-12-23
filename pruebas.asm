global _func

_func:

    jmp $+4
    dw 0x2222
    mov eax, 1
    ret
