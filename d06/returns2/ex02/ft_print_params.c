/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:34:09 by jtian             #+#    #+#             */
/*   Updated: 2021/08/25 16:35:59 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_params(int argc, char **argv)
{
	int count;

	count = 1;
	while (count < argc)
	{
		while (*argv[count] != '\0')
		{
			ft_putchar(*argv[count]);
			argv[count]++;
		}
		ft_putchar('\n');
		count++;
	}
}

int		main(int argc, char **argv)
{
	ft_print_params(argc, argv);
	return (0);
}
