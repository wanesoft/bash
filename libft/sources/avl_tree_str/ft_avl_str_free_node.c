/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_free_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:03:49 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/06 18:08:23 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_str.h"

t_avl_node	*ft_avl_free_node(t_avl_node *p)
{
	if (!p)
		return (NULL);
	free(p->key);
	free(p);
	return (NULL);
}
