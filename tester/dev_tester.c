#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include "../libasm/libasm.h"

#define LONG_SIZE 100000000             // 100 MBytes

int	main(void)
{
	printf("\033[0;32mTest ft_strlen\033[0m\n");
	const char *str = "Hello, World!";
    printf("%s\n", str);
	printf("Standard function -> Length: %zu\n", strlen(str));
	printf("Assembly function -> Length: %zu\n\n", ft_strlen(str));

    printf("\033[0;32mTest ft_strlen (very long 100 MBytes)\033[0m\n");
    char *str10 = malloc(sizeof(char) * LONG_SIZE);
    memset(str10, 'A', LONG_SIZE);
    memset(str10 + LONG_SIZE - 1, 0, 1);
	printf("Standard function -> Length: %zu\n", strlen(str10));
	printf("Assembly function -> Length: %zu\n\n", ft_strlen(str10));

    printf("\033[0;32mTest ft_strcpy\033[0m\n");
    char *str2 = malloc(sizeof(char) * 100);
    char *str3 = malloc(sizeof(char) * 100);    
    printf("Standard function -> String: %s\n", strcpy(str2, str));
    printf("Standard function -> Length: %zu\n", strlen(str2));
    printf("Assembly function -> String: %s\n", ft_strcpy(str3, str));
    printf("Assembly function -> Length: %zu\n", ft_strlen(str3));
    printf("Assembly function -> Difference: %d \n\n", ft_strcmp(str2, str3));

    printf("\033[0;32mTest ft_strcpy (very long 100 MBytes)\033[0m\n");
    char *str11 = malloc(sizeof(char) * LONG_SIZE);
    char *str12 = malloc(sizeof(char) * LONG_SIZE);
    printf("Standard function -> Pointer: %p\n", strcpy(str11, str10));
    printf("Standard function -> Length: %zu\n", strlen(str11));
    printf("Assembly function -> Pointer: %p\n", ft_strcpy(str12, str10));
	printf("Assembly function -> Length: %zu\n", ft_strlen(str12));
    printf("Assembly function -> Difference: %d \n\n", ft_strcmp(str11, str12));

    printf("\033[0;32mTest ft_strcmp\033[0m\n");
    const char *str4 = "ABJ";
    const char *str5 = "ABC";    
    printf("Standard function -> Difference: %d \n", strcmp(str4,str5));
    printf("Assembly function -> Difference: %d \n\n", ft_strcmp(str4, str5));

    printf("\033[0;32mTest ft_write\033[0m\n");
    printf("Standard function -> Printed: %ld\n", write(1, "Hello, World!\n", 14));
    printf("Standard function -> Error number: %d\n", errno);
    printf("Standard function -> Error message: %s\n", strerror(errno));
    printf("Assembly function -> Printed: %ld\n", ft_write(1, "Hello, World!\n", 14));
    printf("Assembly function -> Error number: %d\n", errno);
    printf("Assembly function -> Error message: %s\n\n", strerror(errno));

    printf("\033[0;32mTest ft_write (to a file)\033[0m\n");
    int fd = open("file_test", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    printf("Standard function -> Printed: %ld\n", write(fd, "Standard Hello, World! ", 23));
    printf("Standard function -> Error number: %d\n", errno);
    printf("Standard function -> Error message: %s\n", strerror(errno));
    printf("Assembly function -> Printed: %ld\n", ft_write(fd, "Assembler Hello, World!", 23));
    printf("Assembly function -> Error number: %d\n", errno);
    printf("Assembly function -> Error message: %s\n\n", strerror(errno));
    close(fd);

    printf("\033[0;32mTest ft_read\033[0m\n");
    char *str6 = calloc(100, sizeof(char));
    char *str7 = calloc(100, sizeof(char));
    printf("Enter a text for comparison:\n");
    printf("Standard function -> Read: %ld\n", read(1, str6, 100));
    printf("Standard function -> Error number: %d\n", errno);
    printf("Standard function -> Error message: %s\n", strerror(errno));
    printf("Enter a text for comparison:\n");
    printf("Assembly function -> Read: %ld\n", ft_read(1, str7, 100));
    printf("Assembly function -> Error number: %d\n", errno);
    printf("Assembly function -> Error message: %s\n", strerror(errno));
    printf("Assembly function -> Difference: %d \n\n", ft_strcmp(str6, str7));

    printf("\033[0;32mTest ft_read (from a file)\033[0m\n");
    int fd2 = open("file_test", O_RDONLY);
    char *str15 = calloc(100, sizeof(char));    
    printf("Standard function -> Read: %ld\n", read(fd2, str15, 100));
    printf("Standard function -> String: %s\n", str15);
    printf("Standard function -> Error number: %d\n", errno);
    printf("Standard function -> Error message: %s\n", strerror(errno));
    close(fd2);
    int fd3 = open("file_test", O_RDONLY);
    char *str16 = calloc(100, sizeof(char));
    printf("Assembly function -> Read: %ld\n", ft_read(fd3, str16, 100));
    printf("Assembly function -> String: %s\n", str16);
    printf("Assembly function -> Error number: %d\n", errno);
    printf("Assembly function -> Error message: %s\n", strerror(errno));
    close(fd3);
    printf("Assembly function -> Difference: %d \n\n", ft_strcmp(str15, str16));

    printf("\033[0;32mTest ft_strdup\033[0m\n");
    char *str8 = strdup("Hello, World!");
    char *str9 = ft_strdup("Hello, World!");
    printf("Standard function -> String: %s\n", str8);
    printf("Standard function -> Length: %zu\n", strlen(str8));
    printf("Assembly function -> String: %s\n", str9);
	printf("Assembly function -> Length: %zu\n", ft_strlen(str9));
    printf("Assembly function -> Difference: %d \n\n", ft_strcmp(str8, str9));

    printf("\033[0;32mTest ft_strdup (very long 100 MBytes)\033[0m\n");
    char *str13 = strdup(str11);
    char *str14 = ft_strdup(str12);
    printf("Standard function -> Pointer: %p\n", str13);
    printf("Standard function -> Length: %zu\n", strlen(str13));
    printf("Assembly function -> Pointer: %p\n", str14);
	printf("Assembly function -> Length: %zu\n", ft_strlen(str14));
    printf("Assembly function -> Difference: %d \n\n", ft_strcmp(str13, str14));

    free(str2);
    free(str3);
    free(str6);
    free(str7);
    free(str8);
    free(str9);
    free(str10);
    free(str11);
    free(str12);
    free(str13);
    free(str14);
    free(str15);
    free(str16);
    return 0;
}
// make && gcc -Wall -Werror -Wextra dev_tester.c ../libasm/libasm.a && ./a.out
// make && gcc -Wall -Werror -Wextra dev_tester.c ../libasm/libasm.a && valgrind --leak-check=full ./a.out