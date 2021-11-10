/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:45:05 by jtian             #+#    #+#             */
/*   Updated: 2021/09/02 20:08:07 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	print_file(char *filename)
{
	int		file;
	char	character;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return ;
	while (read(file, &character, 1))
		write(1, &character, 1);
	close(file);
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		print_file(argv[1]);
	return (0);
}
