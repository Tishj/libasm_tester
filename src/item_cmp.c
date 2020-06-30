/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   item_cmp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 19:44:52 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/21 18:15:26 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <tester.h>

int		ft_item_cmp(void *item1, void *item2)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen((char *)item1);
	len2 = ft_strlen((char *)item2);
	if (len1 > len2)
		return (1);
	return (0);
}
