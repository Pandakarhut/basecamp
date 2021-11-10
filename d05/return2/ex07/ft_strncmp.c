/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:54:36 by jtian             #+#    #+#             */
/*   Updated: 2021/09/06 11:40:14 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int index;

	index = 0;
	while (*(s1 + index) == *(s2 + index) && *(s1 + index) && *(s2 + index))
	{
		index++;
		if (index == n)
			return (0);
	}
	return (*(s1 + index) - *(s2 + index));
}

#include <stdio.h>

int main()
{
	char s1[5] = "Rush";
	char s2[5] = "Rush";
	printf("%d", ft_strncmp(s1,s2,2));
	return(0);
}