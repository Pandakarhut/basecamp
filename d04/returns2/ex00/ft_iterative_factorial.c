/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:08:53 by jtian             #+#    #+#             */
/*   Updated: 2021/08/22 14:14:18 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int result;
	int	multiplier;

	result = 1;
	multiplier = 1;
	if (nb < 0 || nb > 16)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	while (multiplier <= nb)
	{
		result *= multiplier;
		multiplier++;
	}
	return (result);
}

int	main()
{
	int return_value;
	for (int i = 0; i < 15; i++)
		printf("%d, %d\n", i, ft_iterative_factorial(i));

	return_value = ft_iterative_factorial(4);
	printf("%d", return_value);
	return(0);
}