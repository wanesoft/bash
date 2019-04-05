/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tilde.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:20:20 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/01 21:06:21 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static char	*replace_pwd(char *av, char **env)
{
	char	*path;

	path = av;
	if (*av == '-')
		while (*env && !ft_strnequ("OLDPWD=", *env, 7))
			++env;
	else
		while (*env && !ft_strnequ("PWD=", *env, 4))
			++env;
	if (*env)
		path = ft_strjoin(av + 1, ft_strchr(*env, '=') + 1);
	else
		path = ft_strdup(av);
	return (path);
}

static void	func(char *av, char **env, int *tilda_is_not_str, char **path)
{
	char			*username;
	char			*p;
	struct passwd	*pw;

	if (*tilda_is_not_str)
	{
		if ((*av == '-' || *av == '+'))
			*path = replace_pwd(av, env);
		else
		{
			p = ft_strchr(av, '/');
			username = (p) ? ft_strsub(av, 0, p - av) : ft_strdup(av);
			if ((pw = getpwnam(username)))
				*path = (p) ? ft_strjoin(pw->pw_dir, p) : ft_strdup(pw->pw_dir);
			else
			{
				ft_putstr("minishell: no such user or named directory: ");
				ft_putendl(av);
				*path = NULL;
			}
			free(username);
		}
	}
	else
		*path = ft_strjoin("~", av);
}

char		*replace_tilde(char *av, char **env, int *tilda_is_not_str)
{
	struct passwd	*pw;
	char			*path;
	int				res;

	if (*av == '\0')
	{
		pw = getpwuid(getuid());
		path = ft_strdup(pw->pw_dir);
	}
	else if (*av == '/')
	{
		pw = getpwuid(getuid());
		path = ft_strjoin(pw->pw_dir, av);
	}
	else
	{
		if (!tilda_is_not_str)
			tilda_is_not_str = &res;
		*tilda_is_not_str = (ft_strchr(av, '~') || ft_strchr(av, '=')) ? 0 : 1;
		func(av, env, tilda_is_not_str, &path);
	}
	return (path);
}
