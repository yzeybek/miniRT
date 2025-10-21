/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_strjoin.c                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/15 10:42:38 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:50:49 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "ft_str.h"

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
	res = mem_malloc(sizeof(char) * (i + j + 1));
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
