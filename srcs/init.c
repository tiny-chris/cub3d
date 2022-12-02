/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:20 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/02 19:39:05 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_get_rotation_angle(t_game *game)
{
	float	rotation_angle;

	rotation_angle = 0;
	if (game->p_direction == 'N')
		rotation_angle = M_PI / 2;
	else if (game->p_direction == 'S')
		rotation_angle = (3 * M_PI) / 2;
	else if (game->p_direction == 'E')
		rotation_angle = 2 * M_PI;
	else if (game->p_direction == 'W')
		rotation_angle = M_PI;
	return (rotation_angle);
}

void	ft_init_player(t_data *data)
{
	t_game	*game;

	game = data->base.game;
	data->player.x = game->p_x * TILE_SIZE;
	data->player.y = game->p_y * TILE_SIZE;
	data->player.width = 4;
	data->player.height = 4; // ne garder que width ?
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.rotation_angle = ft_get_rotation_angle(game);
	printf("\ndata->playerotationangle %f\n", data->player.rotation_angle);
	data->player.turn_speed =  10 * (M_PI / 180); // 2 * (M_PI / 180) dans le js; 
	data->player.walk_speed = 2.0;
}

void	ft_init_data(t_data *data)
{
	// init data mlx
	data->img.mlx_ptr = mlx_init();
	// if (data->img.mlx_ptr == NULL)
	// 	ft_clean_game(data);//ajouter le nettoyage mlx
	data->img.win_ptr = mlx_new_window(data->img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	// if (data->img.win_ptr == NULL)
	// 	ft_clean_game(data);//ajouter le nettoyage mlx
	data->img.img = mlx_new_image(data->img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img)
		return ; // On free ?
	data->img.addr = mlx_get_data_addr(data->img.img, &(data->img.bits_per_pixel), \
				&(data->img.line_lenght), &(data->img.endian));
	if (!data->img.addr)
		return ; // On free ?
	// init player
	ft_init_player(data);
}