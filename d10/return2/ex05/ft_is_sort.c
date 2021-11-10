/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:46:09 by jtian             #+#    #+#             */
/*   Updated: 2021/08/30 21:06:00 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int had_minus;
	int had_plus;

	i = 0;
	had_minus = 0;
	had_plus = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			had_minus = 1;
		if (f(tab[i], tab[i + 1]) > 0)
			had_plus = 1;
		i++;
	}
	if (had_minus && had_plus)
		return (0);
	return (1);
}
