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
	mov		dl, byte [rsi + rcx]
	mov		byte [rdi + rcx], dl
	inc		rcx
	cmp		dl, 0
	jne		.loop
	mov		rax, rdi
	ret