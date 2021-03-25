section .text
global _ft_strcpy

_ft_strcpy:
	mov		rax, 0					;rax = 0
	jmp		loop					;go to loop

loop:
	mov		cl, BYTE[rsi + rax]		;cl = src[0 + rax]
	cmp		cl, 0					;cl == 0?
	je		exit					;if TRUE go to exit
	mov		BYTE[rdi + rax], cl		;dest[0 + rax] = cl
	inc		rax						;rax++
	jmp		loop					;go to loop

exit:
	mov		BYTE[rdi + rax], cl		;dest[0 + rax] = '\0' 
	mov		rax, rdi				;rax = &dest[0];
	ret								;return(rax)
