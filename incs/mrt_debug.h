/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   mrt_debug.h                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/10/28 23:50:27 by yzeybek              #+#    #+#          */
/*   Updated: 2026/01/08 18:51:28 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_DEBUG_H
# define MRT_DEBUG_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# include "mrt_structs.h"

void	print_scene(t_scene *scene);

#endif
