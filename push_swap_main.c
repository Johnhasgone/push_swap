/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:22:01 by cimogene          #+#    #+#             */
/*   Updated: 2019/12/01 17:22:09 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		quick_sort(t_list **list_a, t_list **list_b)
{
	int		iter_base;
	int		iter;

	init_iter(list_a);
	iter = 0;
	while (!sort_check_a(*list_a, *list_b) || *list_b)
	{
		iter_base = (*list_a)->iter;
		while (!sort_check_a(*list_a, *list_b))
			push_swap_a(list_a, list_b, iter_base, ++iter);
		if (*list_b)
			push_swap_b(list_a, list_b);
	}
}

int			main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc < 2)
		return (0);
	if (array_to_list(argc, argv, &list_a) == 0)
		write(2, "Error\n", 6);
	else
		quick_sort(&list_a, &list_b);
	delete_list(&list_a);
	delete_list(&list_b);
	return (0);
}
