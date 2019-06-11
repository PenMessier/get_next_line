/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:42:27 by frenna            #+#    #+#             */
/*   Updated: 2019/06/10 18:27:29 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*current;

	if (!lst || !f)
		return (0);
	new = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (!new)
		return (0);
	current = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!new->next)
			return (0);
		new = new->next;
		lst = lst->next;
	}
	return (current);
}
