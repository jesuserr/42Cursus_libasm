SECTION	.data
	EatMsg:	db "Eat at Joe's!",10
	EatLen:	equ $-EatMsg

SECTION	.bss

SECTION	.text

global	_start

_start:
	push	rbp
	mov		rbp,rsp
	mov		rax,1
	mov		rdi,1
	mov		rsi,EatMsg
	mov		rdx,EatLen
	syscall

	mov		rax,60
	mov		rdi,0
	syscall

;nasm -f elf64 -g -F dwarf eatsyscall.asm && ld -o eatsyscall eatsyscall.o