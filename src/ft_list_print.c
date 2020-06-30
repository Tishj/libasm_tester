/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_print.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 20:09:15 by tbruinem       #+#    #+#                */
/*   Updated: 2020/03/12 20:23:26 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"

void	ft_list_print(t_list *head)
{
	while (head)
	{
		printf("%s", (char *)head->data);
		head = head->next;
		if (head)
			printf("->");
		else
			printf("\n");
	}
}
