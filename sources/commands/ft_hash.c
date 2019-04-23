/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:32:39 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/23 23:22:33 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void	print_commands(t_list *head, const char *k)
{
	while (head)
	{
		if (ft_strequ(head->name, k))
			break ;
		head = head->next;
	}
	if (head)
	{
		ft_putstr(head->name);
		write(1, "=", 1);
		ft_putendl(head->path);
	}
}

int			ft_hash(t_list *head)
{
	char	**tmp;

	if (head)
	{
		tmp = g_commands;
		while (*tmp)
		{
			print_commands(head, *tmp);
			++tmp;
		}
	}
	return (1);
}
