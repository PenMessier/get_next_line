/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:37:29 by frenna            #+#    #+#             */
/*   Updated: 2019/06/10 18:27:29 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	int				j;

	if (!dest || !src)
		return (0);
	i = 0;
	j = 0;
	while (i < n)
	{
		if (j == 1)
			dest[i] = '\0';
		else if (src[i] == '\0')
		{
			j = 1;
			dest[i] = '\0';
		}
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
