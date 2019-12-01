/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:14:27 by cimogene          #+#    #+#             */
/*   Updated: 2019/11/27 19:14:29 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			int_check(char *str)
{
	int		i;
	int 	num;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	if ((num = ft_atoi(str)) < 0)
		num *= -1;
	if (num % 10 != str[i - 1] - '0')
		return (0);
	return (1);
}

int			array_to_list(int argc, char **argv, t_list **list)
{
	int		i;
	int		num;

	i = 1;
	while (i < argc)
	{
		if (int_check(argv[i]) == 0)
			return (0);
		else
		{
			num = (int)malloc(sizeof(int));
			num = ft_atoi(argv[i]);
			if (!(ft_lst_check_add_end(list, ft_lstnew(&num, 4))))
				return (0);
			i++;
		}
	}
	return (1);
}

int			sort_list(t_list **list_a, t_list **list_b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		list_swap(list_a);
	else if (ft_strcmp(line, "sb") == 0)
		list_swap(list_b);
	else if (ft_strcmp(line, "ss") == 0)
		list_swap_ab(list_a, list_b);
	else if (ft_strcmp(line, "pa") == 0)
		list_push(list_a, list_b);
	else if (ft_strcmp(line, "pb") == 0)
		list_push(list_b, list_a);
	else if (ft_strcmp(line, "ra") == 0)
		list_rotate(list_a);
	else if (ft_strcmp(line, "rb") == 0)
		list_rotate(list_b);
	else if (ft_strcmp(line, "rr") == 0)
		list_rotate_ab(list_a, list_b);
	else if (ft_strcmp(line, "rra") == 0)
		list_reverse_rotate(list_a);
	else if (ft_strcmp(line, "rrb") == 0)
		list_reverse_rotate(list_b);
	else if (ft_strcmp(line, "rrr") == 0)
		list_reverse_rotate_ab(list_a, list_b);
	else
		return (0);
	return (1);
}

int			read_instructions(t_list **list_a, t_list **list_b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!(sort_list(list_a, list_b, line)))
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	return (1);
}
