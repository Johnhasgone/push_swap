/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:38:54 by cimogene          #+#    #+#             */
/*   Updated: 2019/12/01 16:39:11 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			last_number(t_list *list)
{
	while (list->next)
		list = list->next;
	return (*(int*)list->content);
}

void		push_swap_a(t_list **list_a, t_list **list_b)
{
	int		last_num_a;

	last_num_a = last_number(*list_a);
	if (last_num_a < LIST_A->content && last_num_a < LIST_A->next->content)
	{
		list_reverse_rotate(list_a);
		write(1, "rra\n", 4);
	}
	if (LIST_A->next->content < LIST_A->content)
	{
		list_swap(list_a);
		write(1, "sa\n", 3);
	}
	if (!sort_check(*list_a) && (!*list_b || !(*list_b)->next ||
		LIST_A->content > LIST_B->next->content ||
		LIST_A->content < last_number(*list_b)))
	{
		list_push(list_b, list_a);
		write(1, "pb\n", 3);
	}
}

void		push_swap_b(t_list **list_b, t_list **list_a)
{
	int		last_num_b;

	last_num_b = last_number(*list_b);
	if ((*list_b)->next && LIST_B->content < LIST_B->next->content &&
		LIST_B->content > last_num_b)
	{
		list_swap(list_b);
		write(1, "sb\n", 3);
	}
	if ((*list_b)->next && LIST_B->content < LIST_B->next->content &&
		LIST_B->content < last_num_b)
	{
		list_rotate(list_b);
		write(1, "rb\n", 3);
	}
	if ((LIST_B->content > LIST_A->content && (*list_b)->next) ||
	sort_check(*list_a))
	{
		list_push(list_a, list_b);
		write(1, "pa\n", 3);
	}
}

int			sort_check(t_list *list_a)
{
	while (list_a->next)
	{
		if (*(int*)list_a->content < *(int*)list_a->next->content)
			list_a = list_a->next;
		else
			break ;
	}
	if (!list_a->next)
		return (1);
	return (0);
}
