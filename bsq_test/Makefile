# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtian <jtian@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 12:32:22 by deelliot          #+#    #+#              #
#    Updated: 2021/09/08 19:57:10 by jtian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC_DIR = srcs
INCLUDE_DIR = includes
BIN_DIR = .

SRCS = $(SRC_DIR)/ft_calculate_square.c \
	$(SRC_DIR)/ft_create_map.c \
	$(SRC_DIR)/ft_print_array.c \
	$(SRC_DIR)/ft.c \
	$(SRC_DIR)/bsq.c \
	$(SRC_DIR)/ft_create_temp.c \
	$(SRC_DIR)/ft_check_errors.c \
	$(SRC_DIR)/ft_check_header.c \
	$(SRC_DIR)/main.c

OBJECTS = ft_calculate_square.o \
	ft_create_map.o \
	ft_print_array.o \
	ft.o \
	bsq.o \
	ft_create_temp.o\
	ft_check_errors.o \
	ft_check_header.o \
	main.o

FLAGS = -Wall -Werror -Wextra

EXE := $(BIN_DIR)/$(NAME)

all: $(NAME)

$(NAME):
	gcc -c $(SRCS) -I $(INCLUDE_DIR) $(FLAGS)
	gcc $(OBJECTS) -o $(EXE)

.PHONY: clean all fclean re
clean:
	rm -f $(wildcard $(BIN_DIR)/*.o)

fclean: clean
	rm -f $(NAME)
	rm -f _tmp_map.txt

re: fclean all
	