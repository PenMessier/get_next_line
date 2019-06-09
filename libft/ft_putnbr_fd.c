/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:41:04 by Elena             #+#    #+#             */
/*   Updated: 2019/06/03 15:44:29 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		printarr(int *str, int i, int fd)
{
	if (str[0] == 1)
		ft_putchar_fd('-', fd);
	if (str[0] == 2)
	{
		ft_putchar_fd('-', fd);
		str[1] = str[1] + 1;
	}
	while (i > 0)
	{
		ft_putchar_fd(('0' + str[i]), fd);
		i--;
	}
}

static	int		checknum(int nb, int *str)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			str[0] = 2;
			nb = -1 * (nb + 1);
		}
		else
		{
			str[0] = 1;
			nb *= -1;
		}
	}
	else
		str[0] = 0;
	return (nb);
}

void			ft_putnbr_fd(int nb, int fd)
{
	int i;
	int str[11];

	i = 1;
	nb = checknum(nb, str);
	while (nb >= 10)
	{
		str[i] = nb % 10;
		nb /= 10;
		i++;
	}
	if (nb < 10)
		str[i] = nb;
	printarr(str, i, fd);
}
