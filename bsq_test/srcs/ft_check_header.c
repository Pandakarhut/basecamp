/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:17:37 by jtian             #+#    #+#             */
/*   Updated: 2021/09/09 10:13:18 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			ft_count_newlines(char *filename)
{
	int		i;
	int		fd;
	char	ch;

	i = 0;
	fd = ft_open_file(filename);
	while (read(fd, &ch, 1) > 0)
		if (ch == '\n')
			i++;
	close(fd);
	return (i);
}

t_map_key		ft_check_digits(char *str, t_map_key key)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			key.error = 1;
		str++;
	}
	return (key);
}

t_map_key	ft_assign_keys(t_map_key key, char *keys, int len)
{
	key.empty = keys[len - 3];
	key.obstacle = keys[len - 2];
	key.full = keys[len - 1];
	return (key);
}

int			ft_calculate_length(char *filename)
{
	int		fd;
	char	ch;
	int		len;

	len = 0;
	fd = ft_open_file(filename);
	while (read(fd, &ch, 1) > 0 && ch != '\n')
		len++;
	close(fd);
	return (len);
}

t_map_key	ft_check_header_and_rows(char *filename, t_map_key key, int i)
{
	int		fd;
	char	ch;
	int		len;
	char	*header_str;

	len = ft_calculate_length(filename);
	if (len < 4)
		key.error = 1;
	else
	{
		header_str = (char*)malloc(sizeof(char) * len);
		fd = ft_open_file(filename);
		while (read(fd, &ch, 1) > 0 && ch != '\n')
			header_str[i++] = ch;
		close(fd);
		key = ft_assign_keys(key, header_str, len);
		header_str[len - 3] = '\0';
		key = ft_check_digits(header_str, key);
		if (ft_count_newlines(filename) != ft_atoi(header_str) + 1)
			key.error = 1;
	}
	return (key);
}
