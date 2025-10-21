/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_lstlast.c                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/15 19:48:11 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:49:43 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_lst.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
