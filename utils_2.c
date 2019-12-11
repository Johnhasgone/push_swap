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

int 		select_pivot(t_list *pivot, t_list *list, int iteration)
{
	int 	smaller;

	smaller = 0;
	while (list)
	{
		if (list->iter == iteration)
		{
			if (*list->content <= *pivot->content)
				smaller++;
		}
		list = list->next;
	}
	return (smaller);
}

int			median_pivot(t_list *list, int iteration)
{
	t_list	*pivot;

	pivot = list;
	while (pivot)
	{
		if (count_iter_base(list, iteration) % 2 == 0)
		{
			if (count_iter_base(list, iteration) / 2 == select_pivot(pivot, list, iteration))
				return (*pivot->content);
		}
		else if (count_iter_base(list, iteration) % 2 == 1)
		{
			if (count_iter_base(list, iteration) / 2 + 1 == select_pivot(pivot, list, iteration))
				return (*pivot->content);
		}
		pivot = pivot->next;
	}
	return (0);
}

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
