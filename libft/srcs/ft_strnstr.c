/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:05:22 by frenna            #+#    #+#             */
/*   Updated: 2019/06/11 12:24:55 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *h, const char *ned, size_t len)
{
	int		i;
	int		j;
	size_t	n;

	if (len == 0)
		return (0);
	i = 0;
	if (h[i] == '\0')
		return (0);
	if (!(n = ft_strlen(ned)))
		return ((char *)h);
	j = 0;
	while (len-- >= n && h[i])
	{
		while (ned[j] == h[i + j])
		{
			if (j == (int)n - 1)
				return ((char *)h + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
