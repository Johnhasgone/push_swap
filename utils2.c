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

int			average(t_list *list, int iteration)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (list)
	{
		if (list->iter == iteration)
		{
			num += *(int*)list->content;
			i++;
		}
		list = list->next;
	}
	return (i != 0 ? num / i : 0);
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
