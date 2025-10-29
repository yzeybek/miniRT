/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   render_utils.c                                        :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/10/28 23:09:59 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/28 23:13:27 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "mrt_view.h"

void	put_pixel(t_view_data *vd, int x, int y, int color)
{
	char	*dst;

	dst = vd->img_addr + (y * vd->img_len + x * (vd->img_bpp / 8));
	*(unsigned int *)dst = color;
}
