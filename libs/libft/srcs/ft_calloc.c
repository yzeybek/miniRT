/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:12:49 by yzeybek           #+#    #+#             */
/*   Updated: 2024/10/19 10:22:57 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*zeroptr;
	void			*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	zeroptr = ptr;
	while (i < count * size)
	{
		zeroptr[i] = '\0';
		i++;
	}
	return (ptr);
}
