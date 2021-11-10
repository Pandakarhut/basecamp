/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:42:22 by jtian             #+#    #+#             */
/*   Updated: 2021/09/02 19:14:24 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int		i;
	t_list	*tmp;

	if (ac <= 0)
		return (NULL);
	i = 0;
	tmp = NULL;
	while (i < ac)
	{
		list = ft_create_elem(av[i]);
		list->next = tmp;
		tmp = list;
		i++;
	}
	return (list);
}

// Testing

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

t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	while (begin_list->next != 0)
		begin_list = begin_list->next;
	return (begin_list);
}

#include <stdio.h>
int main()
{
	char **names;
	names = (char**)malloc(sizeof(char*)*3);
	names[0] = "Quong";
	names[1] = "Jing";
	names[2] = "Jill";
	
	t_list *test = ft_list_push_params(3, names);
	test = ft_list_last(test);
    
	char *value = (char*)test->data;
	printf("%s", value);
	return(0);
}