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

static char			**ft_get_path_dirs(t_ev *ev)
{
	while (ev)
	{
		if (ft_strequ(ev->key, "PATH"))
			return (ev->val);
		ev = ev->next;
	}
	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
	return (NULL);
}

static int			ft_count_files(char **dirs)
{
	int				i;
	int				count;
	DIR				*d1;
	struct dirent	*f1;

	i = 0;
	count = 0;
	while (dirs[i])
	{
		d1 = opendir(dirs[i]);
		while ((f1 = readdir(d1)))
		{
			if ((f1->d_name)[0] != '.' && f1->d_type == '\b')
				count++;
		}
		closedir(d1);
		i++;
	}
	return (count);
}

static void			ft_put_files(char **files, char **dirs)
{
	int				i;
	DIR				*d1;
	int				j;
	struct dirent	*f1;

	j = 0;
	i = 0;
	while (dirs[i])
	{
		d1 = opendir(dirs[i]);
		while ((f1 = readdir(d1)))
		{
			if ((f1->d_name)[0] != '.' && f1->d_type == '\b')
			{
				files[j] = ft_strdup(f1->d_name);
				j++;
			}
		}
		closedir(d1);
		i++;
	}
}

static void			ft_show_files(char **files)
{
	int				i;

	i = 0;
	while (files[i])
	{
		ft_putstr_fd(files[i], TESTTT);
		write(TESTTT, " ", 1);
		i++;
	}
	write(TESTTT, "\n", 1);
}

void				ft_autocompl(t_ev *ev, char str[B_SIZE], int *j)
{
	char			**dirs;
	char			**files;
	int				i;

	i = 0;
	if (!(dirs = ft_get_path_dirs(ev)))
		return ;
	if (!(files = (char **)malloc(sizeof(char *) * (ft_count_files(dirs) + 1))))
		return ;
	files[ft_count_files(dirs)] = NULL;
	ft_put_files(files, dirs);
	if (str[0] == '\0')
		ft_show_files(files);
	else
		ft_autocompl_2(str, j, files);
	while (files[i])
	{
		free(files[i]);
		i++;
	}
	free(files);
	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
}
