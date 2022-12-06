/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:20:02 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/06 14:35:39 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_orientation(t_data *data, float ray_angle, int strip_id)
{
	if (ray_angle > 0 && ray_angle < M_PI)
		data->rays[strip_id].is_ray_facing_down = TRUE;
	else
		data->rays[strip_id].is_ray_facing_up = TRUE;
	if (ray_angle < (M_PI / 2) || ray_angle > (3 * M_PI / 2))
		data->rays[strip_id].is_ray_facing_right = TRUE;
	else
		data->rays[strip_id].is_ray_facing_left = TRUE;
}

float	ft_normalize_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, (M_PI * 2));
	if (ray_angle < 0)
		ray_angle = (2 * M_PI) + ray_angle;
	return (ray_angle);
}

void	ft_check_horz_intersection(t_data *data, float ray_angle, int strip_id, t_hit *horz)
{
	horz->y_intercept = floor(data->player.p.y / TILE_SIZE) * TILE_SIZE;
	if (data->rays[strip_id].is_ray_facing_down == TRUE)
		horz->y_intercept += TILE_SIZE;
	horz->x_intercept = data->player.p.x + (horz->y_intercept - data->player.p.y) / tan(ray_angle);
	horz->y_step = TILE_SIZE;
	if (data->rays[strip_id].is_ray_facing_up == TRUE)
		horz->y_step *= -1;
	horz->x_step = TILE_SIZE / tan(ray_angle);
	if (data->rays[strip_id].is_ray_facing_left == TRUE && horz->x_step > 0)
		horz->x_step *= -1;
	if (data->rays[strip_id].is_ray_facing_right == TRUE && horz->x_step < 0)
		horz->x_step *= -1;
	horz->next_touch_x = horz->x_intercept;
	horz->next_touch_y = horz->y_intercept;
	while (horz->next_touch_x >= 0 && horz->next_touch_x <= WIN_WIDTH && horz->next_touch_y >= 0 && horz->next_touch_y <= WIN_HEIGHT)
	{
		horz->x_to_check = horz->next_touch_x;
		horz->y_to_check = horz->next_touch_y;
		if (data->rays[strip_id].is_ray_facing_up == TRUE)
			horz->y_to_check -= 1;
		if (ft_check_wall(data, horz->x_to_check, horz->y_to_check) == TRUE)
		{
			horz->wall_hit.x = horz->next_touch_x;
			horz->wall_hit.y = horz->next_touch_y;
			horz->found_wall_hit = TRUE;
			break ;
		}
		else
		{
			horz->next_touch_x += horz->x_step;
			horz->next_touch_y += horz->y_step;
		}
	}
}

void	ft_check_vert_intersection(t_data *data, float ray_angle, int strip_id, t_hit *vert)
{
	vert->x_intercept = floor(data->player.p.x / TILE_SIZE) * TILE_SIZE;
	if (data->rays[strip_id].is_ray_facing_right == TRUE)
		vert->x_intercept += TILE_SIZE;
	vert->y_intercept = data->player.p.y + (vert->x_intercept - data->player.p.x) * tan(ray_angle);
	vert->x_step = TILE_SIZE;
	if (data->rays[strip_id].is_ray_facing_left == TRUE)
		vert->x_step *= -1;
	vert->y_step = TILE_SIZE * tan(ray_angle);
	if (data->rays[strip_id].is_ray_facing_up == TRUE && vert->x_step > 0)
		vert->y_step *= -1;
	if (data->rays[strip_id].is_ray_facing_down == TRUE && vert->x_step < 0)
		vert->y_step *= -1;
	vert->next_touch_x = vert->x_intercept;
	vert->next_touch_y = vert->y_intercept;
	while (vert->next_touch_x >= 0 && vert->next_touch_x <= WIN_WIDTH && vert->next_touch_y >= 0 && vert->next_touch_y <= WIN_HEIGHT)
	{
		vert->y_to_check = vert->next_touch_y;
		vert->x_to_check = vert->next_touch_x;
		if (data->rays[strip_id].is_ray_facing_left == TRUE)
			vert->x_to_check -= 1;
		if (ft_check_wall(data, vert->x_to_check, vert->y_to_check) == TRUE)
		{
			vert->wall_hit.x = vert->next_touch_x;
			vert->wall_hit.y = vert->next_touch_y;
			vert->found_wall_hit = TRUE;
			break ;
		}
		else
		{
			vert->next_touch_x += vert->x_step;
			vert->next_touch_y += vert->y_step;
		}
	}
}

