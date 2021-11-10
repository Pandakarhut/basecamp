/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:13:05 by jtian             #+#    #+#             */
/*   Updated: 2021/08/25 16:33:36 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	if (argc > 0)
	{
		while (*argv[0])
		{
			ft_putchar(*argv[0]);
			argv[0]++;
		}
		ft_putchar('\n');
	}
	return (0);
}
