/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:57:22 by Elena             #+#    #+#             */
/*   Updated: 2019/06/09 16:42:50 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		fd1;
	char	**line;
	
	line = (char **)malloc(sizeof(char **));
	fd = open("file.txt", O_RDONLY);
	fd1 = open("file1.txt", O_RDONLY);
	printf("%d\n", get_next_line(fd, line));
	printf("%s\n", *line);
	//ft_strdel(line);
	printf("%d\n", get_next_line(fd1, line));
	printf("%s\n", *line);
	printf("%d\n", get_next_line(fd, line));
	printf("%s\n", *line);
	printf("%d\n", get_next_line(fd1, line));
	printf("%s\n", *line);
	printf("%d\n", get_next_line(fd, line));
	printf("%s\n", *line);
	/*
	while (get_next_line(fd, line) == 1)
	{
		//printf("%d\n", get_next_line(fd, line));
		printf("%s\n", *line);
		//ft_memdel((void **)line);
	}
	*/
	close(fd);
	close(fd1);
	return (0);
}
