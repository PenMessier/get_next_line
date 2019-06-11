/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:45:07 by frenna            #+#    #+#             */
/*   Updated: 2019/06/11 13:40:47 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Creates a new node and pushes it to the end of the list pointed by **str
** if the list is not NULL. Otherwise pushes it to the head of the list.
*/

void				ft_init(t_node **s, char *content, int fd, size_t c_size)
{
	t_node			*curr;
	t_node			*new;

	if (!c_size || !(new = (t_node *)malloc(sizeof(*new))))
		return ;
	new->content = ft_strnew(c_size);
	if (!new->content)
	{
		free(new);
		return ;
	}
	ft_memcpy(new->content, content, c_size);
	new->fd = fd;
	new->content_size = c_size;
	new->next = NULL;
	if (*s == NULL)
	{
		*s = new;
		return ;
	}
	curr = *s;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	return ;
}

/*
** Counts size in bytes for memory allocation for the line.
** Allocates memory. If allocation fail returns 0.
*/

size_t				ft_size(t_node **s, int fd, char **line)
{
	t_node			*tmp;
	size_t			n;

	tmp = *s;
	n = 0;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
		{
			n += tmp->content_size;
			if (ft_strrchr(tmp->content, '\n'))
				break ;
		}
		tmp = tmp->next;
	}
	if (!(*line = ft_strnew(n)))
		return (0);
	return (n);
}

/*
** Allocates memory for the line. Copies the content
** from the list **str to the **line according to the fd
** and remooves copied element from the list.
*/

void				ft_line(t_node **s, char **line, int fd)
{
	t_node			*curr;
	t_node			*tmp;

	curr = *s;
	tmp = NULL;
	while (curr != NULL)
	{
		if (curr->fd == fd)
		{
			*line = ft_strcat(*line, curr->content);
			if (curr == *s)
				*s = (*s)->next;
			tmp = curr;
			ft_strdel(&(tmp->content));
			tmp->fd = -1;
			tmp = NULL;
			ft_memdel((void **)&tmp);
		}
		if (ft_strrchr(*line, '\n'))
			break ;
		curr = curr->next;
	}
	ft_strrchr(*line, '\n') ? *ft_strrchr(*line, '\n') = '\0' : 0;
	free(*line);
}

/*
** Finds the end of the line ('\n') if it exists in the buffer,
** upgrades *f to 1. Then creates a new list element and puts
** buffer content till '\n' in it. Since the buffer contains
** characters after '\n' creates a new element and
** puts the rest of buffer content there.
*/

size_t				ft_r(int fd, ssize_t rd, t_node **s, char *buff)
{
	char			*tmp;
	char			*curr;
	int				i;

	i = 1;
	tmp = buff;
	if (ft_strrchr(buff, '\n'))
	{
		while (*tmp)
		{
			if (*tmp == '\n')
			{
				ft_init(s, curr, fd, i);
				curr = tmp + 1;
				i = 0;
			}
			i++;
			tmp++;
		}
		(*tmp - *curr != 0) ? ft_init(s, curr, fd, i) : 0;
		return (1);
	}
	else
		ft_init(s, buff, fd, rd);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[1];
	char			*buff;
	static	t_node	*s;
	size_t			f;
	ssize_t			rd;

	if (fd < 0 || !line || read(fd, (void *)buf, 0) < 0 || !BUFF_SIZE)
		return (-1);
	f = 0;
	while (f == 0 && (buff = ft_strnew(BUFF_SIZE)))
	{
		if (!buff)
			return (-1);
		if (!(rd = read(fd, (void *)buff, BUFF_SIZE)))
		{
			ft_strdel(&buff);
			break ;
		}
		f = ft_r(fd, rd, &s, buff);
		ft_strdel(&buff);
	}
	ft_size(&s, fd, line);
	ft_line(&s, line, fd);
	return (*line ? 1 : 0);
}
