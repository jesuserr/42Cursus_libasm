#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../libasm/libasm.h"

int	main(void)
{
	printf("\033[0;32mTest ft_strlen\033[0m\n");
	const char *str = "Hello, World!";
	printf("Standard function -> Length: %zu\n", strlen(str));
	printf("Assembly function -> Length: %zu\n\n", ft_strlen(str));

    printf("\033[0;32mTest ft_strcpy\033[0m\n");
    char *str2 = malloc(100);
    char *str3 = malloc(100);    
    printf("Standard function -> String: %s\n", strcpy(str2, str));
    printf("Assembly function -> String: %s\n\n", ft_strcpy(str3, str));

    printf("\033[0;32mTest ft_strcmp\033[0m\n");
    const char *str4 = "ABJ";
    const char *str5 = "ABC";    
    printf("Standard function -> Difference: %d \n", strcmp(str4,str5));
    printf("Assembly function -> Difference: %d \n\n", ft_strcmp(str4,str5));

    printf("\033[0;32mTest ft_write\033[0m\n");
    printf("Standard function -> Printed: %ld\n", write(1, "Hello, World!\n", 14));
    printf("Standard function -> Error number: %d\n", errno);
    printf("Standard function -> Error message: %s\n", strerror(errno));
    printf("Assembly function -> Printed: %ld\n", ft_write(1, "Hello, World!\n", 14));
    printf("Assembly function -> Error number: %d\n", errno);
    printf("Assembly function -> Error message: %s\n\n", strerror(errno));

    printf("\033[0;32mTest ft_read\033[0m\n");
    char *str6 = calloc(100, sizeof(char));
    char *str7 = calloc(100, sizeof(char));
    printf("Reading...\n");
    printf("Standard function -> Read: %ld\n", read(1, str6, 100));
    printf("Standard function -> Error number: %d\n", errno);
    printf("Standard function -> Error message: %s\n", strerror(errno));
    printf("Reading...\n");
    printf("Standard function -> Read: %ld\n", ft_read(1, str7, 100));
    printf("Assembly function -> Error number: %d\n", errno);
    printf("Assembly function -> Error message: %s\n", strerror(errno));
    printf("Comparison: %s\n\n", ft_strcmp(str6, str7) ? "Different" : "Equal");

    printf("\033[0;32mTest ft_strdup\033[0m\n");
    char *str8 = strdup("Hello, World!");
    printf("Standard function -> Error number: %d\n", errno);
    printf("Standard function -> Error message: %s\n", strerror(errno));
    char *str9 = ft_strdup(str8);
    printf("Assembly function -> Error number: %d\n", errno);
    printf("Assembly function -> Error message: %s\n", strerror(errno));
    printf("Address str8: %p\nAddress str9: %p\nContent str9: %s\n", str8, str9, str9);

    free(str2);
    free(str3);
    free(str6);
    free(str7);
    free(str8);
    free(str9);
    return 0;
}
// make && gcc -Wall -Werror -Wextra dev_tester.c ../libasm/libasm.a && ./a.out