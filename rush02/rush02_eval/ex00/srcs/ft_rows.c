/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 08:09:08 by jtian             #+#    #+#             */
/*   Updated: 2021/09/05 13:32:47 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_rows(char *str)
{
	int i;
	int rows;

	i = 0;
	rows = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			rows++;
		i++;
	}
	return (rows);
}
