/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:03:49 by jtian             #+#    #+#             */
/*   Updated: 2021/08/29 20:19:00 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**ft_put_into_array (char **argv);
int		check_rows (int i, int y, int **array);
int		check_column (int i, int x, int **array);
int		check_grid (int x, int y, int i, int **array);
void	ft_print_grid(int **array);

int		master_checker(int i, int x, int y, int **array)
{
	if (check_rows(i, y, array) == 1)
	{
		if (check_column(i, x, array) == 1)
		{
			if (check_grid(x, y, i, array) == 1)
			{
				return (1);
			}
		}
	}
	return (0);
}

int		ft_check_numbers(int x, int y, int **array)
{
	int i;
	int fit_count;

	fit_count = 0;
	if (array[y][x] == 0)
	{
		i = 1;
		while (i < 10)
		{
			if (master_checker(i, x, y, array) == 1)
			{
				fit_count++;
				array[y][x] = i;
			}
			i++;
		}
		if (fit_count != 1)
			array[y][x] = 0;
	}
	return (fit_count);
}

void	ft_solve_grid(int x, int y, int **array)
{
	int fit_count;

	while (y < 9)
	{
		fit_count = 0;
		x = 0;
		while (x < 9 && fit_count != 1)
		{
			fit_count = ft_check_numbers(x, y, array);
			x++;
		}
		y++;
		if (fit_count == 1)
			y = 0;
	}
}

int		main(int argc, char **argv)
{
	int **array;

	(void)argc;
	array = ft_put_into_array(argv);
	ft_solve_grid(0, 0, array);
	ft_print_grid(array);
	free(array);
}
