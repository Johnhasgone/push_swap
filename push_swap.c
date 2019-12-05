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

int 		count(t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int 		average(t_list *list)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (list)
	{
		num += *(int*)list->content;
		list = list->next;
		i++;
	}
	return (i != 0 ? num / i : 0);
}

int			last_number(t_list *list)
{
	while (list->next)
		list = list->next;
	return (*(int*)list->content);
}

int 		check_aver(t_list *list, int aver)
{
	while (list)
	{
		if (*(int*)list->content < aver)
			return (0);
		else
			list = list->next;
	}
	return (1);
}

void		devide(t_list **list_a, t_list **list_b, int aver)
{
	while ((*list_a)->next)
	{
		if (LIST_A->content < aver)
			list_push(list_b, list_a, 'b');
		else
		{
			list_rotate(list_a, 'a');
			if (check_aver(*list_a, aver))
				break ;
		}
	}
}

void		push_swap_a(t_list **list_a, t_list **list_b, int aver)
{
	//t_list	*node;
	if (last_number(*list_a) < aver)
	{
		if (LIST_A->content > LIST_A->next->content && LIST_A->content < aver)
			list_swap(list_a, 'a');
		list_reverse_rotate(list_a, 'a');
		if (LIST_A->content > LIST_A->next->content || LIST_A->next->content
		>= aver)
			list_swap(list_a, 'a');
		if (LIST_A->content > aver)
			list_rotate(list_a, 'a');
	}
	else
	{
		if (LIST_A->content >= aver && (*list_a)->next != NULL)
		{
			if (LIST_A->next->content >= aver)
			{
				if (LIST_A->content > LIST_A->next->content)
					list_swap(list_a, 'a');
				list_rotate(list_a, 'a');
			}
			list_rotate(list_a, 'a');
		}
	}
	if (last_number(*list_a) < LIST_A->content && last_number(*list_a) <=
	LIST_A->next->content)
	{
		if (LIST_A->content > LIST_A->next->content)
			list_swap(list_a, 'a');
		if (!(sort_check(*list_a)) && last_number(*list_a) < aver)
			list_reverse_rotate(list_a, 'a');
	}
	/*
	if (LIST_A->content < last_number(*list_a) && LIST_A->content < LIST_A->next->content)
	{
		if (last_number(*list_a) < LIST_A->next->content)
		{
			list_reverse_rotate(list_a, 'a');
			list_swap(list_a, 'a');
		}
	}
	 */
	if ((*list_a)->next && LIST_A->next->content < LIST_A->content &&
	LIST_A->next->content <= last_number(*list_a))
		LIST_A->content > last_number(*list_a) ? list_rotate(list_a, 'a') :
		list_swap(list_a, 'a');

	/*
	node = *list_a;
	while (node->next)
	{
		if (node->next->next == NULL)
		{
			if (*(int*)node->next->content < *(int*)node->content)
			{
				list_reverse_rotate(list_a, 'a');
				list_reverse_rotate(list_a, 'a');
				list_swap(list_a, 'a');
				list_rotate(list_a, 'a');
				list_rotate(list_a, 'a');
			}
			else
				break ;
		}
		else
			node = node->next;
	}

	*/
	if (!sort_check(*list_a) && (!*list_b || !(*list_b)->next ||
	LIST_A->content > LIST_B->next->content ||
	LIST_A->content < last_number(*list_b)))
		list_push(list_b, list_a, 'b');
}

void push_swap_b(t_list **list_b, t_list **list_a, int aver)
{
	int		last_num_b;


	if (*list_b && (*list_b)->next)
	{
		last_num_b = last_number(*list_b);
		if (last_number(*list_b) > aver)
		{
			if (LIST_B->content < LIST_B->next->content && LIST_B->content > aver)
				list_swap(list_b, 'b');
			list_reverse_rotate(list_b, 'b');
			if (LIST_B->content < LIST_B->next->content || LIST_B->next->content
														   < aver)
				list_swap(list_b, 'b');
			if (LIST_B->content < aver)
				list_rotate(list_b, 'b');
		}
		else
		{
			if (LIST_B->content < aver && (*list_b)->next != NULL)
			{
				if (LIST_B->next->content < aver)
				{
					if (LIST_B->content < LIST_B->next->content)
						list_swap(list_b, 'b');
					list_rotate(list_b, 'b');
				}
				list_rotate(list_b, 'b');
			}
		}
		if ((*list_b)->next && LIST_B->content < LIST_B->next->content &&
		LIST_B->content > last_num_b)
			list_swap(list_b, 'b');
		if ((*list_b)->next && LIST_B->content < LIST_B->next->content &&
		LIST_B->content < last_num_b)
			list_rotate(list_b, 'b');
	}
	if (*list_b && (LIST_B->content > LIST_A->content ||
	sort_check(*list_a)))
		list_push(list_a, list_b, 'a');
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
