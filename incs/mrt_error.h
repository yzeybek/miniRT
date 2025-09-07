/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   mrt_error.h                                         :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: yzeybek <yzeybek@student.42.com.tr>         +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:43:30 by yzeybek           #+#    #+#             */
/*   Updated: 2025/09/07 06:25:09 by yzeybek          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_ERROR_H
# define MRT_ERROR_H

# define ERR_ARG_COUNT "Invalid Argument Count\n"
# define ERR_ARG_NAME "Invalid Argument Name\n"
# define ERR_VIEW_INIT "Couldn't Initialized View\n"
# define ERR_VIEW_SETUP "Couldn't Setup View\n"
# define ERR_PARSE_ID "Found Unknown Identifier\n"
# define ERR_PARSE_COUNT_AMB "More Than One Ambient Detected\n"
# define ERR_PARSE_COUNT_CAM "More Than One Camera Detected\n"
# define ERR_PARSE_COUNT_LIGHT "More Than One Light Detected\n"
# define ERR_PARSE_NON_NUM "Non-numeric Character Detected\n"
# define ERR_PARSE_AMB_RATIO "Couldn't Parse Ambient Ratio\n"
# define ERR_PARSE_AMB_COLOR "Couldn't Parse Ambient Color\n"
# define ERR_PARSE_AMB_UNKNOWN "Unknown Format On Ambident\n"
# define ERR_PARSE_CAM_POS "Couldn't Parse Camera Position\n"
# define ERR_PARSE_CAM_DIR "Couldn't Parse Camera Direction\n"
# define ERR_PARSE_CAM_FOV "Couldn't Parse Camera FOV\n"
# define ERR_PARSE_CAM_UNKNOWN "Unknown Format On Camera\n"
# define ERR_PARSE_LIGHT_POS "Couldn't Parse Light Position\n"
# define ERR_PARSE_LIGHT_RATIO "Couldn't Parse Light Ratio\n"
# define ERR_PARSE_LIGHT_COLOR "Couldn't Parse Light Color\n"
# define ERR_PARSE_LIGHT_UNKNOWN "Unknown Format On Light\n"

int	put_err(char *msg);
int	check_arg(char *arg);

#endif // MRT_ERROR_H
