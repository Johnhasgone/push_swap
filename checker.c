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

int 	int_check(char *str)
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

int		array_to_list(int argc, char **argv, t_list **list)
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
			ft_lstaddend(list, ft_lstnew(&num, 1));
			i++;
		}
	}
	return (1);
}

void	read_instructions(t_list **lst_instr)
{
	char 	*line;
	int 	res = 1;

	line = NULL;
	while (res > 0)
	{
		res = get_next_line(0, &line);
		ft_lstaddend(lst_instr, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
}

/*void	sort_list(t_list **lst_a, t_list **lst_b, t_list *lst_instr)
{

}*/

int 		main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*lst_instr;

	lst_a = NULL;
	lst_b = NULL;
	lst_instr = NULL;
	if (argc < 2)
		return (0);
	if (array_to_list(argc, argv, &lst_a) == 0)
		write(2, "Error\n", 6);
	else
	{
		read_instructions(&lst_instr);
		//sort_list(&lst_a, &lst_b, lst_instr);
	}
	while (lst_instr)
	{
		ft_putstr((char*)lst_instr->content);
		write(1, "\n", 1);
		lst_instr = lst_instr->next;
	}
	write(1, "fin\n", 4);
	return (0);

}