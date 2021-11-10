/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:10:45 by jtian             #+#    #+#             */
/*   Updated: 2021/09/03 20:12:34 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_infix(root->left, applyf);
	(*applyf)(root->item);
	btree_apply_infix(root->right, applyf);
}

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
	btree_apply_infix(test, ft_increase);
	write(1, test->item, 1);
	return(0);
}
