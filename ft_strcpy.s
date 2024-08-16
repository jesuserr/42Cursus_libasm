;	char	*ft_strcpy(char *dst, const char *src);
;	Input -> rdi = char *dst, rsi = const char *src
;	Output -> rax = char *dst

SECTION	.note.GNU-stack
	db 0

SECTION	.data

SECTION	.bss

SECTION	.text
	global	ft_strcpy

ft_strcpy:
	xor		rax, rax
.loop:
	cmp		byte [rsi + rax], 0
	je		.end
	mov		bl, byte [rsi + rax]
	mov		byte [rdi + rax], bl
	inc		rax
	jmp		.loop
.end:
	mov		byte [rdi + rax], 0
	mov		rax, rdi
	ret