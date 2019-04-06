/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 06:19:13 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/06 18:30:31 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "21sh.h"

// static void	add_g_commmands(t_avl_node *node)
// {
// 	g_commands = (char **)ft_vector_add((void **)g_commands,
// 										(void *)ft_strdup(node->key));
// }

// void		fill_g_commands(t_avl_node *root)
// {
// 	ft_free_char_arr(&g_commands);
// 	g_commands = (char **)ft_vector_add((void **)g_commands,
// 										(void *)ft_strdup("setenv"));
// 	g_commands = (char **)ft_vector_add((void **)g_commands,
// 										(void *)ft_strdup("unsetenv"));
// 	if (root)
// 		ft_avl_iter_in_order(root, &add_g_commmands);
// 	g_commands = ft_sort_strarray(g_commands, 1);
// }

// char		*commands_generator(const char *text, int state)
// {
// 	static int	list_index;
// 	static int	len;
// 	char		*name;

// 	if (!state)
// 	{
// 		list_index = 0;
// 		len = ft_strlen(text);
// 	}
// 	while ((name = g_commands[list_index++]))
// 	{
// 		if (ft_strncmp(name, text, len) == 0)
// 			return (ft_strdup(name));
// 	}
// 	return (NULL);
// }

// char		**commands_completion(const char *text, int start, int end)
// {
// 	(void)start;
// 	(void)end;
// 	rl_attempted_completion_over = 1;
// 	return (rl_completion_matches(text, commands_generator));
// }
