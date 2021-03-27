section	.text
global _ft_strcmp

;rdi = s1, rsi = s2
_ft_strcmp:
	mov 	r10, 0

loop:
	mov	al, byte[rdi + r10]		;al = s1[o + r8]
	mov	bl, byte[rsi + r10]		;bl = s2[o + r8]
	cmp	al, 0					;al == 0?
	je	exit					;go to exit
	cmp	bl, 0					;bl == 0?
	je	exit					;go to exit
	cmp	al, bl					;al == bl?
	jne	exit					;if FALSE go to exit
	inc	r10						;r8++
	jmp	loop					;go to loop

exit:
	movzx	rax, al
	movzx	rbx, bl
	sub		rax, rbx			;al = al - bl
	ret
