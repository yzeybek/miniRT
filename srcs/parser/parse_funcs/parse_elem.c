/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   parse_elem.c                                        :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: yzeybek <yzeybek@student.42.com.tr>         +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:36:07 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/07 06:35:21 by yzeybek          ###   ########.tr       */
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
	while (*str == ' ' || *str == '\t')
		str++;
	if (!*str || parse_double(str, &scene->ambient.ratio))
		return (put_err(ERR_PARSE_AMB_RATIO), 1);
	while (ft_isdigit(*str) || *str == '-' || *str == '+' || *str == '.'
			|| *str == ' ' || *str == '\t')
		str++;
	if (!*str || parse_color(str, &scene->ambient.color))
		return (put_err(ERR_PARSE_AMB_COLOR), 1);
	while (ft_isdigit(*str) || *str == ',' || *str == '\t' || *str == ' ')
		str++;
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
	while (*str == ' ' || *str == '\t')
		str++;
	if (!*str || parse_vector(str, &scene->camera.pos))
		return (put_err(ERR_PARSE_CAM_POS), 1);
	while (ft_isdigit(*str) || *str == ',' || *str == '\t' || *str == ' '
			|| *str == '.' || *str == '-' || *str == '+')
		str++;
	if (!*str || parse_vector(str, &scene->camera.dir))
		return (put_err(ERR_PARSE_CAM_DIR), 1);
	while (ft_isdigit(*str) || *str == ',' || *str == '\t' || *str == ' '
			|| *str == '.' || *str == '-' || *str == '+')
	if (!*str || parse_double(str, &scene->camera.fov))
		return (put_err(ERR_PARSE_CAM_FOV), 1);
	while (ft_isdigit(*str) || *str == '\t' || *str == ' ' || *str == '.'
			|| *str == '-' || *str == '+')
		str++;
	if (*str)
		return (put_err(ERR_PARSE_CAM_UNKNOWN), 1);
	return (2);
}

int	parse_light(char *str, t_scene *scene, int count, t_byte cap)
{
	if (count >= 2 && cap)
		return (put_err(ERR_PARSE_COUNT_AMB), 1);
	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM)), 1;
	scene->lights = mem_realloc(scene->lights, count / 2 + 1);
	while (*str == ' ' || *str == '\t')
		str++;
	if (!*str || parse_vector(str, &scene->lights[count / 2].pos))
		return (put_err(ERR_PARSE_LIGHT_POS), 1);
	while (ft_isdigit(*str) || *str == ',' || *str == '\t' || *str == ' '
			|| *str == '.' || *str == '-' || *str == '+')
		str++;
	if (!*str || parse_double(str, &scene->lights[count / 2].ratio))
		return (put_err(ERR_PARSE_LIGHT_RATIO), 1);
	while (ft_isdigit(*str) || *str == '\t' || *str == ' ' || *str == '.'
			|| *str == '-' || *str == '+')
		str++;
	if (!cap && (!*str || parse_color(str, &scene->lights[count / 2].color)))
		return (put_err(ERR_PARSE_LIGHT_COLOR), 1);
	while (!cap && (ft_isdigit(*str) || *str == ',' || *str == '\t'
			|| *str == ' '))
		str++;
	if (*str)
		return (put_err(ERR_PARSE_LIGHT_UNKNOWN), 1);
	return (2);
}
