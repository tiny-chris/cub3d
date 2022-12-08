// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   color_buffer.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/12/06 15:16:10 by cgaillag          #+#    #+#             */
// /*   Updated: 2022/12/06 15:30:44 by cgaillag         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "cub3d.h"

// u_int32_t *color_buffer;

// // allocate enough memory to hold the entire screen in the color buffer
// color_buffer = (u_int32_t *) malloc(sizeof(u_int32_t) * (u_int32_t)WIN_WIDTH) * (u_int32_t)WIN_HEIGHT);

// // clear the entire color buffer with the color Black
// //my window width * number of rows and shift x
// int	x;
// int	y;

// x = 0;
// while (x < WIN_WIDTH)
// {
// 	y = 0;
// 	while (y < WIN_HEIGHT)
// 	{
// 		color_buffer[(WIN_WIDTH * y) + x] = 0xFF000000;
// 		y++;
// 	}
// 	x++;
// }
