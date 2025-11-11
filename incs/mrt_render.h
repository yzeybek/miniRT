/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   mrt_render.h                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/11/04 12:57:10 by yzeybek              #+#    #+#          */
/*   Updated: 2025/11/11 15:01:09 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_RENDER_H
# define MRT_RENDER_H

# include "mrt_view.h"
# include "mrt_structs.h"

int		render_scene(t_scene *scene, t_view_data *vd);

void	put_pixel(t_view_data *vd, int x, int y, int color);

int		plane_intersect(t_ray ray, t_shape shape, double *t);
int		sphere_intersect(t_ray ray, t_shape shape, double *t);
int		cylinder_intersect(t_ray ray, t_shape shape, double *t);
int		cone_intersect(t_ray ray, t_shape shape, double *t);

t_color	miss_shader();
t_color	hit_shader(t_scene *scene, t_ray ray, t_hit closest);

#endif // MRT_RENDER_H
