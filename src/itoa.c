/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   itoa.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 15:13:05 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/24 15:13:53 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <tester.h>

static int		numsize(int num)
{
	int size;

	size = (num > 0) ? 0 : 1;
	num = (num >= 0) ? num : -num;
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}

static void		numfill(char *new, int num, int size)
{
	while (size >= 0)
	{
		new[size] = (num % 10) + '0';
		num /= 10;
		size--;
	}
}

char			*itoa(int num)
{
	int		size;
	char	*new;

	size = numsize(num);
	new = malloc(sizeof(char) * (size + 1));
	new[size] = 0;
	numfill(new, (num >= 0) ? num : -num, size - 1);
	if (num < 0)
		new[0] = '-';
	return (new);
}
