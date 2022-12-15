/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/15 12:07:13 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  ***** Cleaning - display the error messages *****
**  *************************
**  <SUMMARY>	Print an error message on stderr (if any)
**				and return the provided error value
*/
int	ft_msg_1(int res, char *msg1, char *msg2, char *msg3)
{
	if (!msg1 && !msg2 && !msg3)
		return (res);
	write(2, "Error\n", 6);
	if (msg1)
	{
		ft_putstr_fd(msg1, STDERR_FILENO);
		write(STDERR_FILENO, ": ", 2);
	}
	if (msg2)
	{
		ft_putstr_fd(msg2, STDERR_FILENO);
		write(STDERR_FILENO, ": ", 2);
	}
	ft_putendl_fd(msg3, STDERR_FILENO);
	return (res);
}

int	ft_msg_2(int res, char *msg1, char *msg2, char *msg3)
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
