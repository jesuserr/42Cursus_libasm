SECTION	.note.GNU-stack
	db 0

SECTION	.data

SECTION	.bss

SECTION	.text
	global	ft_strlen

ft_strlen:
	xor		rax, rax
.loop:
	cmp		byte [rdi + rax], 0
	jne		.inc
	ret
.inc:
	inc		rax
	jmp		.loop
	
