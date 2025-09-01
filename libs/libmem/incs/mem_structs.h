/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:11:37 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/01 18:13:11 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_STRUCTS_H
# define MEM_STRUCTS_H

# include <stddef.h>

typedef struct s_mem_block
{
	void				*data;
	size_t				size;
	struct s_mem_block	**head;
	struct s_mem_block	*next;

}	t_mem_block;

#endif // MEM_STRUCTS_H
