/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   mrt_error.h                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yzeybek <yzeybek@student.42istanbul.com.tr>   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/02 19:43:30 by yzeybek              #+#    #+#          */
/*   Updated: 2025/11/10 00:24:36 by yzeybek             ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_ERROR_H
# define MRT_ERROR_H

# define ERR_ARG_COUNT "Invalid Argument Count\n"
# define ERR_ARG_NAME "Invalid Argument Name\n"
# define ERR_VIEW_INIT "Couldn't Initialized View\n"
# define ERR_RENDER "Problem Occured During Render\n"
# define ERR_VIEW_SETUP "Couldn't Setup View\n"
# define ERR_PARSE_OPEN "Couldn't Open The File\n"
# define ERR_PARSE_EMPTY "File Content Is Empty\n"
# define ERR_PARSE_ID "Found Unknown Identifier\n"
# define ERR_PARSE_COUNT_AMB "More Than One Ambient Detected\n"
# define ERR_PARSE_COUNT_CAM "More Than One Camera Detected\n"
# define ERR_PARSE_COUNT_LIGHT "More Than One Light Detected\n"
# define ERR_PARSE_NON_NUM "Non-numeric Character Detected\n"
# define ERR_PARSE_AMB_MISS "Ambient Lightning Is Missing\n"
# define ERR_PARSE_AMB_RATIO "Couldn't Parse Ambient Ratio\n"
# define ERR_PARSE_AMB_COLOR "Couldn't Parse Ambient Color\n"
# define ERR_PARSE_AMB_UNKNOWN "Unknown Format On Ambident\n"
# define ERR_PARSE_CAM_MISS "Camera Is Missing\n"
# define ERR_PARSE_CAM_POS "Couldn't Parse Camera Position\n"
# define ERR_PARSE_CAM_DIR "Couldn't Parse Camera Direction\n"
# define ERR_PARSE_CAM_FOV "Couldn't Parse Camera FOV\n"
# define ERR_PARSE_CAM_UNKNOWN "Unknown Format On Camera\n"
# define ERR_PARSE_LIGHT_MISS "Lightning Is Missing\n"
# define ERR_PARSE_LIGHT_POS "Couldn't Parse Light Position\n"
# define ERR_PARSE_LIGHT_RATIO "Couldn't Parse Light Ratio\n"
# define ERR_PARSE_LIGHT_COLOR "Couldn't Parse Light Color\n"
# define ERR_PARSE_LIGHT_UNKNOWN "Unknown Format On Light\n"
# define ERR_PARSE_SHP_MISS "Any Kind Of Shape Is Missing\n"
# define ERR_PARSE_PL_POS "Couldn't Parse Plane Position\n"
# define ERR_PARSE_PL_DIR "Couldn't Parse Plane Direction\n"
# define ERR_PARSE_PL_COLOR "Couldn't Parse Plane Color\n"
# define ERR_PARSE_PL_UNKNOWN "Unkown Format On Plane\n"
# define ERR_PARSE_SP_POS "Couldn't Parse Sphere Position\n"
# define ERR_PARSE_SP_DIA "Couldn't Parse Sphere Diameter\n"
# define ERR_PARSE_SP_COLOR "Couldn't Parse Sphere color\n"
# define ERR_PARSE_SP_UNKNOWN "Unknown Format On Sphere\n"
# define ERR_PARSE_CY_POS "Couldn't Parse Cylinder Position\n"
# define ERR_PARSE_CY_DIR "Couldn't Parse Cylinder Direction\n"
# define ERR_PARSE_CY_DIA "Couldn't Parse Cylinder Diameter\n"
# define ERR_PARSE_CY_HEIGHT "Couldn't Parse Cylinder Height\n"
# define ERR_PARSE_CY_COLOR "Couldn't Parse Cylinder Color\n"
# define ERR_PARSE_CY_UNKNOWN "Unknown Format On Cylinder\n"
# define ERR_PARSE_CN_POS "Couldn't Parse Cone Position\n"
# define ERR_PARSE_CN_DIR "Couldn't Parse Cone Direction\n"
# define ERR_PARSE_CN_DIA "Couldn't Parse Cone Diameter\n"
# define ERR_PARSE_CN_HEIGHT "Couldn't Parse Cone Height\n"
# define ERR_PARSE_CN_COLOR "Couldn't Parse Cone Color\n"
# define ERR_PARSE_CN_UNKNOWN "Unknown Format On Cone\n"

int	put_err(char *msg);
int	check_arg(char *arg);

#endif // MRT_ERROR_H
