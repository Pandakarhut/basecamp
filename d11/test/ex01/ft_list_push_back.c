/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:42:22 by jtian             #+#    #+#             */
/*   Updated: 2021/09/02 19:04:58 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

//Testing functions

t_list	*ft_create_elem(void *data)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	tmp->data = data;
	tmp->next = NULL;
	return (tmp);
}

#include <stdio.h>
int main()
{

	char c = 'a';
	t_list *test = ft_create_elem(&c);
	
    char d = 'b';
	ft_list_push_back(&test, &d);
	
	void *data = test->next->data; //Should be d.
	char *char_data = (char*)data; //casting
	char value = *char_data;
		
	printf("%c", value);
	return(0);
}