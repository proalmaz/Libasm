section .text
global _ft_list_size

_ft_list_size:
	mov		rax, 0

loop:
	cmp		rdi, 0
	je		exit
	mov		rdi, [rdi + 8]
	inc		rax
	jmp		loop

exit:
	ret
