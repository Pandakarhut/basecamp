/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:38:14 by jtian             #+#    #+#             */
/*   Updated: 2021/09/01 21:21:08 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

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

void	ft_list_reverse(t_list **begin_list)
{
	t_list *pre;
	t_list *next;
	t_list *current;

	pre = NULL;
	current = *begin_list;
	while (current != NULL)
	{
		next = current->next;
		current->next = pre;
		pre = current;
		current = next;
	}
	*begin_list = pre;
}

int main()
{
	char c = 'c';
	t_list *test = ft_create_elem(&c);
	
    char d = 'd';
	ft_list_push_back(&test, &d);
	
	void *data = test->data; //Should be c.
	char *char_data = (char*)data;
	char value = *char_data;
	printf("First %c\n", value);

	//Reverse list
	ft_list_reverse(&test);
	printf("Reversed...\n");
	
	data = test->data; //Should be d.
	char_data = (char*)data;
	value = *char_data;
	printf("First %c\n", value);
	
	return(0);
}