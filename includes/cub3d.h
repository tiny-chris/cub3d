/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:22:54 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/24 12:56:13 by cgaillag         ###   ########.fr       */
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

/*	define	*/

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define COLOR_LOW 0x007733FF

# define ER_NO_AG "missing argument\nUsage: ./cub3D <map_path>.cub"
# define ER_TOO_AG "too many arguments\nUsage: ./cub3D <map_path>.cub"
# define ER_MALLOC "memory allocation failed"
# define ER_MAP_EMPTY "no such file or empty file"
# define ER_MAP_EXT "incorrect file extension"
# define ER_MAP_ISDIR ": is a directory"

/*	enum	*/

typedef enum s_sizetype
{
	TAB_INT1		= 100,
	TAB_INT2		= 200,
	TAB_INTS		= 300,
	TAB_STR1		= 400,
	TAB_STR2		= 500,
	TAB_STRS		= 600,
}	t_sizetype;

/*	structure	*/

/*	structure for parsing - TO BE UPDATED*/
typedef struct s_data
{
	char	**file_content;
	char	**map_base;
	char	**elem_base;
}	t_data;

typedef struct s_img {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}			t_img;

typedef struct s_point {
	int		x;
	int		y;
}			t_point;

// typedef struct s_map
// {
// 	/* data */
// } t_map;

/*	Parse	*/

int		ft_check_arg_err(int argc, char *file);
int		ft_check_argc(int argc);
int		ft_check_filename(char *file, char *ext);
int		ft_check_isdirectory(char *file);
int		ft_count_lines_gnl(char *file);

int		ft_check_file_err(t_data *data);
int		ft_check_nb_lines(t_data *data);
int		ft_check_lines_order(t_data *data);
void	ft_get_file_content_detailed(t_data *data);
int		ft_check_map_err(char **map_base);
int		ft_check_elem_err(char **elem_base);

/*	Init */

void	ft_init_t_data_cub(char *file, t_data *data);
char	**ft_get_file_content(char	*file);

/*	Clean	*/

void	ft_quit(t_img *img);
int		ft_err_msg(int res, char *msg1, char *msg2);
void	*ft_malloc(int type, int size);

/*	Draw line	*/

void	ft_draw_vertical(t_point *p1, t_point *p2, t_img *img);

/*	Utils 	*/

int		ft_open_read(const char *file);
void	my_pixel_put(t_img *img, int x, int y, int color);
int		key_hook(int keycode, t_img *img);

#endif
