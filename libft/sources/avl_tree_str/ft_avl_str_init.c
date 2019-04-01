/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_str_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:39:00 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/01 03:18:43 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_str.h"

t_avl_node	*ft_avl_init(const char *k, const char *path)
{
	t_avl_node	*node;

	node = (t_avl_node *)malloc(sizeof(t_avl_node));
	if (node)
	{
		node->key = ft_strdup(k);
		node->path = ft_strjoin_free(path, ft_strjoin("/", k), 2);
		node->left = NULL;
		node->right = NULL;
		node->height = 1;
	}
	return (node);
}
