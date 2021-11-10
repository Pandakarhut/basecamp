/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 13:16:00 by deelliot          #+#    #+#             */
/*   Updated: 2021/08/29 20:07:19 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_rows(int i, int y, int **array)
{
	int x;

	x = 0;
	while (x < 9)
	{
		if (array[y][x] != i)
		{
			x++;
		}
		else
		{
			return (0);
			break ;
		}
	}
	return (1);
}

int	check_column(int i, int x, int **array)
{
	int y;

	y = 0;
	while (y < 9)
	{
		if (array[y][x] != i)
		{
			y++;
		}
		else
		{
			return (0);
			break ;
		}
	}
	return (1);
}

int	change_x_coordinates(int x)
{
	if (x < 3)
	{
		return (0);
	}
	else if (x < 6)
	{
		return (3);
	}
	else
	{
		return (6);
	}
}

int	change_y_coordinates(int y)
{
	if (y < 3)
	{
		return (0);
	}
	else if (y < 6)
	{
		return (3);
	}
	else
	{
		return (6);
	}
}

int	check_grid(int x, int y, int i, int **array)
{
	int j;
	int k;
	int original_j;
	int original_k;

	k = change_y_coordinates(y);
	j = change_x_coordinates(x);
	original_k = k;
	original_j = j;
	while (k < original_k + 3)
	{
		while (j < original_j + 3)
		{
			if (array[k][j] != i)
				j++;
			else
			{
				return (0);
				break ;
			}
		}
		j = original_j;
		k++;
	}
	return (1);
}
