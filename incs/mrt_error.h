/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:43:30 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/05 10:09:39 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_ERROR_H
# define MRT_ERROR_H

# define ERR_ARG_COUNT "Invalid Argument Count\n"
# define ERR_ARG_NAME "Invalid Argument Name\n"
# define ERR_VIEW_INIT "Couldn't Initialized View\n"
# define ERR_VIEW_SETUP "Couldn't Setup View\n"
# define ERR_PARSE_ID "Found Unknown Identifier\n"

int	put_err(char *msg);
int	check_arg(char *arg);

#endif // MRT_ERROR_H
