/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/15 12:32:52 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_close_fd(void)
{
	int	fd;

	fd = 0;
	while (fd < OPEN_MAX)
		close (fd++);
}

void	ft_clean_cub(t_data *data)
{
	if (!data)
		return ;
	if (data->base.no.img)
		mlx_destroy_image(data->mlx_ptr, data->base.no.img);
	if (data->base.so.img)
		mlx_destroy_image(data->mlx_ptr, data->base.so.img);
	if (data->base.we.img)
		mlx_destroy_image(data->mlx_ptr, data->base.we.img);
	if (data->base.ea.img)
		mlx_destroy_image(data->mlx_ptr, data->base.ea.img);
	if (data->m2d.img)
		mlx_destroy_image(data->mlx_ptr, data->m2d.img);
	if (data->cub.img)
		mlx_destroy_image(data->mlx_ptr, data->cub.img);
	if (data->map2d_display == TRUE)
		mlx_destroy_window(data->mlx_ptr, data->map2d_win_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_loop_end(data->mlx_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	ft_exit_base(int res)
{
	ft_magic_malloc(0, NULL, 0);
	ft_close_fd();
	exit(res);
}

int	ft_quit(t_data *data)
{
	ft_clean_cub(data);
	ft_magic_malloc(0, NULL, 0);
	ft_close_fd();
	exit(0);
}

void	ft_exit_cub(int res, t_data *data)
{
	ft_clean_cub(data);
	ft_magic_malloc(0, NULL, 0);
	ft_close_fd();
	exit(res);
}
