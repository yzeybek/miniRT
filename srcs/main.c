/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 22:46:12 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/02 23:40:59 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "mrt_view.h"
#include "mrt_error.h"

static int	miniRT_main(int argc, char **argv)
{
	t_view_data *const	vd = &(t_view_data){0};

	if (argc != 2)
		return (put_err(ERR_ARG_COUNT));
	if (check_arg(argv[1]))
		return (put_err(ERR_ARG_NAME));
	// Parsing
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

	res = miniRT_main(argc, argv);
	mem_clear();
	return (res);
}
