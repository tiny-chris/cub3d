/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:32:47 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/14 15:14:39 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define USAGE_CUB "\nUsage: ./cub3D <map_path>.cub"
# define USAGE_XPM "\nUsage: ./cub3D <texture_path>.xpm"
# define USAGE_COL "\nUsage (RGB): < n1,n2,n3 > with 'n#' between 0 and 255"
# define ER_ARG_MISS "Missing argument"
# define ER_ARG_TOO "Too many arguments"
# define ER_MEM_ALLOC "Memory allocation failed"
# define ER_FOD_INEX "no such file or directory"
# define ER_FIL_OPEN "Cannot open file"
# define ER_FIL_EMPTY "is an empty file"
# define ER_FIL_EXT "has an incorrect file extension"
# define ER_FIL_ISDIR "is a directory"
# define ER_ELE_UNEX "is an unexpected line"
# define ER_ELE_MISS "Missing textures and/or colors"
# define ER_ELE_TOO "Duplicate textures and/or colors"
# define ER_TEX_NBR "Invalid number of textures (must be 4)"
# define ER_COL_NBR "Invalid number of colors (must be 2)"
# define ER_COL_FOR "Invalid format of colors"
# define ER_COL_VAL "Invalid color values"
# define ER_MAP_NONE "Missing game map"
# define ER_MAP_ERR "Invalid map"
# define ER_MAP_OPEN "Invalid map, not properly closed"
# define ER_MAP_UNEX "Invalid map, unauthorised character(s)"
# define ER_PLY_MISS "missing player (no spawn on the map)"
# define ER_PLY_TOO "more than one player (only one spawn allowed)"
# define ER_PLY_ZERO "player or floor '0' is surrounded by wrong character"

# define ER_MLX_INIT "initialisation failed"
# define ER_MLX_WIN "window creation failed"
# define ER_MLX_IMG "image creation failed"
# define ER_MLX_ADDR "address setup failed"
# define ER_TEX_IMG "open texture failed"
# define ER_TEX_SIZE "wrong texture size: only !! XXxXX !! size is allowed"// à ajuster !!

// # define E_MAP_BIG_MSG "the map is immense"
// # define E_MLX_FAILURE_MSG "mlx failed"
// # define E_MLX_XPM_FAILURE_MSG "mlx xpm image loading failed (check files)"

#endif
