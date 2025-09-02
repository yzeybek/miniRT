/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_prods.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:07:05 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/02 23:10:49 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_PRODS_H
# define VEC_PRODS_H

# include "vec_structs.h"

double		vec_dot(const t_vector *a, const t_vector *b);
t_vector	vec_cross(const t_vector *a, const t_vector *b);

#endif // VEC_PRODS_H
