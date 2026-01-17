/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   cone.c                                                :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/01/16 21:30:34 by yzeybek              #+#    #+#          */
/*   Updated: 2026/01/17 15:31:07 by yzeybek             ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mrt_render.h"

t_vector	cone_normal(t_shape shape, t_vector point)
{
	t_vector	cp;
	double		proj;
	double		radius_at_h;
	t_vector	radial;

	cp = vec_sub(point, shape.pos);
	proj = vec_dot(cp, shape.obj.cn->dir);
	if (proj > shape.obj.cn->height - EPSILON)
		return (shape.obj.cn->dir);
	radial = vec_sub(cp, vec_scale(shape.obj.cn->dir, proj));
	radius_at_h = (shape.obj.cn->dia * 0.5) * (proj / shape.obj.cn->height);
	return (vec_normalized(vec_sub(vec_scale(radial, shape.obj.cn->height),
				vec_scale(shape.obj.cn->dir, radius_at_h * shape.obj.cn->height
					/ (shape.obj.cn->dia * 0.5)))));
}

static int	solve_quadratic(t_ray ray, t_shape shape, double *ts)
{
	const t_vector	co = vec_sub(ray.pos, shape.pos);
	const double	k_2 = pow(shape.obj.cn->dia * 0.5, 2) /
			pow(shape.obj.cn->height, 2);
	double			abc[3];

	abc[0] = vec_dot(ray.dir, ray.dir) - (1.0 + k_2)
		* pow(vec_dot(ray.dir, shape.obj.cn->dir), 2);
	abc[1] = 2.0 * (vec_dot(ray.dir, co) - (1.0 + k_2)
			* vec_dot(ray.dir, shape.obj.cn->dir)
			* vec_dot(co, shape.obj.cn->dir));
	abc[2] = vec_dot(co, co) - (1.0 + k_2)
		* pow(vec_dot(co, shape.obj.cn->dir), 2);
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
	t_vector	point;
	double		proj[2];
	double		ts[2];

	if (!solve_quadratic(ray, shape, ts))
		return (0);
	point = vec_add(ray.pos, vec_scale(ray.dir, ts[0]));
	proj[0] = vec_dot(vec_sub(point, shape.pos), shape.obj.cn->dir);
	point = vec_add(ray.pos, vec_scale(ray.dir, ts[1]));
	proj[1] = vec_dot(vec_sub(point, shape.pos), shape.obj.cn->dir);
	if (ts[0] > EPSILON && proj[0] >= 0.0 && proj[0] <= shape.obj.cn->height)
	{
		*t = ts[0];
		return (1);
	}
	if (ts[1] > EPSILON && proj[1] >= 0.0 && proj[1] <= shape.obj.cn->height)
	{
		*t = ts[1];
		return (1);
	}
	return (0);
}

static int	cap_intersect(t_ray ray, t_shape shape, double *t)
{
	double		temp_t;
	double		denom;
	t_vector	ctr;
	t_vector	htc;

	ctr = vec_add(shape.pos, vec_scale(shape.obj.cn->dir,
				shape.obj.cn->height));
	denom = vec_dot(ray.dir, shape.obj.cn->dir);
	if (fabs(denom) < EPSILON)
		return (0);
	temp_t = vec_dot(vec_sub(ctr, ray.pos), shape.obj.cn->dir) / denom;
	if (temp_t <= EPSILON)
		return (0);
	htc = vec_sub(vec_add(ray.pos, vec_scale(ray.dir, temp_t)), ctr);
	if (vec_dot(htc, htc) > pow(shape.obj.cn->dia * 0.5, 2))
		return (0);
	*t = temp_t;
	return (1);
}

int	cone_intersect(t_ray ray, t_shape shape, double *t)
{
	double	tmp_t;
	double	closest;
	t_byte	hit;

	hit = 0;
	closest = INFINITY;
	if (body_intersect(ray, shape, &tmp_t) && tmp_t < closest)
	{
		closest = tmp_t;
		hit = 1;
	}
	if (cap_intersect(ray, shape, &tmp_t) && tmp_t < closest)
	{
		closest = tmp_t;
		hit = 1;
	}
	if (hit)
		*t = closest;
	return (hit);
}
