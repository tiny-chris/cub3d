/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:25:02 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/28 01:22:55 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h> 
# include <X11/keysym.h>
# include <X11/X.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define TILE 32

# define IMG_0 "./img/img_Empty.xpm"
# define IMG_1 "./img/img_Wall.xpm"
# define IMG_C "./img/img_Collect.xpm"
# define IMG_E "./img/img_Exit.xpm"
# define IMG_P "./img/img_Player.xpm"

# define SUCMSG_WD "Well done!"
# define SUCMSG_ES "You just decide to end the game."
# define ERRMSG_F1 "File error: no argument or too many arguments"
# define ERRMSG_F2 "File error: no file, empty file or incorrect extension"
# define ERRMSG_M0 "Memory allocatin failure"
# define ERRMSG_M1 "No map or memory allocation failure"
# define ERRMSG_M2 "Invalid map: the map is not rectangular"
# define ERRMSG_M3 "Invalid map: there is not a unique player"
# define ERRMSG_M4 "Invalid map: there is no exit or no collectible"
# define ERRMSG_M5 "Invalid map: there is at least 1 unauthorized character"
# define ERRMSG_M6 "Invalid map: the map is not closed/surrounded by walls"
# define ERRMSG_G1 "Connection can not be established to the graphical system"
# define ERRMSG_G2 "Graphical window can not be created"
# define ERRMSG_G3 "Some images can not be loaded"

/******************************* STRUCTURE ************************************/

/*	***** Structure to gather all necessary elements for a specific map *****
** 	Game map content:
**		> map_init: initial map from file '.ber' with potential empty lines
**		> map: cleaned map from map_init without potential empty lines
**		> p_x = coordinate of x for player position (same for y)
*/
typedef struct s_game
{
	char	**map;
	int		length;
	int		height;
	int		p_x;
	int		p_y;
	int		moves;
	int		ncoll;
}	t_game;

/*	***** Monitoring structure for using mlx *****
** 	Data content:
** 		> mlx (ex mlx_ptr): connection identifier to the graphical server
** 		> win (ex win_ptr): window identifier on the created window 
*/
typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_game	*game;
	void	*empty;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*player;
	int		tile_x;
	int		tile_y;
}	t_data;

/****************************************************************************/

/*	***** GENERIC FUNCTIONS ***** */

int		ft_check_filename(char *file_name, char *ext);

/*	***** SO_LONG FUNCTIONS ***** */

int		ft_check_map_format_sl(char **map, int lines);
int		ft_count_char_sl(char **map, int lines, char c);
int		ft_count_lines_gnl(char *file);
char	**ft_get_map_sl(char *file);
t_game	*ft_create_t_game_sl(char *file);

int		ft_check_rect_len_sl(char **map);
int		ft_count_char_sl(char **map, int lines, char c);
int		ft_check_allw_char_sl(char **map, int lines, const char *set);
int		ft_is_wall_sl(char **map, int lines, char axis, int i);
int		ft_check_walls_sl(char **map, int lines);

t_data	*ft_init_t_data_sl(char *file);
void	ft_init_t_game_sl(t_data *d_ref, char *file);
void	ft_init_valid_map_sl(t_data *d_ref, char *file);
int		ft_init_winmlx_sl(t_data *d_ref);
int		ft_init_img_sl(t_data *d_ref);
int		ft_find_x_tabstr(char **map, int len_lines, int lines, char c);
int		ft_find_y_tabstr(char **map, int len_lines, int lines, char c);

void	ft_move_up(t_data *d_ref);
void	ft_move_down(t_data *d_ref);
void	ft_move_left(t_data *d_ref);
void	ft_move_right(t_data *d_ref);

int		ft_key_press_sl(int keycode, t_data *d_ref);
int		ft_destroy_hook_sl(t_data *d_ref);

int		ft_draw_map_sl(t_data *d_ref);
void	ft_display_nmoves(t_data *d_ref);

void	ft_clean_game(t_data *d_ref, int res, char *res_msg);
void	ft_free_game(t_game *game);
void	ft_exit_sl(int res, char *res_msg);
void	ft_error_msg_sl(char *res_msg);

#endif
