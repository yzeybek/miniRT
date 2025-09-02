/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_prods.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:36:01 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/02 17:38:00 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_prods.h"
#include "vec_consts.h"

double	vec_dot(const t_vector *a, const t_vector *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vector	vec_cross(const t_vector *a, const t_vector *b)
{
	return (vec_new(
			a->y * b->z - a->z * b->y,
			a->z * b->x - a->x * b->z,
			a->x * b->y - a->y * b->x
		));
}
