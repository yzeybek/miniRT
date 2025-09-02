/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_oprs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:30:23 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/02 17:33:24 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_oprs.h"
#include "vec_consts.h"

t_vector	vec_add(const t_vector *a, const t_vector *b)
{
	return (vec_new(a->x + b->x, a->y + b->y, a->z + b->z));
}

t_vector	vec_sub(const t_vector *a, const t_vector *b)
{
	return (vec_new(a->x - b->x, a->y - b->y, a->z - b->z));
}

t_vector	vec_mul(const t_vector *a, const t_vector *b)
{
	return (vec_new(a->x * b->x, a->y * b->y, a->z * b->z));
}

t_vector	vec_div(const t_vector *a, const t_vector *b)
{
	return (vec_new(a->x / b->x, a->y / b->y, a->z / b->z));
}
