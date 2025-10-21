/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_substr.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/15 09:45:22 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:51:24 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "ft_str.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	slen;

	slen = 0;
	while (s[slen])
		slen++;
	if (start > slen)
		len = 0;
	if (len > slen - start)
		len = slen - start;
	res = mem_malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
