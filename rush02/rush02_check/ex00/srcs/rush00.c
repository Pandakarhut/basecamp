/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 18:46:48 by conguyen          #+#    #+#             */
/*   Updated: 2021/09/06 11:46:54 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		ft_add_to_print(char **print, char *str)
{
	while (*str)
	{
		**print = *str;
		(*print)++;
		str++;
	}
}

void		ft_rush00(int x, int y, char **print)
{
	int		tempx;
	int		tempy;

	tempx = x;
	tempy = y + 1;
	while (tempy-- >= 1 && y >= 1 && x >= 1)
	{
		if (tempx > 1)
			ft_add_to_print(print, "o");
		while (tempx-- > 2)
			ft_add_to_print(print, "-");
		if (y >= 1 && x >= 1)
			ft_add_to_print(print, "o\n");
		while (tempy-- > 2)
		{
			tempx = x;
			if (tempx > 1)
				ft_add_to_print(print, "|");
			while (tempx-- > 2)
				ft_add_to_print(print, " ");
			ft_add_to_print(print, "|\n");
		}
		tempx = x;
	}
}

int			match_rush_00(char *input, int rows, int columns)
{
	char	*print;
	char	*print_begin;
	int		match;
	int		size;

	size = rows * (columns + 1) + 1;
	print = (char *)malloc(sizeof(char) * size);
	print_begin = print;
	match = 0;
	ft_rush00(columns, rows, &print);
	*print = '\0';
	if (ft_strcmp(input, print_begin) == 0)
		match = 1;
	print = print_begin;
	free(print);
	return (match);
}
