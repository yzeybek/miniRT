/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:55:57 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/01 19:59:43 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "ft_int.h"

static size_t	get_len(long ln)
{
	size_t	i;

	i = 0;
	if (ln == 0)
		return (1);
	else if (ln < 0)
	{
		i++;
		ln = -ln;
	}
	while (ln != 0)
	{
		ln /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	long	ln;

	ln = n;
	len = get_len(ln);
	res = mem_malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (ln == 0)
		res[len] = '0';
	else if (ln < 0)
	{
		res[0] = '-';
		ln = -ln;
	}
	while (ln != 0)
	{
		res[len] = ln % 10 + '0';
		ln /= 10;
		len--;
	}
	return (res);
}
