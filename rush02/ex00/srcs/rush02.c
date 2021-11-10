/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 18:46:48 by conguyen          #+#    #+#             */
/*   Updated: 2021/09/05 19:31:35 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		print_rush2(char *chars, int d, char **print)
{
	char a;
	char b;
	char c;

	a = chars[0];
	b = chars[1];
	c = chars[2];
	**print = a;
	(*print)++;
	while (d-- > 2)
	{
		**print = b;
		(*print)++;
	}
	if (d-- > 0)
	{
		**print = c;
		(*print)++;
	}
	**print = '\n';
	(*print)++;
}

void		ft_rush02(int x, int y, char **print)
{
	int		temp;
	int		tempy;

	temp = x;
	tempy = y;
	if (x >= 1 && y >= 1)
	{
		print_rush2("ABA", temp, print);
		while (tempy-- > 2)
			print_rush2("B B", temp, print);
		if (tempy-- > 0)
			print_rush2("CBC", temp, print);
	}
}

int			match_rush_02(char *input, int rows, int columns)
{
	char	*print;
	char	*print_begin;
	int		match;
	int		size;

	size = rows * (columns + 1) + 1;
	print = (char *)malloc(sizeof(char) * size);
	print_begin = print;
	match = 0;
	ft_rush02(columns, rows, &print);
	*print = '\0';
	if (ft_strcmp(input, print_begin) == 0)
		match = 1;
	print = print_begin;
	free(print);
	return (match);
}
