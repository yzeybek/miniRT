/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_oprs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:07:30 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/02 17:29:02 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_OPRS_H
# define VEC_OPRS_H

# include "vec_strcts.h"

t_vector	vec_add(const t_vector *a, const t_vector *b);
t_vector	vec_sub(const t_vector *a, const t_vector *b);
t_vector	vec_mul(const t_vector *a, const t_vector *b);
t_vector	vec_div(const t_vector *a, const t_vector *b);

#endif // VEC_OPRS_H
