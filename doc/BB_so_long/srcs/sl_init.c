/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:59:21 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/28 01:25:03 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

/*  ***** FT_INIT_T_DATA so long *****
**  *************************
**  Initialises the reference structure that will run mlx, hold images and 
**	contain the structure for the game
*/
t_data	*ft_init_t_data_sl(char *file)
{
	t_data	*d_ref;

	d_ref = malloc(sizeof(t_data));
	if (d_ref == 0)
		ft_exit_sl(-1, ERRMSG_M0);
	d_ref->mlx = 0;
	d_ref->win = 0;
	d_ref->game = 0;
	d_ref->empty = 0;
	d_ref->wall = 0;
	d_ref->coll = 0;
	d_ref->exit = 0;
	d_ref->player = 0;
	ft_init_t_game_sl(d_ref, file);
	return (d_ref);
}

/*  ***** FT_INIT_T_GAME so long *****
**  *************************
**  Initialises the structure that will gather all necessary data for the game
*/
void	ft_init_t_game_sl(t_data *d_ref, char *file)
{
	d_ref->game = malloc(sizeof(t_game));
	if (d_ref->game == 0)
		ft_clean_game(d_ref, -1, ERRMSG_M0);
	d_ref->game->map = 0;
	d_ref->game->length = 0;
	d_ref->game->height = 0;
	d_ref->game->p_x = 0;
	d_ref->game->p_y = 0;
	d_ref->game->moves = 0;
	d_ref->game->ncoll = 0;
	ft_init_valid_map_sl(d_ref, file);
}

/*  ***** FT_INIT_VALID_MAP so long *****
**  *************************
**  Gets valid map by making several checkings (file existence, format...)
*/
void	ft_init_valid_map_sl(t_data *d_ref, char *file)
{
	char	**map;
	int		lines;
	int		len;

	if (!file)
		ft_clean_game(d_ref, -1, ERRMSG_F2);
	map = ft_get_map_sl(file);
	if (!map)
		ft_clean_game(d_ref, -1, NULL);
	lines = ft_lines_tabstr(map);
	len = ft_strlen_spechar(map[0], '\n');
	if (ft_check_map_format_sl(map, lines) == 0)
	{
		ft_free_tabstr(map, lines);
		ft_clean_game(d_ref, -1, NULL);
	}
	d_ref->game->map = map;
	d_ref->game->length = len;
	d_ref->game->height = lines;
	d_ref->game->p_x = ft_find_x_tabstr(map, len, lines, 'P');
	d_ref->game->p_y = ft_find_y_tabstr(map, len, lines, 'P');
	d_ref->game->ncoll = ft_count_char_sl(map, lines, 'C');
}

/*  ***** FT_INIT_WINMLX so long *****
**  *************************
**  Initialises functions to enable diplay & open a window
*/
int	ft_init_winmlx_sl(t_data *d_ref)
{
	if (!d_ref)
		return (ft_clean_game(d_ref, -1, ERRMSG_M1), 1);
	d_ref->mlx = mlx_init();
	if (d_ref->mlx == NULL)
		return (ft_clean_game(d_ref, -1, ERRMSG_G1), 1);
	d_ref->win = mlx_new_window(d_ref->mlx, d_ref->game->length * TILE, \
		d_ref->game->height * TILE, "so_long");
	if (d_ref->win == NULL)
		return (ft_clean_game(d_ref, -1, ERRMSG_G2), 1);
	return (0);
}

/*  ***** FT_INIT_IMG so long *****
**  *************************
**  Initialises images to be used for the game
*/
int	ft_init_img_sl(t_data *d_ref)
{
	d_ref->empty = mlx_xpm_file_to_image(d_ref->mlx, IMG_0, &d_ref->tile_x, \
		&d_ref->tile_y);
	if (d_ref->empty == 0)
		return (ft_clean_game(d_ref, -1, ERRMSG_G3), 1);
	d_ref->wall = mlx_xpm_file_to_image(d_ref->mlx, IMG_1, &d_ref->tile_x, \
		&d_ref->tile_y);
	if (d_ref->wall == 0)
		return (ft_clean_game(d_ref, -1, ERRMSG_G3), 1);
	d_ref->coll = mlx_xpm_file_to_image(d_ref->mlx, IMG_C, &d_ref->tile_x, \
		&d_ref->tile_y);
	if (d_ref->coll == 0)
		return (ft_clean_game(d_ref, -1, ERRMSG_G3), 1);
	d_ref->exit = mlx_xpm_file_to_image(d_ref->mlx, IMG_E, &d_ref->tile_x, \
		&d_ref->tile_y);
	if (d_ref->exit == 0)
		return (ft_clean_game(d_ref, -1, ERRMSG_G3), 1);
	d_ref->player = mlx_xpm_file_to_image(d_ref->mlx, IMG_P, &d_ref->tile_x, \
		&d_ref->tile_y);
	if (d_ref->player == 0)
		return (ft_clean_game(d_ref, -1, ERRMSG_G3), 1);
	return (0);
}
