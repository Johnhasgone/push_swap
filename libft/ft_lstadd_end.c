/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:26:49 by cimogene          #+#    #+#             */
/*   Updated: 2019/09/11 20:55:02 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*elem;

	if (new == NULL)
		return ;
	elem = *alst;
	if (elem == NULL)
	{
		*alst = new;
	}
	else
	{
		while (elem->next)
			elem = elem->next;
		elem->next = new;
	}
}

int	ft_lst_check_add_end(t_list **alst, t_list *new)
{
	t_list	*elem;

	if (new == NULL)
		return (0);
	elem = *alst;
	if (elem == NULL)
	{
		*alst = new;
	}
	else
	{
		while (elem->next)
		{
			if (*(int*)elem->content == *(int*)new->content)
				return (0);
			elem = elem->next;
		}
		elem->next = new;
	}
	return (1);
}
