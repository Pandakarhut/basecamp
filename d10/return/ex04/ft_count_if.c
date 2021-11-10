/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:44:14 by jtian             #+#    #+#             */
/*   Updated: 2021/09/01 12:44:31 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (tab[i])
	{
		count += f(tab[i]);
		i++;
	}
	return (count);
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
	int count_of_dogs = ft_count_if(argv, ft_is_dog);
	printf("Number of dogs: %d\n", count_of_dogs);
	return(0);
}
