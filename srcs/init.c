/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:20 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/08 14:29:43 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_get_rotation_angle(t_base *base)
{
	// inverser l'orientation 
	float	rotation_angle;

	rotation_angle = 0;
	if (base->p_direction == 'N')
		rotation_angle = (3 * M_PI) / 2;
	else if (base->p_direction == 'S')
		rotation_angle = M_PI / 2;
	else if (base->p_direction == 'E')
		rotation_angle = 0;
	else if (base->p_direction == 'W')
		rotation_angle = M_PI;
	return (rotation_angle);
}

void	ft_init_player(t_data *data)
{
	t_base	*base;

	base = &data->base;
	// data->player.x = game->p_x * TILE_SIZE;
	// data->player.y = game->p_y * TILE_SIZE;
	data->player.p.x = base->p_x * TILE_SIZE;
	data->player.p.y = base->p_y * TILE_SIZE;
	data->player.width = 4;
	data->player.height = 4; // ne garder que width ?
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.side_direction = 0;
	data->player.rotation_angle = ft_get_rotation_angle(base);
	printf("\ndata->playerotationangle %f\n", data->player.rotation_angle);
	data->player.turn_speed =  3 * (M_PI / 180);
	data->player.walk_speed = 2.0;
}

void	ft_init_rays(t_data *data)
{
	int	strip_id;

	strip_id = 0;
	while (strip_id < WIN_WIDTH)
	{
		data->rays[strip_id].wall_hit.x = 0;
		data->rays[strip_id].wall_hit.y = 0;
		data->rays[strip_id].distance = 0;
		data->rays[strip_id].wall_hit_vertical = FALSE;
		data->rays[strip_id].is_ray_facing_up = FALSE;
		data->rays[strip_id].is_ray_facing_down = FALSE;
		data->rays[strip_id].is_ray_facing_left = FALSE;
		data->rays[strip_id].is_ray_facing_right = FALSE;
		strip_id++;
	}
}

void	ft_init_data(t_data *data)
{
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
	data->nbr_rays = WIN_WIDTH;
	ft_init_player(data);
	ft_init_rays(data);
}