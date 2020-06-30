/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strcmp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 19:41:50 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/24 15:05:14 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <tester.h>

void	test_ft_strcmp(char *p1, char *p2)
{
	char	*s1;
	char	*s2;
	int		out[2];
	int		version;

	s1 = (p1) ? p1 : "lala";
	s2 = (p2) ? p2 : "lalb";
	if (strcmp(s1, "NULL") == 0)
		s1 = NULL;
	if (strcmp(s2, "NULL") == 0)
		s2 = NULL;
	version = REAL;
	printf("---STRCMP---\n");
	while (version < 2)
	{
		out[version] = (version == REAL) ? strcmp(s1, s2) : ft_strcmp(s1, s2);
		printf("%sSTR1: %s | STR2: %s | OUT: %d\n", vname(version), s1, s2, out[version]);
		version++;
	}
	write(1, "\n", 1);
}
