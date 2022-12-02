/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:58:11 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/02 19:37:55 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_t_game_0(t_base *base)
{
	t_game	*game;

	game = ft_magic_malloc(MALLOC + LST_GAME, NULL, 1);
	game->map = NULL;
	game->rows = -1;
	game->cols = -1;
	game->p_y = -1;
	game->p_x = -1;
	game->p_direction = '\0';
	base->game = game;
}

static void	ft_init_t_base_cub_0(t_base *base)
{
	base->file_base = NULL;
	base->map_base = NULL;
	base->list_elem = NULL;
	base->nblines_base = -1;
	base->list_base = NULL;
	ft_init_t_game_0(base);
}

static void	ft_init_list_base(t_base *b, t_line_type ref)
{
	int			i;
	int			j;

	i = 0;
	while (b->file_base[i])
	{
		j = 0;
		while (b->file_base[i][j] == ' ')
			j++;
		if (b->file_base[i][j] == '\0' || b->file_base[i][j] == '\n')
			ref = L_EMPTY;
		else if ((b->file_base[i][j] == 'N' && b->file_base[i][j + 1] == 'O')
		|| (b->file_base[i][j] == 'S' && b->file_base[i][j + 1] == 'O')
		|| (b->file_base[i][j] == 'W' && b->file_base[i][j + 1] == 'E')
		|| (b->file_base[i][j] == 'E' && b->file_base[i][j + 1] == 'A'))
			ref = L_TEXTURE;
		else if (b->file_base[i][j] == 'F' || b->file_base[i][j] == 'C')
			ref = L_COLOR;
		else if (b->file_base[i][j] == '1')
			ref = L_MAP;
		ft_lstadd_line(&(b->list_base), i, b->file_base[i], ref);
		ref = L_UNEXPECT;
		i++;
	}
}

/*  ***** Initialisation - base structure *****
**  *************************
**  <SUMMARY>	Initialise the reference structure that will:
**				-
**				- ...
**				(run mlx, hold images and contain the structure for the game)
*/
void	ft_init_t_base_cub(char *file, t_base *base)
{
	int	i;
	int	val_exit;

	i = 0;
	ft_init_t_base_cub_0(base);
	base->file_base = ft_get_file_base(file);
	if (!base->file_base)
	{
		val_exit = ft_err_msg_1(1, "TBD 2", NULL, "a revoir");
		exit(ft_clean_base(val_exit));
	}
	while (base->file_base[i])
		i++;
	base->nblines_base = i;
	ft_init_list_base(base, L_UNEXPECT);
}

void	ft_init_t_game(t_base *base)
{
	t_game	*game;

	game = base->game;
	game->rows = ft_lines_tabstr(base->map_base);
	game->cols = ft_strlen_spechar(base->map_base[0], '\n');
	game->map = ft_get_map_game_int(base);
	game->p_y = ft_get_player_y(base);
	game->p_x = ft_get_player_x(base, game->p_y);
	game->p_direction = base->map_base[game->p_y][game->p_x];
}
