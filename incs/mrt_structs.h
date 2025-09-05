/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 23:08:33 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/05 09:05:55 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_STRUCTS_H
# define MRT_STRUCTS_H

# include "libvec.h"

# define ID_COUNT 8

typedef unsigned char	t_byte;
typedef t_vector		t_point;

typedef enum e_obj_type
{
	OBJ_SP,
	OBJ_PL,
	OBJ_CY,
	OBJ_CN,
}	t_obj_type;

typedef union u_color
{
	struct
	{
		t_byte	r;
		t_byte	g;
		t_byte	b;
		t_byte	a;
	};
	int				color;
}	t_color;

typedef struct s_camera
{
	t_point		pos;
	t_vector	dir;
	double		fov;

}	t_camera;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;

}	t_ambient;

typedef struct s_light
{
	t_point		pos;
	t_color		color;
	double		ratio;

}	t_light;

typedef struct s_sphere
{
	double	dia;

}	t_sphere;

typedef struct s_plane
{
	t_vector	dir;

}	t_plane;

typedef struct s_cylinder
{
	t_vector	dir;
	double		rad;
	double		height;

}	t_cylinder;

typedef struct s_cone
{
	t_vector	dir;
	double		rad;
	double		height;

}	t_cone;

typedef struct s_shape
{
	union u_obj
	{
		t_sphere	sp;
		t_plane		pl;
		t_cylinder	cy;
		t_cone		cn;
	} obj;
	t_obj_type	obj_type;
	t_color		color;
	t_point		pos;

}	t_shape;

typedef struct s_ray
{
	t_point		pos;
	t_vector	dir;

}	t_ray;

typedef struct s_hit
{
	t_ray	ray;
	t_shape	shape;
	t_color	color;

}	t_hit;

typedef struct s_scene
{
	t_camera	camera;
	t_ambient	ambient;
	t_light		*lights;
	t_shape		*shapes;

}	t_scene;

#endif // MRT_STRUCTS_H
