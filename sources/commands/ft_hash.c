/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:32:39 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/07 00:17:24 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "21sh.h"

// static void	print_commands(t_avl_node *root, const char *k)
// {
// 	t_avl_node	*node;

// 	node = ft_avl_search(root, k);
// 	if (node)
// 	{
// 		ft_putstr(node->key);
// 		write(1, "=", 1);
// 		ft_putendl(node->path);
// 	}
// }

// int			ft_hash(t_avl_node *root)
// {
// 	char	**tmp;

// 	if (root)
// 	{
// 		tmp = g_commands;
// 		while (*tmp)
// 		{
// 			print_commands(root, *tmp);
// 			++tmp;
// 		}
// 	}
// 	return (1);
// }
