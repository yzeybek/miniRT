/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ansi_colors.h                                         :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/10/21 14:32:50 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 15:05:19 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_COLORS_H
# define ANSI_COLORS_H

# define ANSI_RESET "\x1b[0m"

// Text Colors
# define ANSI_COLOR_BLACK "\x1b[30m"
# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_WHITE "\x1b[37m"

// Text styles
# define ANSI_BOLD "\x1b[1m"
# define ANSI_UNDERLINE "\x1b[4m"
# define ANSI_REVERSED "\x1b[7m"

#endif // ANSI_COLORS_H
