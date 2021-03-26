/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:05:16 by vping             #+#    #+#             */
/*   Updated: 2021/03/26 18:41:19 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

ssize_t				ft_read(int fildes, void *buf, size_t nbyte);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *s);
ssize_t				ft_write(int fildes, const void *buf, size_t nbyte);
char				*ft_strdup(const char *s1);
int					ft_list_size(t_list *lst);
void				ft_list_push_front(t_list **begin_list, void *data);

#endif
