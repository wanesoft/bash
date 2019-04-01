/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:43:33 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/06 18:08:55 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_str.h"

static t_avl_node	*ft_avl_findmin(t_avl_node *p)
{
	return ((p->left != NULL) ? ft_avl_findmin(p->left) : p);
}

static t_avl_node	*findmin_to_remove(t_avl_node *p)
{
	if (p->left == NULL)
		return (p->right);
	p->left = findmin_to_remove(p->left);
	return (ft_avl_balance(p));
}

static t_avl_node	*ft_for_remove_node(t_avl_node *p)
{
	t_avl_node	*l;
	t_avl_node	*r;
	t_avl_node	*min;

	l = p->left;
	r = p->right;
	ft_avl_free_node(p);
	if (!r)
		return (l);
	min = ft_avl_findmin(r);
	min->right = findmin_to_remove(r);
	min->left = l;
	return (ft_avl_balance(min));
}

t_avl_node			*ft_avl_remove(t_avl_node *p, const char *k)
{
	int	cmp;

	if (!p)
		return (NULL);
	cmp = ft_strcmp(p->key, k);
	if (cmp < 0)
		p->left = ft_avl_remove(p->left, k);
	else if (cmp > 0)
		p->right = ft_avl_remove(p->right, k);
	else
		return (ft_for_remove_node(p));
	return (ft_avl_balance(p));
}
