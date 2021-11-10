/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:47:29 by jtian             #+#    #+#             */
/*   Updated: 2021/08/25 08:11:07 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int index;

	index = 0;
	while (*(to_find + index) && *(str + index))
	{
		if (*(to_find + index) != *(str + index))
		{
			str++;
			index = 0;
		}
		else
		{
			index++;
		}
	}
	if (*(to_find + index) == '\0')
		return (str);
	return (0);
}

int main()
{
	char s1[5] = "Tian";
	char s2[5] = "o";
	printf("%s", ft_strstr(s1,s2));
	return(0);
}