SECTION	.note.GNU-stack
	db 0

SECTION	.data
	EatMsg:	db "Eat at Joe's!",10
	EatLen:	equ $-EatMsg

SECTION	.bss

SECTION	.text
	global	ft_strlen

ft_strlen:
	push	rbp
	mov		rbp,rsp
	mov		rax,1
	mov		rdi,1
	lea		rsi,[rel EatMsg]	; Use of relative addressing for position-independent code
	mov		rdx,EatLen
	syscall

	mov		rax,60
	mov		rdi,0
	syscall

;nasm -f elf64 -g -F dwarf ft_strlen.s && ld -o ft_strlen ft_strlen.o

;nasm -f elf64 ft_strlen.s && gcc main.c ft_strlen.o && ./a.out