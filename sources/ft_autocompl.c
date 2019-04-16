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

static char			**ft_get_gcom_arr(char str[B_SIZE])
{
	char			**arr;
	int				i;
	int				count;
	
	count = 0;;
	i = 0;
	arr = NULL;
	while (g_commands && g_commands[i])
	{
//		if (ft_strnequ(str, g_commands[i], *j))
		if (ft_strnequ(str, g_commands[i], ft_strlen(str)))
		{
			count++;
			if (count == 1)
				ft_putchar('\n');
			ft_putstr(g_commands[i]);
			if (count)
				ft_putchar(' ');
		}
		i++;
	}
	if (count)
	{
		arr = (char **)malloc(sizeof(char *) * (count + 1));
		arr[count] = NULL;
	}
	ft_putchar('\n');
	return (arr);
}

static int			ft_find_ws(char str[B_SIZE])
{
	int				i;
	
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == ' ')
			return (i + 1);
		--i;
	}
	return (0);
}
//void				ft_autocompl_2(char str[B_SIZE], int *j)
//{
//	int				i;
//
//	i = 0;
//	while (g_commands[i])
//	{
//		if (ft_strnequ(str, g_commands[i], ((*j))))
//		{
//			ft_memcpy(str, g_commands[i], ft_strlen(g_commands[i]) + 1);
//			break ;
//		}
//		i++;
//	}
//	if (g_commands[i])
//		(*j) = (int)ft_strlen(g_commands[i]);
////	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
////	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
//}

static void			ft_autocompl_2(char str[B_SIZE], int *j, char **arr_gcom)
{
	int				i;
	int				jj;
	int				len;
	
	jj = 1;
	i = 0;
	len = (int)ft_strlen(str);
	while (arr_gcom && arr_gcom[i])
	{
		if (arr_gcom[i + 1] && arr_gcom[i][len] == arr_gcom[i + 1][len])
			++jj;
		++i;
	}
	if (i)
		--i;
	if (jj == ft_count_arr(arr_gcom) && arr_gcom[i][len] != '\0')
	{
		str[len] = arr_gcom[i][len];
		*j = *j + 1;
		ft_autocompl_2(str, j, arr_gcom);
	}
//	if (g_commands[i])
//		(*j) = (int)ft_strlen(g_commands[i]);
}

void				ft_autocompl(char str[B_SIZE], int *j)
{
	int				i;
	char			**arr_gcom;
	int				k;
	int				ws;
	
	ws = ft_find_ws(str);
	arr_gcom = ft_get_gcom_arr(&str[ws]);
	i = 0;
	k = 0;
	while (arr_gcom && g_commands[i])
	{
		if (ft_strnequ(&str[ws], g_commands[i], ft_strlen(&str[ws])))
		{
			arr_gcom[k] = ft_strdup(g_commands[i]);
			k++;
		}
		i++;
	}
	ft_autocompl_2(&str[ws], j, arr_gcom);
	str[*j] = '\0';
	free(arr_gcom);
	//del arr_gcom
	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
}
