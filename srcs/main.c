/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/15 17:51:55 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_check_arg_err(argc, argv[1]))
		ft_exit_base(EXIT_FAILURE);
	ft_init_t_base(argv[1], &data.base);
	if (ft_check_file_err(&data.base))
		ft_exit_base(EXIT_FAILURE);
	ft_update_t_base_game(&data.base);
	ft_init_data(&data);
	mlx_hook(data.win_ptr, 17, 1L << 17, ft_quit, &data);
	mlx_hook(data.win_ptr, 2, 1L << 0, ft_key_hook, &data);
	mlx_hook(data.win_ptr, 3, 1L << 1, ft_key_release, &data);
	mlx_loop_hook(data.mlx_ptr, ft_render_next_frame, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
