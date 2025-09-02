/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_consts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:13:25 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/02 17:39:21 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_consts.h"

t_vector	vec_new(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector	vec_from_double(double d)
{
	return (vec_new(d, d, d));
}

t_vector	vec_zero(void)
{
	return (vec_new(0.0, 0.0, 0.0));
}

t_vector	vec_copy(const t_vector *v)
{
	return (vec_new(v->x, v->y, v->z));
}
