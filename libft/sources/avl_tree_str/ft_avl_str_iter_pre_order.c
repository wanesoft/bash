/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_iter_pre_order.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:19:48 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/06 18:08:48 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_str.h"

void	ft_avl_iter_pre_order(t_avl_node *node, void (*f)(t_avl_node *node))
{
	if (node != NULL)
	{
		f(node);
		ft_avl_iter_pre_order(node->left, f);
		ft_avl_iter_pre_order(node->right, f);
	}
}
