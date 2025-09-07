/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   main.c                                              :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: yzeybek <yzeybek@student.42.com.tr>         +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 22:46:12 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/07 22:19:49 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "mrt_view.h"
#include "mrt_error.h"
#include "mrt_parser.h"

static int	minirt_main(int argc, char **argv)
{
	t_view_data *const	vd = &(t_view_data){0};
	t_scene				*scene;

	if (argc != 2)
		return (put_err(ERR_ARG_COUNT));
	if (check_arg(argv[1]))
		return (put_err(ERR_ARG_NAME));
	scene = parse_scene(argv[1]);
	if (!scene)
		return (1);
	if (view_init(vd))
		return (put_err(ERR_VIEW_INIT));
	// Rendering
	if (view_setup(vd))
		return (put_err(ERR_VIEW_SETUP));
	return (0);
}

int	main(int argc, char **argv)
{
	int	res;

	res = minirt_main(argc, argv);
	mem_clear();
	return (res);
}
