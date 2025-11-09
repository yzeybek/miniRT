/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   vec_prods.h                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/02 17:07:05 by yzeybek              #+#    #+#          */
/*   Updated: 2025/11/08 17:39:40 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_PRODS_H
# define VEC_PRODS_H

# include "vec_structs.h"

double		vec_dot(const t_vector a, const t_vector b);
t_vector	vec_cross(const t_vector a, const t_vector b);

#endif // VEC_PRODS_H
