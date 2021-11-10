# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtian <jtian@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 15:46:56 by jtian             #+#    #+#              #
#    Updated: 2021/09/02 20:10:17 by jtian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: compile

compile:
	gcc -Wall -Wextra -Werror -c ft_cat.c -o ft_cat.o
	gcc -Wall -Wextra -Werror ft_cat.o -o ft_cat

clean:
	/bin/rm -f ft_cat.o

fclean: clean
	/bin/rm -f ft_cat

re: fclean all
