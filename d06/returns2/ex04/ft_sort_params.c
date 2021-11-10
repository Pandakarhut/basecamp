/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:41:47 by jtian             #+#    #+#             */
/*   Updated: 2021/08/26 12:22:18 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int index;

	index = 0;
	while (*(s1 + index) == *(s2 + index) && *(s1 + index) && *(s2 + index))
	{
		index++;
	}
	return (*(s1 + index) - *(s2 + index));
}

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
	int		arg;
	char	*temp;

	if (argc > 1)
	{
		arg = 1;
		while (arg < argc - 1)
		{
			if (ft_strcmp(argv[arg], argv[arg + 1]) > 0)
			{
				temp = argv[arg];
				argv[arg] = argv[arg + 1];
				argv[arg + 1] = temp;
				arg = 1;
			}
			else
				arg++;
		}
		ft_print_params(argc, argv);
	}
	return (0);
}
