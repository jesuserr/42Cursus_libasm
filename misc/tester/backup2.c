/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:15:33 by jesuserr          #+#    #+#             */
/*   Updated: 2024/09/04 15:05:19 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <errno.h>
#include "../libasm/libasm.h"

void	five_functions_tester(const char *test_str)
{
	char	*dst;
	char	*src;

	src = ft_strdup(test_str);
	dst = malloc(sizeof(char) * (ft_strlen(src) + 1));
	dst = ft_strcpy(dst, src);
	//printf("\nTest string: \"%s\"\n", test_str);
	if (ft_strcmp(src, dst) != 0)
		ft_write(1, "\033[0;31mKO\033[0m ", 15);
	else
		ft_write(1, "\033[0;32mOK\033[0m ", 15);
	free (dst);
	free (src);
}

void	ft_combined_tester(void)
{
	int			i;
	const char	*test_cases[] = {"",
		"Hello, World!", "This is a longer string to test the function.",
		"Special characters: !@#$%^&*()", "String with\nnewline and \ttabss",
		"String with\0nulls", "Unicode: \u03A9\u03B1\u03B2",
		"Very long string: Lorem ipsum dolor sit amet, consectetur adipiscing \
		elit. Phasellus semper, dolor ac accumsan luctus, sapien nibh malesuada \
		metus, sed blandit turpis metus non sem. In et varius eros. Sed ultricies \
		ante ac velit tempus, vel pulvinar arcu faucibus. Pellentesque laoreet sit \
		amet metus quis consectetur. In vitae hendrerit odio, ac convallis ligula. \
		Donec eleifend massa sed elit finibus facilisis. Proin congue dictum \
		elementum. Aliquam tincidunt quam at elit malesuada venenatis. Fusce \
		pellentesque lacus tellus, in fermentum turpis varius vitae. Vivamus non \
		purus sit amet lorem convallis pellentesque.",
		"This is a string with a double quote \"",
		"This is a string with a single quote '",
		"This is a string with a backslash and a double quote \\\"",
		"This is a string with a backslash and a single quote \\'",
		"This is a string with a backslash and a backslash \\\\", 0};

	i = 0;
	while (test_cases[i])
		five_functions_tester(test_cases[i++]);
}

int	main(void)
{
	printf("\033[H\033[J");
	printf("Combined tester (");
	printf("ft_strlen, ft_strcpy, ft_strcmp, ft_write and ft_strdup)\n");
	ft_combined_tester();
	printf("\n");
	return (0);
}
