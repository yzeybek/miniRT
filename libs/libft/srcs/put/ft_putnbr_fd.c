/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:28:08 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/01 19:44:23 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_put.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	temp;

	ln = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	if (ln >= 10)
	{
		ft_putnbr_fd(ln / 10, fd);
		temp = ln % 10 + '0';
		write(fd, &temp, 1);
	}
	else
	{
		temp = ln + '0';
		write(fd, &temp, 1);
	}
}
