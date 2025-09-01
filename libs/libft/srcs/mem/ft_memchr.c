/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:54:42 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/01 19:43:11 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char *const	sptr = (unsigned char *)s;

	i = 0;
	while (i < n)
	{
		if (sptr[i] == (unsigned char)c)
			return (&sptr[i]);
		i++;
	}
	if (!(unsigned char)c && sptr[i] == (unsigned char)c && n)
		return (&sptr[i]);
	return (NULL);
}
