/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:45:07 by frenna            #+#    #+#             */
/*   Updated: 2019/06/09 16:41:30 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Creates a new node and pushes it to the end of the list pointed by **str
 * if the list is not NULL. Otherwise pushes it to the head of the list.
 **/
static	void	ft_init(node **str, char *content, int fd, size_t content_size)
{
	node		*curr;
	node		*new;

	if (!content_size || !(new = (node *)malloc(sizeof(*new))))
		return ;
	new->content = (char *)malloc(content_size);
	if (!new->content)
	{
		free(new);
		return ;
	}
	ft_memcpy(new->content, content, content_size);
	new->fd = fd;
	new->content_size = content_size;
	new->next = NULL;
	if (*str == NULL)
	{
		*str = new;
		return ;
	}
	curr = *str;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	return ;
}

/*
* Counts size in bytes for memory allocation for the line.
*/
static size_t	ft_size(node **str, int fd)
{
	node		*tmp;
	size_t		n;

	tmp = *str;
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
	return (n);
}

/*
* Allocates memory for the line. Copies the content
* from the list **str to the **line according to the fd
* and remooves copied element from the list.
*/
static void	ft_line(node **str, char **line, int fd, size_t *f)
{
	node	*curr;
	node	*tmp;

	//ft_strdel(line);
	if (!(*line = ft_strnew(*f)))
		return ;
	curr = *str;
	tmp = NULL;
	while (curr != NULL)
	{
		if(curr->fd == fd)
		{
			*line = ft_strcat(*line, curr->content);
			if (curr == *str)
				*str = (*str)->next;
			tmp = curr;
			if (tmp->content)
				ft_strdel(&(tmp->content));
			tmp->fd = -1;
			tmp->content_size = 0;
			tmp = NULL;
			ft_memdel((void **)&tmp);
		}
		if (ft_strrchr(*line, '\n'))
			break ;
		curr = curr->next;
	}
}

/*
* Finds the end of the line ('\n') if it exists in the buffer, upgrades *f to 1.
* Then creates a new list element and puts buffer content till '\n' in it.
* Since the buffer contains characters after '\n' creates a new element
* and puts the rest of buffer content there.
*/
static	void	ft_readline(int fd, ssize_t rd, node **str, size_t *f, char *buff)
{
	char		*tmp;
	char		*curr;
	int			i;

	i = 0;
	tmp = buff;
	curr = buff;
	if (ft_strrchr(buff, '\n'))
	{
		*f = 1;
		while (*tmp)
		{
			if (*tmp == '\n')
			{
				ft_init(str, curr, fd, (i + 1));
				curr = tmp + 1;
				i = 0;
			}
			else
				i++;
			tmp++;
		}
		if (*tmp - *curr != 0)
			ft_init(str, curr, fd, (i + 1));
	}
	else
		ft_init(str, buff, fd, rd);
}

int	get_next_line(const int fd, char **line)
{
	char	buf[1];
	char	*buff;
	static	node	*str;
	size_t	f;
	ssize_t	rd;

	if (fd < 0 || !line || read(fd, (void *)buf, 0) < 0)
		return (-1);
	f = 0;
	while (f == 0 && (buff = ft_strnew(BUFF_SIZE)))
	{
		if (!(rd = read(fd, (void *)buff, BUFF_SIZE)))
		{
			ft_strdel(&buff);
			break ;
		}
		ft_readline(fd, rd, &str, &f, buff);
		ft_strdel(&buff);
	}
	f = ft_size(&str, fd);
	ft_line(&str, line, fd, &f);
	if (ft_strrchr(*line, '\n'))
		*ft_strrchr(*line, '\n') = '\0';
	return (*line ? 1 : 0);
}
