/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:31:53 by deelliot          #+#    #+#             */
/*   Updated: 2021/09/08 18:32:49 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			map_is_empty(int r, char ch)
{
	if (r == 0 || ch != '\n')
		return (-1);
	return (0);
}

int			is_ch_invalid(int r, char ch, t_map_key key)
{
	if (r >= 1 && (ch != key.empty && ch != key.obstacle && ch != '\n'))
		return (1);
	else
		return (0);
}

int			ft_check_if_invalid(int fd, t_map_key key)
{
	int		i;
	int		r;
	char	ch;

	i = 0;
	r = 0;
	while (read(fd, &ch, 1) > 0)
	{
		if (ch == '\n')
		{
			if ((r >= 1 && i != key.column) || key.column == 0)
				return (-1);
			else
				i = 0;
			r++;
		}
		else
		{
			if ((r == 1 && i == 0 && ch == '\n') || is_ch_invalid(r, ch, key))
				return (-1);
			i++;
		}
	}
	return (map_is_empty(r, ch));
}
