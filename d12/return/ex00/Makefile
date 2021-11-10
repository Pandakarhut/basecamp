# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtian <jtian@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 15:45:55 by jtian             #+#    #+#              #
#    Updated: 2021/09/02 20:06:47 by jtian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: compile

compile:
	gcc -Wall -Wextra -Werror -c main.c -o main.o
	gcc -Wall -Wextra -Werror main.o -o ft_display_file

clean:
	/bin/rm -f main.o

fclean: clean
	/bin/rm -f ft_display_file

re: fclean all
