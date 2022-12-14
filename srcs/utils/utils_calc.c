/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:10:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/14 20:23:15 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_normalize_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, (PI * 2));
	if (ray_angle < 0)
		ray_angle = (2 * PI) + ray_angle;
	return (ray_angle);
}

float	ft_distance_btw_points(t_player player, t_point wall_hit)
{
	float	distance;

	distance = sqrtf((wall_hit.x - player.p.x) * (wall_hit.x - player.p.x) \
		+ (wall_hit.y - player.p.y) * (wall_hit.y - player.p.y));
	return (distance);
}
