/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:40:29 by jtian             #+#    #+#             */
/*   Updated: 2021/09/02 19:25:16 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
void *data_ref, int (*cmp)(void *, void *))
{
	t_list *list_ptr;

	list_ptr = begin_list;

	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
		{
			(*f)(list_ptr->data);
		}
		list_ptr = list_ptr->next;
	}
}

//Testing

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

int	ft_strcmp(void *s1, void *s2)
{
	int index;

	char *s1char = (char*)s1;
	char *s2char = (char*)s2;
	

	index = 0;
	while (*(s1char + index) == *(s2char + index) && *(s1char + index) && *(s2char + index))
	{
		index++;
	}
	return (*(s1char + index) - *(s2char + index));
}

void ft_change(void *data)
{
	char *str;
	str = (char*)data;
	str[0] = 'x';
	str[1] = 'y';
	str[2] = 'z';
	str[3] = '\0';
}

int main()
{
	char *str = malloc(sizeof(char) * 4);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';
	
	t_list *test = ft_create_elem(str);
	
    char *str2 = malloc(sizeof(char) * 4);;
	str2[0] = 'Q';
	str2[1] = 'u';
	str2[2] = 'a';
	str2[3] = '\0';
	ft_list_push_back(&test, str2);

	void *data = test->data; //Should be abc.
	char *char_data = (char*)data;
	printf("First %s\n", char_data);
	
	data = test->next->data; //Should be def.
	char_data = (char*)data;
	printf("Second %s\n", char_data);
	
	char data_ref[4] = "Qua"; //Apply ft_change function if value of element data is "def".
	ft_list_foreach_if(test, ft_change, (void*)data_ref, ft_strcmp);
	
	data = test->data; //Should be NULL.
	char_data = (char*)data;
	printf("First %s\n", char_data);
	
	data = test->next->data; //Should be def.
	char_data = (char*)data;
	printf("Second %s\n", char_data);
	
	return(0);
}