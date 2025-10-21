/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   parse_objs.c                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/05 10:15:03 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:47:49 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "mrt_error.h"
#include "mrt_parser.h"

int	parse_plane(char *str, t_scene *scene, int *counts)
{
	const int	sum = counts[0] / 2 + counts[1] / 2 + counts[2] / 2 + counts[3]
		/ 2;

	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM), 1);
	scene->shapes = mem_realloc(scene->shapes, sizeof(t_shape) * (sum + 1));
	scene->shapes[sum].obj.pl = mem_calloc(sizeof(t_plane), 1);
	scene->shapes[sum].obj_type = OBJ_PL;
	pass_chars(&str, " \t");
	if (!*str || parse_vector(str, &scene->shapes[sum].pos))
		return (put_err(ERR_PARSE_PL_POS), 1);
	pass_chars(&str, "0123456789-+.,");
	pass_chars(&str, " \t");
	if (!*str || parse_vector(str, &scene->shapes[sum].obj.pl->dir))
		return (put_err(ERR_PARSE_PL_DIR), 1);
	pass_chars(&str, "0123456789-+.,");
	pass_chars(&str, " \t");
	if (!*str || parse_color(str, &scene->shapes[sum].color))
		return (put_err(ERR_PARSE_PL_COLOR), 1);
	pass_chars(&str, "0123456789, \t");
	if (*str)
		return (put_err(ERR_PARSE_PL_UNKNOWN), 1);
	return (2);
}

int	parse_sphere(char *str, t_scene *scene, int *counts)
{
	const int	sum = counts[0] / 2 + counts[1] / 2 + counts[2] / 2 + counts[3]
		/ 2;

	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM), 1);
	scene->shapes = mem_realloc(scene->shapes, sizeof(t_shape) * (sum + 1));
	scene->shapes[sum].obj.sp = mem_calloc(sizeof(t_sphere), 1);
	scene->shapes[sum].obj_type = OBJ_SP;
	pass_chars(&str, " \t");
	if (!*str || parse_vector(str, &scene->shapes[sum].pos))
		return (put_err(ERR_PARSE_SP_POS), 1);
	pass_chars(&str, "0123456789-+.,");
	pass_chars(&str, " \t");
	if (!*str || parse_double(str, &scene->shapes[sum].obj.sp->dia))
		return (put_err(ERR_PARSE_SP_DIA), 1);
	pass_chars(&str, "0123456789-+.");
	pass_chars(&str, " \t");
	if (!*str || parse_color(str, &scene->shapes[sum].color))
		return (put_err(ERR_PARSE_SP_COLOR), 1);
	pass_chars(&str, "0123456789, \t");
	if (*str)
		return (put_err(ERR_PARSE_SP_UNKNOWN), 1);
	return (2);
}

static int	parse_helper(char *str, t_scene *scene, int sum, t_obj_type type)
{
	pass_chars(&str, "0123456789-+.");
	pass_chars(&str, " \t");
	if (type == OBJ_CY)
	{
		if (!*str || parse_color(str, &scene->shapes[sum].color))
			return (put_err(ERR_PARSE_CY_COLOR), 1);
		pass_chars(&str, "0123456789, \t");
		if (*str)
			return (put_err(ERR_PARSE_CY_UNKNOWN), 1);
		return (2);
	}
	if (!*str || parse_color(str, &scene->shapes[sum].color))
		return (put_err(ERR_PARSE_CN_COLOR), 1);
	pass_chars(&str, "0123456789, \t");
	if (*str)
		return (put_err(ERR_PARSE_CN_UNKNOWN), 1);
	return (2);
}

int	parse_cylinder(char *str, t_scene *scene, int *counts)
{
	const int	sum = counts[0] / 2 + counts[1] / 2 + counts[2] / 2 + counts[3]
		/ 2;

	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM));
	scene->shapes = mem_realloc(scene->shapes, sizeof(t_shape) * (sum + 1));
	scene->shapes[sum].obj.cy = mem_calloc(sizeof(t_cylinder), 1);
	scene->shapes[sum].obj_type = OBJ_CY;
	pass_chars(&str, " \t");
	if (!*str || parse_vector(str, &scene->shapes[sum].pos))
		return (put_err(ERR_PARSE_CY_POS), 1);
	pass_chars(&str, "0123456789-+.,");
	pass_chars(&str, " \t");
	if (!*str || parse_vector(str, &scene->shapes[sum].obj.cy->dir))
		return (put_err(ERR_PARSE_CY_DIR), 1);
	pass_chars(&str, "0123456789-+.,");
	pass_chars(&str, " \t");
	if (!*str || parse_double(str, &scene->shapes[sum].obj.cy->dia))
		return (put_err(ERR_PARSE_CY_DIA), 1);
	pass_chars(&str, "0123456789-+.");
	pass_chars(&str, " \t");
	if (!*str || parse_double(str, &scene->shapes[sum].obj.cy->height))
		return (put_err(ERR_PARSE_CY_HEIGHT), 1);
	return (parse_helper(str, scene, sum, OBJ_CY));
}

int	parse_cone(char *str, t_scene *scene, int *counts)
{
	const int	sum = counts[0] / 2 + counts[1] / 2 + counts[2] / 2 + counts[3]
		/ 2;

	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM));
	scene->shapes = mem_realloc(scene->shapes, sizeof(t_shape) * (sum + 1));
	scene->shapes[sum].obj.cn = mem_calloc(sizeof(t_cone), 1);
	scene->shapes[sum].obj_type = OBJ_CN;
	pass_chars(&str, " \t");
	if (!*str || parse_vector(str, &scene->shapes[sum].pos))
		return (put_err(ERR_PARSE_CN_POS), 1);
	pass_chars(&str, "0123456789-+.,");
	pass_chars(&str, " \t");
	if (!*str || parse_vector(str, &scene->shapes[sum].obj.cn->dir))
		return (put_err(ERR_PARSE_CN_DIR), 1);
	pass_chars(&str, "0123456789-+.,");
	pass_chars(&str, " \t");
	if (!*str || parse_double(str, &scene->shapes[sum].obj.cn->dia))
		return (put_err(ERR_PARSE_CN_DIA), 1);
	pass_chars(&str, "0123456789-+.");
	pass_chars(&str, " \t");
	if (!*str || parse_double(str, &scene->shapes[sum].obj.cn->height))
		return (put_err(ERR_PARSE_CN_HEIGHT), 1);
	return (parse_helper(str, scene, sum, OBJ_CN));
}
