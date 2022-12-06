/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:22:54 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/06 18:16:49 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/keysym.h> // a supprimer

# include <errno.h>	//	perror, errno
# include <fcntl.h>	//	open,
# include <stdio.h>	//	printf, perror
# include <stdlib.h>//	malloc, free
# include <string.h>//	strerror
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>//	close, read, write, exit
# include <math.h>
# include <limits.h>

/*	define	*/

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# define DIR_LEN 20

# define WIN_WIDTH 1800
# define WIN_HEIGHT 1600

# define COLOR_LOW 0x007733FF
# define COLOR_BLACK 0x000000
# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED 0xFF0000
# define COLOR_BLUE 0x0000FF

# define TILE_SIZE 32

# define FOV_ANGLE (60 * (M_PI / 180))

# define USAGE_CUB "\nUsage: ./cub3D <map_path>.cub"
# define ER_NO_AG "Missing argument"
# define ER_TOO_AG "Too many arguments"
# define ER_MALLOC "Memory allocation failed"
# define ER_MAP_EMPTY "No such file or empty file"
# define ER_MAP_EXT "has an incorrect file extension"
# define ER_MAP_ISDIR "is a directory"

/*	enum	*/

typedef enum e_keycode
{
	KEY_ESC				= 65307,
	KEY_MOVING_UP		= 119, //87,
	KEY_MOVING_DOWN		= 115,
	KEY_MOVING_LEFT		= 97,
	KEY_MOVING_RIGHT	= 100,
	KEY_CAMERA_LEFT		= 65361,
	KEY_CAMERA_RIGHT	= 65363,
}	t_keycode;

typedef enum e_bool
{
	TRUE,
	FALSE,
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
	LST_GAME		= 800,
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
}	t_line;

typedef struct s_img {
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
}	t_img;

typedef struct s_point {
	float			x;
	float			y;
}	t_point;

/*	Structure for initial data - TO BE UPDATED	*/

typedef struct s_game {
	int				**map;
	int				rows; //height;
	int				cols; //width;
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
	t_point			p;
	float			width;			// radius ?
	float			height;			// radius ?
	int				turn_direction;	// -1 for looking left +1 for looking right
	int				walk_direction;	// -1 for back +1 for front
	int				side_direction; // -1 for left +1 for right
	float			rotation_angle;
	float			turn_speed;
	float			walk_speed;
}	t_player;

typedef	struct s_hit {
	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;
	int		found_wall_hit;
	float	next_touch_x;
	float	next_touch_y;
	float	x_to_check;
	float	y_to_check;
	float	hit_distance;
	t_point	wall_hit;
}	t_hit;


typedef struct	s_ray {
	float			ray_angle;
	// float			wall_hit_x;
	// float			wall_hit_y;
	t_point			wall_hit;
	float			distance;
	int				wall_hit_vertical;
	int				is_ray_facing_up;
	int				is_ray_facing_down;
	int				is_ray_facing_left;
	int				is_ray_facing_right;
//	int				wall_hit_content;
}	t_ray;

typedef struct s_data {
	t_base			base;
	int				nbr_rays; // a calculer = WIN_WIDTH
	t_ray			rays[WIN_WIDTH];
	t_img			img;
	t_point			p1; //
	t_point			p2; //
	t_player		player;
}	t_data;

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
void		ft_lstdelone_line(t_line *node);
// free

/*	game_list*/

/*	Init parser */

void		ft_init_t_base_cub(char *file, t_base *base);
void		ft_init_t_game(t_base *base);
void		ft_init_t_data_cub(char *file, t_base *data);
char		**ft_get_file_content(char	*file);
char		**ft_get_file_base(char	*file);

/*	Init	*/

void		ft_init_player(t_data *data);
void		ft_init_data(t_data *data);
float		ft_get_rotation_angle(t_game *game);

/*	Clean	*/

void		ft_quit(t_data *data);
int			ft_clean_base(int res);
void		ft_clean_cub(t_data *data, int res);
int			ft_err_msg_1(int res, char *msg1, char *msg2, char *msg3);
int			ft_err_msg_2(int res, int i, char *msg1, char *msg2);
void		ft_close_fd(void);

// void		*ft_free_tabint(int **tab_int, int size);
void		*ft_free_tabint2(int **tab_int, int size, int type);
// void		*ft_free_tabint_bin(int **tab_int, int size, int type);
void		ft_free_strs(char *str1, char *str2, char *str3);
void		ft_free_ints(int *t_int1, int *t_int2, int *t_int3);
// void		*ft_free_tabstr(char **tab_str);
void		*ft_free_tabstr2(char **tab_str, int type);
// void		*ft_free_tabstr_bin(char **tab_str, int type);

/*	Handle malloc*/

void		*ft_malloc(int type, int size);
void		*ft_magic_malloc(int flag_type, void *ptr, int size);
int			ft_lstadd_bin(t_bin **bin_head, void *ptr, int type, int size);
void		ft_free_ptr_type(void *ptr, int type, int size);
void		ft_lstdelone_bin(t_bin *node);
void		ft_lstclearone_bin(t_bin **bin_head, void *ptr);
void		ft_free_bin(t_bin **bin_head);

/*	Draw line	*/

float		ft_abs(float nbr);
void		ft_draw_line(t_data *data, t_point p1, t_point p2, int color);
void		ft_draw_vertical(t_data *data, t_point p1, t_point p2, int color);
void		ft_draw_horizontal(t_data *data, t_point p1, t_point p2, int color);
void		ft_big_slope(t_data *data, t_point p1, t_point p2, int color, float m);
void		ft_small_slope(t_data *data, t_point p1, t_point p2, int color, float m);

/*	Render map	*/

void		ft_draw_rect(t_data *data, t_point tile, int color, int size);
void		ft_render_map(t_data *data);
int			ft_render_next_frame(t_data *data);

/*	Render player	*/

void		ft_render_player(t_data *data);
void		ft_update_player(t_data *d);
t_bool		ft_check_wall(t_data *data, float x, float y);

/*	Utils 	*/

void		my_pixel_put(t_data *data, int x, int y, int color);
int			ft_key_hook(int keycode, t_data *data);
int			ft_key_release(int keycode, t_data *data);

int			ft_open_read(const char *file);
int			ft_strlen_spechar(const char *str, char spe_c);
int			ft_len_delspace_str(char *str);
int			ft_lines_tabstr(char **tab_str);
int			*ft_intdup(int *tab, int size);
int			ft_atoi_cub(char *str);
size_t		ft_is_in_set(const char *set, char c);
int			ft_count_isinset(char *str, char c);

/*	Cast Rays	*/

void	ft_cast_all_rays(t_data *data);
void	ft_cast_ray(t_data *data, float ray_angle, int strip_id);
void	ft_fill_ray(t_data *data, int strip_id, t_hit horz, t_hit vert);
float	ft_distance_btw_points(t_player player, t_point wall_hit);
void	ft_init_horz_vert(t_hit *horz);
void	ft_check_vert_intersection(t_data *data, float ray_angle, int strip_id, t_hit *vert);
void	ft_check_horz_intersection(t_data *data, float ray_angle, int strip_id, t_hit *horz);
float	ft_normalize_angle(float ray_angle);
void	ft_ray_orientation(t_data *data, float ray_angle, int strip_id);

#endif
