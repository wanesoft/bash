/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:16:06 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/23 19:55:06 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freemap(t_list **lst)
{
	if (!lst || !*lst)
		return ;
	if ((*lst)->next != NULL)
		ft_freemap(&((*lst)->next));
	free((*lst)->content);
	(*lst)->content = NULL;
	free(*lst);
	*lst = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	if (!(new = f(lst)))
	{
		ft_freemap(&res);
		return (NULL);
	}
	res = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(new->next = f(lst)))
		{
			ft_freemap(&res);
			return (NULL);
		}
		new = new->next;
	}
	return (res);
}
