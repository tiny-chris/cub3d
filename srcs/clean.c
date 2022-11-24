/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/24 15:01:09 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Fonction qui ne prend q'un seul argument peut etre qu'il faudra que 
**	la structure envoyee en paramettre pointe vers d'autres structures pour 
**	tout free avant d'exit ou bien faire un garbage collector aussiiiiii
*/

void	ft_quit(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_loop_end(img->mlx_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free(img->mlx_ptr);
	exit(0);
}

/*  ***** Cleaning - display the error message *****
**  *************************
**  <SUMMARY>	Print an error message on stderr (if any) 
**				and return the provided error value
*/
int	ft_err_msg(int res, char *msg1, char *msg2)
{
	if (!msg1 && !msg2)
		return (res);
	write(2, "Error\n", 6);
	if (msg1)
	{
		ft_putstr_fd(msg1, STDERR_FILENO);
		write(2, ": ", STDERR_FILENO);
	}
	ft_putendl_fd(msg2, STDERR_FILENO);
	return (res);
}

/* <SUMMARY> Gets the 'sizeof' corresponding to the given type
*/
static size_t	ft_get_sizeof(int type)
{
	if (type == TAB_INT1)
		return (sizeof(int));
	else if (type == TAB_INT2 || type == TAB_INTS)
		return (sizeof(int *));
	else if (type == TAB_STR1)
		return (sizeof(char));
	else if (type == TAB_STR2 || type == TAB_STRS)
		return (sizeof(char *));
	return (0);
}

/*  ***** Cleaning - protect memory allocation *****
**  *************************
**  <SUMMARY>	Allocate uninitialized space 
**				and return a pointer to the allocated memory
*/
void	*ft_malloc(int type, int size)
{
	void	*ptr;

	ptr = malloc(ft_get_sizeof(type) * size);
	if (!ptr)
	{
		ft_err_msg(1, NULL, ER_MALLOC);
		//nettoyer
		exit(EXIT_FAILURE);//revoir
	}
	return (ptr);
}
