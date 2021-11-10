/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:13:46 by deelliot          #+#    #+#             */
/*   Updated: 2021/08/29 20:13:04 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**allocate_array(void)
{
	int		**array;
	int		i;

	i = 0;
	array = (int **)malloc(9 * sizeof(int *));
	while (i < 10)
	{
		array[i] = (int *)malloc(9 * sizeof(int));
		i++;
	}
	i = 1;
	return (array);
}

int	**ft_put_into_array(char **argv)
{
	int		**array;
	int		x;
	int		y;
	int		i;

	i = 1;
	x = 0;
	y = 0;
	array = allocate_array();
	while (i < 10)
	{
		x = 0;
		while (argv[i][x] != '\0')
		{
			if (argv[i][x] >= '1' && argv[i][x] <= '9')
				array[y][x] = argv[i][x] - 48;
			else
				array[y][x] = 0;
			x++;
		}
		y++;
		i++;
	}
	return (array);
}
