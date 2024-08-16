#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the external function
extern size_t ft_strlen(const char *str);
extern char * ft_strcpy(char *dst, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);

int main() {
    // Call the assembly function
    const char *str = "Hello, World!";
    char *str2 = malloc(100);
    char *str3 = malloc(100);
    size_t len = ft_strlen(str);
    printf("Length: %zu\n", len);
    printf("%p %p\n", str2, ft_strcpy(str2, str));
    printf("%p %p\n", str3, strcpy(str3, str));    
    printf("lib String: %s\n", str3);
    printf("asm String: %s\n", str2);
    const char *str4 = "ABJ";
    const char *str5 = "ABC";
    printf("%d %d\n", strcmp(str4,str5), ft_strcmp(str4,str5));
    return 0;
}