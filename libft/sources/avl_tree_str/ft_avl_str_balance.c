/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_balance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:24:29 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/06 18:43:26 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_str.h"

static int			ft_avl_bfactor(t_avl_node *p)
{
	return (ft_avl_height(p->right) - ft_avl_height(p->left));
}

static void			ft_avl_fixheight(t_avl_node *p)
{
	unsigned char	hl;
	unsigned char	hr;

	hl = ft_avl_height(p->left);
	hr = ft_avl_height(p->right);
	p->height = ((hl > hr) ? hl : hr) + 1;
}

static t_avl_node	*ft_avl_rotateleft(t_avl_node *p)
{
	t_avl_node	*tmp;

	tmp = p->right;
	p->right = tmp->left;
	tmp->left = p;
	ft_avl_fixheight(p);
	ft_avl_fixheight(tmp);
	return (tmp);
}

static t_avl_node	*ft_avl_rotateright(t_avl_node *p)
{
	t_avl_node	*tmp;

	tmp = p->left;
	p->left = tmp->right;
	tmp->right = p;
	ft_avl_fixheight(p);
	ft_avl_fixheight(tmp);
	return (tmp);
}

t_avl_node			*ft_avl_balance(t_avl_node *p)
{
	int	bfactor;

	ft_avl_fixheight(p);
	bfactor = ft_avl_bfactor(p);
	if (bfactor == 2)
	{
		if (ft_avl_bfactor(p->right) < 0)
			p->right = ft_avl_rotateright(p->right);
		return (ft_avl_rotateleft(p));
	}
	else if (bfactor == (-2))
	{
		if (ft_avl_bfactor(p->left) > 0)
			p->left = ft_avl_rotateleft(p->left);
		return (ft_avl_rotateright(p));
	}
	return (p);
}
