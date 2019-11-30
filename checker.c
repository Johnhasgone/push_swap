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
#include <stdio.h>

int			int_check(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

int			array_to_list(int argc, char **argv, t_list **list)
{
	int i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (int_check(argv[i]) == 0)
			return (0);
		else
		{
			num = (int)malloc(sizeof(int));
			num = ft_atoi(argv[i]);
			ft_lstadd_end(list, ft_lstnew(&num, 1));
			i++;
		}
	}
	return (1);
}

void		sort_list(t_list **list_a, t_list **list_b, char *line)
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
}

void read_instructions(t_list **list_a, t_list **list_b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		sort_list(list_a, list_b, line);
		//ft_lstadd_end(list_a, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
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
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else
	{
		read_instructions(&list_a, &list_b);
	}
	/*
	while (list_a)
	{
		printf("%d    ", *(int*)list_a->content);
		if (list_b)
		{
			printf("%d", *(int*)list_b->content);
			list_b = list_b->next;
		}
		printf("\n");
		list_a = list_a->next;
	}
	printf("A    B");
	 */
	while (list_a->next)
	{
		if (*(int*)list_a->content < *(int*)list_a->next->content)
			list_a = list_a->next;
		else
			break ;
	}
	if (!list_a->next && !list_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
