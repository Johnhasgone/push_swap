/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:33:30 by cimogene          #+#    #+#             */
/*   Updated: 2019/12/10 18:33:36 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_aver_b(t_list *list, int aver)
{
	while (list)
	{
		if (*(int*)list->content >= aver)
			return (0);
		else
			list = list->next;
	}
	return (1);
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
