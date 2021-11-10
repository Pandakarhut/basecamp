/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:01:32 by jtian             #+#    #+#             */
/*   Updated: 2021/08/23 15:24:55 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		get_bottom_width(int size)
{
	int section;
	int characters;
	int layer;

	section = 1;
	characters = 1;
	layer = 4;
	while (section <= size)
	{
		characters += 2 * (2 + section);
		section++;
		characters += layer;
		if (section < size && section % 2 == 1)
			layer += 2;
	}
	return (characters - layer);
}

void	write_characters(int size, int section, int layer, int chars)
{
	int door;
	int x;

	door = 2 * ((section - 1) / 2) + 1;
	x = 0;
	while (x < chars)
	{
		if (x == 0)
			ft_putchar('/');
		else if (x == chars - 1)
			ft_putchar('\\');
		else
		{
			// First check if the next character is in the door area.
			if (section == size && x < (chars + door) / 2
					&& x >= (chars - door) / 2 && section - layer + 3 <= door)
				// Next if checks if we are exactly where the door handle should be.
				if (door > 4 && layer == section - door / 2 + 2
						&& x == (chars + door) / 2 - 2)
					ft_putchar('$');
				else
					ft_putchar('|');
			else
				ft_putchar('*');
		}
		x++;
	}
}

void	write_spaces(int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putchar(' ');
		i++;
	}
}

void	sastantua(int size)
{
	int section;
	int	layers;
	int	layer;
	int	characters;

	if (size > 0)
	{
		section = 1;
		characters = 1;
		while (section <= size)
		{
			layer = 1;
			layers = 2 + section;
			while (layer <= layers)
			{
				characters += 2;
				write_spaces((get_bottom_width(size) - characters) / 2);
				write_characters(size, section, layer, characters);
				ft_putchar('\n');
				layer++;
			}
			characters += 4 + 2 * ((section - 1) / 2);
			section++;
		}
	}
}
