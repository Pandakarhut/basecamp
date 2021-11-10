/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:51:39 by jtian             #+#    #+#             */
/*   Updated: 2021/09/06 11:15:44 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strcmp(char *s1, char *s2)
{
	int index;

	index = 0;
	while (*(s1 + index) == *(s2 + index) && *(s1 + index) && *(s2 + index))
	{
		index++;
	}
	return (*(s1 + index) - *(s2 + index));
}

#include <stdio.h>

int main()
{
	char s1[] = "Tian";
	char s2[] = "Tian";
	printf("%d", ft_strcmp(s1, s2));
	return(0);
}