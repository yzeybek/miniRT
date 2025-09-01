/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:11:01 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/01 18:13:38 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_UTILS_H
# define MEM_UTILS_H

# include "mem_structs.h"

t_mem_block	*mem_add_new_block(void *data, size_t size);
void		mem_clear_block(t_mem_block **head);
size_t		mem_find_size(void *data);
void		*mem_error(void);

#endif // MEM_UTILS_H
