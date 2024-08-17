;	char *ft_strdup(const char *s);
;	Input -> rdi = const char *s
;	Output -> rax = char *dst

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
	neg		rax
	mov		rdi, rax
	call	__errno_location wrt ..plt
	mov		[rax], rdi
	mov		rax, -1
	ret

;char *ft_strdup(const char *s) {
;    char *dup = malloc(strlen(s) + 1);
;    if (dup) {
;        strcpy(dup, s);
;    }
;    return dup;
;}

;char	*ft_strdup(const char *s1)
;{
;	void	*ptr;
;	size_t	bytes;
;	bytes = ft_strlen (s1) + 1;
;	ptr = (char *)malloc(bytes * (sizeof(*s1)));
;	if (ptr == NULL)
;		return (0);
;	ft_memcpy (ptr, s1, bytes);
;	return (ptr);
;}