/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:38:45 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/06 18:08:59 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_str.h"

t_avl_node	*ft_avl_search(t_avl_node *p, const char *k)
{
	int	compare;

	if (!p)
		return (NULL);
	compare = ft_strcmp(p->key, k);
	if (compare == 0)
		return (p);
	else if (compare < 0)
		return (ft_avl_search(p->left, k));
	else
		return (ft_avl_search(p->right, k));
}
