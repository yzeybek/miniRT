/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_putendl_fd.c                                       :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/15 18:26:06 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:50:25 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_put.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
