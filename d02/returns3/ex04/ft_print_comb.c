/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:45:40 by jtian             #+#    #+#             */
/*   Updated: 2021/08/19 19:24:34 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_comb(void)
{
	int first;
	int second;
	int third;

	first = -1;
	while (++first <= 7)
	{
		second = first;
		while (++second <= 8)
		{
			third = second;
			while (++third <= 9)
			{
				ft_putchar(first + '0');
				ft_putchar(second + '0');
				ft_putchar(third + '0');
				if (first + second + third < 24)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
