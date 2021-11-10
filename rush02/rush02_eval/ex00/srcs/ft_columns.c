/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_columns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 08:09:08 by jtian             #+#    #+#             */
/*   Updated: 2021/09/05 13:33:43 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_columns(char *str)
{
	int columns;

	columns = 0;
	while (str[columns] && str[columns] != '\n')
		columns++;
	return (columns);
}
