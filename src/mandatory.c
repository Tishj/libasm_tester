/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandatory.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 18:02:35 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/24 13:09:52 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <errno.h>
#include <tester.h>

void	mandatory(void)
{
	printf("~~~~MANDATORY FUNCTIONS~~~~\n\n");
	test_ft_write(NULL, NULL);
	test_ft_read(NULL);
	test_ft_strlen(NULL);
	test_ft_strcpy(NULL, NULL);
	test_ft_strcmp(NULL, NULL);
	test_ft_strdup(NULL);
}
