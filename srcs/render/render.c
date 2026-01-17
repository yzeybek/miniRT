/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   render.c                                              :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/10/28 15:34:27 by yzeybek              #+#    #+#          */
/*   Updated: 2026/01/17 20:55:50 by yzeybek             ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "mrt_render.h"

int	check_hit(t_ray ray, t_shape shape, double *t)
{
	if (shape.obj_type == OBJ_PL)
		return (plane_intersect(ray, shape, t));
	if (shape.obj_type == OBJ_SP)
		return (sphere_intersect(ray, shape, t));
	if (shape.obj_type == OBJ_CY)
		return (cylinder_intersect(ray, shape, t));
	if (shape.obj_type == OBJ_CN)
		return (cone_intersect(ray, shape, t));
	return (0);
}

static t_color	trace_ray(t_scene *scene, t_ray ray)
{
	t_hit		closest;
	double		t;
	int			i;
	const int	count = scene->ids[4] / 2 + scene->ids[5] / 2
		+ scene->ids[6] / 2 + scene->ids[7] / 2;

	i = -1;
	closest.is_hit = 0;
	closest.t = INFINITY;
	while (++i < count)
	{
		if (check_hit(ray, scene->shapes[i], &t) && t < closest.t)
		{
			closest.is_hit = 1;
			closest.t = t;
			closest.ray = ray;
			closest.shape = scene->shapes[i];
		}
	}
	if (!closest.is_hit)
		return (miss_shader());
	return (hit_shader(scene, ray, closest));
}

static void	calc_cam_basis(t_scene *scene)
{
	t_vector	world_up;
	double		aspect;

	world_up = vec_new(0, 1, 0);
	if (fabs(vec_dot(scene->camera.dir, world_up)) > 1.0 - EPSILON)
		world_up = vec_new(0, 0, 1);
	scene->camera.right = vec_normalized(vec_cross(world_up,
				scene->camera.dir));
	scene->camera.up = vec_normalized(vec_cross(scene->camera.dir,
				scene->camera.right));
	aspect = (double)VIEW_WIDTH / (double)VIEW_HEIGHT;
	scene->camera.half_w = tan((scene->camera.fov * M_PI / 180.0) / 2.0);
	scene->camera.half_h = scene->camera.half_w / aspect;
}

int	render_scene(t_scene *scene, t_view_data *vd)
{
	int		x;
	int		y;
	t_ray	ray;

	calc_cam_basis(scene);
	ray.pos = scene->camera.pos;
	x = -1;
	while (++x < VIEW_WIDTH)
	{
		y = -1;
		while (++y < VIEW_HEIGHT)
		{
			ray.dir = vec_normalized(vec_add(scene->camera.dir, vec_add(
							vec_scale(scene->camera.right,
								((x / (double)VIEW_WIDTH) * 2.0 - 1.0)
								* scene->camera.half_w),
							vec_scale(scene->camera.up,
								(1.0 - (y / (double)VIEW_HEIGHT) * 2.0)
								* scene->camera.half_h)
							)
						));
			put_color(vd, x, y, trace_ray(scene, ray).color);
		}
	}
	return (mlx_put_image_to_window(vd->mlx, vd->win, vd->img, 0, 0), 0);
}
