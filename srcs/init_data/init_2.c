/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:20 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/16 18:42:37 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	<SUMMARY> Gets the roation angle of the player according to the map
*/

float	ft_get_rotation_angle(t_base *base)
{
	float	rotation_angle;

	rotation_angle = 0;
	if (base->p_direction == 'N')
		rotation_angle = (3 * PI) / 2;
	else if (base->p_direction == 'S')
		rotation_angle = PI / 2;
	else if (base->p_direction == 'E')
		rotation_angle = 0;
	else if (base->p_direction == 'W')
		rotation_angle = PI;
	return (rotation_angle);
}

/*	<SUMMARY> Initialize the player position and orientation
*/

void	ft_init_player(t_data *data)
{
	t_base	*base;

	base = &data->base;
	data->player.p.x = (base->p_x * TILE_SIZE) + (TILE_SIZE / 2);
	data->player.p.y = (base->p_y * TILE_SIZE) + (TILE_SIZE / 2);
	data->player.height = 4;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.side_direction = 0;
	data->player.rotation_angle = ft_get_rotation_angle(base);
	data->player.turn_speed = TURN_SPEED_COEF * (PI / 180);
	data->player.walk_speed = WALK_SPEED;
}

/*	<SUMMARY> Initialize every ray to cast
*/
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
