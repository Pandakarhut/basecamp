/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:41:26 by deelliot          #+#    #+#             */
/*   Updated: 2021/09/08 20:14:38 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_map_key
{
	int			row;
	int			column;
	char		empty;
	char		obstacle;
	char		full;
	int			error;
}				t_map_key;

typedef struct	s_max_square
{
	int			max;
	int			row;
	int			column;
}				t_max_square;

void			ft_putchar (char c);
void			ft_putstr(char *str);
void			ft_puterror(char *str);
void			ft_putnbr(int nb);
int				ft_atoi(char *str);
void			ft_print_map(char **map, t_map_key key);
char			**allocate_array(t_map_key key);
char			**ft_assign_array(t_map_key key, char **map, int fd);
int				ft_open_file(char *file_name);
t_map_key		ft_read_file (int fd);
int				**ft_allocate_temp(t_map_key key);
int				**populate_temp(char **map, int **temp, t_map_key key);
t_max_square	calculate_square (int **temp, t_map_key key);
char			**ft_update_map(char **map, t_map_key key, t_max_square result);
int				execute_program(char *filename);
int				ft_check_if_invalid(int fd, t_map_key key);
t_map_key		ft_check_header_and_rows(char *filename, t_map_key key, int i);

#endif
