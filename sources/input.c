/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:03:53 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/24 16:49:07 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int			read_input(t_list **head, char ***env)
{
	char		**commands;
	char		**split;
	char		**tmp;
	char		*input_str;
	char		*str;

	//handle_signals();
	input_str = ft_new_while();
	// ---
	// ft_putstr("Ya vernul: ");
	// ft_putstr(input_str);
	// ft_putstr("\n");
	// ---
	commands = divide_commands(input_str);
	tmp = commands;
	if (tmp)
	{
		while (*tmp)
		{
			str = replace_variable(*tmp, *env);
			split = spec_split(str, *env);
			if (!split)
				break ;
			if (split[0])
				call_functions(split, env, head);
			ft_free_char_arr(&split);
			free(str);
			tmp++;
		}
		ft_free_char_arr(&commands);
	}
	return (1);
}
