/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_memcpy.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/08 13:49:37 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:50:12 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned char *const	dstptr = (unsigned char *)dst;
	unsigned char *const	srcptr = (unsigned char *)src;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dstptr[i] = srcptr[i];
		i++;
	}
	return (dst);
}
