/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/08 15:57:38 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Fonction qui ne prend q'un seul argument peut etre qu'il faudra que
**	la structure envoyee en paramettre pointe vers d'autres structures pour
**	tout free avant d'exit ou bien faire un garbage collector aussiiiiii
*/
void	ft_quit(t_data *data)
{
	// if (data->cub.img)
	// 	mlx_destroy_image(data->cub.mlx_ptr, data->cub.img);
	// if (data->cub.win_ptr)
	// 	mlx_destroy_window(data->cub.mlx_ptr, data->cub.win_ptr);
	// if (data->cub.mlx_ptr != 0)
	// {
	// 	mlx_loop_end(data->cub.mlx_ptr);
	// 	mlx_destroy_display(data->cub.mlx_ptr);
	// 	free(data->cub.mlx_ptr);
	// }
	if (data->img.img)
		mlx_destroy_image(data->img.mlx_ptr, data->img.img);
	if (data->img.win_ptr)
		mlx_destroy_window(data->img.mlx_ptr, data->img.win_ptr);
	if (data->img.mlx_ptr != 0)
	{
		mlx_loop_end(data->img.mlx_ptr);
		mlx_destroy_display(data->img.mlx_ptr);
		free(data->img.mlx_ptr);
	}
	(void) data;
	ft_exit_base(0);
}

void	ft_close_fd(void)
{
	int	fd;

	fd = 0;
	while (fd < OPEN_MAX)
		close (fd++);
}

// int	ft_clean_base(int res)
// {
// 	ft_magic_malloc(0, NULL, 0);
// 	ft_close_fd();
// 	return (res);
// }

void	ft_exit_base(int res)
{
	ft_magic_malloc(0, NULL, 0);
	ft_close_fd();
	exit(res);
}

/*	Function **CLEAN GAME** that frees struct 'data'
**	***********
**	Actions:
**	1. clean struct 'game' that contains 'char **map' if not NULL (via sub fct)
**	2. destroy all graphical elements if not NULL:
**		- images (init images for 01CEP): pointer on mlx + void *img
**		- window: pointer on mlx + pointer on window
**		- display: sub fct for 2 steps = 1.end_loop + 2.destroy & free display
**	3. call fct 'exit' correct exit + error messages, error nb (if applicable)
**	***********
**	Parameters:
**	- t_data = struct 'd_ref' to clean
**	- res = result for the exit (0 = success, INT_MAX = no exit, else = failure)
**	- res_msg = to print
*/
// void	ft_clean_cub(t_data *data, int res)
// {
// 	if (data != 0)
// 	{
// 		//clean base + game
// 		ft_magic_malloc(0, NULL, 0);
// 		ft_close_fd();
// 		//
// 		// if (d_ref->empty != 0)
// 		// 	mlx_destroy_image(d_ref->mlx, d_ref->empty);
// 		// if (d_ref->wall != 0)
// 		// 	mlx_destroy_image(d_ref->mlx, d_ref->wall);
// 		// if (d_ref->coll != 0)
// 		// 	mlx_destroy_image(d_ref->mlx, d_ref->coll);
// 		// if (d_ref->exit != 0)
// 		// 	mlx_destroy_image(d_ref->mlx, d_ref->exit);
// 		// if (d_ref->player != 0)
// 		// 	mlx_destroy_image(d_ref->mlx, d_ref->player);
// 		// if (d_ref->win != 0)
// 		// 	mlx_destroy_window(d_ref->mlx, d_ref->win);
// 		//
// 		// A REVOIR:

// 		if (data->mlx != 0)
// 		{
// 			mlx_loop_end(data->mlx);
// 			mlx_destroy_display(data->mlx);
// 			free(data->mlx);
// 		}
// 		//revoir car pas malloc...??
// 		free(data);
// 	}
// 	exit(res, res_msg);
// }
