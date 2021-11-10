/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:35:58 by jtian             #+#    #+#             */
/*   Updated: 2021/09/02 19:04:19 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	tmp->data = data;
	tmp->next = NULL; //points to NULL
	return (tmp);
}

//Testing
#include <stdio.h>
int main()
{
	t_list *test;
	char c = 'q';
	test = ft_create_elem(&c);
	
	void *data = test->data;
	char *char_data = (char*)data;
	char value = *char_data;
		
	printf("%c", value);
	return(0);
}