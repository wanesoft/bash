/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:03:12 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/01 21:05:46 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_env(char **av, char **env)
{
	char	**arr;
	char	**tmp;

	if (*av == NULL)
		while (*env)
		{
			ft_putendl(*env);
			++env;
		}
	else
	{
		if (ft_strequ("-s", *av))
		{
			arr = ft_sort_strarray(env, 0);
			tmp = arr;
			while (*arr)
			{
				ft_putendl(*arr);
				++arr;
			}
			ft_free_char_arr(&tmp);
		}
	}
	return (1);
}
