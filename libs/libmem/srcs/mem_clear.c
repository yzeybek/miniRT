/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   mem_clear.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/01 18:17:32 by yzeybek              #+#    #+#          */
/*   Updated: 2026/01/17 16:26:21 by yzeybek             ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mem_utils.h"

void	*mem_absorb(void *ptr)
{
	mem_add_new_block(ptr, 1);
	return (ptr);
}

static void	mem_free_node(t_mem_block *node, t_mem_block *prev, t_mem_block **h)
{
	if (!prev)
		*h = node->next;
	else
		prev->next = node->next;
	free(node->data);
	free(node);
}

void	mem_free(void *ptr)
{
	t_mem_block	**head;
	t_mem_block	*node;
	t_mem_block	*prev;

	head = mem_add_new_block(NULL, 0)->head;
	if (!head || !*head)
		return ;
	node = *head;
	prev = NULL;
	while (node)
	{
		if (node->data == ptr)
			return (mem_free_node(node, prev, head));
		prev = node;
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
