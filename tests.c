#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "libasm.h"

int main() {
    const char *str = "Hello, World!";
    size_t len = ft_strlen(str);
    printf("Length: %zu\n\n", len);

    char *str2 = malloc(100);
    char *str3 = malloc(100);
    printf("%p %p\n", str2, ft_strcpy(str2, str));
    printf("%p %p\n", str3, strcpy(str3, str));    
    printf("lib String: %s\n", str3);
    printf("asm String: %s\n\n", str2);

    //const char *str4 = "ABJ";
    //const char *str5 = "ABC";
    const char *str4 = "\xfe";
    const char *str5 = "\xfe\xff";
    printf("%d %d\n\n", strcmp(str4,str5), ft_strcmp(str4,str5));

    printf("%ld\n", write(1, "Hello, World!\n", 14));
    printf("%d, lib write error: %s\n", errno, strerror(errno));        
    printf("%ld\n", ft_write(1, "Hello, World!\n", 14));
    printf("%d, lib write error: %s\n\n", errno, strerror(errno));

    char *str6 = calloc(100, sizeof(char));
    char *str7 = calloc(100, sizeof(char));
    printf("%ld\n", read(0, str6, 100));
    printf("%s\n", str6);
    printf("%ld\n", ft_read(0, str7, 100));
    printf("%s\n", str7);

    char *str8 = strdup("Hello, World!");
    char *str9 = ft_strdup(str8);
    if (!str9)
    {
        printf("%d, %s\n\n", errno, strerror(errno));
        exit(1);
    }
    printf("%p %p %s\n", str8, str9, str9);

    free(str2);
    free(str3);
    free(str6);
    free(str7);
    free(str8);
    free(str9);
    return 0;
}

// make && gcc -Wall -Werror -Wextra tests.c libasm.a && ./a.out
