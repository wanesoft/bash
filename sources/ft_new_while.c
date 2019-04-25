/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_while.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:47:46 by draynor           #+#    #+#             */
/*   Updated: 2019/03/02 18:40:46 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char				g_str[B_SIZE];
int					g_j = 0;
int					g_pos = 0;

void				ft_hello_mess(char *str)
{
	int				tmp;
	int				bksl;
	int				i;
	
	bksl = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			++bksl;
		++i;
	}
	tmp = g_pos;
	while (bksl)
	{
		ft_putstr_fd(tgetstr("up", NULL), TESTTT);
		--bksl;
	}
	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
	ft_putstr_fd("\033[36mWelcome>\033[0m", TESTTT);
	ft_putstr_fd(str, TESTTT);
	while (g_j > tmp)
	{
		ft_putstr_fd(tgetstr("le", NULL), TESTTT);
		++tmp;
	}
}

static void			ft_put_let(char *str, int *g_j, unsigned long i)
{
	if (*g_j == g_pos)
	{
		str[g_pos] = i;
		++g_pos;
		*g_j += 1;
		str[*g_j] = '\0';
	}
	else if (*g_j < g_pos)
		str[0] = 'B';
	else
	{
		char *tmp = ft_strdup(&str[g_pos]);
		str[g_pos] = i;
		ft_memcpy(&str[g_pos + 1], tmp, (ft_strlen(tmp) + 1));
		*g_j += 1;
		g_pos++;
		free(tmp);
	}
	ft_hello_mess(str);
}

static char			*ft_i_enter(char *str, int *g_j)
{
	int				i;
	int				l;
	
	l = 0;
	i = 0;
	write(1, "\n", TESTTT);
	while (str[i])
	{
		if (str[i] == '"')
			++l;
		++i;
	}
	if (l && l % 2 != 0)
	{
		ft_put_let(str, g_j, '\n');
		ft_new_while(1);
	}
	else
		return (g_str);
	return (g_str);
}

static void			ft_i_arrows(unsigned long i)
{
	if (i == K_LEFT && g_pos > 0)
		--g_pos;
	else if (i == K_RIGHT && g_pos < g_j)
		++g_pos;
	else if (i == K_HOME && g_pos > 0)
		g_pos = 0;
	else if (i == K_END && g_pos < g_j)
		g_pos = g_j;
	ft_hello_mess(g_str);
}

static void			ft_i_bksp(char *str, int *g_j)
{
	char			*tmp;
	
	tmp = ft_strdup(str);
	if (*g_j > 0 && g_pos > 0)
	{
		ft_memcpy(&str[g_pos - 1], &tmp[g_pos], ft_strlen(&tmp[g_pos]));
		str[*g_j - 1] = '\0';
		*g_j -= 1;
		--g_pos;
//		free(tmp;)
	}
	free(tmp);
	ft_hello_mess(str);
}

char				*ft_new_while(int flag)
{
	unsigned long	i;

	i = 0;
	if (!flag)
	{
		ft_bzero(g_str, B_SIZE);
		g_j = 0;
		g_pos = 0;
		ft_hello_mess(g_str);
	}
	while (1)
	{
		signal(SIGINT, ft_main_sig);
		read(STDIN_FILENO, &i, 8);
//		printf("%lu\n", i);
		if (i == '\n')
			return (ft_i_enter(g_str, &g_j));
		else if (i == K_ESC)
			exit(EXIT_SUCCESS) ;
		else if (i == '\t')
			ft_autocompl(g_str, &g_j);
		else if (i == K_BACKSP)
			ft_i_bksp(g_str, &g_j);
		else if (i == K_LEFT || i == K_RIGHT || i == K_HOME || i == K_END)
			ft_i_arrows(i);
		else if (ft_isprint((int)i))
			ft_put_let(g_str, &g_j, i);
		i = 0;
	}
	return (0);
}
