/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:53:10 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/14 19:59:45 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_ray(t_data *data, int strip_id, t_cast *cast)
{
	if (cast->vert.hit_distance < cast->horz.hit_distance)
	{
		data->rays[strip_id].distance = cast->vert.hit_distance;
		data->rays[strip_id].wall_hit.x = cast->vert.wall_hit.x;
		data->rays[strip_id].wall_hit.y = cast->vert.wall_hit.y;
		data->rays[strip_id].wall_hit_vertical = TRUE;
	}
	else
	{
		data->rays[strip_id].distance = cast->horz.hit_distance;
		data->rays[strip_id].wall_hit.x = cast->horz.wall_hit.x;
		data->rays[strip_id].wall_hit.y = cast->horz.wall_hit.y;
		data->rays[strip_id].wall_hit_vertical = FALSE;
	}
	data->rays[strip_id].ray_angle = cast->ray_angle;
	data->rays[strip_id].is_ray_facing_down = cast->ray_facing_down;
	data->rays[strip_id].is_ray_facing_left = cast->ray_facing_left;
	data->rays[strip_id].is_ray_facing_right = cast->ray_facing_right;
	data->rays[strip_id].is_ray_facing_up = cast->ray_facing_up;
}
