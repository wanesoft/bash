/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:52:40 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/06 18:31:13 by ggwin-go         ###   ########.fr       */
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

static void	add_command(t_avl_node **root, char *name, char *path)
{
	t_avl_node		*node;

	if (!(node = ft_avl_search(*root, (const char *)name)))
	{
		*root = ft_avl_insert(*root, name, path);
		// g_commands = (char **)ft_vector_add((void **)g_commands,
		// 	(void *)ft_strdup(name));
	}
}

static void	fill_commands_tree(char **path, t_avl_node **root)
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
		if ((*path)[len - 1] == '/')
			(*path)[len - 1] = '\0';
		while ((dt = readdir(dir)) != NULL)
		{
			tmp = cat_path(*path, dt->d_name);
			if (!access(tmp, X_OK) && !ft_strequ("..", dt->d_name))
				add_command(root, dt->d_name, *path);
			free(tmp);
		}
		closedir(dir);
		path++;
	}
}

t_avl_node	*ft_bins_from_env(char **env)
{
	char			**path;
	t_avl_node		*root;

	root = NULL;
	while (*env && !ft_strnequ(*env, "PATH", 4))
		env++;
	if (*env)
	{
		path = ft_strsplit(ft_strchr(*env, '=') + 1, ':');
		fill_commands_tree(path, &root);
		ft_free_char_arr(&path);
	}
	return (root);
}

char		**copy_env(char **env)
{
	char	**new_env;
	size_t	count;

	count = 0;
	while (env[count])
		++count;
	new_env = (char **)malloc(sizeof(char *) * (count + 1));
	count = -1;
	while (env[++count])
		new_env[count] = ft_strdup(env[count]);
	return (new_env);
}
