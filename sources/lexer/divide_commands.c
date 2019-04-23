/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:45:40 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/24 01:09:23 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void	skip_closed_block(char **s, char c)
{
	char	*p;

	if (!(p = ft_strchr(*s + 1, c)))
		return ;
	*s = p;
}

static void	add_command(char **tmp, char ***arr, char *s)
{
	char	*p;

	p = *tmp;
	*arr = (char **)ft_vector_add((void **)*arr,
								(void *)ft_strsub(p, 0, s - p));
	*tmp = s + 1;
}

char		**divide_commands(char *str)
{
	char	**arr;
	char	*s_to_free;
	char	*tmp;
	char	*s;
	char	c;

	arr = (char **)malloc(sizeof(char *));
	arr[0] = NULL;
	if (!str)
		return (arr);
	s = ft_strtrim(str);
	s_to_free = s;
	if (*s)
	{
		tmp = s;
		while ((c = *s))
		{
			if (c == '\'' || c == '\"' || c == '`' || c == '(')
				skip_closed_block(&s, c);
			else if (c == ';')
				add_command(&tmp, &arr, s);
			++s;
		}
		arr = (char **)ft_vector_add((void **)arr, (void *)ft_strdup(tmp));
	}
	free(s_to_free);
	return (arr);
}
