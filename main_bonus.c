/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:03:55 by vping             #+#    #+#             */
/*   Updated: 2021/03/26 18:37:55 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

t_list	*list_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int		list_size(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_list	*list_new(void *data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	list_add_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = list_last(*lst);
	last->next = new;
}

void	ft_list_size_bonus(void)
{
	t_list	*list;
	int		x;

	list = NULL;
	x = 10;
	while (x--)
		list_add_back(&list, list_new(&x));
	if (list_size(list) == ft_list_size(list))
		printf("" GREEN "ft_list_size_bonus is [OK]\n" RESET "");
	else
		printf("" RED "ft_list_size_bonus is [KO]\n" RESET "");
}

void	ft_list_push_front_bonus(void)
{
	t_list	*list;
	char	*new;

	list = NULL;
	new = strdup("aue");
	list_add_back(&list, list_new("123"));
	list_add_back(&list, list_new("456"));
	ft_list_push_front(&list, new);
	if (!new && !list->data)
	{
		printf("" GREEN "ft_list_push_front is [OK]\n" RESET "");
		return ;
	}
	if (!strcmp(list->data, (char*)new))
		printf("" GREEN "ft_list_push_front is [OK]\n" RESET "");
	else
		printf("" RED "ft_list_push_front is [KO]\n" RESET "");
}

int		main(void)
{
	ft_list_size_bonus();
	ft_list_push_front_bonus();
}
