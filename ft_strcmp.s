section	.text
global _ft_strcmp

;rdi = s1, rsi = s2
_ft_strcmp:
	mov r8, 0

loop:
	mov	r9, qword[rdi + r8]		;r9 = s1[o + r8]
	mov	r10, qword[rsi + r8]		;r10 = s2[o + r8]
	cmp	r9, r10					;r9 == r10?
	jne	exit					;if FALSE go to exit
	inc	r8						;r8++
	jmp	loop					;go to loop

exit:
	sub	r9, r10					;r9 = r9 - r10
	mov	rax, r9					;rax = r9
	ret
