/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:58:10 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/14 19:58:53 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_vert_steps(t_data *data, t_cast *cast)
{
	cast->vert.x_intercept = floor(data->player.p.x / TILE_SIZE) * TILE_SIZE;
	if (cast->ray_facing_right == TRUE)
		cast->vert.x_intercept += TILE_SIZE;
	cast->vert.y_intercept = data->player.p.y + (cast->vert.x_intercept \
		- data->player.p.x) * tan(cast->ray_angle);
	cast->vert.x_step = TILE_SIZE;
	if (cast->ray_facing_left == TRUE)
		cast->vert.x_step *= -1;
	cast->vert.y_step = TILE_SIZE * tan(cast->ray_angle);
	if (cast->ray_facing_up == TRUE && cast->vert.y_step > 0)
		cast->vert.y_step *= -1;
	if (cast->ray_facing_down == TRUE && cast->vert.y_step < 0)
		cast->vert.y_step *= -1;
}

void	ft_check_vert_intersection(t_data *data, t_cast *cast)
{
	ft_get_vert_steps(data, cast);
	cast->vert.next_touch_x = cast->vert.x_intercept;
	cast->vert.next_touch_y = cast->vert.y_intercept;
	while (cast->vert.next_touch_x >= 0 && cast->vert.next_touch_y >= 0)
	{
		cast->vert.y_to_check = cast->vert.next_touch_y;
		cast->vert.x_to_check = cast->vert.next_touch_x;
		if (cast->ray_facing_left == TRUE)
			cast->vert.x_to_check -= 1;
		if (ft_check_wall(data, cast->vert.x_to_check, \
			cast->vert.y_to_check) == TRUE)
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
