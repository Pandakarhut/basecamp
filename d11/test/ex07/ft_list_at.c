/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:36:28 by jtian             #+#    #+#             */
/*   Updated: 2021/09/02 17:07:24 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	if (!begin_list)
		return (NULL);
	i = 0;
	while (i < nbr)
	{
		if (begin_list->next)
			begin_list = begin_list->next;
		else
			return (NULL);
		i++;
	}
	return (begin_list);
}

//Testing
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

#include <stdio.h>
int main()
{

	char c = 'c';
	t_list *test = ft_create_elem(&c);
	
    char d = 'd';
	ft_list_push_back(&test, &d);
	
	t_list *first = ft_list_at(test, 0);
	t_list *second = ft_list_at(test, 1);
	
	void *data = first->data; //Should be c.
	char *char_data = (char*)data;
	char value = *char_data;
	printf("%c\n", value);
	
	data = second->data; //Should be d
	char_data = (char*)data;
	value = *char_data;
	printf("%c\n", value);
	
	return(0);
}