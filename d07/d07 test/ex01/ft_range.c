/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:22:28 by jtian             #+#    #+#             */
/*   Updated: 2021/08/27 19:28:14 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *range;
	int i;

	if (min >= max)
		return (NULL);
	range = (int*)malloc(sizeof(*range) * (max - min));
	// int array don't have '\0', which is 0 in ascii code
	i = 0;
	while (min < max )
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range); 
	// it returns a int pointer points at the 1st int in the array, 0, 1, 2, 3..9
}

#include <stdio.h>

int main()
{
	int min = 0;
	int max = 9;
	int *range = ft_range(min, max);
	int i = 0;
	while (i < max - min)
	{
		printf("Index: %d, Value: %d\n", i, range[i]);
		i++;
	}
}