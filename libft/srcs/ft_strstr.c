/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:10:02 by frenna            #+#    #+#             */
/*   Updated: 2019/06/10 18:27:29 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *hay, const char *ned)
{
	int i;
	int j;
	int len;

	if (!(len = ft_strlen(ned)))
		return ((char *)hay);
	i = 0;
	j = 0;
	while (hay[i])
	{
		while (ned[j] == hay[i + j])
		{
			if (j == len - 1)
				return ((char *)hay + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
