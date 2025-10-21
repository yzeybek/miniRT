/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   parse_elem.c                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/05 09:36:07 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:47:52 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#define FT_IS
#include "libft.h"
#include "libmem.h"
#include "mrt_error.h"
#include "mrt_parser.h"

int	parse_ambient(char *str, t_scene *scene, int count)
{
	if (count >= 2)
		return (put_err(ERR_PARSE_COUNT_AMB), 1);
	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM), 1);
	pass_chars(&str, " \t");
	if (!*str || parse_double(str, &scene->ambient.ratio))
		return (put_err(ERR_PARSE_AMB_RATIO), 1);
	pass_chars(&str, "0123456789-+.");
	pass_chars(&str, " \t");
	if (!*str || parse_color(str, &scene->ambient.color))
		return (put_err(ERR_PARSE_AMB_COLOR), 1);
	pass_chars(&str, "0123456789, \t");
	if (*str)
		return (put_err(ERR_PARSE_AMB_UNKNOWN), 1);
	return (2);
}

int	parse_camera(char *str, t_scene *scene, int count)
{
	if (count >= 2)
		return (put_err(ERR_PARSE_COUNT_AMB), 1);
	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM), 1);
	pass_chars(&str, " \t");
	if (!*str || parse_vector(str, &scene->camera.pos))
		return (put_err(ERR_PARSE_CAM_POS), 1);
	pass_chars(&str, "0123456789-+.,");
	pass_chars(&str, " \t");
	if (!*str || parse_vector(str, &scene->camera.dir))
		return (put_err(ERR_PARSE_CAM_DIR), 1);
	pass_chars(&str, "0123456789-+.,");
	pass_chars(&str, " \t");
	if (!*str || parse_double(str, &scene->camera.fov))
		return (put_err(ERR_PARSE_CAM_FOV), 1);
	pass_chars(&str, "0123456789-+. \t");
	if (*str)
		return (put_err(ERR_PARSE_CAM_UNKNOWN), 1);
	return (2);
}

int	parse_light(char *str, t_scene *scene, int count, t_byte cap)
{
	if (count >= 2 && cap)
		return (put_err(ERR_PARSE_COUNT_AMB), 1);
	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM), 1);
	scene->lights = mem_realloc(scene->lights, sizeof(t_light) * (count / 2
				+ 1));
	pass_chars(&str, " \t");
	if (!*str || parse_vector(str, &scene->lights[count / 2].pos))
		return (put_err(ERR_PARSE_LIGHT_POS), 1);
	pass_chars(&str, "0123456789-+.,");
	pass_chars(&str, " \t");
	if (!*str || parse_double(str, &scene->lights[count / 2].ratio))
		return (put_err(ERR_PARSE_LIGHT_RATIO), 1);
	pass_chars(&str, "0123456789-+.");
	pass_chars(&str, " \t");
	if (!cap && (!*str || parse_color(str, &scene->lights[count / 2].color)))
		return (put_err(ERR_PARSE_LIGHT_COLOR), 1);
	pass_chars(&str, "0123456789, \t");
	if (*str)
		return (put_err(ERR_PARSE_LIGHT_UNKNOWN), 1);
	return (2);
}
