/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_lstdelone.c                                        :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/17 14:33:57 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:49:36 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "ft_lst.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	mem_free(lst);
}
