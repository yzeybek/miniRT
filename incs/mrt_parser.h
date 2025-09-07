/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   mrt_parser.h                                        :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: yzeybek <yzeybek@student.42.com.tr>         +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:43:29 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/08 02:05:37 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_PARSER_H
# define MRT_PARSER_H

# include "mrt_structs.h"

t_scene		*parse_scene(char *file);

int			parse_ambient(char *str, t_scene *scene, int count);
int			parse_camera(char *str, t_scene *scene, int count);
int			parse_light(char *str, t_scene *scene, int count, t_byte cap);

int			parse_plane(char *str, t_scene *scene, int *counts);
int			parse_sphere(char *str, t_scene *scene, int *counts);
int			parse_cylinder(char *str, t_scene *scene, int *counts);
int			parse_cone(char *str, t_scene *scene, int *counts);

int			check_numeric(char *str);
void		pass_chars(char **str, char *chars);
int			parse_double(char *str, double *ret);
int			parse_color(char *str, t_color *ret);
int			parse_vector(char *str, t_vector *ret);

#endif
