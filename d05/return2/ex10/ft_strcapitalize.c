/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:53:43 by jtian             #+#    #+#             */
/*   Updated: 2021/08/24 20:13:16 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (i == 0)
				str[i] -= 32;
			else if (!(str[i - 1] >= '0' && str[i - 1] <= '9')
				&& !(str[i - 1] >= 'a' && str[i - 1] <= 'z')
				&& !(str[i - 1] >= 'A' && str[i - 1] <= 'Z'))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}

int main()
{
	char name[10] = "j iJJN aY";
	char *text = ft_strcapitalize(name);
	printf("%s",text);
	return(0);
}