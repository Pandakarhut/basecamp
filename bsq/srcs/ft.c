/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:41:34 by deelliot          #+#    #+#             */
/*   Updated: 2021/09/08 17:20:51 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
	{
		ft_putchar(str[c]);
		c++;
	}
}

void	ft_puterror(char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
	{
		write(2, &str[c], 1);
		c++;
	}
}

void	ft_putnbr(int nb)
{
	long int a;

	a = nb;
	if (a < 0)
	{
		ft_putchar('-');
		a = -a;
	}
	if (a / 10 != 0)
	{
		ft_putnbr(a / 10);
	}
	ft_putchar(a % 10 + '0');
}

int		ft_atoi(char *str)
{
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}
