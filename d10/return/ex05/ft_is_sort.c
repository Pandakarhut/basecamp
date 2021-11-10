/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:46:09 by jtian             #+#    #+#             */
/*   Updated: 2021/09/01 12:51:09 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int had_minus;
	int had_plus;

	i = 0;
	had_minus = 0;
	had_plus = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			had_minus = 1;
		if (f(tab[i], tab[i + 1]) > 0)
			had_plus = 1;
		i++;
	}
	if (had_minus && had_plus)
		return (0);
	return (1);
}

//
int ft_compare(int num1, int num2)
{
	if (num1 < num2)
		return (-1);
	else if (num1 > num2)
		return (1);
	return (0);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	int nums[3];
	nums[0] = 1;
	nums[1] = 0;
	nums[2] = 3;

	int is_sorted = ft_is_sort(nums, 3, ft_compare);
	printf("Is sorted: %d", is_sorted);
	return(0);
}
