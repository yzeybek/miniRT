/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_strmapi.c                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/15 17:50:50 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:51:02 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "ft_str.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*res;
	unsigned int		i;
	unsigned int		slen;

	slen = 0;
	while (s[slen])
		slen++;
	res = mem_malloc(sizeof(char) * (slen + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
