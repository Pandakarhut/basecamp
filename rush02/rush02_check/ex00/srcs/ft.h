/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:27:01 by jtian             #+#    #+#             */
/*   Updated: 2021/09/05 18:08:51 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <unistd.h>

int		ft_columns(char *str);
int		ft_rows(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_strcmp(void *s1, void *s2);
int		match_rush_00(char *input, int rows, int columns);
int		match_rush_01(char *input, int rows, int columns);
int		match_rush_02(char *input, int rows, int columns);
int		match_rush_03(char *input, int rows, int columns);
int		match_rush_04(char *input, int rows, int columns);

#endif
