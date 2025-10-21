/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_strdup.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/12 16:34:35 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:50:42 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "ft_str.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	s1len;
	char	*res;

	s1len = 0;
	while (s1[s1len])
		s1len++;
	res = mem_malloc(sizeof(char) * (s1len + 1));
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
