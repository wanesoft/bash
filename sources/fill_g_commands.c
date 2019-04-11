/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 06:19:13 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/10 17:14:42 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void	add_g_commmands(t_avl_node *node)
{
	g_commands = (char **)ft_vector_add((void **)g_commands,
										(void *)ft_strdup(node->key));
}

void		fill_g_commands(t_avl_node *root)
{
	ft_free_char_arr(&g_commands);
	g_commands = (char **)ft_vector_add((void **)g_commands,
										(void *)ft_strdup("setenv"));
	g_commands = (char **)ft_vector_add((void **)g_commands,
										(void *)ft_strdup("unsetenv"));
	if (root)
		ft_avl_iter_in_order(root, &add_g_commmands);
	g_commands = ft_sort_strarray(g_commands, 1);
}
