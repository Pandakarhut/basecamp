/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:17:24 by deelliot          #+#    #+#             */
/*   Updated: 2021/09/08 08:21:43 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**ft_update_map(char **map, t_map_key key, t_max_square result)
{
	int i;
	int j;

	j = result.row - (result.max - 1);
	while (j <= result.row)
	{
		i = result.column - (result.max - 1);
		while (i <= result.column)
		{
			map[j][i] = key.full;
			i++;
		}
		j++;
	}
	return (map);
}

void	ft_print_map(char **map, t_map_key key)
{
	int j;
	int k;

	j = 0;
	while (j < key.row)
	{
		k = 0;
		while (k < key.column)
		{
			ft_putchar(map[j][k]);
			k++;
		}
		ft_putchar('\n');
		j++;
	}
}
