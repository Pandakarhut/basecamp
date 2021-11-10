/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:45:40 by jtian             #+#    #+#             */
/*   Updated: 2021/08/18 23:57:09 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int first;
	int second;
	int third;

	first = 0;
	while (first <= 7)
	{
		second = first + 1;
		while (second <= 8)
		{
			third = second + 1;
			while (third <= 9)
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
			third++;
		}
		second++;
	}
	first++;
}
