/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_write.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 19:43:33 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/24 13:13:42 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <tester.h>

void	test_ft_write(char *p1, char *p2)
{
	char	*str;
	int		version;
	int		out[2];
	int		fd;

	fd = (p2) ? open(p2, O_RDWR | O_CREAT, 666) : 1;
	str = (p1) ? p1 : "Yeet";
	version = REAL;
	printf("---WRITE---\n");
	while (version < 2)
	{
		write(fd, vname(version), ft_strlen(vname(version)));
		out[version] = (version == REAL) ?
			write(fd, str, strlen(str)) : ft_write(fd, str, strlen(str));
		printf(" | OUT: %d | ERRNO: %d\n", out[version], errno);
		version++;
	}
	write(1, "\n", 1);
}
