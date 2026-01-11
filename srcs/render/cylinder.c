/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   cylinder.c                                            :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/01/11 00:57:16 by yzeybek              #+#    #+#          */
/*   Updated: 2026/01/12 01:24:37 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mrt_render.h"

t_vector	cylinder_normal(t_shape shape, t_vector point)
{
	t_vector	dir;
	t_vector	base;
	t_vector	cp;
	double		proj;

	dir = vec_normalized(shape.obj.cy->dir);
	base = vec_sub(shape.pos, vec_scale(dir, shape.obj.cy->height * 0.5));
	cp = vec_sub(point, base);
	proj = vec_dot(cp, dir);
	if (proj < EPSILON)
		return (vec_scale(dir, -1.0));
	if (proj > shape.obj.cy->height - EPSILON)
		return (dir);
	return (vec_normalized(vec_sub(cp, vec_scale(dir, proj))));
}

static int	solve_quadratic(t_ray ray, t_shape shape, double *ts)
{
	t_vector	dir;
	t_vector	base;
	t_vector	v;
	t_vector	w;
	double		c[3];

	dir = vec_normalized(shape.obj.cy->dir);
	base = vec_sub(shape.pos, vec_scale(dir, shape.obj.cy->height * 0.5));
	v = vec_sub(ray.dir, vec_scale(dir, vec_dot(ray.dir, dir)));
	c[0] = vec_dot(v, v);
	if (fabs(c[0]) < EPSILON)
		return (0);
	w = vec_sub(vec_sub(ray.pos, base), vec_scale(dir,
				vec_dot(vec_sub(ray.pos, base), dir)));
	c[1] = 2.0 * vec_dot(v, w);
	c[2] = vec_dot(w, w) - pow(shape.obj.cy->dia * 0.5, 2);
	if (c[1] * c[1] - 4.0 * c[0] * c[2] < 0.0)
		return (0);
	ts[0] = (-c[1] - sqrt(c[1] * c[1] - 4.0 * c[0] * c[2])) / (2.0 * c[0]);
	ts[1] = (-c[1] + sqrt(c[1] * c[1] - 4.0 * c[0] * c[2])) / (2.0 * c[0]);
	return (1);
}

static int	body_intersect(t_ray ray, t_shape shape, double *t)
{
	t_vector	dir;
	t_vector	base;
	double		ts[2];
	double		proj[2];

	dir = vec_normalized(shape.obj.cy->dir);
	base = vec_sub(shape.pos, vec_scale(dir, shape.obj.cy->height * 0.5));
	if (!solve_quadratic(ray, shape, ts))
		return (0);
	proj[0] = vec_dot(vec_sub(vec_add(ray.pos, vec_scale(ray.dir, ts[0])),
				base), dir);
	proj[1] = vec_dot(vec_sub(vec_add(ray.pos, vec_scale(ray.dir, ts[1])),
				base), dir);
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

	nml = vec_scale(vec_normalized(shape.obj.cy->dir), -1);
	ctr = vec_sub(shape.pos, vec_scale(nml, shape.obj.cy->height * -0.5));
	if (tb)
	{
		nml = vec_normalized(shape.obj.cy->dir);
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
	int			hit;

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
