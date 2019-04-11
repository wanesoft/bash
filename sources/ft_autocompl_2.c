/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocompl_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:45:46 by draynor           #+#    #+#             */
/*   Updated: 2019/03/02 17:45:50 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				ft_autocompl_2(char str[B_SIZE], int *j)
{
	int				i;

	i = 0;
	while (g_commands[i])
	{
		if (ft_strnequ(str, g_commands[i], ((*j))))
		{
			ft_memcpy(str, g_commands[i], ft_strlen(g_commands[i]) + 1);
			break ;
		}
		i++;
	}
	if (g_commands[i])
		(*j) = (int)ft_strlen(g_commands[i]);
	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
}
