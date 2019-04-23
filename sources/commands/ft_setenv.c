/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/23 23:24:40 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void	replace_var(char *av, char **tmp, char ***env)
{
	char	*var;

	var = ft_strdup(av);
	if (tmp && *tmp)
	{
		free(*tmp);
		*tmp = var;
	}
	else
		*env = (char **)ft_vector_add((void **)*env, (void *)var);
}

int			ft_setenv(char **av, char ***env, t_list **head)
{
	char	*p;
	char	**tmp;

	if (!env)
		return (0);
	while (*av)
	{
		tmp = *env;
		p = ft_strchr(*av, '=');
		if (!p && ++av)
			continue ;
		while (*tmp && !ft_strnequ(*av, *tmp, p - *av + 1))
			++tmp;
		replace_var(*av, tmp, env);
		if (ft_strnequ(*av, "PATH=", 5))
		{
			ft_free_char_arr(&g_commands);
			ft_lstdel(head);
			*head = get_list_of_bins(*env);
			fill_g_commands(*head);
		}
		++av;
	}
	return (1);
}
