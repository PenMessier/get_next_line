/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:35:48 by frenna            #+#    #+#             */
/*   Updated: 2019/06/10 18:27:29 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int i;
	unsigned int j;

	if (!dest || !src)
		return (0);
	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (i < n && *src)
	{
		dest[j] = *src;
		j++;
		src++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
