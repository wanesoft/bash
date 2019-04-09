/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_ev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:28:14 by draynor           #+#    #+#             */
/*   Updated: 2019/02/02 22:09:55 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static t_ev			*ft_swap_ev(t_ev *ev1, t_ev *ev2)
{
	ev1->next = ev2->next;
	ev2->next = ev1;
	return (ev2);
}

t_ev				*ft_cmp_key_ev(t_ev *frst)
{
	if (!frst)
		return (NULL);
	if (frst->next && ft_strcmp(frst->key, frst->next->key) > 0)
		frst = ft_swap_ev(frst, frst->next);
	frst->next = ft_cmp_key_ev(frst->next);
	if (frst->next && ft_strcmp(frst->key, frst->next->key) > 0)
	{
		frst = ft_swap_ev(frst, frst->next);
		frst->next = ft_cmp_key_ev(frst->next);
	}
	return (frst);
}

static t_ev			*ft_create_ev(char *key, char **val)
{
	t_ev			*new;
	int				len;
	int				i;

	i = 0;
	len = ft_count_arr(val);
	new = (t_ev *)malloc(sizeof(t_ev));
	new->key = ft_strdup(key);
	if (!len)
		new->val = NULL;
	else
	{
		new->val = (char **)malloc(sizeof(char *) * (len + 1));
		new->val[len] = NULL;
		while (val[i])
		{
			new->val[i] = ft_strdup(val[i]);
			i++;
		}
	}
	new->next = NULL;
	return (new);
}

void				ft_push_ev(t_ev **frst, char *key, char **val)
{
	t_ev			*buf;

	buf = *frst;
	if (!buf)
		*frst = ft_create_ev(key, val);
	else
	{
		while (buf->next)
			buf = buf->next;
		buf->next = ft_create_ev(key, val);
	}
}
