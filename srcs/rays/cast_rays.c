/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:20:02 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/07 20:12:02 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_orientation(t_cast *cast, float ray_angle)
{
	if (ray_angle > 0 && ray_angle < M_PI)
		cast->ray_facing_down = TRUE;
	else
		cast->ray_facing_up = TRUE;
	if (ray_angle < (M_PI / 2) || ray_angle > (3 * M_PI / 2))
		cast->ray_facing_right = TRUE;
	else
		cast->ray_facing_left = TRUE;
}

float	ft_normalize_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, (M_PI * 2));
	if (ray_angle < 0)
		ray_angle = (2 * M_PI) + ray_angle;
	return (ray_angle);
}

void	ft_get_horz_steps(t_data *data, float ray_angle, t_cast *cast)
{
	cast->horz.y_intercept = floor(data->player.p.y / TILE_SIZE) * TILE_SIZE;
	if (cast->ray_facing_down == TRUE)
		cast->horz.y_intercept += TILE_SIZE;
	cast->horz.x_intercept = data->player.p.x + (cast->horz.y_intercept - data->player.p.y) / tan(ray_angle);
	cast->horz.y_step = TILE_SIZE;
	if (cast->ray_facing_up == TRUE)
		cast->horz.y_step *= -1;
	cast->horz.x_step = TILE_SIZE / tan(ray_angle);
	if (cast->ray_facing_left == TRUE && cast->horz.x_step > 0)
		cast->horz.x_step *= -1;
	if (cast->ray_facing_right == TRUE && cast->horz.x_step < 0)
		cast->horz.x_step *= -1;
}

void	ft_check_horz_intersection(t_data *data, float ray_angle, t_cast *cast)
{
	ft_get_horz_steps(data, ray_angle, cast);
	cast->horz.next_touch_x = cast->horz.x_intercept;
	cast->horz.next_touch_y = cast->horz.y_intercept;
	while (cast->horz.next_touch_x >= 0 && cast->horz.next_touch_x <= WIN_WIDTH && cast->horz.next_touch_y >= 0 && cast->horz.next_touch_y <= WIN_HEIGHT)
	{
		cast->horz.x_to_check = cast->horz.next_touch_x;
		cast->horz.y_to_check = cast->horz.next_touch_y;
		if (cast->ray_facing_up == TRUE)
			cast->horz.y_to_check -= 1;
		if (ft_check_wall(data, cast->horz.x_to_check, cast->horz.y_to_check) == TRUE)
		{
			cast->horz.wall_hit.x = cast->horz.next_touch_x;
			cast->horz.wall_hit.y = cast->horz.next_touch_y;
			cast->horz.found_wall_hit = TRUE;
			break ;
		}
		else
		{
			cast->horz.next_touch_x += cast->horz.x_step;
			cast->horz.next_touch_y += cast->horz.y_step;
		}
	}
}

void	ft_get_vert_steps(t_data *data, float ray_angle, t_cast *cast)
{
	cast->vert.x_intercept = floor(data->player.p.x / TILE_SIZE) * TILE_SIZE;
	if (cast->ray_facing_right == TRUE)
		cast->vert.x_intercept += TILE_SIZE;
	cast->vert.y_intercept = data->player.p.y + (cast->vert.x_intercept - data->player.p.x) * tan(ray_angle);
	cast->vert.x_step = TILE_SIZE;
	if (cast->ray_facing_left == TRUE)
		cast->vert.x_step *= -1;
	cast->vert.y_step = TILE_SIZE * tan(ray_angle);
	if (cast->ray_facing_up == TRUE && cast->vert.y_step > 0) //
		cast->vert.y_step *= -1;
	if (cast->ray_facing_down == TRUE && cast->vert.y_step < 0) //
		cast->vert.y_step *= -1;
}

