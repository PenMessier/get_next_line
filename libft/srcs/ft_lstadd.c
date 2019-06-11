/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:35:44 by frenna            #+#    #+#             */
/*   Updated: 2019/06/10 18:27:29 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!alst && !new)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	if (new == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}
