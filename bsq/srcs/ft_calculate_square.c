/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 07:36:06 by deelliot          #+#    #+#             */
/*   Updated: 2021/09/08 19:52:43 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int				min_value(int **temp, int j, int i)
{
	int north;
	int west;
	int nw;

	north = temp[j - 1][i];
	west = temp[j][i - 1];
	nw = temp[j - 1][i - 1];
	if (north < west && north < nw)
		return (north);
	else if (west < nw)
		return (west);
	else
		return (nw);
}

t_max_square	ft_outliers(int **temp, t_map_key key, t_max_square result)
{
	int i;
	int j;

	i = 0;
	j = 0;
	result.row = 0;
	result.column = 0;
	while (j < key.row)
	{
		i = 0;
		while (i < key.column)
		{
			if (temp[j][i] == 1)
			{
				result.max = temp[j][i];
				result.row = j;
				result.column = i;
				return (result);
				break ;
			}
			i++;
		}
		j++;
	}
	return (result);
}

t_max_square	ft_set_result(int **temp, int j, int i, t_max_square result)
{
	result.max = temp[j][i];
	result.row = j;
	result.column = i;
	return (result);
}

t_max_square	calculate_square(int **temp, t_map_key key)
{
	int				i;
	int				j;
	t_max_square	result;

	i = 1;
	j = 1;
	result.max = 0;
	while (j < key.row)
	{
		i = 1;
		while (i < key.column)
		{
			if (temp[j][i] > 0)
				temp[j][i] = 1 + min_value(temp, j, i);
			if (temp[j][i] > result.max)
			{
				result = ft_set_result(temp, j, i, result);
			}
			i++;
		}
		j++;
	}
	if (result.max == 0 || result.max == 1)
		result = ft_outliers(temp, key, result);
	return (result);
}
