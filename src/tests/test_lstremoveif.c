/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_lstremoveif.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 19:37:34 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/23 20:37:48 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <tester.h>
#include <time.h>
#include <stdlib.h>

void	test_ft_list_remove_if(char *p1, char *p2)
{
	t_list		*head = NULL;
	const char	*data[] = {
	[0] = "DELETE_ME",
	[1] = "list",
	};
	int			counter[2];
	int			i;
	int			id;
	int			total;

	counter[0] = (p1) ? (atoi(p1)) : 5;
	counter[1] = (p2) ? atoi(p2) : 3;
	srand(time(NULL));
	total = counter[0] + counter[1];
	i = 0;
	id = (rand() % 2 == 0) ? 1 : 0;
	while (i < total)
	{
		if (counter[0] && counter[1])
		{
			if (i % 2)
			{
				ft_list_push_front(&head, (char *)data[id]);
				counter[id]--;
			}
			else
			{
				ft_list_push_front(&head, (char *)data[!id]);
				counter[!id]--;
			}
		}
		else if (counter[1])
			ft_list_push_front(&head, "list");
		else if (counter[0])
			ft_list_push_front(&head, "DELETE_ME");
		i++;
	}
	printf("---LIST_REMOVE_IF---\n");
	printf("BEFORE: ");
	ft_list_print(head);
	ft_list_remove_if(&head, "DELETE_ME", &ft_strcmp);
	printf("AFTER: ");
	ft_list_print(head);
	printf("\n");
}
