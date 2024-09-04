;	char *ft_strdup(const char *s);
;	Input -> rdi = const char *s
;	Output -> rax = char *dst
;
;	The standard strdup function does not check if its argument is NULL.
;	If you pass NULL to strdup, it will likely cause a segmentation fault
;	because it will attempt to dereference the NULL pointer. Therefore not
;	implemented in this function either.
;
;	Malloc does not set errno directly. Instead, it returns NULL to indicate
;	an error. To set errno, we must call __errno_location and set the value
;	provoKe malloc error -> mov		rdi, 1024 * 1024 * 1024 * 1024
;
;	1. Caller-Saved Registers: These registers are not preserved across function
;	calls. If the caller wants to preserve their values, it must save them
;	before the call and restore them afterward.
;	rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11
;
;	2. Callee-Saved Registers: These registers must be preserved by the callee.
;	If the callee wants to use them, it must save their values before
;	overwriting them and restore them before returning.
;	rbx, rbp, r12, r13, r14, r15

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
	mov		dword [rax], 12			; errno is ENOMEM (dword -> 32 bits integer)
	xor		rax, rax				; return NULL
	ret