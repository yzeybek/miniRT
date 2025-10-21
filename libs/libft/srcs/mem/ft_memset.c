/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_memset.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/08 13:51:40 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:50:18 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t					i;
	unsigned char *const	ptr = (unsigned char *)b;

	i = 0;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}
