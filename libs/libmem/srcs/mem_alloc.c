/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:14:06 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/01 18:48:35 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mem_utils.h"

void	*mem_malloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (!res)
		return (mem_error());
	mem_add_new_block(res, size);
	return (res);
}

void	*mem_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	void			*res;
	size_t			i;

	res = malloc(size * nmemb);
	if (!res)
		return (mem_error());
	ptr = res;
	i = -1;
	while (++i < size * nmemb)
		ptr[i] = '\0';
	mem_add_new_block(res, size * nmemb);
	return (res);
}

void	*mem_realloc(void *ptr, size_t size)
{
	size_t					i;
	void					*res;
	unsigned char			*new_ptr;
	size_t					old_size;
	unsigned char *const	old_ptr = ptr;

	res = malloc(size);
	if (!res)
		return (mem_error());
	i = -1;
	new_ptr = res;
	old_size = mem_find_size(ptr);
	while (++i < (old_size * (old_size < size)) + (size
			* (size < old_size)))
		new_ptr[i] = old_ptr[i];
	mem_add_new_block(res, size);
	return (res);
}
