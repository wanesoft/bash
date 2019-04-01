/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:35:44 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/06 18:08:34 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_str.h"

t_avl_node	*ft_avl_insert(t_avl_node *p, const char *k, const char *path)
{
	int	cmp;

	if (!p)
		return (ft_avl_init(k, path));
	cmp = ft_strcmp(p->key, k);
	if (cmp < 0)
		p->left = ft_avl_insert(p->left, k, path);
	else
		p->right = ft_avl_insert(p->right, k, path);
	return (ft_avl_balance(p));
}
