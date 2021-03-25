section .text
global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy

;rdi = dest, rsi = src

_ft_strdup:
	push	rdi
	call	_ft_strlen
	inc		rax
	mov		rdi, rax
	call	_malloc
	pop		rdi
	cmp		rax, 0
	je		exit
	mov		rsi, rdi
	mov		rdi, rax
	call	_ft_strcpy
	mov		rax, rdi
	ret

exit:
	ret
