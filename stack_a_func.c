/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:32:55 by cimogene          #+#    #+#             */
/*   Updated: 2019/12/10 18:33:02 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sort_check_a(t_list *list_a, t_list *list_b)
{
	t_list *max_b;

	max_b = find_max(list_b);
	while (list_a && list_a->next)
	{
		if (*list_a->content < *list_a->next->content
			&& (!list_b || *list_a->content > *max_b->content))
			list_a = list_a->next;
		else
			break ;
	}
	if (list_a && !list_a->next)
		return (1);
	return (0);
}

int			check_aver_a(t_list *list, int aver)
{
	while (list)
	{
		if (*(int*)list->content <= aver)
			return (0);
		else
			list = list->next;
	}
	return (1);
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

void		push_swap_a(t_list **lst_a, t_list **lst_b, int iter_base, int iter)
{
	int		aver;

	aver = median_pivot(*lst_a, iter_base);
	while (last_elem(*lst_a)->iter != 0 && !sort_check_a(*lst_a, *lst_b))
		list_reverse_rotate(lst_a, 'a');
	if (count_all(*lst_a) == 3 || *(*lst_a)->content > *(*lst_a)->next->content)
		sort_small_stack_a(lst_a);
	while (!check_aver_a(*lst_a, aver) && !sort_check_a(*lst_a, *lst_b))
	{
		if ((*(*lst_a)->content <= aver))
		{
			(*lst_a)->iter = iter;
			list_push(lst_b, lst_a, 'b');
		}
		else
		{
			if (count_all(*lst_a) == 3)
				sort_small_stack_a(lst_a);
			else if (choose_rotation(*lst_a, aver) <= count_all(*lst_a) / 2)
				list_rotate(lst_a, 'a');
			else
				list_reverse_rotate(lst_a, 'a');
		}
	}
}
