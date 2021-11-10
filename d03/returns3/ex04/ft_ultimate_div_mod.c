/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:33:54 by jtian             #+#    #+#             */
/*   Updated: 2021/08/21 07:11:59 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int result;

	result = *a / *b;
	*b = *a % *b;
	*a = result;
}

int main()
{
	int number1 = 10;
	int number2 = 3;
	ft_ultimate_div_mod(&number1, &number2);
	printf("Div: %d, Mod: %d", number1, number2);
	
}