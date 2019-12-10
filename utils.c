/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:33:47 by cimogene          #+#    #+#             */
/*   Updated: 2019/12/10 18:33:52 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*find_max(t_list *list)
{
	t_list	*max;

	max = list;
	while (list)
	{
		if (*list->content > *max->content)
			max = list;
		list = list->next;
	}
	return (max);
}

t_list		*last_elem(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

int			count_iter_base(t_list *list, int iter_base)
{
	int		i;

	i = 0;
	while (list)
	{
		if (list->iter == iter_base)
			i++;
		list = list->next;
	}
	return (i);
}

int			count_all(t_list *list)
{
	int		i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int			last_number(t_list *list)
{
	while (list->next)
		list = list->next;
	return (*(int*)list->content);
}
