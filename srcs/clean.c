/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/01 17:26:08 by cgaillag         ###   ########.fr       */
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

int	ft_clean(int res)
{
	ft_magic_malloc(0, NULL, 0);
	ft_close_fd();
	return (res);
}
