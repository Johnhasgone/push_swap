/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:35:16 by cimogene          #+#    #+#             */
/*   Updated: 2019/12/01 16:37:11 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		list_swap(t_list **list)
{
	t_list	*third;
	t_list	*second;

	if ((!*list) || !(*list)->next)
		return ;
	third = (*list)->next->next;
	second = (*list)->next;
	second->next = *list;
	second->next->next = third;
	*list = second;
}

void		list_push(t_list **list_1, t_list **list_2)
{
	ft_lstadd(list_1, ft_lstpop(list_2));
}

void		list_rotate(t_list **list)
{
	ft_lstadd_end(list, ft_lstpop(list));
}

void		list_reverse_rotate(t_list **list)
{
	ft_lstadd(list, ft_lstpop_end(list));
}
