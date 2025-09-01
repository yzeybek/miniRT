/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:47:42 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/01 20:00:33 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "ft_lst.h"

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
		mem_free(node);
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
		new = mem_malloc(sizeof(t_list) * 1);
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
