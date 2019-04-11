/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:47:53 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/11 18:59:22 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char		*get_whitespace(char *s)
{
	char	c;

	while ((c = *s) && !ft_is_whitespaces(c) && c != '\'' && c != '\"')
		++s;
	return (s);
}

int			has_str_in_quotes(char *s)
{
	char	*p;
	char	c;

	while ((c = *s) && !ft_is_whitespaces(c))
	{
		if ((c == '\'' || c == '\"') && (p = ft_strchr(s + 1, c)))
			return (1);
		s++;
	}
	return (0);
}

char		*make_str_in_quotes(char *s, char ***arr, char *tmp, char **env)
{
	char	*str;
	char	*p;
	char	c;
	int		has_tilde;

	has_tilde = (*s == '~') ? 1 : 0;
	str = ft_strnew(0);
	while ((c = *s) && !ft_is_whitespaces(c))
	{
		if ((c == '\'' || c == '\"') && (p = ft_strchr(s + 1, c)))
		{
			if ((p - 1) > s)
				str = ft_strjoin_free(str, ft_strsub(s + 1, 0, p - s - 1), 3);
			if (s > tmp)
				str = ft_strjoin_free(ft_strsub(tmp, 0, s - tmp), str, 3);
			s = get_whitespace(++p);
			if (s > p)
				str = ft_strjoin_free(str, ft_strsub(p, 0, s - p), 3);
			tmp = s;
		}
		else
			++s;
	}
	str = (has_tilde) ? replace_tilde(str + 1, env, NULL) : str;
	if (ft_strlen(str))
		*arr = (char **)ft_vector_add((void **)*arr, (void *)str);
	return (s);
}

// static int	replace_tilde_in_av(char **arr, char **env)
// {
// 	char	*tmp;

// 	while (*arr)
// 	{
// 		if (**arr == '~')
// 		{
// 			tmp = *arr;
// 			*arr = replace_tilde(*arr + 1, env, NULL);
// 			free(tmp);
// 			if (!*arr)
// 				return (0);
// 		}
// 		++arr;
// 	}
// 	return (1);
// }

char		**spec_split(char *s, char **env)
{
	char	**arr;
	char	*tmp;
	char	*substr;

	arr = (char **)malloc(sizeof(char *));
	arr[0] = NULL;
	while (*s)
	{
		s = ft_skip_whitespaces(s);
		if (*s)
			tmp = s;
		else
			return (arr);
		if (has_str_in_quotes(s))
			s = make_str_in_quotes(s, &arr, tmp, env);
		else
		{
			s = get_whitespace(s);
			substr = ft_strsub(tmp, 0, s - tmp);
			substr = (*substr == '~') ? replace_tilde(substr + 1, env, NULL) : substr;
			arr = (char **)ft_vector_add((void **)arr, (void *)substr);
		}
	}
	// if (!replace_tilde_in_av(arr, env))
	// 	ft_free_char_arr(&arr);
	return (arr);
}
