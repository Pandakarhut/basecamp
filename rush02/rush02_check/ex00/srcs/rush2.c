/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 07:56:29 by jtian             #+#    #+#             */
/*   Updated: 2021/09/06 14:00:30 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		print_match(int rush, int columns, int rows, int *match_count)
{
	if (*match_count > 0)
		ft_putstr(" || ");
	if (rush == 0)
		ft_putstr("[rush-00] [");
	if (rush == 1)
		ft_putstr("[rush-01] [");
	if (rush == 2)
		ft_putstr("[rush-02] [");
	if (rush == 3)
		ft_putstr("[rush-03] [");
	if (rush == 4)
		ft_putstr("[rush-04] [");
	ft_putnbr(columns);
	ft_putstr("] [");
	ft_putnbr(rows);
	ft_putstr("]");
	(*match_count)++; //increase the value of match_count
}

// we use pointer here for *match_count, other fuctions can use it and change the value of it so that we don't need to increase the value here
// the fuction will be under 25 lines and looks cleaner

void		check_rushes(char *input, int rows, int columns, int *match_count)
{
	if (match_rush_00(input, rows, columns))
		print_match(0, columns, rows, match_count);
	if (match_rush_01(input, rows, columns))
		print_match(1, columns, rows, match_count);
	if (match_rush_02(input, rows, columns))
		print_match(2, columns, rows, match_count);
	if (match_rush_03(input, rows, columns))
		print_match(3, columns, rows, match_count);
	if (match_rush_04(input, rows, columns))
		print_match(4, columns, rows, match_count);
}

void		ft_copy_input(char *src, char *dest, int nb) // copy all the bytes from *src to *dest
{
	int i;

	i = 0;
	while (i < nb)
	{
		dest[i] = src[i];
		i++;
	}
}

char		*get_pipe_value(char *input)
{
	char	buf;
	int		i;
	int		max; 
	char	*tmp_buffer;

	i = 0;
	max = 2; //starting from 2, if the input is only one character + '\0'
	while (read(0, &buf, 1) != 0)
	{
		//the solution for the uncertain input size
		if (i == max - 1) // -1 for the '\0'
		{
			max = max * 2; //enlarge max 2 times
			tmp_buffer = (char*)malloc(sizeof(char) * max); //enlarge allocated spaces 2 times
			ft_copy_input(input, tmp_buffer, i = 1); //copy input into tmp_buffer
			free(input); 
			input = (char*)malloc(sizeof(char) * max);
			ft_copy_input(tmp_buffer, input, i); //copy tmp_buffer into input
			free(tmp_buffer);
		}
		input[i] = buf;
		i++;
	}
	input[i] = '\0'; // '\0' will be printed here
	return (input);
}

int			main(void)
{
	char	*input; //pointer to the given character string e.g. "ABBA" or "o-----o" from rush00/rush01/rush02 etc.
	int		rows;
	int		columns;
	int		match_count; //how many matches our rush2.c program found, will be used as a pointer in other fuctions

	match_count = 0;
	input = (char*)malloc(sizeof(char) * 2); //starting from 2, if the input is only one character + '\0'
	input = get_pipe_value(input); //1st function: 
	rows = ft_rows(input); //2nd function: to get the number of rows
	columns = ft_columns(input); //3rd function: to get the number of columns
	if (rows == 0 || columns == 0)
	{
		ft_putstr("aucune\n");
		return (0);
	}
	//the main solution function: check_rushes
	// 1)check how many rushes it fits; 
	// 2)change the match_count number;
	// 3)print the matched result.
	
	check_rushes(input, rows, columns, &match_count); //&match_count, the memory address
	if (match_count == 0)
		ft_putstr("aucune\n");
	else
		ft_putstr("\n");
	free(input); //free the allocated memeory address so that other programm can use later, always a good habitation to free after malloc
	return (0);
}
