/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:32:47 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/15 16:55:16 by cgaillag         ###   ########.fr       */
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
# define ER_FIL_BIG "file size is huge! Please consider a smaller size :)"
# define ER_ELE_ERR "Invalid element(s)"
# define ER_ELE_UNEX "is an unexpected line"
# define ER_ELE_MISS "Missing texture and/or color identifier(s)"
# define ER_ELE_TOO "Duplicate texture and/or color identifier(s)"
# define ER_PTH_MISS "Missing texture path(s)"
# define ER_PTH_DUP "Duplicate texture path(s)"
# define ER_TEX_NBR "Invalid number of textures before map (must be 4)"
# define ER_COL_NBR "Invalid number of colors before map (must be 2)"
# define ER_COL_FOR "Invalid format of colors"
# define ER_COL_VAL "Invalid color values"
# define ER_MAP_NONE "Missing game map"
# define ER_MAP_ERR "Invalid map"
# define ER_MAP_OPEN "Invalid map, not properly closed"
# define ER_MAP_UNEX "Invalid map, unauthorised character(s)"
# define ER_PLY_MISS "missing player (a unique spawn required)"
# define ER_PLY_TOO "more than one player (only one spawn allowed)"
# define ER_PLY_ZERO "player or floor '0' is surrounded by wrong character"

# define ER_MLX_INIT "initialisation failed"
# define ER_MLX_WIN "window creation failed"
# define ER_MLX_IMG "image creation failed"
# define ER_MLX_ADDR "address setup failed"
# define ER_TEX_IMG "open texture failed"
# define ER_TEX_SIZE "wrong texture size"

#endif
