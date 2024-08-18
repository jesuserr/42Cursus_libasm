;	char *ft_strdup(const char *s);
;	Input -> rdi = const char *s
;	Output -> rax = char *dst
;
;	Malloc does not set errno directly. Instead, it returns NULL to indicate
;	an error. To set errno, we must call __errno_location and set the value

SECTION	.note.GNU-stack
	db 0

SECTION	.text
	global	ft_strdup
	extern	ft_strlen
	extern	ft_strcpy
	extern	malloc
	extern	__errno_location

ft_strdup:
	push	rdi
	call	ft_strlen
	mov		rdi, rax
	inc		rdi
	call	malloc wrt ..plt
	cmp		rax, 0
	je		.error
	mov		rdi, rax
	pop		rsi
	call	ft_strcpy
	ret
.error:
	pop		rsi						; clear the stack on the error path
	call	__errno_location wrt ..plt
	mov		dword [rax], 12			; errno is ENOMEM (dword becasue an integer)
	xor		rax, rax				; return NULL
	ret