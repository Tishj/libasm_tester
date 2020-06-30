/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 11:22:10 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/24 15:03:56 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <errno.h>
#include <tester.h>

int			main(int argc, char **argv)
{
	if (argc <= 1)
	{
		mandatory();
		bonus();
	}
	else if (argc >= 2)
		options(argc, argv);
	return (0);
}
