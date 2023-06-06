/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:06:08 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/06 19:11:02 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_data	*look_up(t_win *win)
{
	t_data	img;

	if (win->player_walk == 0)
	{
		img = mlx_xpm_file_to_image(mlx, "/character2/tile013.xpm", win->image_length, win->image_heigth);
		win->player_walk = 1;
	}
	else
	{
		img = mlx_xpm_file_to_image(mlx, "/character2/tile015.xpm", win->image_length, win->image_heigth);
		win->player_walk = 0;
	}
	return (img);
}

t_data	*look_down(t_win win, t_data img)
{
	t_data	img;

	if (win->player_walk == 0)
	{
		img = mlx_xpm_file_to_image(mlx, "/character2/tile001.xpm", win->image_length, win->image_heigth);
		win->player_walk = 1;
	}
	else
	{
		img = mlx_xpm_file_to_image(mlx, "/character2/tile003.xpm", win->image_length, win->image_heigth);
		win->player_walk = 0;
	}
	return (img);
}

t_data	*look_left(t_win win, t_data img)
{
	t_data	img;

	if (win->player_walk == 0)
	{
		img = mlx_xpm_file_to_image(mlx, "/character2/tile005.xpm", win->image_length, win->image_heigth);
		win->player_walk = 1;
	}
	else
	{
		img = mlx_xpm_file_to_image(mlx, "/character2/tile007.xpm", win->image_length, win->image_heigth);
		win->player_walk = 0;
	}
	return (img);
}

t_data	*look_rigth(t_win win, t_data img)
{
	t_data	img;

	if (win->player_walk == 0)
	{
		img = mlx_xpm_file_to_image(mlx, "/character2/tile009.xpm", win->image_length, win->image_heigth);
		win->player_walk = 1;
	}
	else
	{
		img = mlx_xpm_file_to_image(mlx, "/character2/tile011.xpm", win->image_length, win->image_heigth);
		win->player_walk = 0;
	}
	return (img);
}
