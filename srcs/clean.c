/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/22 11:13:03 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  ***** Cleaning - display the error message *****
**  *************************
**  Prints an error message on stderr (if any) and returns the provided error
** value
*/
int	ft_err_msg(int res, char *msg1, char *msg2)
{
	if (!msg1 && !msg2)
		return (res);
	write(2, "Error: ", 7);
	if (msg1)
	{
		ft_putstr_fd(msg1, STDERR_FILENO);
		write(2, ": ", STDERR_FILENO);
	}
	ft_putendl_fd(msg2, STDERR_FILENO);
	return (res);
}
