/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_temp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:50:14 by deelliot          #+#    #+#             */
/*   Updated: 2021/09/08 19:56:28 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int				**ft_allocate_temp(t_map_key key)
{
	int i;
	int **temp;

	i = 0;
	temp = (int **)malloc((key.row + 1) * sizeof(int *));
	while (i < key.row)
	{
		temp[i] = (int *)malloc((key.column + 1) * sizeof(int));
		i++;
	}
	if (temp == NULL)
		return (NULL);
	else
		return (temp);
}

int				**populate_temp(char **map, int **temp, t_map_key key)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < key.row)
	{
		i = 0;
		while (i < key.column)
		{
			if (map[j][i] == key.empty)
				temp[j][i] = 1;
			else if (map[j][i] == key.obstacle)
				temp[j][i] = 0;
			else
				return (NULL);
			i++;
		}
		j++;
	}
	return (temp);
}
