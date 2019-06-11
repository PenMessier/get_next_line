/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:23:42 by frenna            #+#    #+#             */
/*   Updated: 2019/06/11 12:24:45 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
		return (0);
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	ft_memset(str, (int)'\0', size + 1);
	return (str);
}
