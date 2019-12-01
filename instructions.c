


#include "push_swap.h"

void list_swap(t_list **list)
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

void list_swap_ab(t_list **list_a, t_list **list_b)
{
	list_swap(list_a);
	list_swap(list_b);
}

void list_push(t_list **list_1, t_list **list_2)
{
	ft_lstadd(list_1, ft_lstpop(list_2));
}

void list_rotate(t_list **list)
{
	ft_lstadd_end(list, ft_lstpop(list));
}

void list_rotate_ab(t_list **list_a, t_list **list_b)
{
	ft_lstadd_end(list_a, ft_lstpop(list_a));
	ft_lstadd_end(list_b, ft_lstpop(list_b));
}

void list_reverse_rotate(t_list **list)
{
	ft_lstadd(list, ft_lstpop_end(list));
}

void list_reverse_rotate_ab(t_list **list_a, t_list **list_b)
{
	ft_lstadd(list_a, ft_lstpop_end(list_a));
	ft_lstadd(list_b, ft_lstpop_end(list_b));
}