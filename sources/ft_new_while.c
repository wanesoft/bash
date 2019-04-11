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

static void			ft_hello_mess(char *str)
{
	ft_putstr_fd("\033[36mWelcome>\033[0m", TESTTT);
	ft_putstr_fd(str, TESTTT);
}

static void			ft_put_let(char *str, int *g_j, unsigned long i)
{
	if (!i)
	{
		ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
		ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
		return ;
	}
	str[*g_j] = i;
	str[*g_j + 1] = '\0';
	*g_j += 1;
	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
}

static void			ft_i_enter(char *str)
{
	int				i;

	i = 0;
	write(1, "\n", TESTTT);
	//ft_tolower_str(&str);
	while (str[i] == ' ')
		i++;
	//ft_minishell(&str[i], ev);
}//	str[0] = '\0';
//	*g_j = 0;


static void			ft_i_bksp(char *str, int *g_j)
{
	if (*g_j > 0)
	{
		str[*g_j - 1] = '\0';
		*g_j -= 1;
	}
	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
}

char				*ft_new_while()
{
	unsigned long	i;

	i = 0;
	g_str[0] = '\0';
	g_j = 0;
	while (1)
	{
		signal(SIGINT, ft_main_sig);
		ft_hello_mess(g_str);
		read(STDIN_FILENO, &i, 8);
		if (i == '\n')
		{
			ft_i_enter(g_str);
			return (g_str);
		}
//		else if (i == 'p')
//		{
//			for (int w = 0; g_commands[w]; w++)
//				ft_putstr(g_commands[w]);
//		}
		else if (i == K_ESC)
			break ;
		else if (i == '\t')
			ft_autocompl(g_str, &g_j);
		else if (i == K_BACKSP)
			ft_i_bksp(g_str, &g_j);
		else if (ft_isprint((int)i))
			ft_put_let(g_str, &g_j, i);
		else
			ft_put_let(g_str, &g_j, 0);
		i = 0;
	}
	return (0);
}
