/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   mrt_render.h                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/11/04 12:57:10 by yzeybek              #+#    #+#          */
/*   Updated: 2026/01/17 01:08:15 by yzeybek             ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_RENDER_H
# define MRT_RENDER_H

# include "mrt_view.h"
# include "mrt_structs.h"

# define EPSILON 1e-4
# define KD 0.8
# define KS 1
# define SHINE 32.0

int			render_scene(t_scene *scene, t_view_data *vd);
int			check_hit(t_ray ray, t_shape shape, double *t);

t_color		new_color(t_byte v);
t_color		scale_color(t_color color, double s);
t_color		mult_color(t_color a, t_color b);
t_color		add_color(t_color a, t_color b);
t_color		add_color(t_color a, t_color b);
void		put_color(t_view_data *vd, int x, int y, int color);

int			plane_intersect(t_ray ray, t_shape shape, double *t);
int			sphere_intersect(t_ray ray, t_shape shape, double *t);
int			cylinder_intersect(t_ray ray, t_shape shape, double *t);
int			cone_intersect(t_ray ray, t_shape shape, double *t);

t_vector	cylinder_normal(t_shape shape, t_vector point);
t_vector	cone_normal(t_shape shape, t_vector point);

t_color		miss_shader(void);
t_color		hit_shader(t_scene *scene, t_ray ray, t_hit closest);

#endif // MRT_RENDER_H
