/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:21:44 by yzeybek           #+#    #+#             */
/*   Updated: 2026/01/16 18:02:27 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mrt_render.h"

t_vector	cone_normal(t_shape shape, t_vector point)
{

}

static int	solve_quadratic(t_ray ray, t_shape shape, double *ts)
{
	double	abc[3];
	
}

static int	body_intersect(t_ray ray, t_shape shape, double *t)
{
	double	ts[2];

	if (!solve_quadratic(ray, shape, ts))
		return (0);
	// clamping
}

static int	cap_intersect(t_ray ray, t_shape shape, double *t)
{

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