void	ft_init_horz_vert(t_hit *horz)
{
	horz->x_intercept = 0;
	horz->y_intercept = 0;
	horz->x_step = 0;
	horz->y_step = 0;
	horz->found_wall_hit = FALSE;
	horz->next_touch_x = 0;
	horz->next_touch_y = 0;
	horz->x_to_check = 0;
	horz->y_to_check = 0;
	horz->wall_hit.x = 0;
	horz->wall_hit.y = 0;
	horz->hit_distance = (float)INT_MAX;
}

float	ft_distance_btw_points(t_player player, t_point wall_hit)
{
	float	distance;

	distance = sqrt((wall_hit.x - player.p.x) * (wall_hit.x - player.p.x) + (wall_hit.y - player.p.y) * (wall_hit.y - player.p.y));
	return (distance);
}

void	ft_fill_ray(t_data *data, int strip_id, t_hit horz, t_hit vert)
{
	if (vert.hit_distance < horz.hit_distance)
	{
		data->rays[strip_id].distance = vert.hit_distance;
		data->rays[strip_id].wall_hit.x = vert.wall_hit.x;
		data->rays[strip_id].wall_hit.y = vert.wall_hit.y;
		data->rays[strip_id].wall_hit_vertical = TRUE;
	}
	else
	{
		data->rays[strip_id].distance = horz.hit_distance;
		data->rays[strip_id].wall_hit.x = horz.wall_hit.x;
		data->rays[strip_id].wall_hit.y = horz.wall_hit.y;
		data->rays[strip_id].wall_hit_vertical = FALSE;
	}
}

void	ft_cast_ray(t_data *data, float ray_angle, int strip_id)
{
	t_hit	horz;
	t_hit	vert;
	
	ft_init_horz_vert(&horz);
	ft_init_horz_vert(&vert);
	ray_angle = ft_normalize_angle(ray_angle);
	ft_ray_orientation(data, ray_angle, strip_id);
	ft_check_horz_intersection(data, ray_angle, strip_id, &horz);
	ft_check_vert_intersection(data, ray_angle, strip_id, &vert);
	if (horz.found_wall_hit == TRUE)
		horz.hit_distance = ft_distance_btw_points(data->player, horz.wall_hit);
	if (vert.found_wall_hit == TRUE)
		vert.hit_distance = ft_distance_btw_points(data->player, vert.wall_hit);
	ft_fill_ray(data, strip_id, horz, vert);
	data->rays[strip_id].ray_angle = ray_angle;
}

void	ft_init_ray(t_data *data, float ray_angle, int strip_id)
{
	data->rays[strip_id].ray_angle = ray_angle;
	data->rays[strip_id].wall_hit.x = 0;
	data->rays[strip_id].wall_hit.y = 0;
	data->rays[strip_id].distance = 0;
	data->rays[strip_id].wall_hit_vertical = FALSE;
	data->rays[strip_id].is_ray_facing_up = FALSE;
	data->rays[strip_id].is_ray_facing_down = FALSE;
	data->rays[strip_id].is_ray_facing_left = FALSE;
	data->rays[strip_id].is_ray_facing_right = FALSE;
}

void	ft_cast_all_rays(t_data *data)
{
	float	ray_angle;
	int		strip_id;
	
	strip_id = 0;
	ray_angle = data->player.rotation_angle - (FOV_ANGLE / 2);
	while (strip_id < data->nbr_rays)
	{
		ft_init_ray(data, ray_angle, strip_id);
		ft_cast_ray(data, ray_angle, strip_id);
		//ft_draw_line(data, data->player.p, data->rays[strip_id].wall_hit, COLOR_RED);
		strip_id++;
	}
}