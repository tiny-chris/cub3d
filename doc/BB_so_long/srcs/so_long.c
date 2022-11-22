/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:20:01 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/28 00:03:51 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

/*  ***** Check - map has a correct extension *****
**  Checks if the filename's extension is correct, i.e. '.ber'
**	- if yes    --> return 1
**  - if no     --> return 0
*/
int	ft_check_filename(char *file_name, char *ext)
{
	int			f_len;
	int			ext_len;
	const char	*start;

	if (!file_name || !ext)
		return (0);
	f_len = ft_strlen(file_name);
	ext_len = ft_strlen(ext);
	start = ft_substr((const char *)file_name, (f_len - ext_len), ext_len);
	if (ft_strncmp((const char *)start, ext, 4) == 0)
		return (free((char *)start), 1);
	free((char *)start);
	return (0);
}

/*  ***** FT_COUNT_LINES using GNL *****
**  *************************
**  Reads the file and counts the number of lines
*/
int	ft_count_lines_gnl(char *file)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (count);
}

/*  ***** GET_MAP so long *****
**  *************************
**  Creates map by saving the file content in a char ** and by reading the file
**  (1 string = 1 line)
*/
char	**ft_get_map_sl(char *file)
{
	char	**map_base;
	int		fd;
	int		lines;
	int		i;

	lines = ft_count_lines_gnl(file);
	fd = open(file, O_RDONLY);
	if (fd < 0 || lines == 0)
		return (ft_error_msg_sl(ERRMSG_F2), NULL);
	i = 0;
	map_base = malloc(sizeof(char **) * (lines + 1));
	if (!map_base)
		return (ft_error_msg_sl(ERRMSG_M1), NULL);
	map_base[i] = get_next_line(fd);
	while (map_base[i])
	{
		i++;
		map_base[i] = get_next_line(fd);
	}
	map_base[i] = NULL;
	close(fd);
	if (!map_base)
		return (ft_error_msg_sl(ERRMSG_M1), NULL);
	return (map_base);
}

/*  ***** KEY_PRESS so long *****
**	Function called in mlx_hook to apply for provided pressed keys a specific 
**	action:
**	- ESC 	= keycode '65307' (escape)
**	- W		= keycode '119' (up)
**	- S		= keycode '115' (down)
**	- A		= keycode '97' (left)
**	- D		= keycode '100' (right)
*/
int	ft_key_press_sl(int keycode, t_data *d_ref)
{
	if (keycode == 65307)
		ft_clean_game(d_ref, 0, SUCMSG_ES);
	else if (keycode == 119)
		ft_move_up(d_ref);
	else if (keycode == 115)
		ft_move_down(d_ref);
	else if (keycode == 97)
		ft_move_left(d_ref);
	else if (keycode == 100)
		ft_move_right(d_ref);
	return (0);
}

/*  ***** MAIN SO_LONG *****
**  ************************
**  Steps:
**  0. Prerequisite: exactly 1 argument after executable + extension .ber 
**  1. Create the ref structure for grahical & non-graphical game data:
**      --> analyse the file to ensure we have a valid map (or exit)
**      --> gather all data for the game & save them in a structure
**  2. Initialise mlx data & proceed in integrating images
**      --> transform the map into graphic elements (using images & mlx)
**  3. Play the game
*/
int	main(int argc, char **argv)
{
	t_data	*d_ref;

	if (argc != 2)
		ft_exit_sl(-1, ERRMSG_F1);
	if (ft_check_filename(argv[1], ".ber") == 0)
		ft_exit_sl(-1, ERRMSG_F2);
	if (!argv[1] || ft_count_lines_gnl(argv[1]) == 0)
		ft_exit_sl(-1, ERRMSG_F2);
	d_ref = ft_init_t_data_sl(argv[1]);
	if (d_ref == 0)
		ft_exit_sl(-1, ERRMSG_F1);
	ft_init_winmlx_sl(d_ref);
	ft_init_img_sl(d_ref);
	mlx_loop_hook(d_ref->mlx, &ft_draw_map_sl, d_ref);
	mlx_hook(d_ref->win, 2, 1L << 0, &ft_key_press_sl, d_ref);
	mlx_hook(d_ref->win, 17, 1L << 17, ft_destroy_hook_sl, d_ref);
	mlx_loop(d_ref->mlx);
	return (0);
}
