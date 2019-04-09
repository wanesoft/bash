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

void				ft_autocompl_2(char str[B_SIZE], int *j, char **files)
{
	int				i;

	i = 0;
	while (files[i])
	{
		if (ft_strnequ(str, files[i], ((*j))))
		{
			ft_memcpy(str, files[i], ft_strlen(files[i]) + 1);
			break ;
		}
		i++;
	}
	if (files[i])
		(*j) = (int)ft_strlen(files[i]);
	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
}
