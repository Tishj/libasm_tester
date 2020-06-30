/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_lstsize.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 19:40:32 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/24 15:18:07 by tbruinem      ########   odam.nl         */
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

void	test_ft_list_size(char *p1)
{
	t_list	*head;
	size_t	out;
	int		size;
	int		i;

	i = 0;
	size = (p1) ? atoi(p1) : 10;
	head = NULL;
	printf("---LST_SIZE---\n");
	while (i < size)
	{
		ft_list_push_front(&head, strjoin("LIST-", itoa(i + 1)));
		i++;
	}
	printf("LIST: ");
	ft_list_print(head);
	out = ft_list_size(head);
	printf("OUT: %ld\n\n", out);
}
