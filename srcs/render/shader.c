/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   shader.c                                              :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/11/09 14:50:52 by yzeybek              #+#    #+#          */
/*   Updated: 2025/11/10 00:09:41 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "mrt_render.h"

t_color	miss_shader()
{
	t_color	ret = {0};
	return (ret);
}

t_color	hit_shader(t_scene *scene, t_ray ray, t_hit closest)
{
	t_color	ret = {0};
	(void)scene;
	(void)ray;
	(void)closest;
	return (ret);
}
