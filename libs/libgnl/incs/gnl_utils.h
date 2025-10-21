/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   gnl_utils.h                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/07/05 21:02:50 by yzeybek              #+#    #+#          */
/*   Updated: 2025/10/21 12:51:52 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_UTILS_H
# define GNL_UTILS_H

# include <stddef.h>

char	*gnl_find_newline(char *str);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(char *str);
size_t	gnl_strlcpy(char *dst, char *src, size_t dstsize);
char	*gnl_strdup(char *str);

#endif // GNL_UTILS_H
