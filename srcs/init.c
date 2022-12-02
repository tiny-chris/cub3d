/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:20 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/02 19:16:21 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_get_rotation_angle(t_game *game)
{
	float	rotationAngle;

	rotationAngle = 0;
	if (game->p_direction == 'N')
		rotationAngle = M_PI / 2;
	else if (game->p_direction == 'S')
		rotationAngle = (3 * M_PI) / 2;
	else if (game->p_direction == 'E')
		rotationAngle = 2 * M_PI;
	else if (game->p_direction == 'W')
		rotationAngle = M_PI;
	return (rotationAngle);
}

void	ft_init_player(t_data *data)
{
	t_game	*game;

	game = data->base.game;
	data->player.x = game->p_x * TILE_SIZE;
	data->player.y = game->p_y * TILE_SIZE;
	data->player.width = 4;
	data->player.height = 4; // ne garder que width ?
	data->player.turnDirection = 0;
	data->player.walkDirection = 0;
	data->player.rotationAngle = ft_get_rotation_angle(game);
	//printf("\ndata->playerotationangle %f\n", data->player.rotationAngle);
	data->player.turnSpeed =  10 * (M_PI / 180); // 2 * (M_PI / 180) dans le js; 
	data->player.walkSpeed = 2.0;
}

void	ft_init_data(t_data *data)
{
	// init data mlx
	data->img.mlx_ptr = mlx_init();
	data->img.win_ptr = mlx_new_window(data->img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
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