/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:55:57 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/14 19:57:57 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_horz_steps(t_data *data, t_cast *cast)
{
	cast->horz.y_intercept = floor(data->player.p.y / TILE_SIZE) * TILE_SIZE;
	if (cast->ray_facing_down == TRUE)
		cast->horz.y_intercept += TILE_SIZE;
	cast->horz.x_intercept = data->player.p.x + (cast->horz.y_intercept \
		- data->player.p.y) / tan(cast->ray_angle);
	cast->horz.y_step = TILE_SIZE;
	if (cast->ray_facing_up == TRUE)
		cast->horz.y_step *= -1;
	cast->horz.x_step = TILE_SIZE / tan(cast->ray_angle);
	if (cast->ray_facing_left == TRUE && cast->horz.x_step > 0)
		cast->horz.x_step *= -1;
	if (cast->ray_facing_right == TRUE && cast->horz.x_step < 0)
		cast->horz.x_step *= -1;
}

void	ft_check_horz_intersection(t_data *data, t_cast *cast)
{
	ft_get_horz_steps(data, cast);
	cast->horz.next_touch_x = cast->horz.x_intercept;
	cast->horz.next_touch_y = cast->horz.y_intercept;
	while (cast->horz.next_touch_x >= 0 && cast->horz.next_touch_y >= 0)
	{
		cast->horz.x_to_check = cast->horz.next_touch_x;
		cast->horz.y_to_check = cast->horz.next_touch_y;
		if (cast->ray_facing_up == TRUE)
			cast->horz.y_to_check -= 1;
		if (ft_check_wall(data, cast->horz.x_to_check, \
			cast->horz.y_to_check) == TRUE)
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
