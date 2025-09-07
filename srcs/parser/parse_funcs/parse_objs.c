/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   parse_objs.c                                        :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: yzeybek <yzeybek@student.42.com.tr>         +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:15:03 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/07 06:36:03 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt_error.h"
#include "mrt_parser.h"

int	parse_plane(char *str, t_scene *scene)
{
	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM));
	(void)scene;
	return (2);
}

int	parse_sphere(char *str, t_scene *scene)
{
	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM));
	(void)scene;
	return (2);
}

int	parse_cylinder(char *str, t_scene *scene)
{
	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM));
	(void)scene;
	return (2);
}

int	parse_cone(char *str, t_scene *scene)
{
	if (check_numeric(str))
		return (put_err(ERR_PARSE_NON_NUM));
	(void)scene;
	return (2);
}
