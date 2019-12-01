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

# define LIST_A *(int*)(*list_a)
# define LIST_B *(int*)(*list_b)

# include "./libft/libft.h"

void	list_swap(t_list **list, char type);
void	list_swap_ab(t_list **list_a, t_list **list_b);
void	list_push(t_list **list_1, t_list **list_2, char type);
void	list_rotate(t_list **list, char type);
void	list_rotate_ab(t_list **list_a, t_list **list_b);
void	list_reverse_rotate(t_list **list, char type);
void	list_reverse_rotate_ab(t_list **list_a, t_list **list_b);

void	push_swap_a(t_list **list_a, t_list **list_b);
void	push_swap_b(t_list **list_a, t_list **list_b);

int		array_to_list(int argc, char **argv, t_list **list);
int		int_check(char *str);
int		sort_list(t_list **list_a, t_list **list_b, char *line);
int		read_instructions(t_list **list_a, t_list **list_b);
int		sort_check(t_list *list_a);
int		last_number(t_list *list);
void	delete_list(t_list **list);

#endif
