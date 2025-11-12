/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   color.c                                               :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/10/28 23:09:59 by yzeybek              #+#    #+#          */
/*   Updated: 2025/11/13 00:39:22 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mrt_render.h"

void	put_color(t_view_data *vd, int x, int y, int c)
{
	char	*dst;

	dst = vd->img_addr + (y * vd->img_len + x * (vd->img_bpp / 8));
	*(unsigned int *)dst = c;
}

t_color	new_color(t_byte v)
{
	t_color	ret;

	ret.r = v;
	ret.g = v;
	ret.b = v;
	ret.a = 255;
	return (ret);
}

t_color	scale_color(t_color c, double s)
{
	t_color	ret;

	ret.r = fmin(255, fmax(0, c.r * s));
	ret.g = fmin(255, fmax(0, c.g * s));
	ret.b = fmin(255, fmax(0, c.b * s));
	ret.a = 255;
	return (ret);
}

t_color	mult_color(t_color a, t_color b)
{
	t_color	ret;

	ret.r = (a.r * b.r) / 255.0;
	ret.g = (a.g * b.g) / 255.0;
	ret.b = (a.b * b.b) / 255.0;
	ret.a = 255;
	return (ret);
}

t_color	add_color(t_color a, t_color b)
{
	t_color	ret;

	ret.r = fmin(255, a.r + b.r);
	ret.g = fmin(255, a.g + b.g);
	ret.b = fmin(255, a.b + b.b);
	ret.a = 255;
	return (ret);
}
