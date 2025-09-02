/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 23:22:53 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/02 23:58:46 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "mrt_view.h"
#include "mlx.h"

int	view_init(t_view_data *vd)
{
	vd->mlx = mem_absorb(mlx_init());
	if (!vd->mlx)
		return (1);
	vd->win = mlx_new_window(vd->mlx, VIEW_WIDTH, VIEW_HEIGHT, VIEW_NAME);
	if (!vd->win)
		return (1);
	vd->img = mlx_new_image(vd->mlx, VIEW_WIDTH, VIEW_HEIGHT);
	if (!vd->img)
		return (mlx_destroy_window(vd->img, vd->win), 1);
	vd->img_addr = mlx_get_data_addr(vd->img, &vd->img_bpp, &vd->img_len,
					&vd->img_end);
	if (!vd->img_addr)
		return (mlx_destroy_image(vd->mlx, vd->img),
				mlx_destroy_window(vd->mlx, vd->win), 1);
	return (0);
}

int	on_exit(t_view_data *vd)
{
	mlx_destroy_image(vd->mlx, vd->img);
	mlx_destroy_window(vd->mlx, vd->win);
	mlx_destroy_display(vd->mlx);
	mem_exit(0);
	return (0);
}

int	on_click(int key, t_view_data *vd)
{
	if (key == 65307)
		return (on_exit(vd));
	return (0);
}

int	view_setup(t_view_data *vd)
{
	mlx_put_image_to_window(vd->mlx, vd->win, vd->img, 0, 0);
	mlx_key_hook(vd->win, on_click, vd);
	mlx_hook(vd->win, 17, 0, on_exit, vd);
	mlx_loop(vd->mlx);
	return (0);
}
