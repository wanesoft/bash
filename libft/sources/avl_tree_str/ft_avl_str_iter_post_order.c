/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_str_iter_post_order.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:17:29 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/03/25 21:15:11 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_str.h"

void	ft_avl_iter_post_order(t_avl_node *node,
								t_avl_node *(*f)(t_avl_node *node))
{
	if (node != NULL)
	{
		ft_avl_iter_post_order(node->left, f);
		ft_avl_iter_post_order(node->right, f);
		f(node);
	}
}
