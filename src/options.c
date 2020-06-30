/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 18:56:57 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/24 15:29:55 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <ctype.h>
#include <tester.h>

void		strtolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = tolower(str[i]);
		i++;
	}
}

static int	str2cmp(char **str2, char *str)
{
	int	i;

	i = 0;
	while (str2[i])
	{
		if (strcmp(str2[i], str) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int			isfunct(char *str, char **options, int *option)
{
	char	*funct;
	int		tmp;

	funct = malloc(strlen(str) + 3 + 1);
	strcpy(funct, "ft_");
	strcat(funct, str);
	if (option)
		*option = str2cmp(options, funct);
	else
		tmp = str2cmp(options, funct);
	free(funct);
	return ((option) ? *option : tmp);
}

void		run_funct(int *i, int option, char **args, char **options)
{
	const static t_singleparamf	p1functs[17] = {
	[STRLEN] = &test_ft_strlen,
	[STRDUP] = &test_ft_strdup,
	[READ] = &test_ft_read,
	[LSTSORT] = &test_ft_list_sort,
	[LSTSIZE] = &test_ft_list_size,
	[LSTPUSHFRONT] = &test_ft_list_push_front,
	};
	const static t_doubleparamf	p2functs[17] = {
	[LSTREMOVEIF] = &test_ft_list_remove_if,
	[WRITE] = &test_ft_write,
	[STRCMP] = &test_ft_strcmp,
	[STRCPY] = &test_ft_strcpy,
	[STRCHR] = &test_ft_strchr,
	[ITOABASE] = &test_ft_itoa_base,
	[ATOIBASE] = &test_ft_atoi_base,
	};
	char						*params[2];

	params[0] = (args[*i + 1] && isfunct(args[*i + 1], options, NULL) == -1) ? args[*i + 1] : NULL;
	params[1] = (args[*i + 1] && args[*i + 2] && isfunct(args[*i + 2], options, NULL) == -1) ? args[*i + 2] : NULL;
	if (p1functs[option])
	{
		p1functs[option](params[0]);
		*i += 1 + ((params[0]) ? 1 : 0);
	}
	else if (p2functs[option])
	{
		p2functs[option](params[0], params[1]);
		*i += 1 + ((params[0]) ? 1 : 0) + ((params[1]) ? 1 : 0);
	}
	else
	{
		if (option == MANDATORY)
			mandatory();
		if (option == BONUS)
			bonus();
		if (option == ALL)
		{
			mandatory();
			bonus();
		}
		*i += 1;
	}
}

void	options(int argc, char **args)
{
	const char	*options[17] = {
		[ALL] = "all",
		[MANDATORY] = "mandatory",
		[BONUS] = "bonus",
		[STRLEN] = "ft_strlen",
		[STRCPY] = "ft_strcpy",
		[STRCMP] = "ft_strcmp",
		[STRCHR] = "ft_strchr",
		[STRDUP] = "ft_strdup",
		[READ] = "ft_read",
		[WRITE] = "ft_write",
		[LSTPUSHFRONT] = "ft_list_push_front",
		[LSTREMOVEIF] = "ft_list_remove_if",
		[LSTSIZE] = "ft_list_size",
		[LSTSORT] = "ft_list_sort",
		[ATOIBASE] = "ft_atoi_base",
		[ITOABASE] = "ft_itoa_base",
	};
	char		*str;
	int			option;
	int			i;

	i = 0;
	while (i < argc && args[i])
	{
		str = strdup(args[i]);
		option = str2cmp((char **)options, str);
		if (option != -1)
			run_funct(&i, option, args, (char **)options);
		else
		{
			if (isfunct(str, (char **)options, &option) != -1)
				run_funct(&i, option, args, (char **)options);
			else
				i++;
		}
		free(str);
	}
}
