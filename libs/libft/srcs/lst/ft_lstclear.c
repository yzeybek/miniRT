/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:08:51 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/01 19:59:38 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "ft_lst.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*node;

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
