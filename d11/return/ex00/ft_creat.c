#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->next = NULL;
		list->data = data; //*data is a void ptr, list->data is also a void ptr
	}
	return(list);
}

char a;
a = 'c';

char *ptr;
ptr = &a;
*ptr = 'd';

write(1, &a, 1);
write(1, "c", 1);