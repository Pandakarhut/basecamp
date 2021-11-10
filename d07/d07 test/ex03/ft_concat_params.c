/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:26:31 by jtian             #+#    #+#             */
/*   Updated: 2021/08/27 19:47:53 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_params_length(int argc, char **argv)
{
	int		length;
	int		arg_index;
	int		char_index;

	length = 0;
	arg_index = 1;
	char_index = -1;
	while (arg_index < argc)
	{
		while (argv[arg_index][++char_index] != '\0')
			length++;
		char_index = -1;
		length++;
		arg_index++;
	}
	return (length);
}

tianjing joonas hive\0

char	*ft_concat_params(int argc, char **argv)
{
	char	*params;
	int		arg_index;
	int		char_index;
	int		string_index;

	arg_index = 0;
	char_index = -1;
	string_index = 0;
	params = (char*)malloc(sizeof(char) * get_params_length(argc, argv));
	while (++arg_index < argc)
	{
		while (argv[arg_index][(++char_index)] != '\0')
			params[string_index++] = argv[arg_index][char_index];
		char_index = -1;
		params[string_index] = '\n';
		string_index++;
	}
	params[string_index - 1] = '\0';
	return (params);
}

#include <stdio.h>

int main(int argc, char **argv) {
	char *params;
	params = ft_concat_params(argc, argv);
	printf("%s", params);
	return(0);
}