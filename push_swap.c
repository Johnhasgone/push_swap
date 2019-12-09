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

void		init_iter(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while (tmp)
	{
		tmp->iter = 0;
		tmp = tmp->next;
	}
}

t_list	*find_max(t_list *list)
{
	t_list *max;

	max = list;
	while (list)
	{
		if (*list->content > *max->content)
			max = list;
		list = list->next;
	}
	return (max);
}

int sort_check_a(t_list *list_a, t_list *list_b)
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

int			sort_check_b(t_list *list_b)
{
	while (list_b && list_b->next)
	{
		if (*list_b->content > *list_b->next->content)
			list_b = list_b->next;
		else
			break ;
	}
	if (list_b && !list_b->next)
		return (1);
	return (0);
}

int 		count_iter_base(t_list *list, int iter_base)
{
	int i;

	i = 0;
	while (list)
	{
		if (list->iter == iter_base)
			i++;
		list = list->next;
	}
	return (i);
}


int 		count_all(t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int 		average(t_list *list, int iteration)
{
	int i;
	int num;

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

int			last_number(t_list *list)
{
	while (list->next)
		list = list->next;
	return (*(int*)list->content);
}

t_list 		*last_elem(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

int 		check_aver_a(t_list *list, int aver)
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

int 		check_aver_b(t_list *list, int aver)
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


void sort_small_stack_a(t_list **list)
{
	if (count_all(*list) != 3)
	{
		if (*(*list)->content > *(*list)->next->content)
			list_swap(list, 'a');
		return ;
	}
	else
	{
		if (*(*list)->next->next->content < *(*list)->next->content)
		{
			if (*(*list)->next->content < *(*list)->content)
				list_swap(list, 'a');
			list_reverse_rotate(list, 'a');
		}
		if (*(*list)->content > *(*list)->next->content)
		{
			if(*(*list)->content < *(*list)->next->next->content)
				list_swap(list, 'a');
			else
				list_rotate(list, 'a');
		}
	}

}

void 		sort_small_stack_b(t_list **list)
{
	if (count_iter_base(*list, (*list)->iter) == 2)
	{
		if (*(*list)->content < *(*list)->next->content)
			list_swap(list, 'b');
		return ;
	}
	if (*(*list)->next->next->content > *(*list)->next->content)
	{
		if (*(*list)->next->content > *(*list)->content)
			list_swap(list, 'b');
		list_reverse_rotate(list, 'b');
	}
	if (*(*list)->content < *(*list)->next->content)
	{
		if(*(*list)->content > *(*list)->next->next->content)
			list_swap(list, 'b');
		else
			list_rotate(list, 'b');
	}
}

void 		push_swap_a(t_list **list_a, t_list **list_b, int iter_base, int iter)
{
	int		aver;


	aver = average(*list_a, iter_base);
	while (last_elem(*list_a)->iter != 0 && !sort_check_a(*list_a, *list_b)) // maybe add checking for being the same iter_base
		list_reverse_rotate(list_a, 'a');


	if (count_all(*list_a) == 3 || *(*list_a)->content > *(*list_a)->next->content)
		sort_small_stack_a(list_a);


	while (!check_aver_a(*list_a, aver) && !sort_check_a(*list_a, *list_b))
	{
		if ((*(*list_a)->content <= aver))
		{
			(*list_a)->iter = iter;
			list_push(list_b, list_a, 'b');
		}
		else
			list_rotate(list_a, 'a');
	}
}

void		push_swap_b(t_list **list_a, t_list **list_b)
{
	int aver;
	int iter_base;
	int i;

	i = 0;

	iter_base = (*list_b)->iter;
	if (count_iter_base(*list_b, iter_base) == 2 || count_all(*list_b) == 3)        //optimizer function for three elements
	{
		sort_small_stack_b(list_b);
		while (*list_b && (*list_b)->iter == iter_base)
			list_push(list_a, list_b, 'a');
		return ;
	}


	aver = average(*list_b, iter_base);


	while (!check_aver_b(*list_b, aver))
	{
		while (last_number(*list_b) > *(*list_b)->content && *(*list_b)->content >= aver)
			list_reverse_rotate(list_b, 'b');
		if ((*list_b)->iter == iter_base && *(*list_b)->content >= aver)
		{
			if ((*list_b)->next && *(*list_b)->content < *(*list_b)->next->content)
				list_swap(list_b, 'b');
			list_push(list_a, list_b, 'a');
		}
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


//void devide(t_list **list_a, t_list **list_b)
//{
//	int		aver;
//	int 	local_aver;
//
//	aver = average(*list_a);
//	local_aver = sort_a(list_a, list_b);
//	while (last_number(*list_a) <= average(*list_a))
//		list_reverse_rotate(list_a, 'a');
//	if (!sort_check(*list_a))
//		devide(list_a, list_b);
//	sort_b(list_a, list_b, local_aver, aver);
//
//}

//void		push_swap_a(t_list **list_a, t_list **list_b, int aver)
//{
//	//t_list	*node;
//
//
//	if (last_number(*list_a) < aver)
//	{
//		if (LIST_A->content > LIST_A->next->content && LIST_A->content < aver)
//			list_swap(list_a, 'a');
//		list_reverse_rotate(list_a, 'a');
//		if (LIST_A->content > LIST_A->next->content || LIST_A->next->content
//		>= aver)
//			list_swap(list_a, 'a');
//		if (LIST_A->content > aver)
//			list_rotate(list_a, 'a');
//	}
//	else
//	{
//		if (LIST_A->content >= aver && (*list_a)->next != NULL)
//		{
//			if (LIST_A->next->content >= aver)
//			{
//				if (LIST_A->content > LIST_A->next->content)
//					list_swap(list_a, 'a');
//				list_rotate(list_a, 'a');
//			}
//			list_rotate(list_a, 'a');
//		}
//	}
//
//	/*
//
//	if (last_number(*list_a) < LIST_A->content && last_number(*list_a) <=
//	LIST_A->next->content)
//	{
//		if (LIST_A->content > LIST_A->next->content)
//			list_swap(list_a, 'a');
//		if (!(sort_check(*list_a)) && last_number(*list_a) < aver)
//			list_reverse_rotate(list_a, 'a');
//	}
//
//	if (LIST_A->content < last_number(*list_a) && LIST_A->content < LIST_A->next->content)
//	{
//		if (last_number(*list_a) < LIST_A->next->content)
//		{
//			list_reverse_rotate(list_a, 'a');
//			list_swap(list_a, 'a');
//		}
//	}
//
//*/
//
//	if ((*list_a)->next && LIST_A->next->content < LIST_A->content &&
//	LIST_A->next->content <= last_number(*list_a))
//		LIST_A->content > last_number(*list_a) ? list_rotate(list_a, 'a') :
//		list_swap(list_a, 'a');
//
//
//
//	/*
//	node = *list_a;
//	while (node->next)
//	{
//		if (node->next->next == NULL)
//		{
//			if (*(int*)node->next->content < *(int*)node->content)
//			{
//				list_reverse_rotate(list_a, 'a');
//				list_reverse_rotate(list_a, 'a');
//				list_swap(list_a, 'a');
//				list_rotate(list_a, 'a');
//				list_rotate(list_a, 'a');
//			}
//			else
//				break ;
//		}
//		else
//			node = node->next;
//	}
//*/
//
//	while (!sort_check(*list_a))
//	{
//		aver = average(*list_a);
//		if (LIST_A->content <= aver)
//			list_push(list_b, list_a, 'b');
//		else
//			list_rotate(list_a, 'a');
//	}
//
//
////	if (!sort_check(*list_a) && (!*list_b || !(*list_b)->next ||
////	LIST_A->content > LIST_B->next->content ||
////	LIST_A->content < last_number(*list_b)))
////		list_push(list_b, list_a, 'b');
//}

//void push_swap_b(t_list **list_b, t_list **list_a, int aver)
//{
//	int		last_num_b;
//
//
//	if (*list_b && (*list_b)->next)
//	{
//		last_num_b = last_number(*list_b);
//		if (last_number(*list_b) > aver)
//		{
//			if (LIST_B->content < LIST_B->next->content && LIST_B->content > aver)
//				list_swap(list_b, 'b');
//			list_reverse_rotate(list_b, 'b');
//			if (LIST_B->content < LIST_B->next->content || LIST_B->next->content
//														   < aver)
//				list_swap(list_b, 'b');
//			if (LIST_B->content < aver)
//				list_rotate(list_b, 'b');
//		}
//		else
//		{
//			if (LIST_B->content < aver && (*list_b)->next != NULL)
//			{
//				if (LIST_B->next->content < aver)
//				{
//					if (LIST_B->content < LIST_B->next->content)
//						list_swap(list_b, 'b');
//					list_rotate(list_b, 'b');
//				}
//				list_rotate(list_b, 'b');
//			}
//		}
//		if ((*list_b)->next && LIST_B->content < LIST_B->next->content &&
//		LIST_B->content > last_num_b)
//			list_swap(list_b, 'b');
//		if ((*list_b)->next && LIST_B->content < LIST_B->next->content &&
//		LIST_B->content < last_num_b)
//			list_rotate(list_b, 'b');
//	}
//	if (*list_b && (LIST_B->content > LIST_A->content ||
//	sort_check(*list_a)))
//		list_push(list_a, list_b, 'a');
//}


