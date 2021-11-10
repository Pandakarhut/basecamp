/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:27:12 by jtian             #+#    #+#             */
/*   Updated: 2021/08/26 17:27:43 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_word_count(char *str)
{
	int i;
	int valid_word;
	int word_count;

	i = 0;
	valid_word = 0;
	word_count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
		{
			valid_word = 1;
			i++;
		}
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
		{
			word_count += valid_word;
			valid_word = 0;
			i++;
		}
	}
	return (word_count);
}

int		ft_w_l(char *str, int i)
{
	int char_count;

	char_count = 0;
	while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
	{
		char_count++;
		i++;
	}
	return (char_count);
}

char	**ft_split_whitespaces(char *str)
{
	char	**words;
	int		i;
	int		w;
	int		c;

	i = 0;
	w = 0;
	if ((words = malloc(sizeof(char*) * (ft_word_count(str) + 1))) == NULL)
		return (NULL);
	while (str[i])
	{
		while ((str[i] == '\t' || str[i] == ' ' || str[i] == '\n') && str[i])
			i++;
		if (str[i])
		{
			c = 0;
			if ((words[w] = malloc(sizeof(char) * ft_w_l(str, i) + 1)) == NULL)
				return (NULL);
			while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
				words[w][c++] = str[i++];
			words[w++][c] = '\0';
		}
	}
	words[w] = NULL;
	return (words);
}
