/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 07:56:29 by jtian             #+#    #+#             */
/*   Updated: 2021/09/05 19:49:29 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		print_match(int rush, int columns, int rows, int *match_count)
{
	if (*match_count > 0)
		ft_putstr(" || ");
	if (rush == 0)
		ft_putstr("[rush-00] [");
	if (rush == 1)
		ft_putstr("[rush-01] [");
	if (rush == 2)
		ft_putstr("[rush-02] [");
	if (rush == 3)
		ft_putstr("[rush-03] [");
	if (rush == 4)
		ft_putstr("[rush-04] [");
	ft_putnbr(columns);
	ft_putstr("] [");
	ft_putnbr(rows);
	ft_putstr("]");
	(*match_count)++;
}

void		check_rushes(char *input, int rows, int columns, int *match_count)
{
	if (match_rush_00(input, rows, columns))
		print_match(0, columns, rows, match_count);
	if (match_rush_01(input, rows, columns))
		print_match(1, columns, rows, match_count);
	if (match_rush_02(input, rows, columns))
		print_match(2, columns, rows, match_count);
	if (match_rush_03(input, rows, columns))
		print_match(3, columns, rows, match_count);
	if (match_rush_04(input, rows, columns))
		print_match(4, columns, rows, match_count);
}

void		ft_copy_input(char *src, char *dest, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		dest[i] = src[i];
		i++;
	}
}

char		*get_pipe_value(char *input)
{
	char	buf;
	int		i;
	int		max;
	char	*tmp_buffer;

	i = 0;
	max = 2;
	while (read(0, &buf, 1) != 0)
	{
		if (i == max - 1)
		{
			max = max * 2;
			tmp_buffer = (char*)malloc(sizeof(char) * max);
			ft_copy_input(input, tmp_buffer, i);
			free(input);
			input = (char*)malloc(sizeof(char) * max);
			ft_copy_input(tmp_buffer, input, i);
			free(tmp_buffer);
		}
		input[i] = buf;
		i++;
	}
	input[i] = '\0';
	return (input);
}

int			main(void)
{
	char	*input;
	int		rows;
	int		columns;
	int		match_count;

	match_count = 0;
	input = (char*)malloc(sizeof(char) * 2);
	input = get_pipe_value(input);
	rows = ft_rows(input);
	columns = ft_columns(input);
	if (rows == 0 || columns == 0)
	{
		ft_putstr("aucune\n");
		return (0);
	}
	check_rushes(input, rows, columns, &match_count);
	if (match_count == 0)
		ft_putstr("aucune\n");
	else
		ft_putstr("\n");
	free(input);
	return (0);
}
