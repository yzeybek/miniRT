/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   vec_consts.h                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/02 17:05:18 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:52:44 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_CONSTS_H
# define VEC_CONSTS_H

# include "vec_structs.h"

t_vector	vec_new(double x, double y, double z);
t_vector	vec_from_double(double d);
t_vector	vec_zero(void);
t_vector	vec_copy(const t_vector *v);

#endif // VEC_CONSTS_H
