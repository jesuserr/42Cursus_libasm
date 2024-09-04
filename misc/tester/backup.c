/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:15:33 by jesuserr          #+#    #+#             */
/*   Updated: 2024/09/04 14:44:15 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <errno.h>
#include "../libasm/libasm.h"

void	test_1(const char *str)
{
	if (strlen(str) != ft_strlen(str))
		printf("\033[0;31mKO\033[0m ");
	else
		printf("\033[0;32mOK\033[0m ");
}

void	ft_strlen_tester(void)
{
	test_1("");
	test_1("Hello, World!");
	test_1("This is a longer string to test the function.");
	test_1("Special characters: !@#$%^&*()");
	test_1("String with\nnewline and \ttabss");
	test_1("String with\0nulls");
	test_1("Unicode: \u03A9\u03B1\u03B2");
	test_1("Very long string: Lorem ipsum dolor sit amet, consectetur adipiscing \
	elit. Phasellus semper, dolor ac accumsan luctus, sapien nibh malesuada \
	metus, sed blandit turpis metus non sem. In et varius eros. Sed ultricies \
	ante ac velit tempus, vel pulvinar arcu faucibus. Pellentesque laoreet sit \
	amet metus quis consectetur. In vitae hendrerit odio, ac convallis ligula. \
	Donec eleifend massa sed elit finibus facilisis. Proin congue dictum \
	elementum. Aliquam tincidunt quam at elit malesuada venenatis. Fusce \
	pellentesque lacus tellus, in fermentum turpis varius vitae. Vivamus non \
	purus sit amet lorem convallis pellentesque.");
	test_1("This is a string with a double quote \"");
	test_1("This is a string with a single quote '");
	test_1("This is a string with a backslash and a double quote \\\"");
	test_1("This is a string with a backslash and a single quote \\'");
	test_1("This is a string with a backslash and a backslash \\\\");
}

void	ft_strcpy_and_ft_strcmp_tester(void)
{
	char	*src="Hello, World!";
	char	*dst;

	dst = malloc(sizeof(char) * (ft_strlen(src) + 1));
	dst = ft_strcpy(dst, src);
	if (ft_strcmp(src, dst) != 0)
		printf("\033[0;31mKO\033[0m ");
	else
		printf("\033[0;32mOK\033[0m ");
}

int	main(void)
{
	printf("\033[H\033[J");
	printf("Testing ft_strlen function:\n");
	ft_strlen_tester();
	printf("\nTesting ft_strcpy function:\n");	
	ft_strcpy_and_ft_strcmp_tester();
	printf("\n");
	return (0);
}
