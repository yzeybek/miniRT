/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:17:32 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/02 22:39:54 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mem_utils.h"

void	*mem_absorb(void *ptr)
{
	mem_add_new_block(ptr, 1);
	return (ptr);
}

void	mem_free(void *ptr)
{
	t_mem_block	**head;
	t_mem_block	*node;
	t_mem_block	*temp;

	head = mem_add_new_block(NULL, 0)->head;
	if (head && *head && (*head)->data == ptr)
	{
		node = (*head)->next;
		free((*head)->data);
		free(*head);
		head = &node;
		return ;
	}
	
	node = (*head);
	while (node && node->next)
	{
		if (node->next->data == ptr)
		{
			temp = node->next->next;
			free(node->next->data);
			free(node->next);
			node->next = temp;
			break ;
		}
		node = node->next;
	}
}

void	mem_clear(void)
{
	mem_clear_block(mem_add_new_block(NULL, 0)->head);
}

void	mem_exit(int status)
{
	mem_clear();
	exit(status);
}
