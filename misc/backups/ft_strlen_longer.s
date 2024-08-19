;	size_t	ft_strlen(const char *s);
;	Input -> rdi = const char *s
;	Output -> rax = size_t

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
	je		.end
	inc		rax
	jmp		.loop
.end:
	ret