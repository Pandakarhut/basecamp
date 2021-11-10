/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:39:43 by jtian             #+#    #+#             */
/*   Updated: 2021/09/01 21:28:18 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	tmp->data = data;
	tmp->next = NULL;
	return (tmp);
}

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

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

void ft_increase(void *data)
{
	int *intPtr;
	intPtr = (int*)data;
	*intPtr = *intPtr + 1;
}

int main()
{
	char c = 'c';
	t_list *test = ft_create_elem(&c);
	
    char d = 'd';
	ft_list_push_back(&test, &d);
	
	ft_list_foreach(test, ft_increase);
	
	void *data = test->data; //Should be d.
	char *char_data = (char*)data;
	char value = *char_data;
	printf("First %c\n", value);
	
	data = test->next->data; //Should be e.
	char_data = (char*)data;
	value = *char_data;
	printf("Second %c\n", value);
	
	return(0);
}