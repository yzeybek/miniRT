/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_lstnew.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/15 18:59:40 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:49:50 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "ft_lst.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = mem_malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
