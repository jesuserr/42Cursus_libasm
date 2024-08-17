;	ssize_t write(int fd, const void buf[.count], size_t count);
;	Input -> rdi = int fd, rsi = const void buf[.count], rdx = size_t count
; 	Output -> ssize_t return value = number of bytes written or -1 on error
;
;	int * __errno_location(void);
;	The __errno_location() function shall return the address
;	of the errno variable for the current thread.
;
;	wrt ..plt: This stands for "with respect to the Procedure Linkage
;	Table (PLT)". The PLT is used in dynamically linked executables 
;	to resolve function addresses at runtime.

SECTION	.note.GNU-stack
	db 0

SECTION	.text
	global	ft_write
	extern	__errno_location

ft_write:
    mov		rax, 1
	syscall
	cmp		rax, 0
	js		.error
	ret
.error:
	neg		rax
	mov		rdi, rax
	call	__errno_location wrt ..plt
	mov		[rax], rdi
	mov		rax, -1
	ret