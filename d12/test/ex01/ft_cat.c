/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:47:36 by jtian             #+#    #+#             */
/*   Updated: 2021/09/02 15:47:44 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_print_stdin(void)
{
	char buf;
	
	while (read(0, &buf, 1) != 0)
		write(1, &buf, 1);
}

void	ft_print_file(char *file)
{
	char buf;
	int fd;

	if (file[0] == '-')
		ft_print_stdin();
	else
	{
		fd = open(file, O_RDONLY);
		if (fd >= 0 )
		{
			while (read(fd, &buf, 1))
				write(1, &buf, 1);
		}
		else
		{
			ft_putstr("ft_cat: ");
			ft_putstr(file);
			ft_putstr(": No such file or directory\n");
		}
		close(fd);
	}
}

int		main(int ac, char **av)
{
	int i;

	i = 1;	
	if (ac < 2)
		ft_print_stdin();
	else
	{
		while (i < ac)
		{
			ft_print_file(av[i]);
			i++;
		}
	}
	return (0);
}
