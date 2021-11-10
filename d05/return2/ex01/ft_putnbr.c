/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:33:27 by jtian             #+#    #+#             */
/*   Updated: 2021/08/24 20:45:54 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	negative_extra;

	negative_extra = 0;
	if (nb == -2147483648)
	{
		negative_extra = 1;
		nb++;
	}
	if (nb < 0)
	{
		nb *= (-1);
		ft_putchar('-');
	}
	if (nb >= 0 && nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + negative_extra + '0');
	}
}

int main()
{
	ft_putnbr(12345);
	return(0);
}