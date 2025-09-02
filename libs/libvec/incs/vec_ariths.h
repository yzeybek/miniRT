/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ariths.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:29:05 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/02 23:10:04 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ARITHS_H
# define VEC_ARITHS_H

# include "vec_structs.h"

t_vector	vec_scale(const t_vector *v, double s);
t_vector	vec_divd(const t_vector *v, double s);
t_vector	vec_neg(const t_vector *v);

#endif // VEC_ARITHS_H
