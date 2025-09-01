/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:54:42 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/01 19:46:16 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	sign;

	i = 0;
	sign = 0;
	while (s[i])
		i++;
	while (i >= 0 && !sign)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		if (i == 0)
			sign = 1;
		else
			i--;
	}
	return (NULL);
}
