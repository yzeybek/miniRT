/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   print.c                                               :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/10/28 23:52:57 by yzeybek              #+#    #+#          */
/*   Updated: 2025/11/10 00:38:51 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mrt_debug.h"
#include "ansi_colors.h"

static void	print_shapes(t_scene *scene)
{
	int			i;
	const int	count = scene->ids[4] / 2 + scene->ids[5] / 2
		+ scene->ids[6] / 2 + scene->ids[7] / 2;

	i = -1;
	while (++i < count)
	{
		if (scene->shapes[i].obj_type == OBJ_SP)
			printf(
				"Sphere\n"
				);
		else if (scene->shapes[i].obj_type == OBJ_PL)
			printf(
				"Plane\n"
				);
		else if (scene->shapes[i].obj_type == OBJ_CY)
			printf(
				"Cylinder\n"
				);
		else if (scene->shapes[i].obj_type == OBJ_CN)
			printf(
				"Cone\n"
				);
	}
}

static void	print_lights(t_scene *scene)
{
	int			i;
	const int	count = scene->ids[2] / 2 + scene->ids[3] / 2;

	i = -1;
	while (++i < count)
		printf(
			"Light (%i)\n"
			"├── Capital: %u\n"
			"├── Position\n"
			"│   ├── X: %lf\n"
			"│   ├── Y: %lf\n"
			"│   └── Z: %lf\n"
			"├── Color\n"
			"│   ├── R: %u\n"
			"│   ├── G: %u\n"
			"│   └── B: %u\n"
			"└── Ratio: %lf\n",
			i, scene->lights[i].is_cap, scene->lights[i].pos.x,
			scene->lights[i].pos.y, scene->lights[i].pos.z,
			scene->lights[i].color.r, scene->lights[i].color.g,
			scene->lights[i].color.b, scene->lights[i].ratio);
}

void	print_scene(t_scene *scene)
{
	printf(ANSI_COLOR_CYAN
		"Camera\n"
		"├── Position\n"
		"│   ├── X: %lf\n"
		"│   ├── Y: %lf\n"
		"│   └── Z: %lf\n"
		"├── Direction\n"
		"│   ├── X: %lf\n"
		"│   ├── Y: %lf\n"
		"│   └── Z: %lf\n"
		"└── FOV: %lf\n"
		"Ambient\n"
		"├── Color\n"
		"│   ├── R: %u\n"
		"│   ├── G: %u\n"
		"│   └── B: %u\n"
		"└── Ratio: %lf\n",
		scene->camera.pos.x, scene->camera.pos.y, scene->camera.pos.z,
		scene->camera.dir.x, scene->camera.dir.y, scene->camera.dir.z,
		scene->camera.fov, scene->ambient.color.r, scene->ambient.color.g,
		scene->ambient.color.b, scene->ambient.ratio);
	print_lights(scene);
	print_shapes(scene);
	printf(ANSI_RESET);
}
