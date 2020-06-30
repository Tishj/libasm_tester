/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 18:06:34 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/23 19:50:41 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <tester.h>

void		bonus(void)
{
	printf("~~~~BONUS FUNCTIONS~~~~\n\n");
	test_ft_list_push_front(NULL);
	test_ft_list_size(NULL);
	test_ft_strchr(NULL, NULL);
	test_ft_atoi_base(NULL, NULL);
	test_ft_itoa_base(NULL, NULL);
	test_ft_list_sort(NULL);
	test_ft_list_remove_if(NULL, NULL);
}
