/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_str_free_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:03:49 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/23 19:53:16 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_str.h"

t_avl_node	*ft_avl_free_node(t_avl_node *p)
{
	if (!p)
		return (NULL);
	free(p->key);
	free(p->path);
	free(p);
	return (NULL);
}
