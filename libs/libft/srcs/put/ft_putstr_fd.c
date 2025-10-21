/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_putstr_fd.c                                        :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/15 18:24:32 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:50:31 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_put.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
