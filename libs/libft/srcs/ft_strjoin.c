/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:42:38 by yzeybek           #+#    #+#             */
/*   Updated: 2024/10/19 10:23:55 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	res = malloc(sizeof(char) * (i + j + 1));
	if (!res)
		return (NULL);
	k = -1;
	while (++k < i)
		res[k] = s1[k];
	k = -1;
	while (++k < j)
		res[i + k] = s2[k];
	res[i + k] = '\0';
	return (res);
}