void	ft_check_vert_intersection(t_data *data, float ray_angle, t_cast *cast)
{
	ft_get_vert_steps(data, ray_angle, cast);
	cast->vert.next_touch_x = cast->vert.x_intercept;
	cast->vert.next_touch_y = cast->vert.y_intercept;
	while (cast->vert.next_touch_x >= 0 && cast->vert.next_touch_x <= WIN_WIDTH && cast->vert.next_touch_y >= 0 && cast->vert.next_touch_y <= WIN_HEIGHT)
	{
		cast->vert.y_to_check = cast->vert.next_touch_y;
		cast->vert.x_to_check = cast->vert.next_touch_x;
		if (cast->ray_facing_left == TRUE)
			cast->vert.x_to_check -= 1;
		if (ft_check_wall(data, cast->vert.x_to_check, cast->vert.y_to_check) == TRUE)
		{
			cast->vert.wall_hit.x = cast->vert.next_touch_x;
			cast->vert.wall_hit.y = cast->vert.next_touch_y;
			cast->vert.found_wall_hit = TRUE;
			break ;
		}
		else
		{
			cast->vert.next_touch_x += cast->vert.x_step;
			cast->vert.next_touch_y += cast->vert.y_step;
		}
	}
}

void	ft_init_hit(t_hit *hit)
{
	hit->x_intercept = 0;
	hit->y_intercept = 0;
	hit->x_step = 0;
	hit->y_step = 0;
	hit->found_wall_hit = FALSE;
	hit->next_touch_x = 0;
	hit->next_touch_y = 0;
	hit->x_to_check = 0;
	hit->y_to_check = 0;
	hit->wall_hit.x = 0;
	hit->wall_hit.y = 0;
	hit->hit_distance = (float)INT_MAX;
}

void	ft_init_cast(t_cast *cast)
{
	ft_init_hit(&cast->horz);
	ft_init_hit(&cast->vert);
	cast->ray_facing_down = FALSE;
	cast->ray_facing_left = FALSE;
	cast->ray_facing_right = FALSE;
	cast->ray_facing_up = FALSE;
}

float	ft_distance_btw_points(t_player player, t_point wall_hit)
{
	float	distance;

	distance = sqrt((wall_hit.x - player.p.x) * (wall_hit.x - player.p.x) + (wall_hit.y - player.p.y) * (wall_hit.y - player.p.y));
	return (distance);
}

void	ft_fill_ray(t_data *data, int strip_id, t_cast *cast, float ray_angle)
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
	data->rays[strip_id].ray_angle = ray_angle;
	data->rays[strip_id].is_ray_facing_down = cast->ray_facing_down;
	data->rays[strip_id].is_ray_facing_left = cast->ray_facing_left;
	data->rays[strip_id].is_ray_facing_right = cast->ray_facing_right;
	data->rays[strip_id].is_ray_facing_up = cast->ray_facing_up;
}

void	ft_cast_ray(t_data *data, float ray_angle, int strip_id)
{
	t_cast	cast;
	
	ft_init_cast(&cast);
	ray_angle = ft_normalize_angle(ray_angle);
	ft_ray_orientation(&cast, ray_angle);
	ft_check_horz_intersection(data, ray_angle, &cast);
	ft_check_vert_intersection(data, ray_angle, &cast);
	if (cast.horz.found_wall_hit == TRUE)
		cast.horz.hit_distance = ft_distance_btw_points(data->player, cast.horz.wall_hit);
	if (cast.vert.found_wall_hit == TRUE)
		cast.vert.hit_distance = ft_distance_btw_points(data->player, cast.vert.wall_hit);
	ft_fill_ray(data, strip_id, &cast, ray_angle);
}

void	ft_cast_all_rays(t_data *data)
{
	float	ray_angle;
	int		strip_id;
	
	strip_id = 0;
	// angle pour le first ray
	ray_angle = data->player.rotation_angle - (FOV_ANGLE / 2);
	while (strip_id < WIN_WIDTH)
	{
		ft_cast_ray(data, ray_angle, strip_id);
		strip_id++;
		ray_angle += FOV_ANGLE / WIN_WIDTH;
	}
	// printf("data->rays[strip_id].is facing down %d\n", data->rays[strip_id - 1].is_ray_facing_down);
	// printf("data->rays[strip_id].is facing up %d\n", data->rays[strip_id - 1].is_ray_facing_up);
	// printf("data->rays[strip_id].is facing left %d\n", data->rays[strip_id - 1].is_ray_facing_left);
	// printf("data->rays[strip_id].is facing right %d\n", data->rays[strip_id - 1].is_ray_facing_right);
}
