/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 12:30:57 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/24 16:24:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>

# include <libasm.h>

enum	e_options
{
	ALL,
	MANDATORY,
	BONUS,
	STRCMP,
	STRLEN,
	STRCPY,
	STRDUP,
	STRCHR,
	READ,
	WRITE,
	LSTSIZE,
	LSTSORT,
	LSTREMOVEIF,
	LSTPUSHFRONT,
	ATOIBASE,
	ITOABASE,
};

void			options(int argc, char **args);
void			mandatory(void);
char			*vname(int version);
void			bonus(void);
void			cleanup(t_list *head);
char			*itoa(int num);

typedef void		(*t_singleparamf)(char *p1);
typedef void		(*t_doubleparamf)(char *p1, char *p2);

void			test_ft_strcmp(char *p1, char *p2);
void			test_ft_strlen(char *p1);
void			test_ft_strcpy(char *p1, char *p2);
void			test_ft_strdup(char *p1);
void			test_ft_write(char *p1, char *p2);
void			test_ft_read(char *p1);

void			test_ft_strchr(char *p1, char *p2);
void			test_ft_itoa_base(char *p1, char *p2);
void			test_ft_atoi_base(char *p1, char *p2);
void			test_ft_list_sort(char *p1);
void			test_ft_list_size(char *p1);
void			test_ft_list_remove_if(char *p1, char *p2);
void			test_ft_list_push_front(char *p1);

#endif
