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
	mov		bl, byte [rsi + rcx]
	mov		byte [rdi + rcx], bl
	inc		rcx
	cmp		bl, 0
	jne		.loop
	mov		rax, rdi
	ret

;	size_t	i;
;	i = 0;
;	while ((s1[i] != '\0' || s2[i] != '\0')))
;	{
;		if (s1[i] == s2[i])
;			i++;
;		else
;			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
;	}
;	return (0);