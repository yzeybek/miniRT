/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_strlcat.c                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/08 13:52:21 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:50:52 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = 0;
	dstlen = 0;
	if ((!src || !dst) && !dstsize)
		return (0);
	while (dst[dstlen] && dstlen < dstsize)
		dstlen++;
	while (src[srclen])
		srclen++;
	if (dstlen >= dstsize)
		return (srclen + dstsize);
	while (src[i] && i < dstsize - dstlen - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (i < dstsize - dstlen)
		dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
