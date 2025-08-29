/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:54:50 by yzeybek           #+#    #+#             */
/*   Updated: 2024/10/19 09:52:33 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	unsigned char *const	s1ptr = (unsigned char *)s1;
	unsigned char *const	s2ptr = (unsigned char *)s2;

	if (!n)
		return (0);
	i = 0;
	while (s1ptr[i] == s2ptr[i] && i < n - 1)
		i++;
	return (s1ptr[i] - s2ptr[i]);
}
