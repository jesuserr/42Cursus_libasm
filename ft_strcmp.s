;	int ft_strcmp(const char *s1, const char *s2);
;	Input -> rdi = const char *s1, rsi = const char *s2
;	Output -> rax = int
;	strcmp() returns an integer indicating the result of the comparison, as follows:
;	•  0, if the s1 and s2 are equal;
;	•  a negative value if s1 is less than s2;
;	•  a positive value if s1 is greater than s2.

SECTION	.note.GNU-stack
	db 0

SECTION	.data

SECTION	.bss

SECTION	.text
	global	ft_strcmp

ft_strcmp:
	xor		rcx, rcx
.loop:
	mov		al, byte [rdi + rcx]
	mov		bl, byte [rsi + rcx]
	cmp		al, 0
	jne		.continue
	cmp		bl, 0
	jne		.continue
	xor		rax, rax
	ret
.continue:
	inc		rcx
	cmp		bl, al
	je		.loop
	sub		al, bl
	movsx	rax, al
	ret