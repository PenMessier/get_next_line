/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:18:14 by frenna            #+#    #+#             */
/*   Updated: 2019/06/03 15:44:29 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void				*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;

	if (n == 0)
		return (str);
	s = (unsigned char *)str;
	while (n)
	{
		*s = (unsigned char)c;
		s++;
		n--;
	}
	return (str);
}
