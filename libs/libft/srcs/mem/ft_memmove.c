/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:50:46 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/01 19:43:41 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					i;
	unsigned char *const	dstptr = (unsigned char *)dst;
	unsigned char *const	srcptr = (unsigned char *)src;

	if (!src && !dst)
		return (NULL);
	i = 0;
	if (src > dst)
	{
		while (i < len)
		{
			dstptr[i] = srcptr[i];
			i++;
		}
	}
	else
		while (len-- > 0)
			dstptr[len] = srcptr[len];
	return (dst);
}
