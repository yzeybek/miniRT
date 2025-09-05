/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:36:07 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/05 13:54:07 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_IS
#include "libft.h"
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
	if (parse_double(str, &scene->ambient.ratio))
		return (put_err(ERR_PARSE_AMB_RATIO), 1);
	while (ft_isdigit(*str) || *str == '-' || *str == '+' || *str == '.')
		str++;
	while (*str == ' ' || *str == '\t')
		str++;
	if (parse_color(str, &scene->ambient.color))
		return (put_err(ERR_PARSE_AMB_COLOR), 1);
	while (ft_isdigit(*str) || *str == ',' || *str == '\t' || *str == ' ')
		str++;
	if (*str)
		return (put_er(ERR_PARSE_AMB_UNKNOWN), 1);
	return (2);
}

int	parse_camera(char *str, t_scene *scene, int count)
{
	if (count >= 2)
		return (put_err(ERR_PARSE_COUNT_AMB));
	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM));
	while (*str == ' ' || *str == '\t')
		str++;
	if (parse_vector(str, &scene->camera.pos))
		return (put_err(ERR_PARSE_CAM_VEC));
}

int	parse_light(char *str, t_scene *scene, int count)
{
	if (count >= 2)
		return (put_err(ERR_PARSE_COUNT_AMB));
	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM));
}
