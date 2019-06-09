/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:13:30 by Elena             #+#    #+#             */
/*   Updated: 2019/06/03 15:44:29 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int *res;

	if (!min || !max)
		return (0);
	if (min >= max)
		return (0);
	res = (int *)malloc((max - min) * sizeof(int) + 1);
	if (!res)
	{
		free(res);
		return (0);
	}
	i = 0;
	while (i < max)
	{
		res[i] = min + i;
		i++;
	}
	res[i] = '\0';
	return (res);
}
