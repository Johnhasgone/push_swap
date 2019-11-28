/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimogene <cimogene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:09:04 by cimogene          #+#    #+#             */
/*   Updated: 2019/09/23 17:15:21 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

typedef struct		s_lst
{
	char			*str;
	int				fdesc;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(const int fd, char **line);

#endif
