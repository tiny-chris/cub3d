/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:11:40 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/21 20:06:00 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*  ***** DRAW MAP using mlx *****
**  *************************
**  Draw the map by using mlx for the only 5 allowed characters:
**		0 for an empty space,
**		1 for a wall,
**		C for a collectible,
**		E for a map exit,
**		P for the player’s starting position
**  *************************
*/
static void	ft_draw_map2_sl(t_data *d_ref, void *img, int i, int j)
{
	mlx_put_image_to_window(d_ref->mlx, d_ref->win, img, j * TILE, i * TILE);
}

int	ft_draw_map_sl(t_data *d_ref)
{
	int	i;
	int	j;

	i = 0;
	while (i < d_ref->game->height)
	{
		j = 0;
		while (j < d_ref->game->length)
		{
			if (d_ref->game->map[i][j] == '1')
				ft_draw_map2_sl(d_ref, d_ref->wall, i, j);
			else if (d_ref->game->map[i][j] == '0')
				ft_draw_map2_sl(d_ref, d_ref->empty, i, j);
			else if (d_ref->game->map[i][j] == 'C')
				ft_draw_map2_sl(d_ref, d_ref->coll, i, j);
			else if (d_ref->game->map[i][j] == 'E')
				ft_draw_map2_sl(d_ref, d_ref->exit, i, j);
			else if (d_ref->game->map[i][j] == 'P')
				ft_draw_map2_sl(d_ref, d_ref->player, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
