section .text
extern	_malloc
global	_ft_list_push_front

_ft_list_push_front:
	push	rdi			;save list_start
	push	rsi			;save content
	mov		rdi, 16		;rdi = 16
	call	_malloc
	cmp		rax, 0		;check malloc
	je		exit		;go to exit
	pop		rsi			;take back rsi
	pop		rdi			;take back rdi
	mov		[rax], rsi	;list = content
	mov		r10, [rdi]	;
	mov		[rax+8], r10;list->next = list_start
	mov		[rdi], rax	;list_start = list
	jmp		exit

exit:
	ret
