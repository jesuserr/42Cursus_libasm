section .data
	text db "Hello, World!",10

section .text
	global _start

_start:	
	call _helloWorld
	mov rax, 60
	mov rdi, 0
	syscall

_helloWorld:
	mov rax, 1
	mov rdi, 1
	mov rsi, text
	mov rdx, 14
	syscall	
	ret

;nasm -f elf64 hello2.asm && ld hello2.o && ./a.out