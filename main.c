#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the external function
extern size_t ft_strlen(const char *str);
extern char * ft_strcpy(char *dst, const char *src);

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
    return 0;
}