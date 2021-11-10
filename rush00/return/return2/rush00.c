/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 07:13:13 by jtian             #+#    #+#             */
/*   Updated: 2021/08/22 08:53:24 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_first_line(int x) 
{
	ft_putchar('o'); 
	
	while (x > 2)
	{
		ft_putchar('-');
		x = x - 1;
	}
	if (x > 1)
		ft_putchar('o');
	ft_putchar('\n');
}

void	ft_print_middle_line(int x)
{
	ft_putchar('|');
	
	while (x > 2)
	{
		ft_putchar(' ');
		x = x - 1;
	}
	if (x > 1)
		ft_putchar('|');
	ft_putchar('\n');
}

void	ft_print_last_line(int x)
{
	ft_putchar('o');
	
	while (x > 2)
	{
		ft_putchar('-');
		x = x - 1;
	}
	if (x > 1)
		ft_putchar('o');
}

void	rush(int x, int y) 
{
	ft_print_first_line(x);

	while (y > 2)
	{
		ft_print_middle_line(x);
		y--;
	}
	if (y > 1)
		ft_print_last_line(x);
}