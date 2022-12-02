/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/02 19:39:14 by cgaillag         ###   ########.fr       */
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
	mlx_destroy_image(data->img.mlx_ptr, data->img.img);
	mlx_destroy_window(data->img.mlx_ptr, data->img.win_ptr);
	mlx_loop_end(data->img.mlx_ptr);
	mlx_destroy_display(data->img.mlx_ptr);
	free(data->img.mlx_ptr);
	exit(0);
}

/*  ***** Cleaning - display the error message *****
**  *************************
**  <SUMMARY>	Print an error message on stderr (if any)
**				and return the provided error value
*/
int	ft_err_msg_1(int res, char *msg1, char *msg2, char *msg3)
{
	if (!msg1 && !msg2)
		return (res);
	write(2, "Error\n", 6);
	if (msg1)
	{
		ft_putstr_fd(msg1, STDERR_FILENO);
		write(STDERR_FILENO, ": ", 2);
	}
	ft_putstr_fd(msg2, STDERR_FILENO);
	ft_putendl_fd(msg3, STDERR_FILENO);
	return (res);
}

int	ft_err_msg_2(int res, int i, char *msg1, char *msg2)
{
	if (!msg1 && !msg2)
		return (res);
	write(2, "Error\n", 6);
	if (i >= 0)
	{
		ft_putstr_fd("line[", STDERR_FILENO);
		write(STDERR_FILENO, ft_itoa(i), 1);
		write(STDERR_FILENO, "]: ", 3);
	}
	if (msg1)
	{
		ft_putstr_fd(msg1, STDERR_FILENO);
		write(STDERR_FILENO, ": ", 2);
	}
	ft_putendl_fd(msg2, STDERR_FILENO);
	return (res);
}

void	ft_close_fd(void)
{
	int	fd;

	fd = 0;
	while (fd < OPEN_MAX)
		close (fd++);
}

int	ft_clean_base(int res)
{
	ft_magic_malloc(0, NULL, 0);
	ft_close_fd();
	return (res);
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
