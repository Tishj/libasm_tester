/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 12:30:57 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/06/21 18:24:55 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>

enum	e_versions
{
	REAL,
	MINE,
};

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

int				ft_item_cmp(void *item1, void *item2);

extern void		ft_list_sort(t_list **begin, int (*cmp)());
extern void		ft_list_print(t_list *head);
extern void		ft_list_remove_if(t_list **begin, void *data_ref, int (*cmp)());
extern size_t	ft_write(int fd, void *buf, size_t size);
extern size_t	ft_read(int fd, void *buf, size_t size);
extern size_t	ft_strlen(char *str);
extern char		*ft_strcpy(char *dest, char *src);
extern int		ft_strcmp(char *s1, char *s2);
extern char		*ft_strdup(char *str);
extern char		*ft_strchr(char *str, char c);
extern void		ft_list_push_front(t_list **head, void *data);
extern size_t	ft_list_size(t_list *begin);
extern int		ft_atoi_base(char *str, char *base);
extern char		*ft_itoa_base(int n, char *base);

#endif
