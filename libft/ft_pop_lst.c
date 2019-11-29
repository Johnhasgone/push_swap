/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:32:44 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/12 15:32:34 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	*ft_pop_lst(t_list **begin_list)
{
	t_list	*new_elem;
	int		*nb;

	nb = (*begin_list)->content;
	new_elem = (*begin_list)->next;
	free(*begin_list);
	*begin_list = new_elem;
	return (nb);
}
