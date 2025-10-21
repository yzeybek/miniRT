/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   error.c                                               :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/02 19:46:27 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 15:04:25 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define FT_STR
#include "libft.h"
#include "mrt_error.h"
#include "ansi_colors.h"

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
		write(STDERR_FILENO, ANSI_COLOR_RED ANSI_BOLD "Error\n"
			ANSI_COLOR_YELLOW, 21)
		+ write(STDERR_FILENO, msg, ft_strlen(msg))
		+ write(STDERR_FILENO, ANSI_RESET, 4)
	);
}
