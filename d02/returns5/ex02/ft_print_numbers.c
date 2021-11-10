/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:28:01 by jtian             #+#    #+#             */
/*   Updated: 2021/08/23 11:30:59 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void	ft_print_numbers(void)
{
	char i;

	i = '0';
	while (i <= '9')
	{
		ft_putchar(i);
		++i;
	}
}

/*int main() {
	ft_print_numbers();
	return(0);
}
