/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:42:37 by jtian             #+#    #+#             */
/*   Updated: 2021/09/01 12:14:14 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *result;

	result = (int*)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}

int ft_increase(int num)
{
	return (num + 1);
}

#include <stdio.h>

int main()
{
	int nums[3];
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	int *nums2;
	nums2 = ft_map(nums, 3, ft_increase);
	printf("%d %d %d", nums2[0], nums2[1], nums2[2]);
	return(0);
}
