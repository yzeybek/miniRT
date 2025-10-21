/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_striteri.c                                         :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/15 18:15:22 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:50:46 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
