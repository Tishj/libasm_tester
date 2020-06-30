/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strchr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 19:39:48 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/23 22:42:27 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <tester.h>

void	test_ft_strchr(char *p1, char *p2)
{
	char	*str;
	char	c;
	int		version;
	char	*ret[2];

	str = (p1) ? p1 : "lalabal";
	c = (p2 && *p2) ? *p2 : 'b';
	if (strcmp(str, "NULL") == 0)
		str = NULL;
	printf("---STRCHR---\n");
	version = REAL;
	while (version < 2)
	{
		ret[version] = (version == REAL) ? strchr(str, c) : ft_strchr(str, c);
		printf("%sSTR: %s | CHR: %c | RET: %s\n", vname(version), str, c, ret[version]);
		version++;
	}
	write(1, "\n", 1);
}
