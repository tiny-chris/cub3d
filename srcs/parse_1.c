/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/24 12:52:40 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  ***** Parsing - number of expected arguments *****
**  *************************
**  <SUMMARY>	Check if the number of arguments is correct (argc == 2)
**	Otherwise display an error message for too many or not enough arguments
*/
int	ft_check_argc(int argc)
{
	if (argc < 2)
		ft_err_msg(1, NULL, ER_NO_AG);
	else if (argc > 2)
		ft_err_msg(1, NULL, ER_TOO_AG);
	return (argc);
}

/*  ***** Parsing - identify map's extension *****
**  *************************
**  <SUMMARY>	Check if the filename's extension is correct, i.e. '.cub'
**	<RETURN>	- if yes	--> return 1
**  			- if no     --> return 0 + display error message
**	<REMARKS>	only '.cub' is not a correct filename
**				
*/
int	ft_check_filename(char *file, char *ext)
{
	int			ext_len;
	const char	*start;

	ext_len = 0;
	start = NULL;
	if (file && ext)
	{
		ext_len = ft_strlen(ext);
		if ((int) ft_strlen(file) > ext_len)
		{
			start = ft_substr(file, (ft_strlen(file) - ext_len), ext_len);
			if (!start)
				return (ft_err_msg(0, "ft_check_filename()", ER_MALLOC));
			if (ft_strncmp(start, ext, 4) == 0)
				if (file[ft_strlen(file) - ext_len - 1] != '/')
					return (free((char *)start), 1);
			free((char *)start);
		}
	}
	ft_err_msg(1, file, ER_MAP_EXT);
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
		ft_err_msg(1, file, ER_MAP_ISDIR);
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
	int		count;

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
	return (count);
}

/*  ***** Parsing - file checking on existence, extension, global content *****
**  *************************
**  <SUMMARY>	Main checking function that gathers tests function
**	<RETURN>	- EXIT_FAILURE if any error
**				- EXIT_SUCCESS to continue the program
*/
int	ft_check_arg_err(int argc, char *file)
{
	if (ft_check_argc(argc) != 2)
		return (EXIT_FAILURE);
	if (!file)
		return (ft_err_msg(EXIT_FAILURE, file, ER_MAP_EMPTY));
	if (!ft_check_filename(file, ".cub"))
		return (EXIT_FAILURE);
	if (ft_check_isdirectory(file))
		return (EXIT_FAILURE);
	if (ft_count_lines_gnl(file) == 0)
		return (ft_err_msg(EXIT_FAILURE, file, ER_MAP_EMPTY));
	return (EXIT_SUCCESS);
}
// int	ft_check_file_err(char *file)
// {
// 	return (EXIT_SUCCESS);
// }

// 	// {
// 	// 	ft_putendl_fd(ER_MAP_EMPTY, 1);
// 	// 	return (EXIT_FAILURE);
// 	// }
