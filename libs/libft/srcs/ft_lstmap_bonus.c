/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:47:42 by yzeybek           #+#    #+#             */
/*   Updated: 2024/10/19 09:49:16 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	clear_list(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*temp;

	if (!(*lst))
		return ;
	node = *lst;
	while (node)
	{
		temp = node->next;
		del(node->content);
		free(node);
		node = temp;
	}
	*lst = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new;
	t_list	**temp;

	if (!lst)
		return (NULL);
	res = NULL;
	temp = &res;
	while (lst)
	{
		new = malloc(sizeof(t_list) * 1);
		if (!new)
		{
			clear_list(&res, del);
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = NULL;
		*temp = new;
		temp = &new->next;
		lst = lst->next;
	}
	return (res);
}
