/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:37:34 by jtian             #+#    #+#             */
/*   Updated: 2021/08/26 13:26:18 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_rev_params(int argc, char **argv)
{
	while (argc >= 2)
	{
		while (*argv[argc - 1])
		{
			ft_putchar(*argv[argc - 1]);
			argv[argc - 1]++;
		}
		ft_putchar('\n');
		argc--;
	}
}

int		main(int argc, char **argv)
{
	ft_rev_params(argc, argv);
	return (0);
}
