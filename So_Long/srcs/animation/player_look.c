/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_look.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:26:48 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/06 19:06:22 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	HERE WILL DEAL WITH THE IMAGE OF WHERE THE PLAYER LOOK
*/

t_data	*look_up(t_win *win)
{
	t_data	img;

	img = mlx_xpm_file_to_image(mlx, "/character2/tile012.xpm", win->image_length, win->image_heigth);
	return (img);
}

t_data	*look_down(t_win win, t_data img)
{
	t_data	img;

	img = mlx_xpm_file_to_image(mlx, "/character2/tile000.xpm", win->image_length, win->image_heigth);
	return (img);
}

t_data	*look_left(t_win win, t_data img)
{
	t_data	img;

	img = mlx_xpm_file_to_image(mlx, "/character2/tile004.xpm", win->image_length, win->image_heigth);
	return (img);
}

t_data	*look_rigth(t_win win, t_data img)
{
	t_data	img;

	img = mlx_xpm_file_to_image(mlx, "/character2/tile008.xpm", win->image_length, win->image_heigth);
	return (img);
}
