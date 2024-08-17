;	size_t	ft_strlen(const char *s);
;	Input -> rdi = const char *s
;	Output -> rax = size_t

SECTION	.note.GNU-stack
	db 0

SECTION	.text
	global	ft_strlen

ft_strlen:
	mov		rax, -1
.loop:
	inc		rax
	cmp		byte [rdi + rax], 0
	jne		.loop
	ret