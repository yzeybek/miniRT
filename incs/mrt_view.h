/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   mrt_view.h                                            :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/02 23:25:00 by yzeybek              #+#    #+#          */
/*   Updated: 2025/11/10 00:36:55 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_VIEW_H
# define MRT_VIEW_H

# define VIEW_WIDTH 1920
# define VIEW_HEIGHT 1080
# define VIEW_NAME "miniRT"

# define KEY_ESC 65307

typedef struct s_view_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		img_len;
	int		img_bpp;
	int		img_end;

}	t_view_data;

int	view_init(t_view_data *vd);
int	view_setup(t_view_data *vd);

#endif // MRT_VIEW_H
