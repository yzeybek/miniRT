/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_arith.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:33:39 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/02 23:10:55 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_ariths.h"
#include "vec_consts.h"

t_vector	vec_scale(const t_vector *v, double s)
{
	return (vec_new(v->x * s, v->y * s, v->z * s));
}

t_vector	vec_divd(const t_vector *v, double s)
{
	return (vec_new(v->x / s, v->y / s, v->z / s));
}

t_vector	vec_neg(const t_vector *v)
{
	return (vec_new(-v->x, -v->y, -v->z));
}
