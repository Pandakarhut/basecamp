/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:11:32 by deelliot          #+#    #+#             */
/*   Updated: 2021/09/09 09:59:24 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_map_key	ft_check_map(char *filename, int fd, t_map_key key)
{
	int			map_check;

	key.error = 0;
	key = ft_check_header_and_rows(filename, key, 0);
	map_check = ft_check_if_invalid(fd, key);
	if (map_check == -1)
		key.error = 1;
	return (key);
}

void		execute_part_two(t_map_key key, char **map)
{
	int				**temp;
	t_max_square	result;

	temp = ft_allocate_temp(key);
	temp = populate_temp(map, temp, key);// int array
	result = calculate_square(temp, key); // calulation
	map = ft_update_map(map, key, result); // update
	ft_print_map(map, key); // print
	free(map);
	free(temp);
}

int			execute_program(char *filename)
{
	int				fd;
	t_map_key		key;
	char			**map;

	fd = ft_open_file(filename);
	if (fd == -1)
		return (0);
	key = ft_read_file(fd);//rows columns
	close(fd);
	fd = ft_open_file(filename);
	key = ft_check_map(filename, fd, key);
	//check headers and rows and check errors(the map has the correct characters)
	if (key.error)
		return (-1);
	close(fd);
	fd = ft_open_file(filename);
	map = allocate_array(key);
	map = ft_assign_array(key, map, fd);// got the 2-dimenational char map
	close(fd);
	execute_part_two(key, map);
	return (0);
}
