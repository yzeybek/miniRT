/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   parse_utils.c                                       :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: yzeybek <yzeybek@student.42.com.tr>         +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:25:22 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/07 06:32:59 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INT
#define FT_IS
#define FT_STR
#include "libft.h"
#include "mrt_parser.h"

int	check_numeric(char *str)
{
	if (!str || !*str)
		return (1);
	while (*str)
	{
		if (!(ft_isdigit(*str) || *str == ' ' || *str == '\t' || *str == '-'
				|| *str == '+' || *str == '.' || *str == ','))
			break ;
		str++;
	}
	if (*str)
		return (1);
	return (0);
}

int	parse_double(char *str, double *ret)
{
	int		sign;
	double	frac;
	double	div;

	*ret = 0.0;
	frac = 0.0;
	div = 1.0;
	sign = (-1 * ((*str) == '-')) + ((*str) != '+');
	str += *str == '+' || *str == '-';
	if (!*str || !ft_isdigit(*str))
		return (1);
	str--;
	while (++str && *str && ft_isdigit(*str))
		*ret = *ret * 10.0 + (double)(*str - '0');
	if (*str == '.')
	{
		if (!ft_isdigit(*(str + 1)))
			return (1);
		while (++str && *str && ft_isdigit(*str))
		{
			frac = frac * 10.0 + (double)(*str - '0');
			div *= 10.0;
		}
	}
	return (*ret = sign * (*ret + frac / div));
}

int	parse_vector(char *str, t_vector *ret)
{
	if (parse_double(str, &ret->x))
		return (1);
	while (ft_isdigit(*str) || *str == '-' || *str == '+')
		str++;
	if (*str++ != ',')
		return (1);
	if (parse_double(str, &ret->y))
		return (1);
	while (ft_isdigit(*str) || *str == '-' || *str == '+')
		str++;
	if (*str++ != ',')
		return (1);
	if (parse_double(str, &ret->z))
		return (1);
	return (0);
}

int	parse_color(char *str, t_color *ret)
{
	ret->r = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str != ',')
		return (1);
	str++;
	ret->g = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str != ',')
		return (1);
	str++;
	ret->b = ft_atoi(str);
	return (0);
}
