/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:29:44 by nslughor          #+#    #+#             */
/*   Updated: 2019/10/23 13:01:55 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	len;

	len = 0;
	if (s && f)
		len = ft_strlen(s);
	if (len)
		while (len--)
			(*f)(&(s[len]));
}