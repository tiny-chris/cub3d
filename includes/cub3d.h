/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:22:54 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/22 11:14:31 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
// # include "mlx.h"
# include <errno.h>//	perror, errno
# include <fcntl.h>//	open, 
# include <stdio.h>//	printf, perror
# include <stdlib.h>//	malloc, free
# include <string.h>//	strerror
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>//	close, read, write, exit

# define ER_NO_AG "missing argument\nUsage: ./cub3D <map_path>.cub"
# define ER_TOO_AG "too many arguments\nUsage: ./cub3D <map_path>.cub"
# define ER_MALLOC "memory allocation failed"
# define ER_MAP_EMPTY "no such file or empty file"
# define ER_MAP_EXT "incorrect file extension"
# define ER_MAP_ISDIR ": is a directory"

// 
// typedef struct s_map
// {
// 	/* data */
// } t_map;

/*	parse	*/

int	ft_check_argc(int argc);

int	ft_check_file(char *file);
int	ft_check_filename(char *file, char *ext);
int	ft_check_isdirectory(char *file);
int	ft_count_lines_gnl(char *file);

int	ft_open_read(const char *file);

/*	clean */

int	ft_err_msg(int res, char *msg1, char *msg2);

/*	utils */

int	ft_open_read(const char *file);

#endif
