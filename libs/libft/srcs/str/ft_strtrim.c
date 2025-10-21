/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_strtrim.c                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/15 12:10:32 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:51:20 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "ft_str.h"

static size_t	check_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	while (s1[start] && check_set(s1[start], set))
		start++;
	end = 0;
	while (s1[end])
		end++;
	end--;
	while (end > start && check_set(s1[end], set))
		end--;
	res = mem_malloc(sizeof(char) * (end - start + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
