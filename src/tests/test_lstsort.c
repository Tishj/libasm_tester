/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_lstsort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 19:38:57 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/30 14:27:02 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <tester.h>
#include <time.h>
#include <stdlib.h>

int			exists(t_list *head, char *str)
{
	while (head)
	{
		if (strcmp(str, (char *)head->data) == 0)
			return (1);
		head = head->next;
	}
	return (0);
}

void		cleanup(t_list *head)
{
	t_list *del;

	while (head)
	{
		del = head;
		head = head->next;
		free(del->data);
		free(del);
	}
}

int			numcmp(char *s1, char *s2)
{
	int ret;

	if (!s1 || !s2)
		return (0);
	ret = atoi(s1) - atoi(s2);
	if (ret > 0)
		ret = 1;
	else if (ret < 0)
		ret = 0;
	return (ret);
}

void		test_ft_list_sort(char *p1)
{
	t_list	*head = NULL;
	size_t	size;
	char	*str;
	size_t	stuck;
	size_t	i;

	stuck = 0;
	size = (p1) ? atoi(p1) : 5;
	i = 0;
	while (i < size)
	{
		srand(time(NULL) + stuck);
		str = itoa(rand() % (size));
		while (exists(head, str))
		{
			free(str);
			srand(time(NULL));
			str = itoa(rand() % (size));
			stuck++;
		}
		ft_list_push_front(&head, str);
		i++;
	}
	printf("---LST_SORT---\n");
	printf("BEFORE:\n");
	ft_list_print(head);
	ft_list_sort(&head, &ft_strcmp);
	printf("AFTER:\n");
	ft_list_print(head);
	cleanup(head);
	printf("\n");
}
