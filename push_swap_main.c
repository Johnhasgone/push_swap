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

int			main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		aver;
	int		i;

	list_a = NULL;
	list_b = NULL;
	if (argc < 2)
		return (0);
	if (array_to_list(argc, argv, &list_a) == 0)
		write(2, "Error\n", 6);
	else
	{
		aver = average(list_a);
		i = count(list_a);
		if (i > 50)
			devide(&list_a, &list_b, aver);
		while (!sort_check(list_a) || list_b)
		{
			aver = average(list_a);
			push_swap_a(&list_a, &list_b, aver);
			aver = average(list_b);
			push_swap_b(&list_b, &list_a, aver);
		}
	}
	delete_list(&list_a);
	delete_list(&list_b);
	return (0);
}
