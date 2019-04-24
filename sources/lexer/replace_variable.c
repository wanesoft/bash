/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:25:50 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/24 16:47:27 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void	handle_variable(char **str, char *s, char *p, char **env)
{
	char	*var;
	size_t	n;
	size_t	i;

	if ((s - 1) > p)
	{
		var = ft_strsub(p + 1, 0, s - (p + 1));
		i = 0;
		n = ft_strlen(var);
		while (env[i] && !ft_strnequ(var, env[i], n))
			++i;
		if (env[i])
		{
			p = ft_strchr(env[i], '=');
			if (p)
				*str = ft_strjoin_free(*str, ft_strsub(p + 1, 0,
											ft_strlen(p + 1)), 3);
		}
	}
	else
		*str = ft_strjoin_free(*str, "$", 1);
}

static int	is_double_dollars(char **s, char **str, char **tmp)
{
	++(*s);
	if (**s == '$')
	{
		++(*s);
		*tmp = *s;
		*str = ft_strjoin_free(*str, ft_itoa((int)getpid()), 3);
		return (1);
	}
	return (0);
}

char		*replace_variable(char *src, char **env)
{
	char	*s;
	char	*str;
	char	*p;
	char	*tmp;

	s = src;
	if (!s || !env)
		return (s);
	tmp = s;
	str = ft_strnew(0);
	while ((p = ft_strchr(s, '$')))
	{
		s = p;
		if (p > tmp)
			str = ft_strjoin_free(str, ft_strsub(tmp, 0, p - tmp), 3);
		if (is_double_dollars(&s, &str, &tmp))
			continue ;
		while (ft_isalnum(*s))
			++s;
		handle_variable(&str, s, p, env);
		tmp = s;
	}
	str = ft_strjoin_free(str, s, 1);
	return (str);
}
