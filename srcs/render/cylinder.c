/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 00:57:16 by yzeybek           #+#    #+#             */
/*   Updated: 2026/01/11 01:49:41 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mrt_render.h"

t_vector	cylinder_normal(t_shape shape, t_vector point)
{
	t_vector	a;
	t_vector	cp;
	double		proj;

	a = vec_normalized(shape.obj.cy->dir);
	cp = vec_sub(point, shape.pos);
	proj = vec_dot(cp, a);
	if (proj < EPSILON)
		return (vec_scale(a, -1.0));
	if (proj > shape.obj.cy->height - EPSILON)
		return (a);
	return (vec_normalized(vec_sub(cp, vec_scale(a, proj))));
}

static int	cylinder_body_intersect(t_ray ray,t_shape shape, double *t)
{
	t_vector axis = vec_normalized(shape.obj.cy->dir);
	double radius = shape.obj.cy->dia * 0.5;
	double		t0;
	double		t1;
	double		proj;
	t_vector	p;

	if (!solve_quadratic(ray, shape, axis, radius, &t0, &t1))
		return (0);
	if (t0 > EPSILON)
	{
		p = vec_sub(vec_add(ray.pos, vec_scale(ray.dir, t0)), shape.pos);
		proj = vec_dot(p, axis);
		if (proj >= 0.0 && proj <= shape.obj.cy->height)
		{
			*t = t0;
			return (1);
		}
	}
	if (t1 > EPSILON)
	{
		p = vec_sub(vec_add(ray.pos, vec_scale(ray.dir, t1)), shape.pos);
		proj = vec_dot(p, axis);
		if (proj >= 0.0 && proj <= shape.obj.cy->height)
		{
			*t = t1;
			return (1);
		}
	}
	return (0);
}


static int	cap_intersect(t_ray ray, t_shape shape, double *t, t_byte tp)
{
	t_vector center = shape.pos;
	t_vector normal = vec_scale(vec_normalized(shape.obj.cy->dir), -1.0);
	double radius = shape.obj.cy->dia * 0.5;
	double		denom;
	double		temp_t;
	t_vector	p;
	t_vector	v;

	denom = vec_dot(ray.dir, normal);
	if (fabs(denom) < EPSILON)
		return (0);
	temp_t = vec_dot(vec_sub(center, ray.pos), normal) / denom;
	if (temp_t <= EPSILON)
		return (0);
	p = vec_add(ray.pos, vec_scale(ray.dir, temp_t));
	v = vec_sub(p, center);
	if (vec_dot(v, v) > radius * radius)
		return (0);
	*t = temp_t;
	return (1);
}

int	cylinder_intersect(t_ray ray, t_shape shape, double *t)
{
	double		tmp_t;
	double		hit_t;

	hit_t = *t;
	if (body_intersect(ray, shape, &tmp_t))
		*t = tmp_t;
	if (cap_intersect(ray, shape, &tmp_t, 0) && tmp_t < *t)
		*t = tmp_t;
	if (cap_intersect(ray, shape, &tmp_t, 1) && tmp_t < *t)
		*t = tmp_t;
	if (hit_t == *t)
		return (0);
	return (1);
}
