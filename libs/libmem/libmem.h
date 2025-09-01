/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:08:46 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/01 18:19:50 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMEM_H
# define LIBMEM_H

# include <stddef.h>

void	*mem_malloc(size_t size);
void	*mem_calloc(size_t nmemb, size_t size);
void	*mem_realloc(void *ptr, size_t size);

void	*mem_absorb(void *ptr);
void	mem_free(void *ptr);
void	mem_clear(void);
void	mem_exit(int status);


#endif // LIBMEM_H
