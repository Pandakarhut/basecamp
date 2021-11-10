/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:43:20 by jtian             #+#    #+#             */
/*   Updated: 2021/09/01 12:43:29 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_any(char **tab, int (*f)(char*))
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

//
int ft_is_dog(char *entry)
{
	if (entry[0] == 'd' && entry[1] == 'o' && entry[2] == 'g')
		return (1);
	return (0);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	int has_dog;
	has_dog = ft_any(argv, ft_is_dog);
	printf("%d", has_dog);
	return(0);
}
