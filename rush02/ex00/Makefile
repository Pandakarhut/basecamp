# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtian <jtian@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 15:45:55 by jtian             #+#    #+#              #
#    Updated: 2021/09/05 18:22:00 by jtian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUTPUT = srcs/ft_columns.c srcs/ft_putnbr.c srcs/ft_rows.c \
srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c \
srcs/rush2.c srcs/rush00.c srcs/rush01.c srcs/rush02.c \
srcs/rush03.c srcs/rush04.c

all: 
	gcc -Wall -Wextra -Werror $(OUTPUT) -I. -o rush-2

clean:
	/bin/rm -f rush-2

fclean: clean

re: fclean all
