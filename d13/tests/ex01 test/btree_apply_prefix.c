/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:06:22 by jtian             #+#    #+#             */
/*   Updated: 2021/09/03 20:09:58 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree *btree;

	btree = (t_btree*)malloc(sizeof(t_btree));
	if (btree)
	{
		btree->left = 0;
		btree->right = 0;
		btree->item = item;
	}
	return (btree);
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	(*applyf)(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}

void ft_increase(void *item)
{
	char *charPtr = (char*)item;
	*charPtr = *charPtr + 1;
}

#include <unistd.h>
int main()
{
	t_btree *test;
	char c = 'c';
	char *charPtr;
	charPtr = &c;
	test = btree_create_node(charPtr);
	write(1, test->item, 1);
	btree_apply_prefix(test, ft_increase);
	write(1, test->item, 1);
	return(0);
}
