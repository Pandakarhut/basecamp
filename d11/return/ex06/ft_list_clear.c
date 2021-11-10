/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:35:20 by jtian             #+#    #+#             */
/*   Updated: 2021/09/01 21:07:06 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:42:22 by jtian             #+#    #+#             */
/*   Updated: 2021/09/01 20:44:10 by jtian            ###   ########.fr       */
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

void	ft_list_clear(t_list **begin_list)
{
	t_list *current;
	t_list *tmp;

	current = *begin_list;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*begin_list = NULL;
}

//Testing
#include <stdio.h>
int main()
{

	char c = 'c';
	t_list *test = ft_create_elem(&c);
	
    char d = 'd';
	ft_list_push_back(&test, &d);
	
	void *data = test->next->data; //Should be d.
	char *char_data = (char*)data;
	char value = *char_data;
		
	printf("%c\n", value);

	//Now lets empty the list
	ft_list_clear(&test);

	if (test == NULL)
		printf("works");
	else
		printf("didnt work");
	
	return(0);
}