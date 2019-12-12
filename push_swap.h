/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:16:49 by cimogene          #+#    #+#             */
/*   Updated: 2019/11/28 15:16:59 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "./libft/libft.h"

/*
** sorting instructions functions (instructions_1.c, instructions_2.c)
*/

void	list_swap(t_list **list, char type);
void	list_swap_ab(t_list **list_a, t_list **list_b);
void	list_push(t_list **list_1, t_list **list_2, char type);
void	list_rotate(t_list **list, char type);
void	list_rotate_ab(t_list **list_a, t_list **list_b);
void	list_reverse_rotate(t_list **list, char type);
void	list_reverse_rotate_ab(t_list **list_a, t_list **list_b);

/*
** CHECKER sorting functions (checker.c)
*/

int		sort_list(t_list **list_a, t_list **list_b, char *line);
int		read_instructions(t_list **list_a, t_list **list_b);

/*
** checking and saving elements into list (stack a) (checker.c)
*/

int		array_to_list(int argc, char **argv, t_list **list);
int		int_check(char *str);

/*
** key PUSH-SWAP sorting functions (push_swap_func.c)
*/

void	push_swap_quick_sort(t_list **list_a, t_list **list_b);
void	push_swap_a(t_list **lst_a, t_list **lst_b, int iter_base, int iter);
void	push_swap_b(t_list **list_b, t_list **list_a);
int		sort_check_a(t_list *list_a, t_list *list_b);
int		median_pivot(t_list *list, int iteration);

/*
** utility functions (utils_1.x, utils_2.c, utils_3.c)
*/

int		last_number(t_list *list);
void	delete_list(t_list **list);
void	sort_small_stack_a(t_list **list);
int		choose_rotation(t_list *list, int aver);
void	init_iter(t_list **list);
t_list	*find_max(t_list *list);
t_list	*last_elem(t_list *list);
int		count_all(t_list *list);
int		count_iter_base(t_list *list, int iter_base);
int		select_pivot(t_list *pivot, t_list *list, int iteration);
int		check_aver_a(t_list *list, int aver);
int		check_aver_b(t_list *list, int aver);

#endif
