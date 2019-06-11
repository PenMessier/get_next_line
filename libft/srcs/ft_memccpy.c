/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:02:06 by frenna            #+#    #+#             */
/*   Updated: 2019/06/10 18:27:29 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int ch, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!src || !dest)
		return (0);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
	{
		*d = *s;
		if (*s == (unsigned char)ch)
		{
			d++;
			return (d);
		}
		s++;
		d++;
	}
	return (0);
}
