# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Elena <Elena@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 15:27:14 by Elena             #+#    #+#              #
#    Updated: 2019/06/10 12:01:09 by Elena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = libft/libft.a get_next_line.c main.c
FLAGS = -Wall -Wextra -Werror

all: $(SRCS)
	gcc $(FLAGS) $(SRCS)

fclean:
	rm -f a.out