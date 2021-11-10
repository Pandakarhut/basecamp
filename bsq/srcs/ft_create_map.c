/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:19:35 by deelliot          #+#    #+#             */
/*   Updated: 2021/09/08 19:52:57 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char		**allocate_array(t_map_key key)
{
	int		i;
	char	**array;

	i = 0;
	array = (char **)malloc((key.row + 1) * sizeof(char *));
	while (i < key.row)
	{
		array[i] = (char *)malloc((key.column + 1) * sizeof(char));
		i++;
	}
	if (array == NULL)
		return (NULL);
	else
		return (array);
}

char		**ft_assign_array(t_map_key key, char **map, int fd)
{
	int		i;
	int		j;
	char	ch;

	j = 0;
	while (read(fd, &ch, 1) > 0)
	{
		if (ch == '\n')
			break ;
	}
	while (j < key.row)
	{
		i = 0;
		while (i < key.column)
		{
			read(fd, &ch, 1);
			if (ch != '\n')
			{
				map[j][i] = ch;
				i++;
			}
		}
		j++;
	}
	return (map);
}

int			ft_open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("Error: unable to open file\n");
		return (-1);
	}
	return (fd);
}

t_map_key	get_map_key(int fd, t_map_key key, char ch)
{
	key.empty = ch;
	read(fd, &ch, 1);
	key.obstacle = ch;
	read(fd, &ch, 1);
	key.full = ch;
	return (key);
}

t_map_key	ft_read_file(int fd)
{
	int			r;
	int			c;
	char		ch;
	t_map_key	key;

	c = 0;
	r = 0;
	while (read(fd, &ch, 1) > 0)
	{
		if (r == 1 && ch != '\n')
			c++;
		if (ch == '\n')
			r++;
	}
	key.row = r - 1;
	key.column = c;
	return (key);
}
