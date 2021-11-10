/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:24:30 by jtian             #+#    #+#             */
/*   Updated: 2021/08/27 18:42:29 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*duplicate;
	int 	bytes;
	int		i;

	i = 0;
	while (src[i])
		i++;

	bytes = 1 * (i + 1);
	duplicate = (char*)malloc(bytes);
	
	if (!duplicate) 
		return (NULL);
	// it will return 0, when malloc didn't reserve any memory address
	
	i = 0;
	while (src[i])
	{
		duplicate[i] = src[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

if (!(duplicate = (char*)malloc(sizeof(char) * (i + 1)))) 
// 5 bytes of memories, it returns a ptr to the 1st byte it reserved, will be converted into a char ptr.
// char *duplicate now points to the 1st memory address reserved by malloc.

int main()
{
	char name[] = "Jing";
	char *result;
	result = ft_strdup(name);
	printf("%s", result);
	return(0);
}
