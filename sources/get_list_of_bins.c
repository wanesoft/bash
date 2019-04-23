/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_of_bins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:34:00 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/24 00:30:28 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static char	*cat_path(char *path, char *file_name)
{
	char	*new_path;
	size_t	path_len;
	size_t	name_len;

	path_len = ft_strlen(path);
	if (path[path_len - 1] == '/')
		--path_len;
	name_len = ft_strlen(file_name);
	new_path = (char *)malloc(sizeof(char) * (path_len + name_len + 2));
	if (path_len)
		ft_memmove(new_path, path, path_len);
	new_path[path_len] = '/';
	ft_memmove(new_path + path_len + 1, file_name, name_len);
	new_path[path_len + name_len + 1] = '\0';
	return (new_path);
}

static void	add_command(t_list **head, const char *name, const char *path)
{
	t_list	*tmp;

	if (!head || !name || !path)
		return ;
	tmp = *head;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
	{
		ft_lst_push_back(head, ft_lstnew(name, path));
		g_commands = (char **)ft_vector_add((void **)g_commands,
			(void *)ft_strdup(name));
	}
}

void	fill_list_of_bins(t_list **head, char **path)
{
	DIR				*dir;
	struct dirent	*dt;
	char			*tmp;
	size_t			len;

	while (*path)
	{
		if (!(dir = opendir(*path)))
			break ;
		len = ft_strlen((const char *)path);
		if (len > 0 && (*path)[len - 1] == '/')
			(*path)[len - 1] = '\0';
		while ((dt = readdir(dir)) != NULL)
		{
			tmp = cat_path(*path, dt->d_name);
			if (!access(tmp, X_OK) && !ft_strequ("..", dt->d_name)
									&& !ft_strequ(".", dt->d_name))
				add_command(head, dt->d_name, tmp);
			free(tmp);
		}
		dt = NULL;
		closedir(dir);
		++path;
	}
}

t_list	*get_list_of_bins(char **env)
{
	t_list	*head;
	char	**path;

	head = NULL;
	while (*env)
	{
		if (ft_strncmp("PATH=", *env, 5) == 0)
			break ;
		++env;
	}
	if (*env && (path = ft_strsplit(ft_strchr(*env, '=') + 1, ':')))
	{
		fill_list_of_bins(&head, path);
		ft_free_char_arr(&path);
	}
	return (head);
}
