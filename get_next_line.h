/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:54:19 by Elena             #+#    #+#             */
/*   Updated: 2019/06/09 16:19:38 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 200

int					get_next_line(const int fd, char **line);

typedef struct		list
{
	char			*content;
	int				fd;
	size_t			content_size;
	struct list		*next;
}					node;

#endif