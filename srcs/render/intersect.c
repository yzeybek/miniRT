/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   intersect.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/11/09 14:46:41 by yzeybek              #+#    #+#          */
/*   Updated: 2025/11/15 15:31:03 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mrt_render.h"

int	plane_intersect(t_ray ray, t_shape shape, double *t)
{
	t_vector	p0l0;
	double		denom;

	denom = vec_dot(shape.obj.pl->dir, ray.dir);
	if (fabs(denom) < EPSILON)
		return (0);
	p0l0 = vec_sub(shape.pos, ray.pos);
	*t = vec_dot(p0l0, shape.obj.pl->dir) / denom;
	if (*t < EPSILON)
		return (0);
	return (1);
}

int	sphere_intersect(t_ray ray, t_shape shape, double *t)
{
	t_vector	oc;
	double		a;
	double		b;
	double		discriminant;

	oc = vec_sub(ray.pos, shape.pos);
	a = vec_dot(ray.dir, ray.dir);
	b = 2.0 * vec_dot(oc, ray.dir);
	discriminant = b * b - 4 * a * (vec_dot(oc, oc) - pow(shape.obj.sp->dia
				/ 2.0, 2));
	if (discriminant < 0.0)
		return (0);
	if ((-b - sqrt(discriminant)) / (2.0 * a) > EPSILON)
		*t = (-b - sqrt(discriminant)) / (2.0 * a);
	else if ((-b + sqrt(discriminant)) / (2.0 * a) > EPSILON)
		*t = (-b + sqrt(discriminant)) / (2.0 * a);
	else
		return (0);
	return (1);
}

int	cylinder_intersect(t_ray ray, t_shape shape, double *t)
{
	(void)ray;
	(void)shape;
	(void)t;
	return (0);
}

int	cone_intersect(t_ray ray, t_shape shape, double *t)
{
	(void)ray;
	(void)shape;
	(void)t;
	return (0);
}
