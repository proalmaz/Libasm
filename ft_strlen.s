section	.text
global _ft_strlen

_ft_strlen:
	mov		rax, 0				;rax = 0

loop:
	cmp		BYTE[rdi+rax], 0	;str[0+rax] == 0?
	je		return
	inc		rax					;rax++
	jmp		loop				;go to loop

return:
	ret							;return(rax)
