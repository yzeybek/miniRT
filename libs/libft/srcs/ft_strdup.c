/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:34:35 by yzeybek           #+#    #+#             */
/*   Updated: 2024/10/19 10:23:15 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	s1len;
	char	*res;

	s1len = 0;
	while (s1[s1len])
		s1len++;
	res = malloc(sizeof(char) * (s1len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
