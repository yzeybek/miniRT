/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   main.c                                                :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/10/21 12:41:39 by yzeybek              #+#    #+#          */
/*   Updated: 2025/11/10 00:23:56 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "mrt_render.h"
#include "mrt_error.h"
#include "mrt_debug.h"
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
	if (DEBUG)
		print_scene(scene);
	if (render_scene(scene, vd))
		return (put_err(ERR_RENDER));
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
