/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:33:57 by cimogene          #+#    #+#             */
/*   Updated: 2019/12/10 18:34:01 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			choose_rotation(t_list *list, int aver)
{
	int		r;

	r = 0;
	while (list)
	{
		if (*list->content > aver)
		{
			r++;
			list = list->next;
		}
		else
			break ;
	}
	return (r);
}

void		init_iter(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		tmp->iter = 0;
		tmp = tmp->next;
	}
}

void		delete_list(t_list **list)
{
	if (!*list)
		return ;
	if ((*list)->next != NULL)
		delete_list(&(*list)->next);
	free((*list)->content);
	free(*list);
	*list = NULL;
}

void		sort_small_stack_a(t_list **list)
{
	if (count_all(*list) != 3)
	{
		if (*(*list)->content > *(*list)->next->content)
			list_swap(list, 'a');
		return ;
	}
	else
	{
		if (*(*list)->next->next->content < *(*list)->next->content)
		{
			if (*(*list)->next->content < *(*list)->content)
				list_swap(list, 'a');
			list_reverse_rotate(list, 'a');
		}
		if (*(*list)->content > *(*list)->next->content)
		{
			if (*(*list)->content < *(*list)->next->next->content)
				list_swap(list, 'a');
			else
				list_rotate(list, 'a');
		}
	}
}