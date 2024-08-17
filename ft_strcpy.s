;	char	*ft_strcpy(char *dst, const char *src);
;	Input -> rdi = char *dst, rsi = const char *src
;	Output -> rax = char *dst

SECTION	.note.GNU-stack
	db 0

SECTION	.text
	global	ft_strcpy

ft_strcpy:
	xor		rcx, rcx
.loop:
	mov		bl, byte [rsi + rcx]
	mov		byte [rdi + rcx], bl
	inc		rcx
	cmp		bl, 0
	jne		.loop
	mov		rax, rdi
	ret