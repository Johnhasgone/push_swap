//
// Created by Евгений Ваганов on 01.12.2019.
//

#include "push_swap.h"
#include <stdio.h>
#include <stdbool.h>

int last_number(t_list *list)
{
	while (list->next)
		list = list->next;
	return (*(int*)list->content);
}

void min_num_up(t_list **list_a, t_list **list_b)
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

void max_num_up(t_list **list_b, t_list **list_a)
{
	int last_num_b;

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

void push_swap(t_list **list_a, t_list **list_b)
{
	min_num_up(list_a, list_b);
	max_num_up(list_b, list_a);
}

int sort_check(t_list *list_a)
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

int main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc < 2)
		return (0);
	if (array_to_list(argc, argv, &list_a) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else
	{
		while (!sort_check(list_a) || list_b)
			push_swap(&list_a, &list_b);
	}
	return (0);
}