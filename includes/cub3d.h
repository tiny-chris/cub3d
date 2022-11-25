/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:22:54 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/25 13:21:43 by cgaillag         ###   ########.fr       */
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
# define ER_MAP_EXT "incorrect file extension\nUsage: ./cub3D <map_path>.cub"
# define ER_MAP_ISDIR "is a directory"

/*	enum	*/

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_sizetype
{
	TAB_INT1		= 100,
	TAB_INT2		= 200,
	TAB_INTS		= 300,
	TAB_STR1		= 400,
	TAB_STR2		= 500,
	TAB_STRS		= 600,
}	t_sizetype;

typedef enum e_line_type
{
	L_TEXTURE	= 1000,
	L_COLOR		= 2000,
	L_MAP		= 3000,
	L_EMPTY		= 5000,
	L_UNEXPECT	= -1,
}	t_line_type;

typedef enum e_texture
{
	NO,
	WE,
	EA,
	SO,
}	t_texture;

/*	structure for parsing	*/

typedef struct s_line
{
	int				index;
	char			*content;
	t_line_type		ref;
	int				range;
	t_texture		texture;
	char			*text_path;
	char			color;
	int				*col_tab;
	struct s_line	*next;
}	t_line;

/*	structure for initial data - TO BE UPDATED*/
typedef struct s_base
{
	char	**file_base;
	char	**map_base;
	char	**elem_base;
	int		nblines_base;
	t_line	*list_base;
	int		index_start_map;
}	t_base;

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

int		ft_check_file_err(t_base *base);
int		ft_check_lines_order(t_base *base);

void	ft_get_file_base_detailed(t_base *base);
int		ft_check_map_err(char **map_base);
int		ft_check_elem_err(char **elem_base);

/*	line_list	*/

t_line	*ft_lstlast_line(t_line *lst);
void	ft_lstadd_line(t_line **line, int index, char *str, t_line_type ref);
// delone
// free


/*	Init */

void	ft_init_t_base_cub(char *file, t_base *base);
char	**ft_get_file_base(char	*file);

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
int		ft_strlen_spechar(const char *str, char spe_c);

#endif
