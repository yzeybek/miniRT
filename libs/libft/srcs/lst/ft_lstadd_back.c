/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_lstadd_back.c                                      :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/15 19:54:13 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:49:19 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_lst.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = new;
}
