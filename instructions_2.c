/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:35:16 by cimogene          #+#    #+#             */
/*   Updated: 2019/12/01 16:37:11 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		list_swap_ab(t_list **list_a, t_list **list_b)
{
	list_swap(list_a);
	list_swap(list_b);
}

void		list_rotate_ab(t_list **list_a, t_list **list_b)
{
	ft_lstadd_end(list_a, ft_lstpop(list_a));
	ft_lstadd_end(list_b, ft_lstpop(list_b));
}

void		list_reverse_rotate_ab(t_list **list_a, t_list **list_b)
{
	ft_lstadd(list_a, ft_lstpop_end(list_a));
	ft_lstadd(list_b, ft_lstpop_end(list_b));
}
