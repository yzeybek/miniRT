/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_lstiter.c                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/17 15:20:31 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:49:40 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
