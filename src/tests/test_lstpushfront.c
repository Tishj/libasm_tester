/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_lstpushfront.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 19:41:06 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/24 15:16:07 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <tester.h>

static char	*strjoin(char *s1, char *s2)
{
	char	*new;

	new = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	strcpy(new, s1);
	strcat(new, s2);
	free(s2);
	return (new);
}

void	test_ft_list_push_front(char *p1)
{
	t_list	*head;
	int		size;
	int		i;

	i = 0;
	size = (p1) ? atoi(p1) : 5;
	printf("---LST_PUSHFRONT---\n");
	head = NULL;
	while (i < size)
	{
		ft_list_push_front(&head, strjoin("LIST-", itoa(i + 1)));
		i++;
	}
	printf("LIST: ");
	ft_list_print(head);
	cleanup(head);
	printf("\n");
}
