/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:20:02 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/14 19:54:21 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_orientation(t_cast *cast)
{
	if (cast->ray_angle > 0 && cast->ray_angle < PI)
		cast->ray_facing_down = TRUE;
	else
		cast->ray_facing_up = TRUE;
	if (cast->ray_angle < (PI / 2) || cast->ray_angle > (3 * PI / 2))
		cast->ray_facing_right = TRUE;
	else
		cast->ray_facing_left = TRUE;
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

void	ft_init_cast(t_cast *cast, float ray_angle)
{
	ft_init_hit(&cast->horz);
	ft_init_hit(&cast->vert);
	cast->ray_facing_down = FALSE;
	cast->ray_facing_left = FALSE;
	cast->ray_facing_right = FALSE;
	cast->ray_facing_up = FALSE;
	cast->ray_angle = ft_normalize_angle(ray_angle);
}

void	ft_cast_ray(t_data *data, float ray_angle, int strip_id)
{
	t_cast	cast;

	ft_init_cast(&cast, ray_angle);
	ft_ray_orientation(&cast);
	ft_check_horz_intersection(data, &cast);
	ft_check_vert_intersection(data, &cast);
	if (cast.horz.found_wall_hit == TRUE)
		cast.horz.hit_distance = ft_distance_btw_points(data->player, \
			cast.horz.wall_hit);
	if (cast.vert.found_wall_hit == TRUE)
		cast.vert.hit_distance = ft_distance_btw_points(data->player, \
			cast.vert.wall_hit);
	ft_fill_ray(data, strip_id, &cast);
}

void	ft_cast_all_rays(t_data *data)
{
	float	ray_angle;
	int		col;

	col = 0;
	while (col < WIN_WIDTH)
	{
		ray_angle = data->player.rotation_angle + atan((col - WIN_WIDTH / 2) \
			/ data->dist_proj_plane);
		ft_cast_ray(data, ray_angle, col);
		col++;
	}
}
