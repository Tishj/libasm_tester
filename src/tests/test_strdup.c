/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strdup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 19:41:28 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/23 18:13:19 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <tester.h>

void	test_ft_strdup(char *p1)
{
	char	*str;
	char	*dup;
	int		version;

	str = (p1) ? p1 : "klwjdf";
	if (strcmp(str, "NULL") == 0)
		str = NULL;
	version = REAL;
	printf("---STRDUP---\n");
	while (version < 2)
	{
		dup = NULL;
		dup = (version == REAL) ? strdup(str) : ft_strdup(str);
		printf("%sSTR: %s %p| DUP: %s %p\n", vname(version), str, str, dup, dup);
		free(dup);
		version++;
	}
	write(1, "\n", 1);
}
