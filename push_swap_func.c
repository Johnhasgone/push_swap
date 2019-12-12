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

void		push_swap_quick_sort(t_list **list_a, t_list **list_b)
{
	int		iter_base;
	int		iter;

	init_iter(list_a);
	iter = 0;
	while (!sort_check_a(*list_a, *list_b) || *list_b)
	{
		iter_base = (*list_a)->iter;
		while (!sort_check_a(*list_a, *list_b))
			push_swap_a(list_a, list_b, iter_base, ++iter);
		if (*list_b)
			push_swap_b(list_a, list_b);
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

void		push_swap_b(t_list **list_a, t_list **list_b)
{
	int aver;
	int iter_base;
	int i;

	i = 0;
	iter_base = (*list_b)->iter;
	aver = median_pivot(*list_b, iter_base);
	while (!check_aver_b(*list_b, aver))
	{
		while (last_number(*list_b) > *(*list_b)->content
			   && *(*list_b)->content >= aver)
			list_reverse_rotate(list_b, 'b');
		if ((*list_b)->iter == iter_base && *(*list_b)->content >= aver)
			list_push(list_a, list_b, 'a');
		else
		{
			list_rotate(list_b, 'b');
			i++;
		}
	}
	if (count_all(*list_b) > count_iter_base(*list_b, iter_base))
	{
		while (i-- > 0)
			list_reverse_rotate(list_b, 'b');
	}
}

int			median_pivot(t_list *list, int iteration)
{
	t_list	*pivot;

	pivot = list;
	while (pivot)
	{
		if (count_iter_base(list, iteration) % 2 == 0)
		{
			if (count_iter_base(list, iteration) / 2 ==
				select_pivot(pivot, list, iteration))
				return (*pivot->content);
		}
		else if (count_iter_base(list, iteration) % 2 == 1)
		{
			if (count_iter_base(list, iteration) / 2 + 1 ==
				select_pivot(pivot, list, iteration))
				return (*pivot->content);
		}
		pivot = pivot->next;
	}
	return (0);
}

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

