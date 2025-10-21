/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   vec_norms.h                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/02 17:07:55 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:52:47 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_NORMS_H
# define VEC_NORMS_H

# include "vec_structs.h"

double		vec_length2(const t_vector *v);
double		vec_length(const t_vector *v);
double		vec_normalize(t_vector *v);
t_vector	vec_normalized(const t_vector *v);

#endif // VEC_NORMS_H
