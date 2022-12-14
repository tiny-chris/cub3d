/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:26:33 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/14 19:27:05 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_WIDTH || x < 0)
		return ;
	if (y > WIN_HEIGHT || y < 0)
		return ;
	dst = data->m2d.addr + (y * data->m2d.line_length \
		+ x * (data->m2d.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_pixel_put2(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_WIDTH || x < 0)
		return ;
	if (y > WIN_HEIGHT || y < 0)
		return ;
	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
