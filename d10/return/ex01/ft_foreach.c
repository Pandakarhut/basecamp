/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:19:03 by jtian             #+#    #+#             */
/*   Updated: 2021/09/01 09:12:45 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

#include <stdio.h>
void ft_print(int num)
{
	printf("%d ", num);
}

int main()
{
	int nums[3];
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	ft_foreach(nums, 3, ft_print);
	return(0);
}