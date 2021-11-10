/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:24:04 by jtian             #+#    #+#             */
/*   Updated: 2021/08/26 17:24:12 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *numbers;
	int i;
	int length;

	i = 0;
	length = max - min;
	if (min >= max)
	{
		numbers = NULL;
		return (0);
	}
	numbers = malloc(sizeof(int) * length);
	while (min < max)
		numbers[i++] = min++;
	*range = numbers;
	return (length);
}
