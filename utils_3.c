/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:33:57 by cimogene          #+#    #+#             */
/*   Updated: 2019/12/10 18:34:01 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			select_pivot(t_list *pivot, t_list *list, int iteration)
{
	int		smaller;

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
