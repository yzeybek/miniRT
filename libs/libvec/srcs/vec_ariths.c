/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   vec_ariths.c                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/02 17:33:39 by yzeybek              #+#    #+#          */
/*   Updated: 2025/11/08 17:33:31 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "vec_ariths.h"
#include "vec_consts.h"

t_vector	vec_scale(const t_vector v, double s)
{
	return (vec_new(v.x * s, v.y * s, v.z * s));
}

t_vector	vec_divd(const t_vector v, double s)
{
	return (vec_new(v.x / s, v.y / s, v.z / s));
}

t_vector	vec_neg(const t_vector v)
{
	return (vec_new(-v.x, -v.y, -v.z));
}
