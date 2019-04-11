/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocompl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:44:47 by draynor           #+#    #+#             */
/*   Updated: 2019/03/02 17:45:33 by draynor          ###   ########.fr       */
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
//	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
//	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
}

void				ft_autocompl(char str[B_SIZE], int *j)
{
	ft_autocompl_2(str, j);

	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
}
