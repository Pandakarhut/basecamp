/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:11:15 by deelliot          #+#    #+#             */
/*   Updated: 2021/09/08 19:56:07 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_read_stdin(void)
{
	char	*filename;
	char	buf;
	int		file;

	file = open("_tmp_map.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU | S_IROTH);
	while (read(0, &buf, 1))
	{
		write(file, &buf, 1);
	}
	close(file);
	filename = "_tmp_map.txt";
	return (filename);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*filename;
	int		x;

	i = 1;
	if (argc == 1)
	{
		filename = ft_read_stdin();
		x = execute_program(filename);
		if (x == -1)
			ft_puterror("map error\n");
	}
	x = 0;
	while (i < argc)
	{
		filename = argv[i];
		x = execute_program(filename);
		if (x == -1)
			ft_puterror("map error\n");
		if (i < (argc - 1))
			ft_putchar('\n');
		i++;
	}
	return (0);
}
