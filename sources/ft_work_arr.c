/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 12:31:31 by draynor           #+#    #+#             */
/*   Updated: 2019/02/02 22:46:17 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void			ft_swap_arr(char **a, char **b)
{
	char			*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void				ft_cmp_arr(char **arr)
{
	int				i;

	i = 0;
	while (arr[i + 1])
	{
		if (ft_strcmp(arr[i], arr[i + 1]) > 0)
		{
			ft_swap_arr(&arr[i], &arr[i + 1]);
			i = 0;
			continue ;
		}
		i++;
	}
}

int					ft_count_arr(char **arr)
{
	int				i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

void				ft_del_arr(char **arr)
{
	int				i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
}
