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

void		list_swap(t_list **list, char type)
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
	if (type == 'a')
		write(1, "sa\n", 3);
	else if (type == 'b')
		write(1, "sb\n", 3);
}

void		list_push(t_list **list_1, t_list **list_2, char type)
{
	ft_lstadd(list_1, ft_lstpop(list_2));
	if (type == 'a')
		write(1, "pa\n", 3);
	else if (type == 'b')
		write(1, "pb\n", 3);
}

void		list_rotate(t_list **list, char type)
{
	ft_lstadd_end(list, ft_lstpop(list));
	if (type == 'a')
		write(1, "ra\n", 3);
	else if (type == 'b')
		write(1, "rb\n", 3);
}

void		list_reverse_rotate(t_list **list, char type)
{
	ft_lstadd(list, ft_lstpop_end(list));
	if (type == 'a')
		write(1, "rra\n", 4);
	else if (type == 'b')
		write(1, "rrb\n", 4);
}
