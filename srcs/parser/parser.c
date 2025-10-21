/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   parser.c                                              :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/05 00:44:39 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 14:26:26 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libmem.h"
#include "libgnl.h"
#define FT_IS
#define FT_STR
#include "libft.h"
#include "mrt_error.h"
#include "mrt_parser.h"

static int	is_empty(char *content)
{
	if (!content || !*content)
		return (1);
	while (*content)
	{
		if (!ft_isspace(*content))
			break ;
		content++;
	}
	if (!*content)
		return (1);
	return (0);
}

static int	has_odd(int *nums, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (nums[i] % 2)
			break ;
	if (i != len)
		return (1);
	return (0);
}

static int	parse_line(char *line, t_scene *scene)
{
	while (line && ft_isnone(*line))
		line++;
	if (*line == 'A' && ft_isnone(*(line + 1)))
		scene->ids[0] += parse_ambient(line + 1, scene, scene->ids[0]);
	else if (*line == 'C' && ft_isnone(*(line + 1)))
		scene->ids[1] += parse_camera(line + 1, scene, scene->ids[1]);
	else if (*line == 'L' && ft_isnone(*(line + 1)))
		scene->ids[2] += parse_light(line + 1, scene, scene->ids[2], 1);
	else if (*line == 'l' && ft_isnone(*(line + 1)))
		scene->ids[3] += parse_light(line + 1, scene, scene->ids[3], 0);
	else if (*line == 'p' && *(line + 1) == 'l' && ft_isnone(*(line + 2)))
		scene->ids[4] += parse_plane(line + 2, scene, scene->ids + 4);
	else if (*line == 's' && *(line + 1) == 'p' && ft_isnone(*(line + 2)))
		scene->ids[5] += parse_sphere(line + 2, scene, scene->ids + 4);
	else if (*line == 'c' && *(line + 1) == 'y' && ft_isnone(*(line + 2)))
		scene->ids[6] += parse_cylinder(line + 2, scene, scene->ids + 4);
	else if (*line == 'c' && *(line + 1) == 'n' && ft_isnone(*(line + 2)))
		scene->ids[7] += parse_cone(line + 2, scene, scene->ids + 4);
	else
		return (put_err(ERR_PARSE_ID));
	if (has_odd(scene->ids, ID_COUNT))
		return (1);
	return (0);
}

t_scene	*parse_scene(char *file)
{
	t_scene	*ret;
	int		fd;
	char	*content;
	char	**lines;

	ret = mem_calloc(sizeof(t_scene), 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	content = gnl_all(fd);
	if (is_empty(content))
		return (NULL);
	lines = ft_strsplit(content, '\n');
	while (lines && *lines)
	{
		while (is_empty(*lines))
			lines++;
		if (parse_line(*lines, ret))
			return (NULL);
		lines++;
	}
	return (ret);
}
