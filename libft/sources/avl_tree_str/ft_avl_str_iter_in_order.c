/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_iter_in_order.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 21:58:24 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/06 18:08:37 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_str.h"

void	ft_avl_iter_in_order(t_avl_node *node, void (*f)(t_avl_node *node))
{
	if (node != NULL)
	{
		ft_avl_iter_in_order(node->left, f);
		f(node);
		ft_avl_iter_in_order(node->right, f);
	}
}
