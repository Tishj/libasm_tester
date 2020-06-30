/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strcpy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 19:42:16 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/23 18:33:14 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <tester.h>

void	test_ft_strcpy(char *p1, char *p2)
{
	char	*dst_origin;
	char	*dest;
	char	*src;
	char	*ret[2];
	int		version;

	dst_origin = (p1) ? p1 : "lala";
	src = (p2) ? p2 : "grr";
	if (strcmp(dst_origin, "NULL") == 0)
		dst_origin = NULL;
	if (strcmp(src, "NULL") == 0)
		src = NULL;
	printf("---STRCPY---\n");
	version = REAL;
	while (version < 2)
	{
		dest = (dst_origin) ? strdup(dst_origin) : NULL;
		ret[version] = NULL;
		printf("%sBEFORE: DEST: %s | SRC: %s | OUT: %p\n", vname(version), dest, src, ret[version]);
		ret[version] = (version == REAL) ? strcpy(dest, src) : ft_strcpy(dest, src);
		printf("%sAFTER: DEST: %s | SRC: %s | OUT: %p\n", vname(version), dest, src, ret[version]);
		write(1, "\n", 1);
		free(dest);
		version++;
	}
}
