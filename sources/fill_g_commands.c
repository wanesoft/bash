/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_g_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 06:19:13 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/23 23:29:11 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		fill_g_commands(t_list *head)
{
	ft_free_char_arr(&g_commands);
	g_commands = (char **)ft_vector_add((void **)g_commands,
										(void *)ft_strdup("setenv"));
	g_commands = (char **)ft_vector_add((void **)g_commands,
										(void *)ft_strdup("unsetenv"));
	while (head)
	{
		g_commands = (char **)ft_vector_add((void **)g_commands,
										(void *)ft_strdup(head->name));
		head = head->next;
	}
	g_commands = ft_sort_strarray(g_commands, 1);
}
