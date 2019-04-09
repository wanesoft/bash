/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 08:09:30 by draynor           #+#    #+#             */
/*   Updated: 2019/03/08 20:50:31 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char				*ft_get_key(char *str)
{
	int				i;
	char			*key;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	key = (char *)malloc(sizeof(char) * (i + 1));
	key[i] = '\0';
	ft_memcpy(key, str, i);
	return (key);
}

void				ft_init_ev(t_ev **ev, char **env)
{
	char			*key;
	char			*pos;
	char			**val;

	key = NULL;
	val = NULL;
	while (*env)
	{
		key = ft_get_key(*env);
		if ((pos = ft_strrchr(*env, '=')))
			val = ft_strsplit(&pos[1], ':');
		else
			val = NULL;
		ft_push_ev(ev, key, val);
		env++;
		ft_del_arr(val);
		free(val);
		free(key);
	}
}
