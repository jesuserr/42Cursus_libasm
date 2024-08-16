;	ssize_t write(int fd, const void buf[.count], size_t count);
;	Input -> rdi = int fd, rsi = const void buf[.count], rdx = size_t count
; 	Output -> ssize_t return value = number of bytes written or -1 on error

SECTION	.note.GNU-stack
	db 0

SECTION	.data

SECTION	.bss

SECTION	.text
	global	ft_write

ft_write:
    mov		rax, 1
	syscall
	cmp		rax, 0
	js		.error
	ret
.error:
	mov		rax, -1
	ret
