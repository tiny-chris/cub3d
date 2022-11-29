/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:22:54 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/29 17:31:15 by lmelard          ###   ########.fr       */
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
# define COLOR_MAP_WALL 0x000000
# define COLOR_MAP_NOWALL 0xFFFFFF

# define TILE_SIZE 64

# define FOV_ANGLE (60 * (M_PI / 180))

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
	LST_LINE		= 700,
}	t_sizetype;

typedef enum s_flag
{
	ADD				= 1000,
	MALLOC			= 2000,
	DELONE			= 3000,
}	t_flag;

typedef enum e_line_type
{
	L_TEXTURE		= 10,
	L_COLOR			= 20,
	L_MAP			= 30,
	L_EMPTY			= 50,
	L_UNEXPECT		= -1,
}	t_line_type;

typedef enum e_texture
{
	NO,
	SO,
	WE,
	EA,
}	t_texture;

typedef struct s_bin {
	void			*ptr;
	int				type;
	int				size;
	struct s_bin	*next;
}	t_bin;

/*	structure for parsing	*/

typedef struct s_line {
	int				index;
	char			*content;
	t_line_type		ref;
	int				range;
	t_texture		texture;
	char			*text_path;
	char			color;
	int				*col_tab;
	struct s_line	*next;
}				t_line;

typedef struct s_img {
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
}					t_img;

typedef struct s_point {
	int				x;
	int				y;
}					t_point;

/*	Structure for initial data - TO BE UPDATED	*/

typedef struct s_game {
	int				**map;
	int				rows;//height;
	int				cols;//width;
	int				p_y;
	int				p_x;
	char			p_direction;
}	t_game;

/*	structure for initial data - TO BE UPDATED*/
typedef struct s_base
{
	char	**file_base;
	char	**map_base;
	t_line	*list_elem;
	int		nblines_base;
	t_line	*list_base;
	t_game	*game;
}	t_base;

typedef struct s_player {
	float			x;
	float			y;
	float			width; // radius ?
	float			height; // radius ?
	int				turnDirection; // -1 for left +1 for right
	int				walkDirection; // -1 for back +1 for front
	float			rotationAngle;
	float			turnSpeed;
	float			walkSpeed;
}				t_player;

typedef struct s_data {
	t_base			base;
	t_img			img;
	t_point			p1;
	t_point			p2;
	t_player		player;
}					t_data;

// typedef struct s_map
// {
// 	/* data */
// } t_map;

/*	Parse	*/

int			ft_check_arg_err(int argc, char *file);
int			ft_check_argc(int argc);
int			ft_check_filename(char *file, char *ext);
int			ft_check_isdirectory(char *file);
int			ft_count_lines_gnl(char *file);

int			ft_check_file_err(t_base *base);
int			ft_check_lines_order_err(t_base *base);

void		ft_get_file_base_detailed(t_base *base);
void		ft_get_texture(t_line **list_base);
void		ft_get_color(t_line **list_base);
t_line		*ft_get_elem_base(t_base *base);
char		**ft_get_map_base(t_base *base);
int			**ft_get_map_game_int(t_base *base);
int			ft_get_player_y(t_base *base);
int			ft_get_player_x(t_base *base, int i);

int			ft_check_elem_err(t_base *base);
int			ft_check_map_err(t_base *base);

int			ft_check_map_only_allowed_set(char **map, int lines, const char *set);
int			ft_check_map_global_struct(char **map, int lines);
int			ft_check_map_unique_player(char **map, int lines);
int			ft_check_map_enclosed_by_walls(char **map, int lines, int len);

/*	line_list	*/

t_line		*ft_lstlast_line(t_line *lst);
void		ft_lstadd_back_line(t_line **line, t_line *new);
void		ft_lstadd_line(t_line **line, int index, char *str, t_line_type ref);
void		ft_lstadd_elem(t_line **list_elem, t_line *line);
// delone
// free

/*	Init */

void		ft_init_t_base_cub(char *file, t_base *base);
void		ft_init_t_game(t_base *base);
void		ft_init_t_data_cub(char *file, t_base *data);
char		**ft_get_file_content(char	*file);
char		**ft_get_file_base(char	*file);

/*	Clean	*/

void		ft_quit(t_data *data);
int			ft_err_msg(int res, char *msg1, char *msg2);
void		*ft_malloc(int type, int size);

/*	Draw line	*/

void		ft_draw_vertical(t_data *data, t_point p1, t_point p2, int color);
void		ft_draw_horizontal(t_data *data, t_point p1, t_point p2, int color);
void		ft_draw_rect(t_data *data, t_point tile);
void		ft_render_map(t_data *data);
int			ft_render_next_frame(t_data *data);

/*	Utils 	*/

void		my_pixel_put(t_data *data, int x, int y, int color);
int			key_hook(int keycode, t_data *data);

int			ft_open_read(const char *file);
int			ft_strlen_spechar(const char *str, char spe_c);
int			ft_len_delspace_str(char *str);
int			ft_lines_tabstr(char **tab_str);
int			*ft_intdup(int *tab, int size);
int			ft_atoi_cub(char *str);
size_t		ft_is_in_set(const char *set, char c);
int			ft_count_isinset(char *str, char c);

#endif
