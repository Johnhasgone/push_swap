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

	list_a = NULL;
	list_b = NULL;
	if (argc < 2)
		return (0);
	if (array_to_list(argc, argv, &list_a) == 0)
		write(2, "Error\n", 6);
	else
		push_swap_quick_sort(&list_a, &list_b);
	delete_list(&list_a);
	delete_list(&list_b);
	return (0);
}
