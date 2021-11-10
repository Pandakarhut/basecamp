/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:29:24 by jtian             #+#    #+#             */
/*   Updated: 2021/08/31 20:25:40 by jtian            ###   ########.fr       */
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

int		ft_atoi(char *str)
{
	int sign;
	int result;

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

int		ft_calculate(int nb1, int nb2, char op)
{
	if (op == '+')
		return (nb1 + nb2);
	else if (op == '-')
		return (nb1 - nb2);
	else if (op == '*')
		return (nb1 * nb2);
	else if (op == '/')
		return (nb1 / nb2);
	else if (op == '%')
		return (nb1 % nb2);
	return (0);
}

int		main(int argc, char **argv)
{
	int		nb1;
	int		nb2;
	char	op;
	int		result;

	if (argc != 4)
		return (0);
	nb1 = ft_atoi(argv[1]);
	nb2 = ft_atoi(argv[3]);
	op = argv[2][0];
	if (op != '+' && op != '-' && op != '/' && op != '*'
			&& op != '%' && argv[2][1] != '\0')
		write(1, "0\n", 2);
	else if (op == '/' && nb2 == 0)
		write(1, "Stop : division by zero\n", 24);
	else if (op == '%' && nb2 == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
	{
		result = ft_calculate(nb1, nb2, op);
		ft_putnbr(result);
		ft_putchar('\n');
	}
	return (0);
}
