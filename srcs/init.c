/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:20 by lmelard           #+#    #+#             */
/*   Updated: 2022/11/30 14:32:25 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_player(t_data *data)
{
	t_game	*game;

	game = data->base.game;
	// data->player.x = WIN_WIDTH / 2;
	// data->player.y = WIN_HEIGHT / 2;
	data->player.x = game->p_x * TILE_SIZE;
	data->player.y = game->p_y * TILE_SIZE;
	data->player.width = 5;
	data->player.height = 5;
	data->player.turnDirection = 0;
	data->player.walkDirection = 0;
	data->player.rotationAngle = M_PI / 2;
	data->player.turnSpeed =  45 * (M_PI / 180); // 2 * (M_PI / 180) dans le js; 
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
