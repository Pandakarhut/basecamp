/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:24:04 by jtian             #+#    #+#             */
/*   Updated: 2021/08/27 18:48:34 by jtian            ###   ########.fr       */
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
	numbers = (int*)malloc(sizeof(int) * length);
	while (min < max)
		numbers[i++] = min++;
	*range = numbers;
	return (length);
}


#include <stdio.h>
int main()
{
	int min = 0;
	int max = 9;
	int *range;
	int size = ft_ultimate_range(&range, min, max);
	// & in front of an variable ,it gives the address of that particular variable
	int i = 0;
	while (i < size)
	{
		printf("Index: %d, Value: %d\n", i, range[i]);
		i++;
	}
}
