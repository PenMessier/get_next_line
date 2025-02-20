/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:17:11 by frenna            #+#    #+#             */
/*   Updated: 2019/06/10 18:27:29 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int			checknum(const char *s, size_t i, int *f)
{
	*f = 1;
	if (s[i] == '-')
	{
		*f = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	return (i);
}

int					ft_atoi(const char *s)
{
	int					f;
	size_t				i;
	unsigned long long	r;

	r = 0;
	i = 0;
	f = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	i = checknum(s, i, &f);
	while (s[i] == '0')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + (s[i] - '0');
		if (f == 1 && r > 9223372036854775807)
			return (-1);
		if (f == -1 && r > 9223372036854775807)
			return (0);
		i++;
	}
	return (r * f);
}
