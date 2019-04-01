/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_str.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:23:06 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/03/24 22:26:53 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AVL_TREE_STR_H
# define FT_AVL_TREE_STR_H

# include "libft.h"

typedef struct			s_avl_node
{
	char				*key;
	char				*path;
	unsigned char		height;
	struct s_avl_node	*left;
	struct s_avl_node	*right;
}						t_avl_node;

t_avl_node				*ft_avl_balance(t_avl_node *p);
unsigned char			ft_avl_height(t_avl_node *p);
t_avl_node				*ft_avl_free_node(t_avl_node *p);
t_avl_node				*ft_avl_init(const char *k, const char *path);
t_avl_node				*ft_avl_insert(t_avl_node *p, const char *k,
														const char *path);
void					ft_avl_iter_in_order(t_avl_node *node,
									void (*f)(t_avl_node *node));
void					ft_avl_iter_post_order(t_avl_node *node,
									t_avl_node *(*f)(t_avl_node *node));
void					ft_avl_iter_pre_order(t_avl_node *node,
									void (*f)(t_avl_node *node));
t_avl_node				*ft_avl_remove(t_avl_node *p, const char *k);
t_avl_node				*ft_avl_search(t_avl_node *p, const char *k);

#endif
