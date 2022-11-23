/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:22:54 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/23 17:33:58 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "../lib/mlx/mlx.h"

# include <errno.h>//	perror, errno
# include <fcntl.h>//	open, 
# include <stdio.h>//	printf, perror
# include <stdlib.h>//	malloc, free
# include <string.h>//	strerror
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>//	close, read, write, exit
# include <math.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define ER_NO_AG "missing argument\nUsage: ./cub3D <map_path>.cub"
# define ER_TOO_AG "too many arguments\nUsage: ./cub3D <map_path>.cub"
# define ER_MALLOC "memory allocation failed"
# define ER_MAP_EMPTY "no such file or empty file"
# define ER_MAP_EXT "incorrect file extension"
# define ER_MAP_ISDIR ": is a directory"


typedef struct s_img {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}			t_img;

// typedef struct s_map
// {
// 	/* data */
// } t_map;

/*	Parse	*/

int		ft_check_argc(int argc);

int		ft_check_file(char *file);
int		ft_check_filename(char *file, char *ext);
int		ft_check_isdirectory(char *file);
int		ft_count_lines_gnl(char *file);

int		ft_open_read(const char *file);

/*	Clean	*/

void	ft_quit(t_img *img);
int		key_hook(int keycode, t_img *img);
int		ft_err_msg(int res, char *msg1, char *msg2);

/*	Utils 	*/

int		ft_open_read(const char *file);

#endif
