/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_norms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:22:54 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/02 17:28:01 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec_norms.h"
#include "vec_consts.h"

double	vec_length2(const t_vector *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}

double	vec_length(const t_vector *v)
{
	return (sqrt(vec_length2(v)));
}

double	vec_normalize(t_vector *v)
{
	double	len;
	double	inv;

	len = vec_length(v);
	if (len > 0.0)
	{
		inv = 1.0 / len;
		v->x *= inv;
		v->y *= inv;
		v->z *= inv;
	}
	return (len);
}

t_vector	vec_normalized(const t_vector *v)
{
	t_vector	out;

	out = vec_copy(v);
	vec_normalize(&out);
	return (out);
}
