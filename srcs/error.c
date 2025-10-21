/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   error.c                                               :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/02 19:46:27 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:47:13 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define FT_STR
#include "libft.h"
#include "mrt_error.h"

int	check_arg(char *arg)
{
	char	*dot;

	dot = ft_strrchr(arg, '.');
	if (!dot || dot == arg || *(dot - 1) == '/' || ft_strncmp(dot, ".rt", 4))
		return (1);
	return (0);
}

int	put_err(char *msg)
{
	return (
		write(STDERR_FILENO, "Error\n", 6)
		+ write(STDERR_FILENO, msg, ft_strlen(msg))
	);
}
