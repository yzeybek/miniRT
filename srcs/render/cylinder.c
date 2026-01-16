/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 00:57:16 by yzeybek           #+#    #+#             */
/*   Updated: 2026/01/16 17:59:53 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mrt_render.h"

t_vector	cylinder_normal(t_shape shape, t_vector point)
{
	t_vector	base;
	t_vector	cp;
	double		proj;

	base = vec_sub(shape.pos, vec_scale(shape.obj.cy->dir, shape.obj.cy->height
				* 0.5));
	cp = vec_sub(point, base);
	proj = vec_dot(cp, shape.obj.cy->dir);
	if (proj < EPSILON)
		return (vec_scale(shape.obj.cy->dir, -1.0));
	if (proj > shape.obj.cy->height - EPSILON)
		return (shape.obj.cy->dir);
	return (vec_normalized(vec_sub(cp, vec_scale(shape.obj.cy->dir, proj))));
}

static int	solve_quadratic(t_ray ray, t_shape shape, double *ts)
{
	t_vector	base;
	t_vector	ray_x_dir;
	t_vector	oc_x_dir;
	double		abc[3];

	base = vec_sub(shape.pos, vec_scale(shape.obj.cy->dir, shape.obj.cy->height
				* 0.5));
	ray_x_dir = vec_cross(ray.dir, shape.obj.cy->dir);
	oc_x_dir = vec_cross(vec_sub(ray.pos, base), shape.obj.cy->dir);
	abc[0] = vec_dot(ray_x_dir, ray_x_dir);
	if (abc[0] < EPSILON)
		return (0);
	abc[1] = 2.0 * vec_dot(ray_x_dir, oc_x_dir);
	abc[2] = vec_dot(oc_x_dir, oc_x_dir) - pow(shape.obj.cy->dia * 0.5, 2);
	if (abc[1] * abc[1] - 4.0 * abc[0] * abc[2] < 0.0)
		return (0);
	ts[0] = (-abc[1] - sqrt(abc[1] * abc[1] - 4.0 * abc[0] * abc[2]))
		/ (2.0 * abc[0]);
	ts[1] = (-abc[1] + sqrt(abc[1] * abc[1] - 4.0 * abc[0] * abc[2]))
		/ (2.0 * abc[0]);
	return (1);
}

static int	body_intersect(t_ray ray, t_shape shape, double *t)
{
	t_vector	base;
	double		ts[2];
	double		proj[2];

	base = vec_sub(shape.pos, vec_scale(shape.obj.cy->dir, shape.obj.cy->height
				* 0.5));
	if (!solve_quadratic(ray, shape, ts))
		return (0);
	proj[0] = vec_dot(vec_sub(vec_add(ray.pos, vec_scale(ray.dir, ts[0])),
				base), shape.obj.cy->dir);
	proj[1] = vec_dot(vec_sub(vec_add(ray.pos, vec_scale(ray.dir, ts[1])),
				base), shape.obj.cy->dir);
	if (ts[0] > EPSILON && proj[0] >= 0.0 && proj[0] <= shape.obj.cy->height)
	{
		*t = ts[0];
		return (1);
	}
	if (ts[1] > EPSILON && proj[1] >= 0.0 && proj[1] <= shape.obj.cy->height)
	{
		*t = ts[1];
		return (1);
	}
	return (0);
}

static int	cap_intersect(t_ray ray, t_shape shape, double *t, t_byte tb)
{
	double		temp_t;
	double		denom;
	t_vector	nml;
	t_vector	ctr;
	t_vector	htc;

	nml = vec_scale(shape.obj.cy->dir, -1);
	ctr = vec_sub(shape.pos, vec_scale(nml, shape.obj.cy->height * -0.5));
	if (tb)
	{
		nml = shape.obj.cy->dir;
		ctr = vec_add(shape.pos, vec_scale(nml, shape.obj.cy->height * 0.5));
	}
	denom = vec_dot(ray.dir, nml);
	if (fabs(denom) < EPSILON)
		return (0);
	temp_t = vec_dot(vec_sub(ctr, ray.pos), nml) / denom;
	if (temp_t <= EPSILON)
		return (0);
	htc = vec_sub(vec_add(ray.pos, vec_scale(ray.dir, temp_t)), ctr);
	if (vec_dot(htc, htc) > pow(shape.obj.cy->dia * 0.5, 2))
		return (0);
	*t = temp_t;
	return (1);
}

int	cylinder_intersect(t_ray ray, t_shape shape, double *t)
{
	double		tmp_t;
	double		closest;
	t_byte		hit;

	hit = 0;
	closest = INFINITY;
	if (body_intersect(ray, shape, &tmp_t) && tmp_t < closest)
	{
		closest = tmp_t;
		hit = 1;
	}
	if (cap_intersect(ray, shape, &tmp_t, 0) && tmp_t < closest)
	{
		closest = tmp_t;
		hit = 1;
	}
	if (cap_intersect(ray, shape, &tmp_t, 1) && tmp_t < closest)
	{
		closest = tmp_t;
		hit = 1;
	}
	if (hit)
		*t = closest;
	return (hit);
}
