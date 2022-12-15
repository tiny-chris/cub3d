/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/15 16:08:04 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  ***** Parsing - number of expected arguments *****
**  *************************
**  <SUMMARY>	Check if the number of arguments is correct (argc == 2)
**	Otherwise display an error message for too many or not enough arguments
*/
static int	ft_check_argc(int argc)
{
	if (argc < 2)
		ft_msg_2(1, NULL, ER_ARG_MISS, USAGE_CUB);
	else if (argc > 2)
		ft_msg_2(1, NULL, ER_ARG_TOO, USAGE_CUB);
	return (argc);
}

/*  ***** Parsing - identify map's extension *****
**  *************************
**  <SUMMARY>	Check if the filename's extension is correct, i.e. '.cub'
**	<RETURN>	- if yes	--> return 1
**  			- if no     --> return 0 + display error message
**	<REMARKS>	only '.cub' is not a correct filename
*/
int	ft_check_filename(char *file, char *ext)
{
	int		ext_len;
	char	*start;

	ext_len = 0;
	start = NULL;
	if (file && ext)
	{
		ext_len = ft_strlen(ext);
		if ((int) ft_strlen(file) > ext_len)
		{
			start = ft_substr(file, (ft_strlen(file) - ext_len), ext_len);
			ft_magic_malloc(ADD + TAB_STR1, start, 0);
			if (ft_strncmp(start, ext, ext_len) == 0)
				if (file[ft_strlen(file) - ext_len - 1] != '/')
					return (1);
		}
	}
	return (0);
}

/*  ***** Parsing - test file's type as directory (and not file) *****
**  *************************
**  <SUMMARY>	Check if the type is a directory with open() function
**	<RETURN>	- if yes	--> return 1
**  			- if no		--> return 0 + display error message
**	<REMARK>	opendir() function is not allowed
*/
int	ft_check_isdirectory(char *file)
{
	int	dir;

	dir = open(file, O_DIRECTORY);
	if (dir >= 0)
	{
		close(dir);
		return (1);
	}
	return (0);
}

/*  ***** Parsing - count lines using gnl *****
**  *************************
**  <SUMMARY>	Read the file and count the number of lines
**	<RETURN>	the number of lines (0 if none)
*/
int	ft_count_lines_gnl(char *file)
{
	char	*line;
	int		fd;
	long	count;

	count = 0;
	fd = ft_open_read(file);
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
	if (count >= INT_MAX)
		ft_exit_base(ft_msg_1(1, file, NULL, ER_FIL_BIG));
	return ((int) count);
}

/*  ***** Parsing - check argc *****
**  *************************
**  <SUMMARY>	Main checking function that gathers tests function on:
**	file existence, extension, global content
**	<RETURN>	- EXIT_FAILURE if any error
**				- EXIT_SUCCESS to continue the program
*/
int	ft_check_arg_err(int argc, char *file)
{
	if (ft_check_argc(argc) != 2)
		return (EXIT_FAILURE);
	if (!file)
		return (ft_msg_1(EXIT_FAILURE, file, NULL, ER_FOD_INEX));
	if (!ft_check_filename(file, ".cub"))
		return (ft_msg_2(EXIT_FAILURE, file, ER_FIL_EXT, USAGE_CUB));
	if (ft_check_isdirectory(file))
		return (ft_msg_1(EXIT_FAILURE, file, NULL, ER_FIL_ISDIR));
	if (ft_count_lines_gnl(file) == 0)
		return (ft_msg_1(EXIT_FAILURE, file, NULL, ER_FIL_EMPTY));
	return (EXIT_SUCCESS);
}
