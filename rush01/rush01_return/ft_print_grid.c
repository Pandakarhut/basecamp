/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:01:21 by jtian             #+#    #+#             */
/*   Updated: 2021/08/29 20:02:15 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_grid(int **array)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < 9)
	{
		while (x < 9)
		{
			ft_putchar(array[y][x] + '0');
			if (x < 8)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}
