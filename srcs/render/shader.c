/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   shader.c                                              :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/11/09 14:50:52 by yzeybek              #+#    #+#          */
/*   Updated: 2026/01/17 01:08:15 by yzeybek             ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mrt_render.h"

t_color	miss_shader(void)
{
	const t_color	ret = {0};

	return (ret);
}

static t_vector	get_normal(t_shape shape, t_vector point, t_ray ray)
{
	t_vector	n;

	if (shape.obj_type == OBJ_SP)
		n = vec_normalized(vec_sub(point, shape.pos));
	else if (shape.obj_type == OBJ_PL)
		n = shape.obj.pl->dir;
	else if (shape.obj_type == OBJ_CY)
		n = cylinder_normal(shape, point);
	else if (shape.obj_type == OBJ_CN)
		n = cone_normal(shape, point);
	else
		n = vec_new(0, 1, 0);
	if (vec_dot(n, ray.dir) > 0)
		n = vec_scale(n, -1.0);
	return (n);
}

static int	is_shadowed(t_scene *scene, t_vector point, t_light light)
{
	const int	count = scene->ids[4] / 2 + scene->ids[5] / 2
		+ scene->ids[6] / 2 + scene->ids[7] / 2;
	t_vector	to_light;
	t_ray		shadow_ray;
	double		t;
	int			i;

	to_light = vec_sub(light.pos, point);
	shadow_ray.pos = vec_add(point,
			vec_scale(vec_normalized(to_light), EPSILON));
	shadow_ray.dir = vec_normalized(to_light);
	i = -1;
	while (++i < count)
		if (check_hit(shadow_ray, scene->shapes[i], &t)
			&& t < vec_length(to_light))
			return (1);
	return (0);
}

t_color	hit_shader(t_scene *scene, t_ray ray, t_hit closest)
{
	const t_vector	point = vec_add(ray.pos, vec_scale(ray.dir, closest.t));
	const t_vector	normal = get_normal(closest.shape, point, ray);
	t_vector		light_dir;
	t_color			result;
	int				i;

	result = scale_color(scene->ambient.color, scene->ambient.ratio);
	i = -1;
	while (++i < scene->ids[2] / 2 + scene->ids[3] / 2)
	{
		if (scene->lights[i].is_cap)
			scene->lights[i].color = new_color(255);
		light_dir = vec_normalized(vec_sub(scene->lights[i].pos, point));
		if (is_shadowed(scene, point, scene->lights[i]))
			continue ;
		result = add_color(result, scale_color(mult_color(closest.shape.color, \
scene->lights[i].color), scene->lights[i].ratio * fmax(0.0, vec_dot(normal, \
light_dir)) * KD));
		result = add_color(result, scale_color(scene->lights[i].color, scene->\
lights[i].ratio * KS * pow(fmax(vec_dot(vec_normalized(vec_scale(ray.dir, -1.0))\
, vec_sub(vec_scale(normal, 2.0 * vec_dot(normal, light_dir)), light_dir)), 0.0)\
, SHINE)));
	}
	return (result);
}
